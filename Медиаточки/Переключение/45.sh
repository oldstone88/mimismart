#!/usr/bin/php
<?php
setlocale(LC_ALL, "ru_RU");
date_default_timezone_set("Europe/Moscow");

define("BASE_DIR", "/home/sh2/");
define("LOG_FILE", BASE_DIR . "logs/logs.txt");
//begin smart house server settings ##################################
define("HOST", "127.0.0.1");
define("PORT", 55555);
define("SECRET_KEY","");
define("KEYS_FILE", BASE_DIR . "keys.txt");

require_once '/home/api/AES128.php';
require_once '/home/api/SHClient.php';

$shClient = new SHClient(HOST, PORT, SECRET_KEY, LOG_FILE);

if($shClient->run())
{
    $consoleParams = $shClient->getDataFromConsole();
    $pSignal = $consoleParams["params"]["signal"];
    $pIP = $consoleParams["params"]["address"];
    file_put_contents('/home/sh2/exe/DEBUG.txt', json_encode($consoleParams));
    //Уставка параметров
    $url = 'http://'.$pIP;

    if($pSignal==1)
    {
        $url = $url.'/httpapi.asp?command=setPlayerCmd:switchmode:wifi';
    }
    elseif ($pSignal==2)
    {
        $url = $url.'/httpapi.asp?command=setPlayerCmd:switchmode:bluetooth';
    }
    elseif ($pSignal==3)
    {
        $url = $url.'/httpapi.asp?command=setPlayerCmd:switchmode:optical';
    }

    //Установка параметров curl
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);

    //Отправка значений
    $result = curl_exec($curl);
    echo $result;
    curl_close($curl);
}
?>