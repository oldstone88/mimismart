#!/usr/bin/php
<?php
require_once  '/home/sh2/exe/nest/aes128.php';
require_once  '/home/sh2/exe/nest/SHClient.php';
$LogPath = '/home/sh2/logs/log.txt';
$LogicPath = '/home/sh2/logic.xml';
$ConfigPath = '/home/sh2/exe/nest/config.json';
$json = file_get_contents($ConfigPath);
$config = json_decode($json,true);



$device_states = array();
$device_states_length = count($config['devices']);

// for($i=0;$i<$device_states_length;$i++){
    // $device_states[$i] = null;
// }


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
    global $config, $ConfigPath;
    
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
    file_put_contents($ConfigPath,json_encode($config,JSON_PRETTY_PRINT));
    // print('new access token:'.PHP_EOL.$config['access_token']);
    
}

// function getCurrentState($device_id){
//     global $config;
//     $url = 'https://smartdevicemanagement.googleapis.com/v1/enterprises/'
//     .$config['project_id'].'/devices/'.$device_id;
//     $headers = array('Content-Type: application/json',
//     'Authorization: Bearer ' . $config['access_token']);
//     return _request('GET',$url,$headers);
    
// }

function getCurrentState(){
    global $config;
    $url = 'https://smartdevicemanagement.googleapis.com/v1/enterprises/'
    .$config['project_id'].'/devices/';
    $headers = array('Content-Type: application/json',
    'Authorization: Bearer ' . $config['access_token']);
    return _request('GET',$url,$headers);
}


$changeTime = 0;
$device_states = array();
$cntr=3599;

while(True){
    // обновляем подключение, обновляем токен
    if($cntr==3599){
        refreshToken();
        try{
            $shClient = new SHClient("",$config['server_port'],$config['mimi_key'],$LogPath,$LogicPath);
            $shClient->readFromBlockedSocket = TRUE;
            $shClient->run();
        }
        catch(\Exception $e){
            if(strstr($e->getMessage(), "No connection")!==FALSE)
            $Message .= "No connection to shs server\n";
        }
        $cntr=0;
    }
    else{
        $cntr++;
        if($cntr==3599){
            $shClient->disconnect();
        }
    }
    
    //get last state mimismart cond
    if ($changeTime != filemtime('/home/sh2/exe/nest/device_states.json')){
        if (file_exists('/home/sh2/exe/nest/device_states.json')){
            // echo "debug: read device_states.json\n";
            $json = file_get_contents('/home/sh2/exe/nest/device_states.json');
            $device_states = json_decode($json,true);
            while (count($device_states)<$device_states_length){
                array_push($device_states,array('on' => 1,'mode' => 0,'temp' => 0,'t-min' => 16));
            }
            $changeTime = filemtime('/home/sh2/exe/nest/device_states.json');
            $cntr = 0;
        }
        else{
            $device_states = array();
            for($i=0;$i<$device_states_length;$i++){
                array_push($device_states,array('on' => 1,'mode' => 0,'temp' => 0,'t-min' => 16));
            }
        }
    }

    $id_cond=0;

    $response = getCurrentState();
    $response = json_decode($response,true);

    if(key_exists('error',$response)){
        echo $response['error']['message'], PHP_EOL;
    }
    else{
        // echo "debug: get cur state successfull", PHP_EOL;
        foreach($response['devices'] as $device){
            $device_id = explode('/', $device['name']);
            $device_id = $device_id[count($device_id)-1];

            if (array_key_exists($device_id,$config['devices'])){
                $device_addr = $config['devices'][$device_id];
                $cond = null;

                if(is_array($device_states[$device_addr])){
                    $cond = $device_states[$device_addr];
                }    
                else{
                    $cond = array(
                        'on' => 1,
                        'mode' => 0,
                        'temp' => 0,
                        't-min' => 16
                    );
                }
                // if( !strcmp($device['traits']['sdm.devices.traits.ThermostatEco']['mode'],'OFF')){
                //off
                if( !strcmp($device['traits']['sdm.devices.traits.ThermostatMode']['mode'],'OFF') ){
                    if ( $cond['on']&1 == 1 ){
                        $cond2 = array(
                            "powerSwitch"   => 0,
                            "temperature"   => $cond['temp'],
                            "air-fan"       => 0,
                            "mode"          => $cond['mode'],
                            "wide_vane"     => 0,
                            "vane"          => 0
                        );
                        print_r('set mode OFF'.PHP_EOL);
                        $shClient->setDeviceStateByAddr($device_addr,$cond2);
                        
                        // $data = "NEST\nMode:OFF";
                        // $IdSensor = explode(':',$config['devices'][$cntr]['textbox_addr'])[0];
                        // $SidSensor = explode(':',$config['devices'][$cntr]['textbox_addr'])[1];
                        // $socket = fsockopen("udp://127.0.0.1", intval($config['server_port']), $errno, $errstr);
                        // $buffer = pack("SSCCCCS", 1, $IdSensor, 5, 244, 67, $SidSensor,strlen($data)); 
                        // $buffer = $buffer . $data;
                        // fwrite($socket, $buffer);
                        // fclose($socket);
                        
                        $cond['on']=0;
                        $device_states[$device_addr] = $cond;
                    }
                }
                //heatcool
                // else if (!strcmp($device['traits']['sdm.devices.traits.ThermostatMode']['mode'],'HEATCOOL')){
                //     $mode = $device['traits']['sdm.devices.traits.ThermostatMode']['mode'];
                //     $temperature = $device ['traits']['sdm.devices.traits.ThermostatTemperatureSetpoint'];
                    
                //     $str="NEST\nMode:HeatCool\nHeatTemp:".strval(round($temperature['heatCelsius'],1))
                //     ."\nCoolTemp:".strval(round($temperature['coolCelsius'],1));
                    
                //     print_r('set mode HEATCOOL'.PHP_EOL);
                //     $shClient->setStatus($config['devices'][$cntr]['textbox_addr'],$str);
                // }
                //heat, cool
                else{
                    $mode = $device ['traits']['sdm.devices.traits.ThermostatMode']['mode'];
                    $temperature = $device ['traits']['sdm.devices.traits.ThermostatTemperatureSetpoint'];
                    
                    $str="NEST\nMode:".$device ['traits']['sdm.devices.traits.ThermostatMode']['mode'];
                    
                    // temperature
                    if (key_exists('heatCelsius',$temperature)){
                        $temperature = floatval($temperature['heatCelsius']);
                        $str .= "\nHeatTemp:".strval(round($temperature,1));
                    }
                    else if (key_exists('coolCelsius',$temperature)){
                        $temperature = floatval($temperature['coolCelsius']);
                        $str .= "\nCoolTemp:".strval(round($temperature,1));
                    }
                    //mode  
                    if ($mode=='COOL') $mode=0;
                    else if ($mode=='HEAT') $mode=1;
                    
                    if((int)$temperature!=(int)round($temperature))
                    $temperature = ceil($temperature);
                    else $temperature = (int)$temperature;
                    
                    if($cond['mode']!=$mode or $cond['temp']!=$temperature){
                        $cond2 = array(
                            "powerSwitch"   => 1,
                            "temperature"   => $temperature,
                            "air-fan"       => 0,
                            "mode"          => $mode,
                            "wide_vane"     => 0,
                            "vane"          => 0
                        );
                        
                        //set states to shs
                        echo 'set mode ', $device ['traits']['sdm.devices.traits.ThermostatMode']['mode'],' temperature ', $temperature, PHP_EOL;
                        $shClient->setDeviceStateByAddr($device_addr,$cond2);

                        // echo "test\n";
                        
                        // $data = $str;
                        // if (array_key_exists('textbox_addr',$config['devices'][$cntr])){
                        //     $IdSensor = explode(':',$config['devices'][$cntr]['textbox_addr'])[0];
                        //     $SidSensor = explode(':',$config['devices'][$cntr]['textbox_addr'])[1];
                        //     $socket = fsockopen("udp://127.0.0.1", intval($config['server_port']), $errno, $errstr);
                        //     $buffer = pack("SSCCCCS", 1, $IdSensor, 5, 244, 67, $SidSensor,strlen($data)); 
                        //     $buffer = $buffer . $data;
                        //     fwrite($socket, $buffer);
                        //     fclose($socket);
                        // }
                        
                        //save new state cond
                        $cond['on']=1;
                        $cond['mode']=$mode;
                        $cond['temp']=$temperature;

                        $device_states[$device_addr] = $cond;   
                        // echo "debug: " . json_encode($device_states) . "\ncond:  " . json_encode($cond) . "\n";
                    }
                    // else echo "State the same, skipped\n";
                }
                // }
            }
        }
    }
  
    if ($device_states != null){
        file_put_contents('/home/sh2/exe/nest/device_states.json',json_encode($device_states,JSON_PRETTY_PRINT));
    }
    
    sleep(15);
}

?>
