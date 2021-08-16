#!/usr/bin/php
<?php
header("Access-Control-Allow-Origin: *");
setlocale(LC_ALL, "ru_RU");
date_default_timezone_set("Asia/Ashgabat");

define("BASE_DIR", "/home/sh2/exe/");
define("LOG_FILE", BASE_DIR . "logs/logs.txt");
//begin smart house server settings ##################################
define("HOST", "127.0.0.1");
define("PORT", 55555);
define("SECRET_KEY","");
define("KEYS_FILE","/home/sh2/keys.txt");

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
    $pLat = trim($consoleParams["params"]["lat"]);
	$pLon = trim($consoleParams["params"]["lon"]);
    $pKey = trim($consoleParams["params"]["key"]);
    if($debug) echo "In params: \n", $pDev,"\n", $pDev2,"\n", $pDev3,"\n", $pDev4,"\n", $pLat,"\n", $pLon,"\n", $pKey,"\n";
	$dstId = null;
    $dstSubId = null;
    $dstId2 = null;
    $dstSubId2 = null;
    $dstId3 = null;
    $dstSubId3 = null;
    $dstId4 = null;
    $dstSubId4 = null;
    if(strpos($pDev, ":") !== FALSE) list($dstId, $dstSubId) = explode(":", $pDev);
    if(strpos($pDev2, ":") !== FALSE) list($dstId2, $dstSubId2) = explode(":", $pDev2);
    if(strpos($pDev3, ":") !== FALSE) list($dstId3, $dstSubId3) = explode(":", $pDev3);
    if(strpos($pDev4, ":") !== FALSE) list($dstId4, $dstSubId4) = explode(":", $pDev4);
    if(is_null($dstId) || is_null($dstSubId) || is_null($dstId2) || is_null($dstSubId2) 
	|| is_null($dstId3) || is_null($dstSubId3) || is_null($dstId4) || is_null($dstSubId4)){
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

$time_unix = $clima->fact->obs_time;
$temp = $clima->fact->temp;
$temp_like = $clima->fact->feels_like;
$humidity = $clima->fact->humidity;
$speed = $clima->fact->wind_speed;
$speeddot = str_replace(',','.',$speed);
$pressure = $clima->fact->pressure_mm;
$condition = $clima->fact->condition;

$today = date("j.m.Y, H:i");
$time = date("j.m.Y, H:i", $time_unix);

$pcondition = array("Yasno", "Malooblachno", "Oblachno s proyasneniyami", "Pasmurno", "Moros", "Ne bolshoy dozhd", "Dozhd",
                    "Umerenno silnyy dozhd", "Silnyy dozhd", "Dlitelno silnyy dozhd", "Liven", "Dozhd so snegom", "Nebolshoy sneg",
                    "Sneg", "Snegopad", "Grad", "Groza", "Dozhd s grazoy", "Groza s gradom");

//Oblachnost i Osadki
if(isset($condition)){
		if ($condition="clear" ) $condition2 = $pcondition[0];
		else if ($condition="partly-cloudy" ) $condition2 = $pcondition[1];
		else if ($condition="cloudy" ) $condition2 = $pcondition[2];
		else if ($condition="overcast" ) $condition2 = $pcondition[3];
		else if ($condition="drizzle" ) $condition2 = $pcondition[4];
		else if ($condition="light-rain" ) $condition2 = $pcondition[5];
		else if ($condition="rain" ) $condition2 = $pcondition[6];
		else if ($condition="moderate-rain" ) $condition2 = $pcondition[7];
		else if ($condition="heavy-rain" ) $condition2 = $pcondition[8];
		else if ($condition="continuous-heavy-rain" ) $condition2 = $pcondition[9];
		else if ($condition="showers" ) $condition2 = $pcondition[10];
		else if ($condition="wet-snow" ) $condition2 = $pcondition[11];
		else if ($condition="light-snow" ) $condition2 = $pcondition[12];
		else if ($condition="snow" ) $condition2 = $pcondition[13];
		else if ($condition="snow-showers" ) $condition2 = $pcondition[14];
		else if ($condition="hail" ) $condition2 = $pcondition[15];
		else if ($condition="thunderstorm" ) $condition2 = $pcondition[16];
		else if ($condition="thunderstorm-with-rain" ) $condition2 = $pcondition[17];
		else if ($condition="thunderstorm-with-hail" ) $condition2 = $pcondition[18];
	}

$data="Data: " . $today . ".\n";
    $data.="Temperatura: " . $temp . " grad.\n";
	//$data.="Vlaznost: " . $humidity . "%.\n";
    $data.="Davleniye: " . $pressure . " mm.\n";
    $data.="Oblachnost: " . $condition2 . ".\n";

$shClient->sendMessage2($data, (int)$dstId, (int)$dstSubId);

if(isset($dstId2) and isset($dstSubId2)){
		$device=array();
		$device['id']=(int)$dstId2;
		$device['sub-id']=(int)$dstSubId2;
		$device['length']=2;
		$device['state']=array(0,(int)$speed);
		$shClient->changeAnyDeviceState($device);
	}

if(isset($dstId3) and isset($dstSubId3)){
		$device=array();
		$device['id']=(int)$dstId3;
		$device['sub-id']=(int)$dstSubId3;
		$device['length']=2;
		$device['state']=array(0,(int)$humidity);
		$shClient->changeAnyDeviceState($device);
	}

if(isset($dstId4) and isset($dstSubId4)){
		$device=array();
		$device['id']=(int)$dstId4;
		$device['sub-id']=(int)$dstSubId4;
		$device['length']=2;
		$device['state']=array(0,(int)$temp_like);
		$shClient->changeAnyDeviceState($device);
	}

	
    if($debug) echo "finished\n";
}else {
    print implode("\n", $shClient->errors) . "\n";
}

?>
