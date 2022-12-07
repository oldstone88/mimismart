#!/usr/bin/php-cgi 
<?php
header("Access-Control-Allow-Origin: *");
setlocale(LC_ALL, "ru_RU");
date_default_timezone_set("Europe/Moscow");

define("BASE_DIR", "/mimismart/");
define("LOG_FILE", "/home/sh2/logs/log.txt");
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
    $pDev = trim($consoleParams["params"]["dev"]);
    $pDev2 = trim($consoleParams["params"]["dev2"]);
    $pDev3 = trim($consoleParams["params"]["dev3"]);
    $pDev4 = trim($consoleParams["params"]["dev4"]);
    $pDev5 = trim($consoleParams["params"]["dev5"]);
    $pIP = trim($consoleParams["params"]["ip"]);
    $pLat = trim($consoleParams["params"]["lat"]);
	$pLon = trim($consoleParams["params"]["lon"]);
    $pKey = trim($consoleParams["params"]["key"]);
    if($debug) echo "In params: \n", $pDev,"\n", $pDev2,"\n", $pDev3,"\n", $pDev4,"\n", $pDev5,"\n", $pLat,"\n", $pLon,"\n", $pKey,"\n", $pIP,"\n";
	$dstId = null;
    $dstSubId = null;
    $dstId2 = null;
    $dstSubId2 = null;
    $dstId3 = null;
    $dstSubId3 = null;
    $dstId4 = null;
    $dstSubId4 = null;
    $dstId5 = null;
    $dstSubId5 = null;
    if(strpos($pDev, ":") !== FALSE) list($dstId, $dstSubId) = explode(":", $pDev);
    if(strpos($pDev2, ":") !== FALSE) list($dstId2, $dstSubId2) = explode(":", $pDev2);
    if(strpos($pDev3, ":") !== FALSE) list($dstId3, $dstSubId3) = explode(":", $pDev3);
    if(strpos($pDev4, ":") !== FALSE) list($dstId4, $dstSubId4) = explode(":", $pDev4);
    if(strpos($pDev5, ":") !== FALSE) list($dstId5, $dstSubId5) = explode(":", $pDev5);
    if(is_null($dstId) || is_null($dstSubId) || is_null($dstId2) || is_null($dstSubId2) 
	|| is_null($dstId3) || is_null($dstSubId3) || is_null($dstId4) || is_null($dstSubId4)
    || is_null($dstId5) || is_null($dstSubId5)){
//        echo "one of the destination address not found\n";
//        exit;
  }

$apiUrl = "https://api.openweathermap.org/data/2.5/weather?lat=".$pLat."&lon=".$pLon."&appid=".$pKey."&lang=en&units=metric";

$crequest = curl_init();


curl_setopt($crequest, CURLOPT_HEADER, 0);
curl_setopt($crequest, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($crequest, CURLOPT_URL, $apiUrl);
curl_setopt($crequest, CURLOPT_FOLLOWLOCATION, 1);
curl_setopt($crequest, CURLOPT_VERBOSE, 0);
curl_setopt($crequest, CURLOPT_SSL_VERIFYPEER, false);
$response = curl_exec($crequest);

curl_close($crequest);
$data = json_decode($response, true);

//$currentTime = time();

$city = $data['name'];
$temp = $data['main']['temp'];
$temp_like = $data['main']['feels_like'];
$humidity = $data['main']['humidity'];
$speed = $data['wind']['speed'];
$pressure = $data['main']['pressure'];

//$today = date("j.m.Y, H:i");

//    $data="Date: " . $today . ".\n";
    $data.="City: " . $city . "\n";
    $data.="Pressure: " . $pressure . " hPa \n";

$shClient->sendMessage2($data, (int)$dstId, (int)$dstSubId);

if(isset($dstId2) and isset($dstSubId2)){
    $IdSensor = $dstId2;
    $SidSensor = $dstSubId2;
    $socket = fsockopen("udp://$pIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $IdSensor, 5, 244, 67, $SidSensor, 2,126,$speed); //126, data - 126 - дробная часть, data-целая
    fwrite($socket, $buffer);
    fclose($socket);
	}

if(isset($dstId3) and isset($dstSubId3)){
	$IdSensor = $dstId3;
    $SidSensor = $dstSubId3;
    $socket = fsockopen("udp://$pIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $IdSensor, 5, 244, 67, $SidSensor, 2,126,$humidity); //126, data - 126 - дробная часть, data-целая
    fwrite($socket, $buffer);
    fclose($socket);
	}

if(isset($dstId4) and isset($dstSubId4)){
	$IdSensor = $dstId4;
    $SidSensor = $dstSubId4;
    $socket = fsockopen("udp://$pIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $IdSensor, 5, 244, 67, $SidSensor, 2,126,$temp_like); //126, data - 126 - дробная часть, data-целая
    fwrite($socket, $buffer);
    fclose($socket);
	}

if(isset($dstId5) and isset($dstSubId5)){
	$IdSensor = $dstId5;
    $SidSensor = $dstSubId5;
    $socket = fsockopen("udp://$pIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $IdSensor, 5, 244, 67, $SidSensor, 2,126,$temp); //126, data - 126 - дробная часть, data-целая
    fwrite($socket, $buffer);
    fclose($socket);
	}

	
    if($debug) echo "finished\n";
}else {
    print implode("\n", $shClient->errors) . "\n";
}

?>
