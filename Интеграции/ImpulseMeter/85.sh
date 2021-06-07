#!/usr/bin/php5-zts
<?php
	$IdLongText = 512;
	$SidLongText = 150;
	$IP_gateway = "192.168.1.135";
	$AddedValue = 0.1;
	$filename = "/home/sh2/exe/meter.txt";

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
	function WriteNewValue($NewValue){
		global $filename;
		$fp = fopen($filename, "w");
		fwrite($fp, strval($NewValue));
		fclose($fp);
	}
	function SendDataToLongText($IdLongText, $SidLongText, $data){
		global $IP_gateway;
		$socket = fsockopen("udp://".$IP_gateway, 55555, $errno, $errstr);
		$buffer = pack("SSCCCCS", 1, $IdLongText, 5, 244, 67, $SidLongText,strlen($data)); 
		$buffer .= $data;
		fwrite($socket, $buffer);
		fclose($socket);

	}
	if(strncmp(hex2bin($argv[3]),"add", 3) == 0){

		$CurrentValue = ReadCurrentValue();
		WriteNewValue($CurrentValue+$AddedValue);
		SendDataToLongText($IdLongText, $SidLongText, " Показания счетчика: ".strval($CurrentValue+$AddedValue));
	}
?>