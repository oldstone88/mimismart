#!/usr/bin/php
<?php
include_once "/home/sh2/exe/ecobee/settings.php";
$CONFIG_FILE = "/home/sh2/exe/ecobee/config.json";


// $controller = new Device($globalSettings);
// //$controller->setDeviceState("771:8");
// $state = $controller->getDeviceState("132:105");
// $controller->debug($state);

// $authorize = new OAuth();
// $authorize->RefreshToken();
$ecobee=new Ecobee();
$t_min=7;

//$temp_settings = $ecobee->getTemperatureSettings("521797890620");
//var_dump($temp_settings);

$shClient = new SHClient();
$p = $shClient->getDataFromConsole();
$p = $p['params'];
var_dump($p);
// if(isset($p['set24'])){
// 	if($p['set24'] == 1){

// 		$current_mode = "";
// 		if(isset($p['mode'])) {
// 			if($p['mode'] == "16") $current_mode = 'heat';
// 			if($p['mode'] == "32") $current_mode = 'auto';
// 			if($p['mode'] == "0") $current_mode = 'cool';
// 		}
// 		$ecobee->setMode($p['id'], $current_mode);
// 		sleep(1);
// 		$temp_settings = $ecobee->getTemperatureSettings($p['id']);
// 		$ecobee->setTemperature($p['id'], 24, $current_mode, $temp_settings);
// 	}
// }
if(isset($p['on'])){
	if($p['on'] == 0){
		$ecobee->setMode($p['id'], "off");
	}
	/*if($p['on'] == 1){
		$current_mode = "";
		if(isset($p['mode_now'])) {
			if($p['mode_now'] == "16") $current_mode = 'heat';
			if($p['mode_now'] == "32") $current_mode = 'auto';
			if($p['mode_now'] == "0") $current_mode = 'cool';
		}
		$ecobee->setMode($p['id'], $current_mode);
	}*/
}
if(isset($p['mode'])){
	// 16 = нагрев
	// 32 = авто
	// 0 - охлаждение
	if($p['mode'] == "16"){
		// $controller = new Device($globalSettings);
		// $state = $controller->setDeviceState("132:105", 0x2117);
		// var_dump($state);
		$ecobee->setMode($p['id'], "heat");
	}
	if($p['mode'] == "32"){
		$ecobee->setMode($p['id'], "auto");
	}
	if($p['mode'] == "0"){
		$ecobee->setMode($p['id'], "cool");
	}
}
if(isset($p['temp'])){
	$temp_settings = $ecobee->getTemperatureSettings($p['id']);
	$current_mode = "";
	if(isset($p['mode_now'])) {
		if($p['mode_now'] == "16") $current_mode = 'heat';
		if($p['mode_now'] == "32") $current_mode = 'auto';
		if($p['mode_now'] == "0") $current_mode = 'cool';
	}
	$ecobee->setTemperature($p['id'], $p['temp'], $current_mode, $temp_settings);
}
class OAuth
{
	public $access_token;
	private $refresh_token;
	private $client_id;
	public $timestamp_update_accesToken;
	public function RefreshToken(){
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
		$a = file_get_contents("config.json");
		$config = json_decode($a, true);
		$config['accessToken'] = $this->access_token;
		$config['timestamp_update_accesToken'] = $this->timestamp_update_accesToken;
		file_put_contents("config.json", json_encode($config, JSON_PRETTY_PRINT));
		return $this->access_token;
	}
	function __construct() {
		$a  =  file_get_contents("config.json");
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
		  CURLOPT_URL => 'https://api.ecobee.com/1/thermostat?format=json&body={%22selection%22%3A{%22selectionType%22%3A%22registered%22%2C%22selectionMatch%22%3A%22%22%2C%22includeRuntime%22%3Atrue}}',
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
    	$celsius = ($Fa_value- 320) * 5 / 90;
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
			"heatHoldTemp":'.$this->CelsiusToFahrenheit($temperature_celsius).',
			"holdType":"nextTransition"
			}
			}
			]
			}';
		}
		if($mode == 'auto'){
			$request = '{
			"selection":{
			"selectionType":"thermostats",
			"selectionMatch":"'.$conder_id.'"
			},
			"functions":[
			{
			"type":"setHold",
			"params":{
			"coolHoldTemp":'.$this->CelsiusToFahrenheit($temperature_celsius + 2).',
			"heatHoldTemp":'.$this->CelsiusToFahrenheit($temperature_celsius - 2).',
			"holdType":"nextTransition"
			}
			}
			]
			}';
		}
		if($mode == 'cool'){
			$request = '{
			"selection":{
			"selectionType":"thermostats",
			"selectionMatch":"'.$conder_id.'"
			},
			"functions":[
			{
			"type":"setHold",
			"params":{
			"coolHoldTemp":'.$this->CelsiusToFahrenheit($temperature_celsius).',
			"heatHoldTemp":'.$currentTempSettings['desiredHeat'].',
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
		  CURLOPT_POSTFIELDS =>$request,
		  CURLOPT_HTTPHEADER => array(
		    'Authorization: Bearer '.$this->access_token,
		    'Content-Type: application/json',
		    'Cookie: did=s%3Av0%3A6f4a1900-4c91-11ee-ad5d-b58ec604f8e5.9IZX%2B0ss5eI0RRIeNxBPCwx4UtwfpLig1fjdivMIv6A; did_compat=s%3Av0%3A6f4a1900-4c91-11ee-ad5d-b58ec604f8e5.9IZX%2B0ss5eI0RRIeNxBPCwx4UtwfpLig1fjdivMIv6A'
		  ),
		));

		$response = curl_exec($curl);
		curl_close($curl);
		echo $response;
    }
    function setMode($conder_id, $mode){
    	$curl = curl_init();

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
		  "selection": {
		    "selectionType":"thermostats",
		    "selectionMatch":"'.$conder_id.'"
		  },
		  "thermostat": {
		    "settings":{
		      "hvacMode":"'.$mode.'"
		    }
		  }
		} ',
		  CURLOPT_HTTPHEADER => array(
		    'Authorization: Bearer '.$this->access_token,
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
