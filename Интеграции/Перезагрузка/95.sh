#!/usr/bin/php
<?php
	// Перезагрузка
	function rebootRelay($IP, $RELAY){
		$url = 'http://' . $IP. '/relay_cgi.cgi?type=1&relay='. $RELAY . '&on=1&time=100&pwd=7777&';
		$curl = curl_init();

		curl_setopt($curl, CURLOPT_URL, $url);
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
		curl_setopt($curl, CURLOPT_HTTPHEADER, array(
        'Content-Type: application/x-www-form-urlencoded',
        'Accept: */*',
        'X-Session-ID: 12345678',
        'Cookie: session=12345678' // Добавление заголовка с сессионным ID
    ));
		$response = curl_exec($curl);
		echo $response;
		curl_close($curl);
	}
	
	// Парсинг параметров
	function parser($text){
        $text = str_replace('|', '&', $text);
        parse_str($text, $string);
        return $string;
    }
// Основной скрипт
    // Получение строки и ее парсинг из MimiSmart в нужный вид
    $consoleParam = hex2bin($argv[3]);
    $consoleParam = parser($consoleParam);
    // Подача команды
    rebootRelay($consoleParam['IP'], $consoleParam['RELAY']);
?>
