#!/usr/bin/php
<?php

foreach($argv as $cmnd){
    if ($cmnd=='--help'){
        echo "\n\n".'    --help, -h     - Show this message.
        --mode, -m     - Set mode on NEST. (COOL,HEAT,COOLHEAT,OFF)
        --cool-temp    - Set temperature for cool mode on NEST.
        --heat-temp    - Set temperature for heat mode on NEST.
        --set-range    - Set temp. range for heatcool mode on NEST.
        '."\n\n";
        exit(0);
    }
}

function send_off($id, $device_id){
    global $config;
    $curl = curl_init();

    curl_setopt_array($curl, array(
        CURLOPT_URL => 'https://smartdevicemanagement.googleapis.com/v1/enterprises/'.$config['project_id'].'/devices/'.$device_id.':executeCommand',
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_ENCODING => '',
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 0,
        CURLOPT_FOLLOWLOCATION => true,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => 'POST',
        CURLOPT_POSTFIELDS =>'{"command" : "sdm.devices.commands.ThermostatMode.SetMode",
            "params" : {
              "mode" : "OFF"
            }}',
        CURLOPT_HTTPHEADER => array(
        'Authorization: Bearer '.$config['access_token'].' Authorization',
        'Content-Type: application/json'
        ),
    ));

    $response = curl_exec($curl);

    curl_close($curl);
    echo $response;


   $response = json_decode($response,true);
    if(key_exists("error", $response))
        echo "NEST: error on device ", $id, ' ', $response['error']['message'], PHP_EOL;
    else {
        echo 'NEST: set OFF mode to device ',$id,PHP_EOL;
        saveCond($id, 'OFF');
    }
}

function hex2str($hex){
    $string='';
    for ($i=0; $i < strlen($hex)-1; $i+=2)
        $string .= chr(hexdec($hex[$i].$hex[$i+1]));
    return $string;
}

function str2hex($string){
    $binary = "";
    for($i=0;$i<strlen($string);$i++)
        $binary .= pack("A", $string[$i]);
    return bin2hex($binary);
}

function _request($method, $url, $header, $postdata=null){
    $curl = curl_init();
    curl_setopt_array($curl, array(
        CURLOPT_URL => $url,
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_ENCODING => '',
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 0,
        CURLOPT_FOLLOWLOCATION => true,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => $method,
        CURLOPT_POSTFIELDS =>$postdata,
        CURLOPT_HTTPHEADER => $header,
        CURLOPT_SSL_VERIFYHOST => false,
        CURLOPT_SSL_VERIFYPEER=>false,
    ));

    $result = curl_exec($curl);
    curl_close($curl);
    return $result;
}

function refreshToken(){
    global $config;
    $url = 'https://www.googleapis.com/oauth2/v4/token';
    $headers = array('Content-Type: text/plain');
    $postdata = '{
        "client_id": "'.$config['client_id'].'",
        "refresh_token": "'.$config['refresh_token'].'",
        "client_secret": "'.$config['client_secret'].'",
        "grant_type" : "refresh_token"
    }';
    $result = _request('POST',$url,$headers,$postdata);
    $result = json_decode($result,true);    

    $config['access_token'] = $result['access_token'];
    file_put_contents('exe/nest/config.json',json_encode($config,JSON_PRETTY_PRINT));
    // print('new access token:'.PHP_EOL.$config['access_token']);

}

function saveCond($addr, $mode, $temp=0){
    global $config;
    $device_states = array();
    $device_states_length = count($config['devices']);

    //если файл существует, то берем оттуда старые данные
    if(file_exists('exe/nest/device_states.json')){
        $json = file_get_contents('exe/nest/device_states.json');
        $device_states = json_decode($json,true);
    }
    //если не существует, то делаем дефолтный массив с кол-вом по конфигу
    else{
        for($i=0;$i<$device_states_length;$i++){
            array_push($device_states,array('on' => 1,'mode' => 0,'temp' => 0,'t-min' => 16));
        }
    }

    //mode  
    if ($mode=='COOL') $mode=0;
    else if ($mode=='HEAT') $mode=1;

    //и записываем данные этого кондиционера.
    $device_states[$addr]['mode'] = $mode;
    if ($temp!=0) $device_states[$addr]['temp'] = $temp;

    // var_dump($device_states);

    file_put_contents('exe/nest/device_states.json',json_encode($device_states,JSON_PRETTY_PRINT)); 
}

function setMode($id, $device_id,$mode){
    global $config;
    $url = 'https://smartdevicemanagement.googleapis.com/v1/enterprises/'
        .$config['project_id'].'/devices/'.$device_id.':executeCommand';
    $headers = array(
        'Authorization: Bearer '.$config['access_token'].' Authorization',
        'Content-Type: application/json'
    );
    $postdata = '{"command" : "sdm.devices.commands.ThermostatMode.SetMode",
        "params" : {
          "mode" : "'.$mode.'"
        }}';
    // var_dump($url);
    // var_dump($headers);
    // var_dump($postdata);

    $response = _request('POST',$url,$headers,$postdata);
    $response = json_decode($response,true);
    if(key_exists("error", $response))
        echo "NEST: error on device ", $id, ' ', $response['error']['message'], PHP_EOL;
    else {
        echo 'NEST: set '.$mode.' mode to device ',$id,PHP_EOL;
        saveCond($id, $mode);
    }
}

//mode
//0-cool
//1-heat
//2-heatcool (set range)
function setTemp($id, $device_id,$temp, $mode){
    global $config;
    // echo "debug: setTemp func started\n";
    $url = 'https://smartdevicemanagement.googleapis.com/v1/enterprises/'
        .$config['project_id'].'/devices/'.$device_id.':executeCommand';
    $headers = array(
        'Authorization: Bearer '.$config['access_token'].' Authorization',
        'Content-Type: application/json'
    );
    if($mode==0) $postdata = '{"command" : "sdm.devices.commands.ThermostatTemperatureSetpoint.SetCool",
        "params" : {"coolCelsius" : '.strval($temp).'}}';
    else if($mode==1) $postdata = '{"command" : "sdm.devices.commands.ThermostatTemperatureSetpoint.SetHeat",
        "params" : {"heatCelsius" : '.strval($temp).'}}';
    else if($mode==2){
        $temp = explode(',',$temp);

        $postdata = '{"command" : "sdm.devices.commands.ThermostatTemperatureSetpoint.SetRange",
            "params" : {
                "heatCelsius" : '.strval(intval($temp[0])).'
                ,"coolCelsius" :' .strval(intval($temp[1])).'}}';
    }
        
    
    $response =  _request('POST',$url,$headers,$postdata);
    $response = json_decode($response,true);
    if(key_exists("error", $response))
        echo "NEST: error on device ", $id, ' ', $response['error']['message'], PHP_EOL;
    else {
        if ($mode==2)echo 'NEST: set temp range to '.$temp[0].'-'.$temp[1]." to device ",$id,PHP_EOL;
        else echo 'NEST: set '.($mode ? 'heat' : 'cool').'-temp to ',$temp, " to device ",$id,PHP_EOL;
        saveCond($id, $mode,$temp);
    }
}

$json = file_get_contents('exe/nest/config.json');
$config = json_decode($json,true);
refreshToken();

//call script from shs
if(count($argv)>3 and $argv[0]==$argv[1]){
    $args = hex2str($argv[3]);
    // $args = "--mode=HEAT --heat-temp=22 --subscribe";

    $args = explode(' ',$args);
    // var_dump($args);
    $parsed_args = array(
        'mode'=>null,
        'cool-temp'=>null,
        'heat-temp'=>null,
        'set-range'=>null,
        't-min'=> null,
        'addr'=>null
    );

    foreach($args as $cmnd){
        if (strpos($cmnd, '=')){
            $tmp = explode('=',$cmnd);
            $tmp[0] = explode('--',$tmp[0])[1];
            
            $parsed_args[$tmp[0]] = $tmp[1];
        }
    }

    $addr = $parsed_args['addr'];
    $device_id = array_search($addr, $config['devices']);

    if ($addr != null && $device_id!==false){

        if ($parsed_args['mode']!=null){            
            $parsed_args['mode'] = explode("\0", $parsed_args['mode'])[0];
            if(strcmp($parsed_args['mode'], 'OFF') === 0)
                send_off($addr, $device_id);
            else setMode($addr, $device_id,$parsed_args['mode']);
        }
        if ($parsed_args['cool-temp']!=null){
            setTemp($addr, $device_id,intval($parsed_args['cool-temp']),0);
        }
        if ($parsed_args['heat-temp']!=null){
            setTemp($addr, $device_id,intval($parsed_args['heat-temp']),1);
        }
        if ($parsed_args['set-range']!=null){
            setTemp($addr, $device_id, $parsed_args['set-range'],2);
        }
    }
}



// echo getCurrentState($config['device_id']) , "\n";
// setMode($config['device_id'],'COOL');
// setMode($config['device_id'],'HEAT');
// setMode($config['device_id'],'OFF');
// setTemp($config['device_id'],25.0,0);


?>
