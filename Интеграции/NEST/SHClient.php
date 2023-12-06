<?php
class SHClient {
    public $host = "127.0.0.1";
    public $port = "55555";
	public $aes = NULL;
    public $aeskey = "";
    public $logFile = "";
    public $initClientDefValue = 0x7ef;
    public $initClientID = 0;
    public $logicXml = "";
    public $xmlFile = "";
    public $allowReadXmlLogic = TRUE;
    public $allowRetraslateUDP = TRUE;
    public $serverWithMessages = FALSE;
    public $saveXmlLogic = TRUE;
    public $keysFile = "/home/sh2/keys.txt";
	public $debug = FALSE;
    

    public $connectionTimeOut = 5;//seconds
    public $connectionResource = null;
    public $errors = array();

    public $devicesStatesStore = array();
    public $devicesEventsStore = array();
    public $displayedDevices = array();
	public $devicesStore = array();
	public $devicesStoreCache = array();
	public $devicesStoreCacheLimit = 300; //microseconds
    
    public $devicesQuery = "";
	public $stopListenEventsOnMsg = FALSE;
	public $readFromBlockedSocket = FALSE;
	
	public $listenEventsDelay = 70000;

    private $bcmathExist = FALSE;
    private $xmlDoc = null;
    private $xpath = null;
    
    private $runSuccess = FALSE;
    private $readSocketTimeout = 3;//seconds
    
    private $eventOnDeviceCallbacks = array();
	private $eventOnMsgCallbacks = array();
	
	private $serverAnswer = "";
	private $shCommandsList = array("update-cans",
                          "update-can-log",
                          "cmd-pn",
                          "cmd-co",
                          "cmd-ti",
                          "cmd-qu"
                          );
	private $retranslateUdpSent = FALSE;
/*
		up - update cans
        lo - read device log
        ti - read device current time
        co - read device compile time
        pn - send PnP broadcast one
        qu - exit
*/ 	

	private $devHistory = array();
	
	
    public function __construct($host = "",$port = "",$aeskey = "",$logfile = "",$xmlfile = ""){
        if($host != "") $this->host = $host;
        if($port != "") $this->port = $port;
        $this->aeskey = $aeskey;
        $this->logFile = $logfile;
        $this->xmlFile = $xmlfile;
        if(function_exists("bcdiv")) $this->bcmathExist = TRUE;
		$this->aes = new \AES128();

        if(defined('KEYS_FILE') && KEYS_FILE != "" && file_exists(KEYS_FILE) && is_readable(KEYS_FILE)) $this->keysFile = KEYS_FILE;

        if($host != "" && $this->aeskey == "") $this->getAESKey();
    }

    public function __destruct(){
    	//$this->debug(__METHOD__);
		//$this->debug($this->errors);

        if($this->connected()) {
            fclose($this->connectionResource);
            $this->connectionResource = null;
        }
		
		
        if(count($this->errors)) $this->logger(implode("\n", $this->errors));
    }
	
	public function clearErrors(){
		$this->errors = array();
	}

    public function run(){
        if(count($this->errors) > 0) return FALSE;
/*        
        if(!class_exists("AES128")){
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "Class AES128 not found";
            return FALSE;
        }
        if(!class_exists("DOMDocument")) {
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "you must install domxml library, type in console: yum install php-dom";
            return FALSE;
        }

        if(!function_exists("bcdiv")) {
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "you must install bcmath library, type in console: yum install php-bcmath";
            return FALSE;
        }
*/
/*
        if(trim($this->logFile) == ""){
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "you must to pass the path of the log file";
            return FALSE;
        }

        if(trim($this->xmlFile) == ""){
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "you must to pass the path of the file where xml logic will be kept";
            return FALSE;
        }
*/
        $this->connectToServer();
        if(!$this->connected()) return FALSE;
        $this->authorization();
        if(!$this->connected()) {
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "Server authorization failed";
            return FALSE;
        }
        
        //if($this->readFromBlockedSocket) stream_set_blocking($this->connectionResource, 1);//set socket to block status
        
        if($this->allowRetraslateUDP){
            if($this->allowReadXmlLogic){
                $this->readXmlLogic();
                if(strpos($this->logicXml,"</smart-house>") === FALSE){
                    $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "Could not get xml logic from smart-house server.";
                    return FALSE;
                }
            }elseif($this->xmlFile != "" && file_exists($this->xmlFile)) {
                $this->readXmlLogic();
                $this->logicXml = file_get_contents($this->xmlFile);
            }
        }
        if($this->logicXml == "") $this->logicXml = "<?xml version='1.0' encoding='UTF-8'?><smart-house name=\"Умный дом\"></smart-house>";

//begin load xml
        $this->xmlDoc = new \DOMDocument('1.0', "UTF-8");
        $this->xmlDoc->formatOutput = TRUE;
        $this->xmlDoc->preserveWhiteSpace = FALSE;

        set_error_handler(function($number, $error){
            if (preg_match('/^DOMDocument::loadXML\(\): (.+)$/', $error, $m) === 1) {
                throw new \Exception($m[1]);
            }
        });
        
        try {
            $this->xmlDoc->loadXML($this->logicXml);
        }catch (Exception $e) {
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "parse xml error: " . $e->getMessage();
            return FALSE;
        }
        restore_error_handler();
//end load xml

        $this->xpath = new \DOMXPath($this->xmlDoc);
        $this->runSuccess = TRUE;
        $this->getDisplayedDevices();
        return TRUE;
    }

    public function run2(){
    	$this->debug(__METHOD__);
        if(count($this->errors) > 0) return FALSE;
/*        
        if(!class_exists("AES128")){
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "Class AES128 not found";
            return FALSE;
        }
		
        if(!class_exists("DOMDocument")) {
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "you must install domxml library, type in console: yum install php-dom";
            return FALSE;
        }

*/ 
        $this->connectToServer();
        if(!$this->connected()) return FALSE;
        $this->authorization();
        if(!$this->connected()) {
            $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "Server authorization failed";
            return FALSE;
        }
		
		$this->runSuccess = TRUE;
		stream_set_blocking($this->connectionResource, 1);//set socket to block status
		//$this->debug(__METHOD__ . " line:" . __LINE__);
        return TRUE;
    }

    public function getAESKey(){

        if(file_exists($this->keysFile)){
            if(!is_readable($this->keysFile)) $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "no read permissions of file: " . $this->keysFile;

            if(!count($this->errors) && ($tmparr = file($this->keysFile)) === FALSE) $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "File read error: " . $this->keysFile;
            
            if(!count($this->errors) && count($tmparr)){
                foreach($tmparr as $k=>$v){
                    $line = str_replace(array("\r\n","\r","\n"), "", $v);
                    if($line != ""){
                        $field = trim(strstr($line," ",true));
                        if($field != ""){
                            $key = "";
                            $status = true;
                            if(($pos = strpos($field,"#")) !== false && $pos == 0) $status = false;
                            $key = ltrim($field,"#");
                            if($status){
                                $this->aeskey = $key;
                                break;
                            }
                        }
                    }
                }
            }
        }else $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "File not found: " . $this->keysFile;

        if($this->aeskey == "") $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "Secret key is not set";
    }
//#######################################################################################################
    public function getDeviceState($id, $subid, $sendRequest = FALSE){
        $state = array();
        $tmpstate = array();
        
        $index = (int)$id . ":" . (int)$subid;
        if(!array_key_exists($index, $this->devicesStatesStore) || $sendRequest) {
            if($this->runSuccess) $tmpstate = $this->requestDeviceState((int)$id, (int)$subid);
        }else $tmpstate = $this->devicesStatesStore[$index];

        $deviceType = $this->getItemType($id, $subid);
        $length = count($tmpstate);

        if($length == 1){
            $state["state"] = $tmpstate[0];
        }else if($length == 2 && $deviceType == "dimer-lamp"){
            $state["state"] = $tmpstate[0];
            $state["value"] = $tmpstate[1];
        }else if($length == 6 && $deviceType == "conditioner"){
            $state["powerSwitch"] = (int)$tmpstate[0] & 0xf;
            $state["temperature"] = (int)$tmpstate[1] + 16;
            $state["air-fan"] = (int)$tmpstate[4] & 0xf;
            $state["mode"] = (int)$tmpstate[0] >> 4;
            $state["wide_vane"] = (int)$tmpstate[3] & 0xf;
            $state["vane"] = (int)$tmpstate[3] >> 4;
        }else {
            $state = $tmpstate;
        }
        if(!array_key_exists("state", $state)) $state["state"] = "";
        return $state;
    }

    public function getDevicesState($sendRequest = FALSE) {
        $states = array();
        if(!count($this->devicesStatesStore) || $sendRequest) $this->devicesStatesStore = $this->requestAllDevicesState();
        if(count($this->devicesStatesStore)){
            foreach ($this->devicesStatesStore as $index => $values) {
                list($id, $subid) = explode(":", $index);
                $states[$index] = $this->getDeviceState($id, $subid);
            }
        }
        return $states;
    }

    public function getDevicesEvents() {
        $events = array();
        $this->readDeviceStateEvent();
        if(count($this->devicesEventsStore)){
            foreach ($this->devicesEventsStore as $index => $values) {
                if(count($values)){
                    list($id, $subid) = explode(":", $index);
                    $events[$index] = $this->getDeviceState($id, $subid);
                    $this->devicesEventsStore[$index] = array();
                }
            }
        }
        return $events;
    }
    
    public function setDeviceState($id, $subid, $values){
        if(!$this->runSuccess) return;
        $deviceType = $this->getItemType($id, $subid);
        $index = (int)$id . ":" . (int)$subid;
        $length = count($values);
        if($deviceType != ""){
            if($length == 1){
                $device = array("id"=>$id,"sub-id"=>$subid,"state"=>$values["state"]);
                $this->changeDeviceState($device);
            }else if($length == 2 && $deviceType == "dimer-lamp"){
                $device = array("id"=>$id,"sub-id"=>$subid,"state"=>$values["state"],"value"=>$values["value"]);
                $this->changeDeviceStateValue($device);
            }else if($length == 6 && $deviceType == "conditioner"){
                // var_dump($values);
                $state = array(0,0,0,0,0,0);
                $currentState = $this->getDeviceStateByAddr($index, true);

                if ($currentState === null) $currentState = array();
                
                $state[0] = $values["powerSwitch"]|($values["mode"] << 4);
                $state[1] = (int)$values["temperature"] - 16;
                if(array_key_exists("air-fan", $currentState)) $state[4] = ((int)$currentState["air-fan"] & 0xf0) | (int)$values["air-fan"];
                if(array_key_exists("wide_vane", $currentState)) $state[3] = ((int)$currentState["wide_vane"] & 0xf0) | (int)$values["wide_vane"];
                $state[3] = ($state[3] & 0xf)|((int)$values["vane"] << 4);
                // $state = array(1,10,0,0,0,0);
                $device = array("id"=>$id,"sub-id"=>$subid,"length"=>6,"state"=>$state);
                // var_dump($device);
                $this->changeAnyDeviceState($device);
            }else {
                $device = array("id"=>$id,"sub-id"=>$subid,"length"=>count($values),"state"=>$values);
                $this->changeAnyDeviceState($device);
            }
        }
    }
    
    public function setDeviceStateByAddr($addr, $values){
        if(!$this->runSuccess) return FALSE;
        list($id, $subid) = explode(":", $addr);
        $this->setDeviceState($id, $subid, $values);
    }
    
//change state of lamps, scripts, jalousie, etc.
    public function changeDeviceState($device = array("id"=>0,"sub-id"=>0,"state"=>null)){
        if(!$this->runSuccess) return FALSE;
        //$this->logger(print_r($device,1));
        if((int)$device["id"] > 0 && (int)$device["sub-id"] > 0 && !is_null($device["state"])){
            $state = $device["state"];
            $data = $this->packData($device["id"], $device["sub-id"], 5, 1, array($state,0,0,0,0,0));
            $this->sendToServer($data);
        }
    }
//change state and value of dimmer-lamp
    public function changeDeviceStateValue($device = array("id"=>0,"sub-id"=>0,"state"=>null,"value"=>null)){
        if(!$this->runSuccess) return FALSE;
        if((int)$device["id"] > 0 && (int)$device["sub-id"] > 0 && !is_null($device["state"]) && !is_null($device["value"])){
            $state = $device["state"];
            $value = 0;
            if((int)$device["value"] >= 0 && (int)$device["value"] <= 100) $value = round((int)$device["value"]*2.5);
            $data = $this->packData($device["id"], $device["sub-id"], 5, 3, array($state,$value,0,0,0,0));
            $this->sendToServer($data);
        }
    }
//change state of any device
    public function changeAnyDeviceState($device = array("id"=>0,"sub-id"=>0,"length"=>0,"state"=>array(0,0,0,0,0,0))){
        if(!$this->runSuccess) return FALSE;
        //$this->logger(print_r($device,1));
        if((int)$device["id"] > 0 && (int)$device["sub-id"] > 0 && (int)$device["length"] > 0 && is_array($device["state"]) && count($device["state"]) > 0){
            $data = $this->packData($device["id"], $device["sub-id"], 5, $device["length"], $device["state"]);
            $this->sendToServer($data);
        }
    }
    public function sendMessage($message, $messageType = 1, $id = 2047, $subid = 32){
        if(!$this->runSuccess) return FALSE;
        $pd = 5;
        $length = 1 + mb_strlen($message);
        $data = pack("S2C4S", $this->initClientID, $id, $pd, 0, 0, $subid, $length);
        $data .= pack("C",$messageType);
        $data .= pack("A*", $message);
        $this->sendToServer($data);
    }
    public function sendMessage2($message, $id = 2047, $subid = 32){
        if(!$this->runSuccess) return FALSE;
        $pd = 5;
        $length = mb_strlen($message);
        $data = pack("S2C4S", $this->initClientID, $id, $pd, 0, 0, $subid, $length);
        $data .= pack("A*", $message);
        $this->sendToServer($data);
    }

    public function setStatus($addr, $value){
        if(!$this->runSuccess) return FALSE;
        list($id, $subid) = explode(":", $addr);
        $pd = 5;
        if(is_array($value)) $length = count($value);
        else $length = mb_strlen($value);
        $data = pack("S2C4S", $this->initClientID, $id, $pd, 0, 0, $subid, $length);
        if(is_string($value)) $data .= pack("A*", $value);
        elseif(is_array($value)) for($i=0;$i < $length;$i++) $data .= pack("C",$value[$i]);
        else $data .= $value;
        $this->sendToServer($data);
    }

//#######################################################################################################

//read state or event of device and save it to local stores
    public function readDeviceStateEvent(){
        $data = $this->fread(10);
        if(!$data["success"]) return;
        $unpackData = unpack("Llength/C6c", $data["data"]);
        $shHead = "";
        for($i=1;$i<=6;$i++) $shHead .= chr($unpackData["c".$i]);
/*
        $file = $this->logFile . ".shclient.head.txt";
        if($fp2 = fopen($file, "a")){
            $line2 = json_encode($unpackData) . " : " . $shHead;
            fwrite($fp2, date("r") . " " . $line2 . "\n");
            fclose($fp2);
        }
*/
        //print "head: " . $shHead . "\n";
        //print_r($unpackData);
        if($shHead != "" && $unpackData["length"] == 6) return;
        
        
        if($shHead == "shcxml"){
            $line = $this->fread(4);
            if(!$line["success"]) return;
            $crc = unpack("L*f",$line["data"]);

            $line = $this->fread(1);
            if(!$line["success"]) return;
            $addata = unpack("C*d",$line["data"]);

            $line = $this->fread($unpackData["length"]-5);
            if(!$line["success"]) return;

            //$this->logger("readDeviceStateEvent->head: " . $shHead);
            
        }elseif($shHead == "messag"){
            $message = $this->fread($unpackData["length"]-6);
            if(!$message["success"]) return;
            //print "head: " . $shHead . "message: " . $message . "\n";
            $this->logger("readDeviceStateEvent: head: " . $shHead . "; message: " . $message["data"]);
        }else {
            $unpackData = unpack("S2s/C4c/Slength", $data["data"]);
//#################################
/*
            $file = $this->logFile . ".shclient.rdata.txt";
            if($fp2 = fopen($file, "a")){
                $line2 = json_encode($unpackData);
                fwrite($fp2, date("r") . " " . $line2 . "\n");
                fclose($fp2);
            }
*/

//#################################
            if($unpackData["c1"] == 7){
                
                $line = $this->fread($unpackData["length"]);
                if(!$line["success"]) return;
                $ad = $line["data"];
                $values = array();
                $index = $unpackData["s1"] . ":" . $unpackData["c3"];
                $itemType = $this->getItemType((int)$unpackData["s1"], (int)$unpackData["c3"]);

                if($unpackData["length"] == 1){
                    $addata = unpack("C*value",$ad);
                    $values[] = $addata["value1"];
                }elseif($unpackData["length"] == 2 && $itemType != "dimer-lamp" && strpos($itemType, "sensor") === FALSE){
                    $addata = unpack("C*value",$ad);
                    $values[] = $addata["value1"];
                }elseif($unpackData["length"] == 2 && $itemType == "dimer-lamp"){
                    $addata = unpack("C*value",$ad);
                    foreach($addata as $v) $values[] = $v;

                    if(array_key_exists(1, $values)) {
                        if($this->bcmathExist) $values[1] = round(bcdiv($values[1], 2.5));
                        else $values[1] = round($values[1]/2.5);
                    }
                    
                }elseif($unpackData["length"] == 2){
                    $addata = unpack("S*value",$ad);
                    if($this->bcmathExist){
                        if($addata["value1"] > 32768) $value = bcdiv(bcsub(65536, $addata["value1"]), -256, 2);
                        else $value = bcdiv($addata["value1"], 256, 2);
                    }else {
                        if($addata["value1"] > 32768) $value = round((double)((65536-$addata["value1"])/-256), 2);
                        else $value = round((double)($addata["value1"]/256), 2);
                    }
                    $values[] = $value;
                }elseif($unpackData["length"] > 2){
                    $addata = unpack("C*value",$ad);
                    foreach($addata as $v) $values[] = $v;
                }

                if(count($values) > 0){
                    $this->devicesEventsStore[$index] = array();
                    //$this->devicesEventsStore[$index] = array("id"=>(int)$unpackData["s1"],"subid"=>(int)$unpackData["c3"],"data"=>$values);
                    $this->devicesEventsStore[$index] = $values;
                    $this->devicesStatesStore[$index] = $this->devicesEventsStore[$index];
                }
            }elseif($unpackData["c1"] == 15){
                $dataLength = $unpackData["length"];
                while($dataLength > 0){
                    $line = $this->fread(2);
                    if(!$line["success"]) return;
                    $dataLength -= 2;
                    $ucanData = unpack("Cucanid/Clength",$line["data"]);
                    $tmpdata = $this->fread($ucanData["length"]);
                    if(!$tmpdata["success"]) return;
                    $line = $tmpdata["data"];
                    $dataLength -= $ucanData["length"];
                    $values = array();
                    $index = $unpackData["s1"] . ":" . $ucanData["ucanid"];

                    $itemType = $this->getItemType((int)$unpackData["s1"], (int)$ucanData["ucanid"]);
                    
                    if($ucanData["length"] == 1){
                        $addata = unpack("C*value",$line);
                        $values[] = $addata["value1"];
                    }elseif($ucanData["length"] == 2 && $itemType != "dimer-lamp" && strpos($itemType, "sensor") === FALSE){
                        $addata = unpack("C*value",$line);
                        $values[] = $addata["value1"];
                    }elseif($ucanData["length"] == 2 && $itemType == "dimer-lamp"){
                        $addata = unpack("C*value",$line);
                        foreach($addata as $v) $values[] = $v;

                        if(array_key_exists(1, $values)) {
                            if($this->bcmathExist) $values[1] = round(bcdiv($values[1], 2.5));
                            else $values[1] = round($values[1]/2.5);
                        }
                    }elseif($ucanData["length"] == 2){
                        $addata = unpack("S*value",$line);

                        if($this->bcmathExist){
                            if($addata["value1"] > 32768) $value = bcdiv(bcsub(65536, $addata["value1"]), -256, 2);
                            else $value = bcdiv($addata["value1"], 256, 2);
                        }else {
                            if($addata["value1"] > 32768) $value = round((double)((65536-$addata["value1"])/-256), 2);
                            else $value = round((double)($addata["value1"]/256), 2);
                        }
                        $values[] = $value;
                    }elseif($ucanData["length"] > 2){
                        $addata = unpack("C*value",$line);
                        foreach($addata as $v) $values[] = $v;
                    }
                    if(count($values) > 0){
                        $this->devicesStatesStore[$index] = array();
                        //$this->devicesStatesStore[$index] = array("id"=>(int)$unpackData["s1"],"subid"=>(int)$ucanData["ucanid"],"data"=>$values);
                        $this->devicesStatesStore[$index] = $values;
                    }
                    //usleep(1000);
                }
            }else {
                $ad = $this->fread($unpackData["length"]);
                if(!$ad["success"]) return;
            }
        }
    }
//request all devices state
    public function requestAllDevicesState(){
        $resultData = array();
        if($this->runSuccess && count($this->displayedDevices)){
            foreach($this->displayedDevices as $index=>$v){
                $res = $this->requestDeviceState($v["id"], $v["subid"]);
                if(count($res) > 0) $resultData[$index] = $res;
            }
        }
        return $resultData;
    }
//request single device state
    public function requestDeviceState($id, $subid){
        $resultData = array();
        if($this->runSuccess && $id > 0 && $subid > 0){
            $data = $this->packData($id, 0, 14, 0, array(0,0,0,0,0,0));
            $this->sendToServer($data);
            $resultData = $this->readDeviceState($id, $subid);
        }
        return $resultData;
    }
//find item with requested id and subid in xml and return type attribute value
    public function getItemType($id, $subid){
        $type = "";
        if(is_null($this->xpath)) return $type;
        
        $query = '//item[(@id="' . (int)$id . '" and @sub-id="' . (int)$subid . '") or @addr="' . (int)$id . ':' . (int)$subid . '"]/@type';
        
        $entries = $this->xpath->query($query);
        if(is_object($entries) && $entries->length > 0) $type = $entries->item(0)->nodeValue;
        
        return $type;
    }
//get first item by type 
    public function getItemAttrsByType($type){
        $attrs = array();
        
        $query = '//item[@type="' . $type . '" and ((@id and @sub-id) or @addr)]';
        
        $entries = $this->xpath->query($query);
        if(is_object($entries) && $entries->length > 0) {
            $entry = $entries->item(0);
            $entryAttributes = array();
            foreach ($entry->attributes as $attr) $entryAttributes[$attr->nodeName] = $attr->nodeValue;
            $id = $subid = 0;
            if(array_key_exists("id", $entryAttributes)) $id = $entryAttributes["id"];
            if(array_key_exists("sub-id", $entryAttributes)) $subid = $entryAttributes["sub-id"];
            if(array_key_exists("addr", $entryAttributes)) list($id, $subid) = explode(":", $entryAttributes["addr"]);
            if((int)$id > 0 && (int)$subid > 0) {
                $entryAttributes["id"] = $id;
                $entryAttributes["sub-id"] = $subid;
				$entryAttributes["addr"] = $id . ":" . $subid;
                $attrs = $entryAttributes;
            }
        }
        
        return $attrs;
    }
    public function getDevicesIndexList($tag, $attr = "", $value = ""){
        $indexes = array();
        
        $query = '//' . $tag;
        if($attr != "") $query .= '[@' . $attr;
        if($attr != "" && $value != "") $query .= '="' . $value . '"';
        $query .= ']';
        
        $entries = $this->xpath->query($query);
        if(is_object($entries) && $entries->length > 0) {
            foreach ($entries as $entry) {
                $entryAttributes = array();
                foreach ($entry->attributes as $attribute) $entryAttributes[$attribute->nodeName] = $attribute->nodeValue;
                $id = $subid = 0;
                if(array_key_exists("id", $entryAttributes)) $id = $entryAttributes["id"];
                if(array_key_exists("sub-id", $entryAttributes)) $subid = $entryAttributes["sub-id"];
                if(array_key_exists("addr", $entryAttributes)) list($id, $subid) = explode(":", $entryAttributes["addr"]);
                if((int)$id > 0 && (int)$subid > 0) {
                    $index = $id . ":" . $subid;
                    $indexes[$index] = $index;
                }
            }
        }
        
        return $indexes;
    }
    
//disconnect
    public function disconnect(){
        if($this->connected()) {
            fclose($this->connectionResource);
            $this->connectionResource = null;
        }
    }

    public function checkConnection(){
        return $this->connected();
    }
    
    public function getXml($reload = FALSE){
        if($reload && $this->runSuccess) $this->readXmlLogic();
        return $this->logicXml;
    }

//begin get history of device
//start-timet and end-timet must be unixtimestamp
//method getDeviceLogs - get values by seconds
//method getDeviceMinutelyLogs - get values by minutes
    public function getDeviceLogs($params){
        $logs = array();
        $debug = false;
        $gmtdiff = bcmul(bcmul((int)substr(date('O'),0,3), 60), -60);
        $xml = "";
        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
        $xml .= '<get-history id="' . $params["id"] . '" sub-id="' . $params["subid"] . '"';
        if(array_key_exists("scale", $params) && $params["scale"] > 1) $xml .= ' scale="' . $params["scale"] . '"';
        if(array_key_exists("fromDate", $params) && $params["fromDate"] != "") $xml .= ' start-timet="' . $params["fromDate"] . '"';
        if(array_key_exists("toDate", $params) && $params["toDate"] != "") $xml .= ' end-timet="' . $params["toDate"] . '"';
        if(array_key_exists("joinType", $params) && $params["joinType"] != "" && $params["joinType"] != "def") $xml .= ' join-type="' . $params["joinType"] . '"';
        $xml .= "/>\n";
        $xml .= "</smart-house-commands>\n";

        if($debug) $this->logger($xml);
        
        $xmlsize = strlen($xml);
        $data = pack("L",$xmlsize) . $xml;
        $this->sendToServer($data);
        if($this->connected()){
            $bindata = $this->fread(4);
            if(!$bindata["success"]) return false;
            $unpackedData = unpack("L",$bindata["data"]);
            $totalLength = $unpackedData[1];

            if($debug) $this->logger("data length: " . $unpackedData[1]);

            $bindata2 = $this->fread(6);
            if(!$bindata2["success"]) return false;
            $unpackedData2 = unpack("L",$bindata2["data"]);

            if($debug) $this->logger("histry: " . $unpackedData2[1]);

            $bindata3 = $this->fread(2);
            if(!$bindata3["success"]) return false;
            $unpackedData3 = unpack("S",$bindata3["data"]);
            if($debug) $this->logger("id: " . $unpackedData3[1]);
            $bindata4 = $this->fread(1);
            if(!$bindata4["success"]) return false;
            $unpackedData4 = unpack("C",$bindata4["data"]);

            if($debug) $this->logger("subid: " . $unpackedData4[1]);
            
            $totalLength -= 9;

            while($totalLength > 0){
                $bindata5 = $this->fread(4);
                if(!$bindata5["success"]) return false;
                $unpackedData5 = unpack("L",$bindata5["data"]);
                $startTime = $unpackedData5[1];

                if($debug) $this->logger("date: " . $unpackedData5[1]);

                $bindata6 = $this->fread(4);
                if(!$bindata6["success"]) return false;
                $unpackedData6 = unpack("L",$bindata6["data"]);
                $eventsNum = (int)$unpackedData6[1];

                if($debug) $this->logger("events number: " . $unpackedData6[1]);

                $totalLength -= 8;
                if($eventsNum > 0){
                    for($i=0;$i<$eventsNum;$i++){
                        $time = "";
                        $value = "";
						$value2 = NULL;
						$value2AddTime = NULL;
    
                        switch($params["devtype"]){
                            case "temperature-sensor":
                                $bindata7 = $this->fread(2);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 2;
                                $unpackedData7 = unpack("S",$bindata7["data"]);
                                $v = $unpackedData7[1];
                                if(dechex($v) == 'ffff' || dechex($v) == 'fffe') $value = null;
                                else {
                                    if($v > 32768) $value = bcdiv((65536-$v),-256,2);
                                    else $value = bcdiv($v,256,2);
                                }
                                break;
                            case "motion-sensor":
                            case "illumination-sensor":
                            case "humidity-sensor":
                            case "co2-sensor":
                            case "voltage-sensor":
                            case "current-sensor":
                            case "methane-sensor":
                                $bindata7 = $this->fread(2);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 2;
                                $unpackedData7 = unpack("C*",$bindata7["data"]);
                                $v = ($unpackedData7[2]<<8) + $unpackedData7[1];
                                $v1 = bcdiv($v,256);
                                $v2 = bcdiv($v,256,2);
                                if($v1 >= 254) $value = null;
                                else $value = $v2;
                                break;
							case "valve-heating":
                                $bindata7 = $this->fread(6);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 6;
                                $unpackedData7 = unpack("C*",$bindata7["data"]);
                                $v = $unpackedData7[1];
                                if($v >= 254) $value = null;
                                else $value = $v;
								break;
							case "dimer-lamp":
                                $bindata7 = $this->fread(2);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 2;
                                $unpackedData7 = unpack("C*",$bindata7["data"]);
                                $v = $unpackedData7[1];
                                if($v >= 254) $value = null;
                                else $value = $v;
								break;
							case "switch":
                                $bindata7 = $this->fread(2);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 2;
                                $unpackedData7 = unpack("C*",$bindata7["data"]);
                                $v = $unpackedData7[1];
								$v2 = $unpackedData7[2];
								if($v2 < 1) $v2 = 1;
                                $value = 1;
								$value2 = 0;
								$value2AddTime = bcmul($v2, 128);
								break;
							case "rgb-lamp":
                                $bindata7 = $this->fread(4);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 4;
                                $unpackedData7 = unpack("C*",$bindata7["data"]);
                                $v = $unpackedData7[1];
                                if($v >= 254) $value = null;
                                else $value = $v;
								break;
                            default:
                                $bindata7 = $this->fread(1);
                                if(!$bindata7["success"]) return false;
                                $totalLength -= 1;
                                $unpackedData7 = unpack("C*",$bindata7["data"]);
                                $v = $unpackedData7[1];
                                if($v >= 254) $value = null;
                                else $value = $v;
                                break;
                        }
        
                        $bindata8 = $this->fread(3);
                        if(!$bindata8["success"]) return false;
                        $totalLength -= 3;
                        $unpackedData8 = unpack("C*",$bindata8["data"]);
                        $time = ($unpackedData8[3]<<16) + ($unpackedData8[2]<<8) + $unpackedData8[1];
                        //$time = bcadd(bcmul($startTime,1000), bcmul($time,10));//unixtimestamp with msec
                        //$time = bcadd($startTime, bcdiv($time,100));//unixtimestamp without msec

                        $time = bcadd($startTime, bcdiv($time,100));
                        $gmtime = bcmul(bcsub($time, $gmtdiff),1000);

                        //if($debug) print $i . "|" . date("H:i:s",$time) . " > " . $value . "; ";
                        if($gmtime != "") {
                            switch($params["devtype"]){
                                /*
                                case "lamp":
                                case "air-fan":
                                case "door-sensor":
                                    if(!is_null($value)){
                                        if($value == 0) $logs[] = array($time,1);
                                        else $logs[] = array($time,0);
                                        $logs[] = array(bcadd($time,100),$value);
                                    }//else $logs[] = array($time,$value);
                                    break;
                                 */
                                default:
                                    $logs[] = array($gmtime,$value);
									if(!is_null($value2)){
										$logs[] = array(bcadd($gmtime, $value2AddTime),$value2);
										$value2 = NULL;
									}
                                    break;
                            }
                        }
                    }
                }
					if($debug) $this->logger("total left: " . $totalLength);
            }
        }

        return $logs;   
    }

    public function getDeviceMinutelyLogs($params){
        $logs = array();
        $debug = false;
        $gmtdiff = bcmul(bcmul((int)substr(date('O'),0,3), 60), -60);
        $scale = 1;
        $xml = "";
        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
        $xml .= '<get-history-minutely id="' . $params["id"] . '" sub-id="' . $params["subid"] . '"';
        if(array_key_exists("scale", $params) && $params["scale"] > 1) {
            $xml .= ' scale="' . $params["scale"] . '"';
            $scale = $params["scale"];
        }
        if(array_key_exists("fromDate", $params) && $params["fromDate"] != "") $xml .= ' start-timet="' . $params["fromDate"] . '"';
        if(array_key_exists("toDate", $params) && $params["toDate"] != "") $xml .= ' end-timet="' . $params["toDate"] . '"';
        if(array_key_exists("joinType", $params) && $params["joinType"] != "" && $params["joinType"] != "def") $xml .= ' join-type="' . $params["joinType"] . '"';
        $xml .= "/>\n";
        $xml .= "</smart-house-commands>\n";

        if($debug) $this->logger($xml);
        
        $xmlsize = strlen($xml);
        $data = pack("L",$xmlsize) . $xml;
        $this->sendToServer($data);
        if($this->connected()){
            $bindata = $this->fread(4);
            if(!$bindata["success"]) return false;
            $unpackedData = unpack("L",$bindata["data"]);
            $totalLength = $unpackedData[1];

            if($debug) $this->logger("data length: " . $unpackedData[1]);

            $bindata2 = $this->fread(6);
            if(!$bindata2["success"]) return false;
            $unpackedData2 = unpack("L",$bindata2["data"]);
            if($debug) $this->logger("histry: " . $unpackedData2[1]);
            
            $bindata3 = $this->fread(2);
            if(!$bindata3["success"]) return false;
            $unpackedData3 = unpack("S",$bindata3["data"]);

            if($debug) $this->logger("id: " . $unpackedData3[1]);
            
            $bindata4 = $this->fread(1);
            if(!$bindata4["success"]) return false;
            $unpackedData4 = unpack("C",$bindata4["data"]);
            if($debug) $this->logger("subid: " . $unpackedData4[1]);
            $totalLength -= 9;
            $bindata5 = $this->fread($totalLength);
            if(!$bindata5["success"]) return false;
			$packExp = "S*";
			if(strpos($params["devtype"],"-sensor") === FALSE || $params["devtype"] == "door-sensor" || $params["devtype"] == "leak-sensor") $packExp = "C*";
            $unpackedData5 = unpack($packExp,$bindata5["data"]);
            if($debug) $this->logger("values length: " . count($unpackedData5));

            $numValues = count($unpackedData5);
            $toTime = $params["toDateUTS"];
            
            foreach($unpackedData5 as $v){
                $value = "";

                switch($params["devtype"]){
                    case "temperature-sensor":
                        if(dechex($v) == 'ffff' || dechex($v) == 'fffe') $value = null;
                        else {
                            if($v > 32768) $value = bcdiv((65536-$v),-256,2);
                            else $value = bcdiv($v,256,2);
                        }
                        break;
                    default:
						if(strpos($params["devtype"],"-sensor") === FALSE || $params["devtype"] == "door-sensor" || $params["devtype"] == "leak-sensor"){
	                        if($v >= 254) $value = null;
	                        else $value = bcdiv($v,256,2);
							$value = $v;
						}else {
	                        $v1 = bcdiv($v,256);
	                        $v2 = bcdiv($v,256,2);

	                        if($v1 >= 254) $value = null;
	                        else $value = $v2;
						}
                        break;
                }
                //$time = bcmul(bcsub($toTime, bcmul($numValues, bcmul(60, $scale))), 1000);
                $time = bcsub($toTime, bcmul($numValues, bcmul(60, $scale)));
                $gmtime = bcmul(bcsub($time, $gmtdiff),1000);
                $numValues--;
                $logs[] = array($gmtime,$value);
            }
        }

        return $logs;
    }

    public function getDeviceHistory($params){

		$history = array();
        $gmtdiff = bcmul(bcmul((int)substr(date('O'),0,3), 60), -60);
        $scale = 1;
        $xml = "";
        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
        $xml .= '<get-history-minutely id="' . $params["id"] . '" sub-id="' . $params["subid"] . '"';
        if(array_key_exists("scale", $params) && $params["scale"] > 1) {
            $xml .= ' scale="' . $params["scale"] . '"';
            $scale = $params["scale"];
        }
        if(array_key_exists("fromDate", $params) && $params["fromDate"] != "") $xml .= ' start-timet="' . $params["fromDate"] . '"';
        if(array_key_exists("toDate", $params) && $params["toDate"] != "") $xml .= ' end-timet="' . $params["toDate"] . '"';
        if(array_key_exists("joinType", $params) && $params["joinType"] != "" && $params["joinType"] != "def") $xml .= ' join-type="' . $params["joinType"] . '"';
        $xml .= "/>\n";
        $xml .= "</smart-house-commands>\n";

        $this->debug($xml);


		$methodName = "onGetDeviceHistoryByMins";
		$callback = array($this, $methodName);
		$this->addEventOnMsgCallback("hismin", $callback, array("params"=>$params,"scale"=>$scale,"gmtdiff"=>$gmtdiff), FALSE);
	        
        $xmlsize = strlen($xml);
        $data = pack("L",$xmlsize) . $xml;
        $this->sendToServer($data);

		$listenEventsDelay = $this->listenEventsDelay;
		$this->listenEventsDelay = 0;
		
		$this->listenEventsOnMsg();
		$this->listenEventsDelay = $listenEventsDelay;
		$history = $this->devHistory;
		$this->devHistory = array();

        return $history;
    }

    public function onGetDeviceHistoryByMins($totalLength, $args, $msg = ""){
        $this->debug(__METHOD__ . " line: " . __LINE__);
        $params = $args["params"];
		$scale = $args["scale"];
		$gmtdiff = $args["gmtdiff"];
        $this->debug("total length: " . $totalLength);
        $this->debug($params);
        $this->debug("message: " . $msg);
        $bindata = $this->readBlockedSocket(2);
        $unpackedData = unpack("S",$bindata);
		
		$this->debug("read 2 bytes");
        $this->debug($unpackedData);
        
        $bindata = $this->readBlockedSocket(1);
        $unpackedData = unpack("C",$bindata);
		$this->debug("read 1 bytes");
        $this->debug($unpackedData);
		
        $totalLength -= 3;
		$this->debug("read " . $totalLength . " bytes");
        $bindata = $this->readBlockedSocket($totalLength);
		$packExp = "S*";
		if(strpos($params["devtype"],"-sensor") === FALSE || $params["devtype"] == "door-sensor" || $params["devtype"] == "leak-sensor") $packExp = "C*";
		if($params["devtype"] == "virtual") $packExp = "S*";
        $unpackedData = unpack($packExp,$bindata);
        $this->debug("values length: " . count($unpackedData));

        $numValues = count($unpackedData);
        $toTime = $params["toDateUTS"];
        
        foreach($unpackedData as $v){
            $value = "";

            switch($params["devtype"]){
                case "temperature-sensor":
                    if(dechex($v) == 'ffff' || dechex($v) == 'fffe') $value = null;
                    else {
                        if($v > 32768) $value = bcdiv((65536-$v),-256,2);
                        else $value = bcdiv($v,256,2);
                    }
                    break;
				case "virtual":
                    if(dechex($v) == 'ffff' || dechex($v) == 'fffe') $value = null;
                    else {
                        if($v > 32768) $value = bcdiv((65536-$v),-256,2);
                        else $value = bcdiv($v,256,2);
                    }
					break;
                default:
					if(strpos($params["devtype"],"-sensor") === FALSE || $params["devtype"] == "door-sensor" || $params["devtype"] == "leak-sensor"){
                        if($v >= 254) $value = null;
                        else $value = bcdiv($v,256,2);
						//$value = $v;
					}else {
                        $v1 = bcdiv($v,256);
                        $v2 = bcdiv($v,256,2);

                        if($v1 >= 254) $value = null;
                        else $value = $v2;
					}
                    break;
            }
            //$time = bcmul(bcsub($toTime, bcmul($numValues, bcmul(60, $scale))), 1000);
            $time = bcsub($toTime, bcmul($numValues, bcmul(60, $scale)));
            $gmtime = bcmul(bcsub($time, $gmtdiff),1000);
            $numValues--;
            $this->devHistory[] = array($gmtime,$value);
        }
		$this->stopListenEvents();
    }

//end get history of device

    public function getDataFromConsole(){
        $consoleParams = array();
        $startIdx = 1;
        if($_SERVER["argc"] > 3) $startIdx = 2;

        $inParams = "";
        if(array_key_exists($startIdx, $_SERVER["argv"])){
            $inParams = trim($_SERVER["argv"][$startIdx]);
            if($inParams == "") {
                $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "input params not found";
            }
        }
        $startIdx++;
        $inParams2 = "";
        if(array_key_exists($startIdx, $_SERVER["argv"])){
            $inParams2 = trim($_SERVER["argv"][$startIdx]);
            if($inParams2 == "") {
                $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "input params not found";
            }
        }

        if(!count($this->errors)){
            if(preg_match("/\d{1,4}\:\d{1,3}/", $inParams)){
                $consoleParams["sender"] = $inParams;
                list($consoleParams["senderID"], $consoleParams["senderSubID"]) = explode(":", $inParams);
            }else $this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "sender id not found";
        }
        if(!count($this->errors)){
            $tmparr = str_split($inParams2, 2);
            $tmparr2 = array();
            foreach ($tmparr as $hex) $tmparr2[] = hexdec($hex);
            $consoleParams["bin"] = $tmparr2;
            $paramsStr = pack("H*", $inParams2);
            $consoleParams["str"] = $paramsStr;

            $tmparr = array();
            if(strpos($paramsStr, "|") !== FALSE) $tmparr = explode("|", $paramsStr);
            $params = array();
            if(count($tmparr)) {
                foreach ($tmparr as $value) {
                    if(strpos($value, "=") !== FALSE){
                        $tmparr2 = explode("=",$value,2);
                        $params[$tmparr2[0]] = $tmparr2[1];
                    }else $params[$value] = "";
                }
            }
            $consoleParams["params"] = $params;
        }
            
        return $consoleParams;
    }
    
    public function setLogicXml($xml){
        $xml = str_replace("&amp;","#amp;",$xml);
        $xml = str_replace("&","&amp;",$xml);
        $xml = str_replace("#amp;","&amp;",$xml);

        $this->logicXml = $xml;
    }
    
    public function addEventCallback($addr, $callbackFunc){
        list($id, $subid) = explode(":", $addr);

        if($this->getItemType($id, $subid) == ""){
            throw new \Exception ("Couldn't find device by addr " . $addr);
            return false;
        }
        if(!function_exists($callbackFunc)){
            throw new \Exception ("Callback function doesn't exist");
            return false;
        }
        
        $this->eventCallbacks[$addr] = $callbackFunc;
        
        return true;
    }

    public function listenEvents(){
        $this->readDeviceStateEvent();

        if(count($this->eventCallbacks)){
            foreach ($this->eventCallbacks as $addr => $callback) {
                if(array_key_exists($addr, $this->devicesEventsStore)) {
                    if(function_exists($callback)) call_user_func($callback, $addr, $this->devicesEventsStore[$addr]);
                    unset($this->devicesEventsStore[$addr]);
                }
            }
        }

    }

	public function clientIsConnected() {
		return $this->connected();
	}

//##########################################################################################################################
    public function addEventOnMsgCallback($message, $callbackFunc, $argv = array(), $readAll = TRUE) {

		if(array_key_exists($message, $this->eventOnMsgCallbacks)) return FALSE;

		$data = array("callback"=>$callbackFunc, "argv"=>$argv, "readAll"=>$readAll);
		if(!array_key_exists($message, $this->eventOnMsgCallbacks)) $this->eventOnMsgCallbacks[$message] = array($data);
		else $this->eventOnMsgCallbacks[$message][] = $data;
        
        return TRUE;
    }

    public function removeEventOnMsgCallback($message) {
		if(array_key_exists($message, $this->eventOnMsgCallbacks)) unset($this->eventOnMsgCallbacks[$message]);
        return TRUE;
    }

    public function eventOnMsgCallbackExist($message) {
		if(array_key_exists($message, $this->eventOnMsgCallbacks)) return TRUE;
		return FALSE;
    }

    public function listenEventsOnMsg() {
    	if(!count($this->eventOnMsgCallbacks)) return false;
    	
		while (!$this->stopListenEventsOnMsg && $this->connected() && count($this->eventOnMsgCallbacks)) {
			//$this->debug(__METHOD__ . " line: " . __LINE__);
			$data = $this->readBlockedSocket(10);
	        $unpackData = @unpack("Llength/C6c", $data);
			$leftLength = $unpackData["length"]-6;
	        $msg = "";
	        for($i=1;$i<=6;$i++) $msg .= chr($unpackData["c".$i]);
			//$this->debug($msg);
/*	        	
	        foreach ($this->eventOnMsgCallbacks as $event => $eventElements) {
 				$this->debug($event);
				foreach ($eventElements as $eventData) {
					$this->debug($eventData["callback"][1]);
				}
	        }
*/
			
	        foreach ($this->eventOnMsgCallbacks as $event => $eventElements) {
				if(preg_match("/[a-zA-Z0-9]{3,}/", $msg) && ($event == $msg || $event == "unknownMsg")) {
					foreach ($eventElements as $eventData) {
						if($eventData["readAll"]){
							$data = NULL;
						    if($leftLength > 0) $data = $this->readBlockedSocket($leftLength);
							if(!is_null($eventData["callback"])) call_user_func($eventData["callback"], $data, $eventData["argv"], $msg);
							$leftLength = 0;
						}elseif(!is_null($eventData["callback"])) {
							 call_user_func($eventData["callback"], $leftLength, $eventData["argv"], $msg);//inner callback for shclient class
							 $leftLength = 0;
						}
					}
					break;
				}elseif(!preg_match("/[a-zA-Z0-9]{3,}/", $msg) && $event == "dev-event") {
					foreach ($eventElements as $eventData) {
						$devState = $this->onDeviceEvent($data);
						if(!is_null($devState)){
							$leftLength = 0;
							if(!is_null($eventData["callback"])){
								call_user_func($eventData["callback"], $devState, $eventData["argv"]);
							}
						}
					}
					break;
				}
	        }
			if($leftLength > 0) $dataTmp = $this->readBlockedSocket($leftLength);
			if($this->listenEventsDelay > 0) usleep($this->listenEventsDelay);
		}
		$this->stopListenEventsOnMsg = FALSE;
    }

    public function sendCommandToSH($command, $callback = NULL) {
        $xml = "";
		switch ($command) {
			case 'get-dev-info':
		        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
		        $xml .= "<get-dev-info />\n";
		        $xml .= "</smart-house-commands>\n";
				
				if(!is_null($callback)) $this->addEventOnMsgCallback("devinf", $callback);
				break;
			case 'get-events':
				if(!is_null($callback)) {
					$this->addEventOnMsgCallback("dev-event", $callback);
				}
				if(!$this->retranslateUdpSent){
				    $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
			        $xml .= "<get-shc retranslate-udp=\"yes\" />\n";
			        $xml .= "</smart-house-commands>\n";
					$this->retranslateUdpSent = TRUE;
					
	
					$methodName = "onGetXmlLogic";
					$callback = array($this, $methodName);
					$this->addEventOnMsgCallback("shcxml", $callback, array(), FALSE);
				}
				break;
			case 'get-shc':
		        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
		        $xml .= "<get-shc />\n";
		        $xml .= "</smart-house-commands>\n";

				$argv = array();
				if(!is_null($callback)) {
					$argv[] = $callback;
				}
				$methodName = "onGetXmlLogic";
				$callback = array($this, $methodName);
				$this->addEventOnMsgCallback("shcxml", $callback, $argv, FALSE);

				break;
			case 'retranslate-udp':
				if(!$this->retranslateUdpSent){
			        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
			        $xml .= "<get-shc retranslate-udp=\"yes\" />\n";
			        $xml .= "</smart-house-commands>\n";
					$this->retranslateUdpSent = TRUE;
	
					$argv = array();
					if(!is_null($callback)) {
						$argv[] = $callback;
					}
					$methodName = "onGetXmlLogic";
					$callback = array($this, $methodName);
					$this->addEventOnMsgCallback("shcxml", $callback, $argv, FALSE);
				}elseif(!is_null($callback) && is_array($callback) && count($callback) == 2){
					$this->stopListenEvents();
					call_user_func($callback, $this->logicXml);
				}
				break;
		}

		if($xml != "") {
	        $xmlsize = strlen($xml);
	        $data = pack("L",$xmlsize) . $xml;
			$this->debug(__METHOD__ . " line: " . __LINE__);
			$this->debug($xml);
	        $this->sendToServer($data);

		}
    }

    public function sendCommand($command = "update-cans", $readAnswer = TRUE) {
        echo "sendCOmmand\n";
		if(count($this->errors)) return FALSE;
/*		
		if(!in_array($command, $this->shCommandsList)){
			$this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . "command not found";
			return FALSE;
		}
*/
		$this->debug(__METHOD__ . " line: " . __LINE__);

        $xmlcommands = array();
        $xmlcommands["xmlStartLine"] = '<?xml version="1.0" encoding="UTF-8"?>' . "\n";
        $xmlcommands["xmlBeginCommand"] = '<smart-house-commands>' . "\n";
        $xmlcommands["xmlEndCommand"] = "</smart-house-commands>\n";
        $xmlcommands["getXMLConf"] = $xmlcommands["xmlStartLine"] . $xmlcommands["xmlBeginCommand"];
		if(in_array($command, $this->shCommandsList)) {
        	$xmlcommands["getXMLConf"] .= '<' . $command . ' />' . "\n";
		}else {
			$xmlcommands["getXMLConf"] .= $command . "\n";
		}
        $xmlcommands["getXMLConf"] .= $xmlcommands["xmlEndCommand"];
		

        $serverAnswer = "";
        $xml = $xmlcommands["getXMLConf"];

        $xmlsize = strlen($xml);
        $data = pack("L",$xmlsize) . $xml;

        $this->sendToServer($data);

        if($command == "update-cans" && $readAnswer) {
			$methodName = "onGetCanInfo";
			$callback = array($this, $methodName);
			$this->addEventOnMsgCallback("caninf", $callback);
			$listenEventsDelay = $this->listenEventsDelay;
			$this->listenEventsDelay = 0;
			
			$this->listenEventsOnMsg();
			$serverAnswer = $this->serverAnswer;
			$this->listenEventsDelay = $listenEventsDelay;
		}

        return $serverAnswer;
    }

	public function stopListenEvents() {
		$this->stopListenEventsOnMsg = TRUE;
	}
	
	private function onGetXmlLogic($leftLength, $argv = NULL) {
		//$this->debug(__METHOD__);
		$callback = NULL;
		if(!is_null($argv) && is_array($argv) && count($argv) > 0) $callback = $argv[0];

	    $data = $this->readBlockedSocket(4);
	    $crc = unpack("L*f",$data);

		//$this->debug("crc");
		//$this->debug($crc);
	
	    $data = $this->readBlockedSocket(1);
	    $addata = unpack("C*d",$data);

	    //$this->debug("after crc");
	    //$this->debug($addata);

	    $this->initClientID = $this->initClientDefValue - $addata["d1"];

	    $data = $this->readBlockedSocket($leftLength-5);
	    $this->logicXml = $data;
	    
		//$this->debug($this->logicXml);

   		$this->getDomXml();

		if(!is_null($callback) && is_array($callback) && count($callback) == 2){
			call_user_func($callback, $this->logicXml);
		}

	}
	
	private function onGetUnknownMsg() {
		$this->debug(__METHOD__);
		//$this->debug(func_num_args());
		//$args = func_get_args();
		//$this->debug($args);
		
		//$this->stopListenEvents();
	}
	
	private function onGetCanInfo($data){
		$this->debug(__METHOD__);
		$this->serverAnswer = $data;
		$this->stopListenEvents();
	}

    private function onDeviceEvent($headerData) {
		$devState = NULL;
		
        $unpackData = @unpack("S2s/C4c/Slength", $headerData);
		//$this->debug($unpackData);
		if(!is_array($unpackData) || count($unpackData) != 7) return NULL;
				
		$readLength = $unpackData["length"];

        if($unpackData["c1"] == 7){
            //begin get events
            $ad = $this->readBlockedSocket($readLength);
            $values = array();
            $addr = $unpackData["s1"] . ":" . $unpackData["c3"];
            $itemType = $this->getItemType((int)$unpackData["s1"], (int)$unpackData["c3"]);

            if($readLength == 1){
                $addata = unpack("C*value",$ad);
                $values[] = $addata["value1"];
            }elseif($readLength == 2 && $itemType != "dimer-lamp" && strpos($itemType, "sensor") === FALSE){
                $addata = unpack("C*value",$ad);
                $values[] = $addata["value1"];
            }elseif($readLength == 2 && $itemType == "dimer-lamp"){
                $addata = unpack("C*value",$ad);
                foreach($addata as $v) $values[] = $v;

                if(array_key_exists(1, $values)) {
                    if($this->bcmathExist) $values[1] = round(bcdiv($values[1], 2.5));
                    else $values[1] = round($values[1]/2.5);
                }
                
            }elseif($readLength == 2){
                $addata = unpack("S*value",$ad);
                if($this->bcmathExist){
                    if($addata["value1"] > 32768) $value = bcdiv(bcsub(65536, $addata["value1"]), -256, 2);
                    else $value = bcdiv($addata["value1"], 256, 2);
                }else {
                    if($addata["value1"] > 32768) $value = round((double)((65536-$addata["value1"])/-256), 2);
                    else $value = round((double)($addata["value1"]/256), 2);
                }
                $values[] = $value;
            }elseif($readLength > 2){
                $addata = unpack("C*value",$ad);
                foreach($addata as $v) $values[] = $v;
            }

            if(count($values) > 0){
            	$devState = array(array("addr"=>$addr, "type"=>$itemType, "event"=>1, "values"=>$values));
                $this->devicesStatesStore[$addr] = $values;
            }
			//end get events
        }elseif($unpackData["c1"] == 15){
			//begin get requested devices state
			while($readLength > 0) {
                $rData = $this->readBlockedSocket(2);
                $readLength -= 2;
                $ucanData = unpack("Cucanid/Clength",$rData);
                $tmpData = $this->readBlockedSocket($ucanData["length"]);
                $readLength -= $ucanData["length"];
                $values = array();
                $addr = $unpackData["s1"] . ":" . $ucanData["ucanid"];

                $itemType = $this->getItemType((int)$unpackData["s1"], (int)$ucanData["ucanid"]);
                
                if($ucanData["length"] == 1){
                    $addata = unpack("C*value",$tmpData);
                    $values[] = $addata["value1"];
                }elseif($ucanData["length"] == 2 && $itemType != "dimer-lamp" && strpos($itemType, "sensor") === FALSE){
                    $addata = unpack("C*value",$tmpData);
                    $values[] = $addata["value1"];
                }elseif($ucanData["length"] == 2 && $itemType == "dimer-lamp"){
                    $addata = unpack("C*value",$tmpData);
                    foreach($addata as $v) $values[] = $v;

                    if(array_key_exists(1, $values)) {
                        if($this->bcmathExist) $values[1] = round(bcdiv($values[1], 2.5));
                        else $values[1] = round($values[1]/2.5);
                    }
                }elseif($ucanData["length"] == 2){
                    $addata = unpack("S*value",$tmpData);

                    if($this->bcmathExist){
                        if($addata["value1"] > 32768) $value = bcdiv(bcsub(65536, $addata["value1"]), -256, 2);
                        else $value = bcdiv($addata["value1"], 256, 2);
                    }else {
                        if($addata["value1"] > 32768) $value = round((double)((65536-$addata["value1"])/-256), 2);
                        else $value = round((double)($addata["value1"]/256), 2);
                    }
                    $values[] = $value;
                }elseif($ucanData["length"] > 2){
                    $addata = unpack("C*value",$tmpData);
                    foreach($addata as $v) $values[] = $v;
                }
				
                if(count($values) > 0) {
                	if(!is_array($devState)) $devState = array();
					$devState[] = array("addr"=>$addr, "type"=>$itemType, "event"=>0,  "values"=>$values);
                    $this->devicesStatesStore[$addr] = $values;
                }
            }
			//end get requested devices state
        }
        
        return $devState;
    }

    private function getDomXml($xml = "") {
    	if($xml == "") $xml = $this->logicXml;

        $logicXml = str_replace("&amp;","#amp;",$xml);
        $logicXml = str_replace("&","&amp;",$logicXml);
        $logicXml = str_replace("#amp;","&amp;",$logicXml);

        $this->xmlDoc = new \DOMDocument('1.0', "UTF-8");
        $this->xmlDoc->formatOutput = TRUE;
        $this->xmlDoc->preserveWhiteSpace = FALSE;

		libxml_use_internal_errors(true);
		        
		if(!$this->xmlDoc->loadXML($logicXml)){
			foreach (libxml_get_errors() as $error) {
		        $errorMsg = "";
				switch ($error->level) {
			        case LIBXML_ERR_WARNING:
			            $errorMsg .= "Warning " . $error->code . ": ";
			            break;
			         case LIBXML_ERR_ERROR:
			            $errorMsg .= "Error " . $error->code . ": ";
			            break;
			        case LIBXML_ERR_FATAL:
			            $errorMsg .= "Fatal Error " . $error->code . ": ";
			            break;
			    }

				$errorMsg .= trim($error->message) . "  Line: $error->line" . "  Column: $error->column";

            	$this->errors[] = __METHOD__ . " line: " . __LINE__ . " " . $errorMsg;
			}
		    libxml_clear_errors();
			$this->xmlDoc = NULL;
			$this->xpath = NULL;
            return FALSE;
		}
		
        $this->xpath = new \DOMXPath($this->xmlDoc);
    }

    public function getDeviceStateByAddr($addr, $sendRequest = TRUE){
			//$this->debug(__METHOD__);

			$listenEventsDelay = $this->listenEventsDelay;
			$this->listenEventsDelay = 0;

			if(!$this->retranslateUdpSent){
				$methodName = "stopListenEvents";
				$callback = array($this, $methodName);
	
	        	$this->sendCommandToSH('retranslate-udp', $callback);
				$this->listenEventsOnMsg();
			}
			//$this->debug(__METHOD__ . " line: " . __LINE__);
			
			$methodName = "onGetDeviceEvent";
			$callback = array($this, $methodName);
			$argv = array("addr"=>$addr);
			$this->addEventOnMsgCallback("dev-event", $callback, $argv);

			//send request on get device state
			list($id, $subid) = explode(":", $addr);
            $data = $this->packData($id, 0, 14, 0, array(0,0,0,0,0,0));
            $this->sendToServer($data);

			//read device state
			$this->listenEventsOnMsg();
			$this->listenEventsDelay = $listenEventsDelay;
			$this->removeEventOnMsgCallback("dev-event");
			
			if(array_key_exists($addr, $this->devicesStore)) return $this->devicesStore[$addr];
			
			return NULL;
    }
	
	public function onGetDeviceEvent($data, $argv){
		//$this->debug(__METHOD__);
		foreach ($data as $value) {
			if($value["addr"] == $argv["addr"]){
				$this->stopListenEvents();
				//$this->debug($value);
				$this->devicesStore[$value["addr"]] = $value;
				break;
			}
		}
	}

//##########################################################################################################################
	
//get single device state
    private function readDeviceState($id, $subid){
        $resultData = array();
        $foundItem = FALSE;
        $j = 0;
        while(!$foundItem && $j < 300){
            //print $id.":".$subid . " - " . $j . "\n";
            $data = $this->fread(10);
            if(!$data["success"]) return $resultData;
            $unpackData = unpack("Llength/C6c", $data["data"]);
            //print_r($unpackData);
            $shHead = "";
            for($i=1;$i<=6;$i++) $shHead .= chr($unpackData["c".$i]);

            //print $shHead . "\n";

            if($shHead != "" && $unpackData["length"] == 6) continue;
            
            if($shHead == "shcxml"){
                $line = $this->fread(4);
                if(!$line["success"]) return $resultData;
                $crc = unpack("L*f",$line["data"]);
    
                $line = $this->fread(1);
                if(!$line["success"]) return $resultData;
                $addata = unpack("C*d",$line["data"]);
                $line = $this->fread($unpackData["length"]-5);
                if(!$line["success"]) return $resultData;
            }elseif($shHead == "messag"){
                $message = $this->fread($unpackData["length"]-6);
                if(!$message["success"]) return $resultData;
                //print "head: " . $shHead . "message: " . $message . "\n";
            }else {
                $unpackData = unpack("S2s/C4c/Slength", $data["data"]);

                if($unpackData["c1"] == 15){
                    $dataLength = $unpackData["length"];
                    while($dataLength > 0){
                        $line = $this->fread(2);
                        if(!$line["success"]) return $resultData;
                        $dataLength -= 2;
                        $ucanData = unpack("Cucanid/Clength",$line["data"]);
                        $tmpdata = $this->fread($ucanData["length"]);
                        if(!$tmpdata["success"]) return $resultData;
                        $line = $tmpdata["data"];
                        $dataLength -= $ucanData["length"];
                        $values = array();
                        $index = $unpackData["s1"] . ":" . $ucanData["ucanid"];
                        
                        $itemType = $this->getItemType((int)$unpackData["s1"], (int)$ucanData["ucanid"]);
                        
                        if($ucanData["length"] == 1){
                            $addata = unpack("C*value",$line);
                            $values[] = $addata["value1"];
                        }elseif($ucanData["length"] == 2 && $itemType != "dimer-lamp" && strpos($itemType, "sensor") === FALSE){
                            $addata = unpack("C*value",$line);
                            $values[] = $addata["value1"];
                        }elseif($ucanData["length"] == 2 && $itemType == "dimer-lamp"){
                            $addata = unpack("C*value",$line);
                            foreach($addata as $v) $values[] = $v;
                            if(array_key_exists(1, $values)) {
                                if($this->bcmathExist) $values[1] = round(bcdiv($values[1], 2.5));
                                else $values[1] = round($values[1]/2.5);
                            }
                        }elseif($ucanData["length"] == 2){
                            $addata = unpack("S*value",$line);
    
                            if($this->bcmathExist){
                                if($addata["value1"] > 32768) $value = bcdiv(bcsub(65536, $addata["value1"]), -256, 2);
                                else $value = bcdiv($addata["value1"], 256, 2);
                            }else {
                                if($addata["value1"] > 32768) $value = round((double)((65536-$addata["value1"])/-256), 2);
                                else $value = round((double)($addata["value1"]/256), 2);
                            }
                            $values[] = $value;
                        }elseif($ucanData["length"] > 2){
                            $addata = unpack("C*value",$line);
                            foreach($addata as $v) $values[] = $v;
                        }

                        if((int)$id == (int)$unpackData["s1"] && (int)$subid == (int)$ucanData["ucanid"] && count($values)){
                            $foundItem = TRUE;
                            //$resultData = array("id"=>(int)$unpackData["s1"],"subid"=>(int)$ucanData["ucanid"],"data"=>$values);
                            $resultData = $values;
                            $this->devicesStatesStore[$index] = $values;
                            //print "status\n";
                            //print_r($resultData);
                        }
                        //usleep(1000);
                    }
                }else {
                    $ad = $this->fread($unpackData["length"]);
                    if(!$ad["success"]) return $resultData;
                }
            }
            //usleep(100000);
            $j++;
        }
        return $resultData;
    }

    private function getDisplayedDevices(){
        if($this->runSuccess) {
                
            $query = '//area[not(@permissions)]/item[@type!="rtsp" and @type!="remote-control" and @type!="multi-room" and @type!="virtual"]';
            if($this->devicesQuery != "") $query = $this->devicesQuery;
            $entries = $this->xpath->query($query);
    
            if(is_object($entries) && $entries->length > 0){
                foreach ($entries as $entry) {
                    $entryAttributes = array();
                    foreach ($entry->attributes as $attr) $entryAttributes[$attr->nodeName] = $attr->nodeValue;
                    $id = $subid = 0;
                    if(array_key_exists("id", $entryAttributes)) $id = $entryAttributes["id"];
                    if(array_key_exists("sub-id", $entryAttributes)) $subid = $entryAttributes["sub-id"];
                    if(array_key_exists("addr", $entryAttributes)) list($id, $subid) = explode(":", $entryAttributes["addr"]);
                    if($id > 0 && $subid > 0) {
                        $index = $id . ":" . $subid;
                        $this->displayedDevices[$index] = array("id"=>$id, "subid"=>$subid);
                    }
                }
            }
            
        }
    }

    private function readXmlLogic(){
        $xml = "";
        $xml .= '<?xml version="1.0" encoding="UTF-8"?>' . "\n" . '<smart-house-commands>' . "\n";
        if($this->allowRetraslateUDP) $xml .= "<get-shc retranslate-udp=\"yes\" />\n";
        else $xml .= "<get-shc />\n";
        $xml .= "</smart-house-commands>\n";
        //print $xml . "\n";
        $xmlsize = strlen($xml);
        $data = pack("L",$xmlsize) . $xml;

        $this->sendToServer($data);

        if($this->connected()){
            $j = 0;
            $logicXml = "";
            
            while($logicXml == "" && $j < 3){
                $data = $this->fread(10);
                if(!$data["success"]) return;
                $unpackData = unpack("Llength/C6c", $data["data"]);
                $shHead = "";
                for($i=1;$i<=6;$i++) $shHead .= chr($unpackData["c".$i]);
        
                if($shHead == "shcxml"){
                    $length = $unpackData["length"];
                    $line = $this->fread(4);
                    if(!$line["success"]) return;
                    $crc = unpack("L*f",$line["data"]);
                    //print "crc: " . print_r($crc,1) . "\n";
        
                    $line = $this->fread(1);
                    if(!$line["success"]) return;
                    $addata = unpack("C*d",$line["data"]);
                    //print_r($addata);
                    $this->initClientID = $this->initClientDefValue - $addata["d1"];
        
                    $receivedFileSize = $length-11;
                    $tmpdata = $this->fread($receivedFileSize);
                    if(!$tmpdata["success"]) return;
                    $logicXml = $tmpdata["data"];
                    $this->logicXml = $tmpdata["data"];
                    //print $this->logicXml . "\n";

                    $this->logicXml = str_replace("&amp;","#amp;",$this->logicXml);
                    $this->logicXml = str_replace("&","&amp;",$this->logicXml);
                    $this->logicXml = str_replace("#amp;","&amp;",$this->logicXml);
                                        
                    if($this->xmlFile != "" && $this->saveXmlLogic && (!file_exists($this->xmlFile) || (file_exists($this->xmlFile) && filesize($this->xmlFile)!=$receivedFileSize))){
                        if($fp = fopen($this->xmlFile,"w")){
                            fwrite($fp,$this->logicXml);
                            fclose($fp);
                        }
                        chmod($this->xmlFile, 0666);
                    }
                }elseif($shHead == "messag"){
                    $message = $this->fread($unpackData["length"]-6);
                    if(!$message["success"]) return;
                }else {
                    $tmpdata = $this->fread($unpackData["length"]-6);
                    if(!$tmpdata["success"]) return;
                }
                $j++;
                usleep(100000);
            }
        }
    }

    private function logger($log_str){
        if($this->logFile != "" && ($fp = @fopen($this->logFile,"a"))){
            $error = @date("r") . " " . $log_str . "\n";
            @fwrite($fp,$error);
            @fclose($fp);
        }
    }

    private function packData($id, $subid, $pd, $length, $value = array(0, 0, 0, 0, 0, 0)){
        $s = pack("S2C4S", $this->initClientID, $id, $pd, 0, 0, $subid, $length);
        if($length > 0) for($i=0;$i < $length;$i++) $s .= pack("C",$value[$i]);
        return $s;
    }

    private function connectToServer(){
    	$this->debug(__METHOD__ . " line:" . __LINE__);
        if (!($this->connectionResource = @fsockopen($this->host, $this->port, $errno, $errstr, $this->connectionTimeOut))) {
            $result = $errno . " " . $errstr;
            $this->logger($result);
            $this->connectionResource = NULL;
            $msg = __METHOD__ . " line: " . __LINE__ . " No connection to shs server " . $this->host . ":" . $this->port;
            $this->errors[] = $msg;
			$this->debug($msg);
            //throw new Exception ($msg);
        }
		$this->retranslateUdpSent = FALSE;
    }

    private function sendToServer($data){
        if($this->connected()){
            try {
                if(!fwrite($this->connectionResource, $data)){
                    $this->disconnect();
                    $this->logger("Couldn't write to socket data: " . $data);
                    $msg = __METHOD__ . " line: " . __LINE__ . " Couldn't write to socket data";
                    $this->errors[] = $msg;
					$this->debug($msg);
                    //throw new Exception ($msg);
                }
            } catch(Exception $e){
                $this->disconnect();
                $this->logger("Exception appeared. Couldn't write to socket next data: " . $data);
                $msg = __METHOD__ . " line: " . __LINE__ . " " . "Exception appeared. Couldn't write to socket data. " . $e->getMessage();
                $this->errors[] = $msg;
				$this->debug($msg);
                //throw new Exception ($msg);
            }
        }
    }

    private function authorization(){
        if($this->connected()){
            $data = $this->fread(16);
            if($data["success"]){
    
                $key = $this->aes->makeKey($this->aeskey);
                $encrypted = $this->aes->blockEncrypt($data["data"], $key);
                fwrite($this->connectionResource, $encrypted);
            }else {
                $error = __METHOD__ . " line: " . __LINE__ . " " . "could not read data for authorization";
                $this->errors[] = $error;
                $this->logger($error);
                $this->disconnect();
            }
        }
    }

    private function fread($size){
        $success = TRUE;
        $res = "";
		if($this->readFromBlockedSocket) {
	        while(($size - strlen($res)) > 0 && (!feof($this->connectionResource))){
	            $res .= fread($this->connectionResource, $size-strlen($res));
	        }
		}else {
	        stream_set_blocking($this->connectionResource, 0);//set socket to nonblock status
	        $info = stream_get_meta_data($this->connectionResource);
	        //set_time_limit(20);
	        while(($size - strlen($res)) > 0 && (!$info['timed_out']) && (!feof($this->connectionResource))){
	            $res .= fread($this->connectionResource, $size-strlen($res));
	            $info = stream_get_meta_data($this->connectionResource);
	        }
	        //set_time_limit(30);
	        if($info['timed_out'] || feof($this->connectionResource)) {
	            $success = FALSE;
	            //throw new Exception ("Read from socket timed out");
	        }
	        if(($size != strlen($res))) {
	            $success = FALSE;
	            //throw new Exception ("Couldn't read required number of bytes from socket");
	        }
			stream_set_blocking($this->connectionResource, 1);//set socket to block status
		}
        
        return array("success"=>$success,"data"=>$res);
    }

    private function readBlockedSocket($size){
    	//$this->debug(__METHOD__ . " size:" . $size);
    	if($size > 300000) return "";
        $res = "";
        while(($size - strlen($res)) > 0 && (!feof($this->connectionResource))){
            $res .= fread($this->connectionResource, $size-strlen($res));
        }
        return $res;
    }

	private function debug($msg = ""){
		if(is_array($msg)) $msg = print_r($msg, 1);
		elseif(!is_string($msg)) $msg = var_export($msg, TRUE);
		if($this->debug) print date("Y-m-d H:i:s") . "\t" . $msg . "\n";
	}


    private function connected() {
        if(!is_null($this->connectionResource) && !empty($this->connectionResource)) {
            $sock_status = stream_get_meta_data($this->connectionResource);
            if($sock_status["eof"]) {
                // the socket is valid but we are not connected anymore
                fclose($this->connectionResource);
                $this->connectionResource = NULL;
				$msg = __METHOD__ . " line: " . __LINE__ . " " . "Connection closed by server. EOF caught while checking if connected.";
				//$this->debug($msg);
				//$this->debug($sock_status);
                $this->errors[] = $msg;

                //throw new Exception ($error);

                //$this->logger($error);
                return FALSE;
            }
            return TRUE; // everything looks good
        }
        return FALSE;
    }
    
}

?>