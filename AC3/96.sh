#!/usr/bin/php
<?php
//Парсинг
function parser($text){
    $string=[
        "addr"=>"",
        "command" => "",
        "fake" => "",
    ];
    $helper = [
        "0" => "",
        "1" => "",
        "2" => "",
    ];
    //echo "String_getted = ". $text."\n";
    $helper = preg_split("/[*|*]/",$text);
    $string["addr"] = substr($helper[0],5);
    $string["command"] = substr($helper[1],8);
    $string["fake"] = substr($helper[2],5);
    //var_dump($string);
    return $string;
}
//Получение параметров
$consoleParam = hex2bin($argv[3]);
$consoleParam = parser($consoleParam);
//Передача запроса
$url = "http://". $consoleParam['addr'] . "/" . $consoleParam['command'];
echo $url; 
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url); 
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
$result=curl_exec($ch);
echo $result; 
curl_close($ch);
?>