#!/usr/bin/php
<?php

//Парсинг
    function parser($text){
        $text = str_replace('|', '&', $text);
        parse_str($text, $string);
        return $string;
    }


    // Получение строки и ее парсинг из MimiSmart в нужный вид
    $consoleParam = hex2bin($argv[3]);
    $consoleParam = parser($consoleParam);
    
    // Начало частной части
    // Получение и преобразование данных
    $apiUrl = 'https://api.openweathermap.org/data/2.5/weather?lat='.$consoleParam['lat'].'&lon='.$consoleParam['lon'].'&appid='.$consoleParam['apiKey'].'&lang=en&units=metric';
    $answer = file_get_contents($apiUrl);
    $answer = json_decode($answer);

    $gwxIP = $consoleParam['gwxIP'];
    
    //Температурв
    $tempSensor = explode(':', $consoleParam['tempSensor']);
    $tempId = $tempSensor[0];
    $tempSId = $tempSensor[1];

    $tempInt = $answer->main->temp;
    $tempFrations = substr($tempInt, strpos($tempInt,'.')+1);

    $socket = fsockopen("udp://$gwxIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $tempId, 5, 244, 67, $tempSId, 2, $tempFrations, $tempInt);
    fwrite($socket, $buffer);
    fclose($socket);

    // Влажность
    $humSensor = explode(':', $consoleParam['humSensor']);
    $humId = $humSensor[0];
    $humSId = $humSensor[1];

    $humInt = $answer->main->humidity;
    $humFrations = substr($humInt, strpos($humInt,'.')+1);

    $socket = fsockopen("udp://$gwxIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $humId, 5, 244, 67, $humSId, 2, $humFrations, $humInt);
    fwrite($socket, $buffer);
    fclose($socket);

?>
