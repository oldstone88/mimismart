#!/usr/bin/php
<?php
	$host1 ="192.168.1.134"; // Адрес шлюза
	$filename = "/home/sh2/exe/relay/errorMeter.txt"; // Файл счетчика ошибок
	$chatID = "-1002236755959"; // ID чата в TG
	$objectName = "ZapadniiPort492"; // Имя объекта

//Читаем число ошибок
	function ReadCurrentValue(){
		global $filename;
		if(file_exists($filename)){
			$CurrentValue = file_get_contents($filename);
			return $CurrentValue;
		}
		else{
			$fp = fopen($filename, "w");
			fwrite($fp, "0");
			fclose($fp);
			return 0;
		}
	}
//Запись значения
	function WriteNewValue($NewValue){
		global $filename;
		$fp = fopen($filename, "w");
		fwrite($fp, strval($NewValue));
		fclose($fp);
	}
//Отправка сообщения
	function sendMessage($hostNumber, $objectName, $chatID){
		$curl = curl_init();

		curl_setopt_array($curl, array(
		  CURLOPT_URL => "https://ms-studio.tk/bot_NotificationsMimiSmart/sendMessage.php?id_chat=".$chatID."&text=GW3%20".$hostNumber."%20on%20object%20".$objectName."%20do%20not%20response",
		  CURLOPT_RETURNTRANSFER => true,
		  CURLOPT_ENCODING => "",
		  CURLOPT_MAXREDIRS => 10,
		  CURLOPT_TIMEOUT => 30,
		  CURLOPT_SSL_VERIFYHOST => 0,
		  CURLOPT_SSL_VERIFYPEER => 0,
		  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
		  CURLOPT_CUSTOMREQUEST => "GET",));

		$response = curl_exec($curl);
		$err = curl_error($curl);

		curl_close($curl);

		if ($err) {
		  echo "cURL Error #:" . $err;
		} else {
		  echo $response;
		}
	}
// Перезагрузка
	function rebootRelay(){
		$url = 'http://192.168.1.100/relay_cgi.cgi?type=1&relay=0&on=1&time=10&pwd=7777&';
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

//Основной скрипт
	//Шлюз №1
	exec("ping -c 1 -W 2 " . $host1, $output, $result);
	if ($result == 0){
		echo "ping success";
	}
	else {
		sendMessage($host1, $objectName, $chatID);
		//Секция перезагрузки
		$countError = ReadCurrentValue();
		if($countError>1){
			//Отправка сообщения
			sendMessage("Rebooted", $objectName, $chatID);
			//Обнуление счетчика
			$countError=0;
			WriteNewValue($countError);
			rebootRelay();
		} else {
			$countError=$countError+1;
			WriteNewValue($countError);
		}
	}
?>
