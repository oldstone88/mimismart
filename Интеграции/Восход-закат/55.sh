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
    $apiUrl = 'https://api.sunrise-sunset.org/json?lat=' . $consoleParam['lat'] . '&lng=' . $consoleParam['lng'] . '&formatted=0&tzid=Europe/Moscow';
    $answer = file_get_contents($apiUrl);
    $answer = json_decode($answer);

    $gwxIP = $consoleParam['gwxIP'];
    $firstSensor = explode(':', $consoleParam['sunrise']);
    $sunriseId = $firstSensor[0];
    $sunriseSId = $firstSensor[1];
    $secondSensor = explode(':', $consoleParam['sunset']);
    $sunsetId = $secondSensor[0];
    $sunsetSId = $secondSensor[1];

    $sunrise = $answer->results->sunrise;
    $sunriseHour = date('H', strtotime($sunrise));
    $sunriseMinute = date('i', strtotime($sunrise));
    $sunset = $answer->results->sunset;
    $sunsetHour = date('H', strtotime($sunset));
    $sunsetMinute = date('i', strtotime($sunset));

    $socket = fsockopen("udp://$gwxIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $sunriseId, 5, 244, 67, $sunriseSId, 2, $sunriseMinute, $sunriseHour);
    fwrite($socket, $buffer);
    fclose($socket);

    $socket = fsockopen("udp://$gwxIP", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $sunsetId, 5, 244, 67, $sunsetSId, 2, $sunsetMinute, $sunsetHour);
    fwrite($socket, $buffer);
    fclose($socket);

?>