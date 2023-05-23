#!/usr/bin/php
<?php
	$host1="192.168.1.134";
	$countError=0;
	$filename = "/home/sh2/exe/errorMeter.txt";

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
	function sendMessage($hostNumber){
		$curl = curl_init();

		curl_setopt_array($curl, array(
		  CURLOPT_URL => "https://ms-studio.tk/bot_NotificationsMimiSmart/sendMessage.php?id_chat=-699633943&text=GW3%20".$hostNumber."%20do%20not%20response",
		  CURLOPT_RETURNTRANSFER => true,
		  CURLOPT_ENCODING => "",
		  CURLOPT_MAXREDIRS => 10,
		  CURLOPT_TIMEOUT => 30,
		  CURLOPT_SSL_VERIFYHOST => 0,
		  CURLOPT_SSL_VERIFYPEER => 0,
		  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
		  CURLOPT_CUSTOMREQUEST => "GET",
		  CURLOPT_HTTPHEADER => array(
		    "cache-control: no-cache",
		    "postman-token: e7eb9eda-3776-b12c-d9df-e98c374ad9b2"
		  ),
		));

		$response = curl_exec($curl);
		$err = curl_error($curl);

		curl_close($curl);

		if ($err) {
		  echo "cURL Error #:" . $err;
		} else {
		  echo $response;
		}
	}
//Основной скрипт
	exec("ping -c 1 -W 2 " . $host1, $output, $result);
	if ($result == 0){
		echo "ping success";
		//Обнуляем число ошибок
		$countError=0;
		WriteNewValue($countError);
	}
	else {
		sendMessage($host1);
		$countError = ReadCurrentValue();
		if($countError>2){
			//Секция перезагрузки
			exec("/home/sh2/exe/relay.sh 192.168.1.100 off 1");
			sleep(7);
			exec("/home/sh2/exe/relay.sh 192.168.1.100 on 1");
			$curl = curl_init();
//Отправка сообщения
		sendMessage("Rebooted");
		//Обнудение счетчика
		$countError=0;
		WriteNewValue($countError);
		} else {
			$countError=$countError+1;
			WriteNewValue($countError);
		}
	}
?>
