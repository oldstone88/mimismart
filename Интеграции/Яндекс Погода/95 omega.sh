#!/usr/bin/php-cgi
<?php
header("Access-Control-Allow-Origin: *");
setlocale(LC_ALL, "ru_RU");
date_default_timezone_set("Europe/Moscow");

define("BASE_DIR", "/mimismart/exe/");
define("LOG_FILE", BASE_DIR . "logs/logs.txt");
//begin smart house server settings ##################################
define("HOST", "127.0.0.1");
define("PORT", 55555);
define("SECRET_KEY","");
define("KEYS_FILE","/mimismart/keys.txt");

require_once '/home/api/AES128.php';
require_once '/home/api/SHClient.php';

$debug = FALSE;

//begin code#################################################################################
$shClient = new SHClient(HOST, PORT, SECRET_KEY, LOG_FILE);
if($shClient->run()){
    $consoleParams = $shClient->getDataFromConsole();
    $pDev1 = trim($consoleParams["params"]["dev1"]);
    $pDev2 = trim($consoleParams["params"]["dev2"]);
    $pLat = trim($consoleParams["params"]["lat"]);
	$pLon = trim($consoleParams["params"]["lon"]);
    $pKey = trim($consoleParams["params"]["key"]);
    if($debug) echo "In params: \n", $pDev1,"\n", $pDev2,"\n", $pLat,"\n", $pLon,"\n", $pKey,"\n";
	$dstId1 = null;
    $dstSubId1 = null;
    $dstId2 = null;
    $dstSubId2 = null;
    if(strpos($pDev1, ":") !== FALSE) list($dstId1, $dstSubId1) = explode(":", $pDev1);
    if(strpos($pDev2, ":") !== FALSE) list($dstId2, $dstSubId2) = explode(":", $pDev2);
    if(is_null($dstId2) || is_null($dstSubId2) 
	|| is_null($dstId1) || is_null($dstSubId1)){
        echo "one of the destination address not found\n";
        exit;
   }

$opts = array(
  'http' => array(
    'method' => "GET",
    'header' => "X-Yandex-API-Key: $pKey"
  )
);

$url = "https://api.weather.yandex.ru/v2/informers?lat=".$pLat."&lon=".$pLon."&limit=1&hours=false&extra=false";
$context = stream_context_create($opts);
$contents = file_get_contents($url, false, $context);
$clima = json_decode($contents);

$temp = $clima->fact->temp;
$humidity = $clima->fact->humidity;

if(isset($dstId1) and isset($dstSubId1)){
		$device=array();
		$device['id']=(int)$dstId1;
		$device['sub-id']=(int)$dstSubId1;
		$device['length']=2;
		$device['state']=array(0,(int)$humidity);
		$shClient->changeAnyDeviceState($device);
	}

if(isset($dstId2) and isset($dstSubId2)){
		$device=array();
		$device['id']=(int)$dstId2;
		$device['sub-id']=(int)$dstSubId2;
		$device['length']=2;
		$device['state']=array(0,(int)$temp);
		$shClient->changeAnyDeviceState($device);
	}

	
    if($debug) echo "finished\n";
}else {
    print implode("\n", $shClient->errors) . "\n";
}

?>
