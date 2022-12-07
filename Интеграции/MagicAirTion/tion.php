<?php

$curl = curl_init();
date_default_timezone_set('Europe/Moscow');
curl_setopt_array($curl, array(
  CURLOPT_URL => "https://api2.magicair.tion.ru/location",
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => "",
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 30,
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => "GET",
  CURLOPT_HTTPHEADER => array(
    "authorization: Bearer da0f8b854b9849239c68f480d00d8a6abe0a840ea944401b8e88a7d22012e875",
    "cache-control: no-cache"
  ),
));

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);

if ($err) {
  echo "cURL Error #:" . $err;
} else {
  $data = json_decode($response, true)[0]['zones'][1]['sensors_average'][0]['data'];
  //var_dump($data);
  echo date("Y-m-d H:i:s")."\nCO2: ".$data['co2'].", temperature: ".$data['temperature'].", humidity: ".$data['humidity']."\n\n";
}
?>