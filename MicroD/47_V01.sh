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
define("KEYS_FILE","/mimismart/keys.txt");

require_once '/home/api/AES128.php';
require_once '/home/api/SHClient.php';

$shClient = new SHClient(HOST, PORT, SECRET_KEY, LOG_FILE);

if($shClient->run())
{
    $consoleParams = $shClient->getDataFromConsole();
    //Получаем параметры модуля
    $pIP = $consoleParams["params"]["ipaddr"]; //IP
    $pID = $consoleParams["params"]["cmaddr"]; //ID
    $pSID = $consoleParams["params"]["sidaddr"]; //SID канала
    $pSTATE = $consoleParams["params"]["state"]; //Статус устройства
    //file_put_contents(BASE_DIR . '/exe/DEBUG.txt', json_encode($consoleParams));
    //Уставка параметров
    $url = 'http://' . $pIP . ':55550';

    if($pSID==1)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==2)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==3)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==4)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==5)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==6)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==7)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==9)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==9)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }
    elseif ($pSID==10)
    {
        $post_data['request'] = 'set-state';
        $post_data['addr'] = $pID . ':' . $pSID;
        $post_data['key'] = '1234567890123456';
        $post_data['state'] = intval($pSTATE);
    }

    $post_data = json_encode($post_data);
    $headers = [
        'Content-Type: application/json; charset=UTF-8',
        'Content-Length: ' . strlen($post_data),
        'Host: ' . $pIP
    ];

    //Установка параметров curl
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($curl, CURLOPT_POSTFIELDS, $post_data);
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_POST, true);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);

    //Отправка значений
    $result = curl_exec($curl);
    curl_close($curl);

    echo "post-data:".$post_data."\n";
    echo "result:".$result."\n";
    }
?>