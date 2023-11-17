<?php
include_once "/home/sh2/exe/ecobee/settings.php";
$CONFIG_FILE = "/home/sh2/exe/ecobee/config.json";
$t_min=7;

// $controller = new Device($globalSettings);
// //$controller->setDeviceState("771:8");
// $state = $controller->getDeviceState("132:105");
// $controller->debug($state);


// обратная связь
if($argv[1] == "feedback"){

	$ecobee=new Ecobee();
	$json_answer = $ecobee->getData();
	$decodedThermostats = json_decode($json_answer, true)["thermostatList"];
	$a = file_get_contents($CONFIG_FILE);
	$config = json_decode($a, true);
	//var_dump($decodedThermostats);
	echo "\n-- got info conders --\n";
	$controller = new Device($globalSettings);
	$shClient = new SHClient(HOST, PORT, SECRET_KEY, LOG_FILE, XML_FILE);
	foreach($decodedThermostats as $thermostat){
		//var_dump($thermostat);
		$mode = $thermostat["settings"]["hvacMode"];
		$temperatureCoolDesired = $thermostat["runtime"]["desiredCool"];
		$temperatureHeatDesired = $thermostat["runtime"]["desiredHeat"];
		$elementSH = $config["thermostats"][$thermostat["identifier"]];
		echo "name_cond: " . $thermostat["name"]
			 . "\n  -- elementSH: ". $elementSH
			 . "\n  -- desiredCool: " . $ecobee->FahrenheitToCelsius($temperatureCoolDesired)
			 . "\n  -- desiredHeat: ". $ecobee->FahrenheitToCelsius($temperatureHeatDesired)
			 . "\n  -- mode: ".$mode. "\n";
		$state_to_cond = array("powerSwitch" => 0, "temperature" => 0, "vane" => 0, "air-fan" => 0,"wide_vane" => 0, "mode" => 0);
		// modes and onoff settings
		if($mode == "off"){
			$state_to_cond['powerSwitch'] = 0;
			$state_to_cond['mode'] = 2;
			$state_to_cond['temperature'] = intval(($ecobee->FahrenheitToCelsius($temperatureHeatDesired) + $ecobee->FahrenheitToCelsius($temperatureCoolDesired))/2) + $t_min +2;
			// temperature settings
		}
		if($mode == "heat"){
			$state_to_cond['powerSwitch'] = 1;
			$state_to_cond['mode'] = 1;
			$state_to_cond['temperature'] = intval($ecobee->FahrenheitToCelsius($temperatureHeatDesired)) + $t_min +2;
		}
		if($mode == "auto"){
			$state_to_cond['powerSwitch'] = 1;
			$state_to_cond['mode'] = 2;
			$state_to_cond['temperature'] = intval(($ecobee->FahrenheitToCelsius($temperatureHeatDesired) + $ecobee->FahrenheitToCelsius($temperatureCoolDesired))/2) + $t_min +2;
		}
		if($mode == "cool"){
			$state_to_cond['powerSwitch'] = 1;
			$state_to_cond['mode'] = 0;
			$state_to_cond['temperature'] = $ecobee->FahrenheitToCelsius($temperatureCoolDesired)+ $t_min+2;
		}
		
		// var_dump($shClient);
		echo "\n1\n";
		if($shClient->run()){
			echo "\n2\n";
			// echo "elementSH: ". $elementSH;
			//var_dump($state_to_cond);
			echo "\ntemperature: ".$state_to_cond['temperature']."\n";
			$shClient->setDeviceStateByAddr($elementSH, $state_to_cond);
			echo "\n3\n";
		}
		usleep(20000);
		
		// $state = $controller->getDeviceState($elementSH);
		// $controller->debug($state);
		
		//break;

	}

	return 0;
}

$authorize = new OAuth();
$authorize->RefreshToken();
//$ecobee=new Ecobee();
//$temp_settings = $ecobee->getTemperatureSettings("521797890620");
//var_dump($temp_settings);

// $shClient = new SHClient();
// $p = $shClient->getDataFromConsole();
// $p = $p['params'];
// var_dump($p);




class OAuth
{
	public $access_token;
	private $refresh_token;
	private $client_id;
	public $timestamp_update_accesToken;
	public function RefreshToken(){
		global $CONFIG_FILE;
		$curl = curl_init();
		curl_setopt_array($curl, array(
		  CURLOPT_URL => 'https://api.ecobee.com/token?grant_type=refresh_token&code='.$this->refresh_token.'&client_id='.$this->client_id,
		  CURLOPT_RETURNTRANSFER => true,
		  CURLOPT_ENCODING => '',
		  CURLOPT_MAXREDIRS => 10,
		  CURLOPT_TIMEOUT => 0,
		  CURLOPT_FOLLOWLOCATION => true,
		  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
		  CURLOPT_CUSTOMREQUEST => 'POST',
		  CURLOPT_HTTPHEADER => array(
		    'Cookie: did=s%3Av0%3A0fd2bb90-4344-11ee-b8a1-e94fa2527d5d.u6UcKrCfEU%2BPUKJB8ykyS8rOp03aP27UBJjk7RomNtQ; did_compat=s%3Av0%3A0fd2bb90-4344-11ee-b8a1-e94fa2527d5d.u6UcKrCfEU%2BPUKJB8ykyS8rOp03aP27UBJjk7RomNtQ'
		  ),
		));
		$response = curl_exec($curl);
		$response_decoded = json_decode($response, true);
		curl_close($curl);
		//echo $response;
		$this->access_token = $response_decoded['access_token'];
		$this->timestamp_update_accesToken = time();
		$a = file_get_contents($CONFIG_FILE);
		$config = json_decode($a, true);
		$config['accessToken'] = $this->access_token;
		$config['timestamp_update_accesToken'] = $this->timestamp_update_accesToken;
		file_put_contents($CONFIG_FILE, json_encode($config, JSON_PRETTY_PRINT));
		return $this->access_token;
	}
	function __construct() {
		global $CONFIG_FILE;
		$a  =  file_get_contents($CONFIG_FILE);
		$config = json_decode($a, true); 
		// var_dump($a);
		// var_dump($config);
		$this->access_token = $config['accessToken'];
		$this->refresh_token = $config['refreshToken'];
		$this->client_id = $config['client_id'];
    }
}

class Ecobee extends OAuth
{
	public $mimismart_sensors = array();
	function __construct() {
		global $CONFIG_FILE;
		$a  =  file_get_contents($CONFIG_FILE);
		$config = json_decode($a, true); 
		// var_dump($a);
		// var_dump($config);
		$this->access_token = $config['accessToken'];
		$this->refresh_token = $config['refreshToken'];
		$this->client_id = $config['client_id'];
    }
    function getData()
    {
    	$curl = curl_init();
    	curl_setopt_array($curl, array(
		  CURLOPT_URL => 'https://api.ecobee.com/1/thermostat?format=json&body={%22selection%22%3A{%22selectionType%22%3A%22registered%22%2C%22selectionMatch%22%3A%22%22%2C%22includeRuntime%22%3Atrue%2C%22includeSettings%22%3Atrue}}',
		  CURLOPT_RETURNTRANSFER => true,
		  CURLOPT_ENCODING => '',
		  CURLOPT_MAXREDIRS => 10,
		  CURLOPT_TIMEOUT => 0,
		  CURLOPT_FOLLOWLOCATION => true,
		  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
		  CURLOPT_CUSTOMREQUEST => 'GET',
		  CURLOPT_HTTPHEADER => array(
		    'Authorization: Bearer '.$this->access_token,
		    'Cookie: did=s%3Av0%3A6f4a1900-4c91-11ee-ad5d-b58ec604f8e5.9IZX%2B0ss5eI0RRIeNxBPCwx4UtwfpLig1fjdivMIv6A; did_compat=s%3Av0%3A6f4a1900-4c91-11ee-ad5d-b58ec604f8e5.9IZX%2B0ss5eI0RRIeNxBPCwx4UtwfpLig1fjdivMIv6A'
		  ),
		));

		$response = curl_exec($curl);

		curl_close($curl);
		return $response;
    }
    function getTemperatureSettings($conder_id){
    	$json  = $this->getData();
    	$temp_settings = array();
    	$conders = json_decode($json, true)['thermostatList'];
    	foreach ($conders as $element) {
    		if($element['identifier'] == $conder_id){
    			//if($element['runtime']['desiredHeat'])
    			$temp_settings["desiredHeat"] =  $element['runtime']['desiredHeat'];
    			$temp_settings["desiredCool"] =  $element['runtime']['desiredCool'];
    			return $temp_settings;
    		}
    		
    	}

    	var_dump(json_decode($json, true));
    }
    function FahrenheitToCelsius($Fa_value){
    	$Fa_value = $Fa_value / 10;
    	$celsius = round(($Fa_value- 32) * 5 / 9, 0);

    	return $celsius;
    }
    function CelsiusToFahrenheit($celsius){
    	$Fa_value =  ($celsius * 9/5) + 32;
    	$Fa_value = $Fa_value * 10;
    	return $Fa_value;
    }
    function setTemperature($conder_id, $temperature_celsius, $mode, $currentTempSettings){
		$curl = curl_init();
		$request = "";
		if($mode == 'heat'){
			$request = '{
			"selection":{
			"selectionType":"thermostats",
			"selectionMatch":"'.$conder_id.'"
			},
			"functions":[
			{
			"type":"setHold",
			"params":{
			"coolHoldTemp":'.$currentTempSettings['desiredCool'].',
			"heatHoldTemp":'.$temperature_celsius.',
			"holdType":"nextTransition"
			}
			}
			]
			}';
		}
		curl_setopt_array($curl, array(
		  CURLOPT_URL => 'https://api.ecobee.com/1/thermostat?format=json',
		  CURLOPT_RETURNTRANSFER => true,
		  CURLOPT_ENCODING => '',
		  CURLOPT_MAXREDIRS => 10,
		  CURLOPT_TIMEOUT => 0,
		  CURLOPT_FOLLOWLOCATION => true,
		  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
		  CURLOPT_CUSTOMREQUEST => 'POST',
		  CURLOPT_POSTFIELDS =>'{
			"selection":{
			"selectionType":"thermostats",
			"selectionMatch":"'.$conder_id.'"
			},
			"functions":[
			{
			"type":"setHold",
			"params":{
			"coolHoldTemp":770,
			"heatHoldTemp":788,
			"holdType":"nextTransition"
			}
			}
			]
			}',
		  CURLOPT_HTTPHEADER => array(
		    'Authorization: Bearer eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6IlJFWXhNVEpDT0Rnek9UaERRelJHTkRCRlFqZEdNVGxETnpaR1JUZzRNalEwTmtWR01UQkdPQSJ9.eyJpc3MiOiJodHRwczovL2F1dGguZWNvYmVlLmNvbS8iLCJzdWIiOiJhdXRoMHw3MmQzYTdlMC01YWI4LTRlZjgtYTNiOC1mYzhlMmY0YzU0ODMiLCJhdWQiOlsiaHR0cHM6Ly9kZXZlbG9wZXItYXBwcy5lY29iZWUuY29tL2FwaS92MSIsImh0dHBzOi8vZWNvYmVlLXByb2QuYXV0aDAuY29tL3VzZXJpbmZvIl0sImlhdCI6MTY5NDI0NjQyOCwiZXhwIjoxNjk0MjUwMDI4LCJhenAiOiIzUlZDbXgzZTY1bGRPSjNSQzRvVml5bGlrM2xPREQ4eSIsInNjb3BlIjoib3BlbmlkIHNtYXJ0V3JpdGUgb2ZmbGluZV9hY2Nlc3MifQ.XL4q_ZjRIxY1V8crtykLT-O-osQKVBg_AXFm5-aczlmeWBFPptdGaiC5-udukq2bG1CwxpE0h9vwHqsRogg_31USS2ts5kVdDS1_3Db3qeEFtMlu8b3bQ0pMnF9ZpH4p0Q-X5ikGe8tDHmrYb8V9AafGuhuvPeLlOS3FCo8sYr6KUnd8gbCvpYHqmIf-As5wJ7YAnPPMvg6PqWEGckuHiZe5G-mC7P6WzWr5t5vxMHvxaN_DOUNp7tYTEQxCqSEEnpDpSaiBuTCHNEsDtZ7-PKAKSxgkTmMI8gIhj5Gx71haPWAPI_0Vv9l15puwYLy2xsCD2sxvCPQwZpWh67IU_g',
		    'Content-Type: application/json',
		    'Cookie: did=s%3Av0%3A6f4a1900-4c91-11ee-ad5d-b58ec604f8e5.9IZX%2B0ss5eI0RRIeNxBPCwx4UtwfpLig1fjdivMIv6A; did_compat=s%3Av0%3A6f4a1900-4c91-11ee-ad5d-b58ec604f8e5.9IZX%2B0ss5eI0RRIeNxBPCwx4UtwfpLig1fjdivMIv6A'
		  ),
		));

		$response = curl_exec($curl);

		curl_close($curl);
		echo $response;

    }
}
class Device {

	public $error = FALSE;
	public $shClient = NULL;
	public $itemAddr = "";
	public $itemState = array();
	public $debug = FALSE;
	public $settings = array();
	public $logFile = "";

	public function __construct($settings) {

		$this->settings = $settings;
		$this->logFile = $this->settings["logFile"];
		$this->debug = $this->settings["debug"];
	}

	public function __destruct(){
		//$this->debug(__METHOD__);
	}
	    
    public function setDeviceState($addr, $state = NULL) {
        
        if(strpos($addr, ":") === FALSE) {
			$this->error = true;
			$this->msg = $this->translate("Device address not received");
        }
		
        if(!$this->error && !is_null($state)){
	        if(!is_array($state) || (is_array($state) && !array_key_exists("state", $state))){
				$state = NULL;
	        }
		}
        
        if(!$this->error) $this->connectToShS();
		
		if(!$this->error){
            if(is_null($state)) $state = array("state"=>0xff);
			$this->itemAddr = $addr;
			$this->itemState = $state;

			$methodName = "onSetDeviceState";
			$callback = array($this, $methodName);

        	$this->shClient->sendCommandToSH('retranslate-udp', $callback);
			$this->shClient->listenEventsOnMsg();
        }
		
    }

    public function getDeviceState($addr) {
    	//$this->debug(__METHOD__ . " " . __LINE__);
    	$state = NULL;
        if(strpos($addr, ":") === FALSE) {
			$this->error = true;
			$this->msg = $this->translate("Device address not received");
        }
        if(!$this->error) $this->connectToShS();
		if(!$this->error) $state = $this->shClient->getDeviceStateByAddr($addr);
        
		return $state;
    }

	public function onSetDeviceState($xml){
		$this->debug(__METHOD__ . " line: " . __LINE__);
		$this->shClient->stopListenEvents();
		$this->debug($this->itemAddr);
		$this->debug($this->itemState);
		$this->shClient->setDeviceStateByAddr($this->itemAddr, $this->itemState);
	}

	public function debug($msg = ""){
		if(is_array($msg)) $msg = print_r($msg, 1);
		elseif(!is_string($msg)) $msg = var_export($msg, TRUE);
		if($this->debug) print date("Y-m-d H:i:s") . "\t" . $msg . "\n";
	}

	private function connectToShS() {
		if(is_null($this->shClient)) {
				
			$this->debug(__METHOD__ . " " . __LINE__);
							
			$settings = $this->settings["shs"];
			$this->shClient = new \SHClient($settings["host"], $settings["port"], $settings["secret_key"], $settings["logFile"]);
			$this->shClient->debug = $this->debug;
			$this->shClient->readFromBlockedSocket = TRUE;
			
			if(!$this->shClient->run2()){
				$this->error = TRUE;

				if(count($this->shClient->errors)){
					foreach ($this->shClient->errors as $msg) {
						$this->msg = $msg;
						$this->debug();
						//$this->logger();
					}
				}
			}
			
		}elseif(!$this->shClient->clientIsConnected()) {
				
			$this->debug(__METHOD__ . " " . __LINE__);
			
			$this->shClient->clearErrors();
			
			if(!$this->shClient->run2()){
				$this->error = TRUE;

				if(count($this->shClient->errors)){
					foreach ($this->shClient->errors as $msg) {
						$this->msg = $msg;
						$this->debug();
						//$this->logger();
					}
				}
			}

		}
		
	}

}
?>
