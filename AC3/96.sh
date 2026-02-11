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
    $string["addr"] = $helper[0];
    $string["command"] = $helper[1];
    $string["fake"] = $helper[2];
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
