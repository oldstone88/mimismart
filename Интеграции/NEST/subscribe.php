#!/usr/bin/php
<?php
require_once  '/home/sh2/exe/nest/aes128.php';
require_once  '/home/sh2/exe/nest/SHClient.php';
$LogPath = '/home/sh2/logs/log.txt';
$LogicPath = '/home/sh2/logic.xml';
$ConfigPath = '/home/sh2/exe/nest/config.json';
$json = file_get_contents($ConfigPath);
$config = json_decode($json,true);


set_time_limit(10);

$device_states = array();
$device_states_length = count($config['devices']);

// for($i=0;$i<$device_states_length;$i++){
    // $device_states[$i] = null;
// }

function setStatusCondUdp($addr, $data ){
        // $data as massive of 6 values
        //   Example:
        // $data[0] = 0x11; // mode + onoff
        // $data[1] = 4; // temperatute
        // $data[2] = 0; 
        // $data[3] = 0;
        // $data[4] = 0;
        // $data[5] = 0;
    $IdSensor = 110;
    $SidSensor = 245;
    $exciterID = 2031;
    $exciterSubID=67;
    $socket = fsockopen("udp://192.168.1.130", 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScccccc", $exciterID, $IdSensor, 5, 15, $exciterSubID, $SidSensor, 6,$data[0],$data[1],$data[2],$data[3],$data[4],$data[5]); 
    fwrite($socket, $buffer);
    fclose($socket);
}
function setStatusVirtSensUDP($addr, $ip, $data){
    $data = round($data, 1);
    $IdSensor = explode(":", $addr)[0];
    $SidSensor = explode(":", $addr)[1];
    $intval = intval($data);
    $floatval = ($data - floor($data)) * 250;
    // echo "IdSensor: ".$IdSensor.PHP_EOL;
    // echo "SidSendor: ".$SidSensor.PHP_EOL;
    // echo "intval: ".$intval.PHP_EOL;
    // echo "floatval: ".$floatval.PHP_EOL;
    $exciterID = 2031;
    $exciterSubID=67;
    $socket = fsockopen("udp://".$ip, 55555, $errno, $errstr);
    $buffer = pack("SSCCCCScc", 1, $IdSensor, 5, 244, 67, $SidSensor, 2, $floatval,$intval); 
    fwrite($socket, $buffer);
    fclose($socket);

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
    print('new access token:'.PHP_EOL.$config['access_token']);
    
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
    echo "cntr=".$cntr."\n";
    if($cntr>=3599){
    //echo "1";
        refreshToken();
    //echo "2";
        // try{
        //     // $shClient = new SHClient("","",$config['mimi_key'],$LogPath,$LogicPath);
        //     $shClient = new SHClient("127.0.0.1","22522",$config['mimi_key'],$LogPath,$LogicPath);
        //     $shClient->readFromBlockedSocket = TRUE;
        //     $shClient->run();
        // }
        // catch(\Exception $e){
        //     if(strstr($e->getMessage(), "No connection")!==FALSE)
        //     $Message .= "No connection to shs server\n";
        // }
        $cntr=0;
    }
    
    $cntr+=30;
        // if($cntr>=3599){
            // $shClient->disconnect();
        // }
    
    //get last state mimismart cond
    if ($changeTime != filemtime('/home/sh2/exe/nest/device_states.json')){
        if (file_exists('/home/sh2/exe/nest/device_states.json')){
            // echo "debug: read device_states.json\n";
            $json = file_get_contents('/home/sh2/exe/nest/device_states.json');
            $device_states = json_decode($json,true);
            while (count($device_states)<$device_states_length){
                array_push($device_states,array('on' => 1,'mode' => 0,'temp' => 0,'t-min' => 19));
            }
            $changeTime = filemtime('/home/sh2/exe/nest/device_states.json');
            
        }
        else{
            $device_states = array();
            for($i=0;$i<$device_states_length;$i++){
                array_push($device_states,array('on' => 1,'mode' => 0,'temp' => 0,'t-min' => 19));
            }
        }
    }

    $id_cond=0;
    //echo "1\n";
    try{
        $shClient = new SHClient("127.0.0.1", (string)$config['server_port'],$config['mimi_key'],$LogPath,$LogicPath);
        $shClient->readFromBlockedSocket = TRUE;
        $shClient->run();
    }
    catch(\Exception $e){
        if(strstr($e->getMessage(), "No connection")!==FALSE)
            $Message .= "No connection to shs server\n";
    }
    $response = getCurrentState();
    $response = json_decode($response,true);
    //echo "2\n";
    //var_dump($response);
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
                    $cond = $device_states[$device_addr]; // получает сост из файла
                }    
                else{
                    $cond = array(
                        'on' => 1,
                        'mode' => 0,
                        'temp' => 0,
                        't-min' => 19
                    );
                }
                // if( !strcmp($device['traits']['sdm.devices.traits.ThermostatEco']['mode'],'OFF')){
                //off
                //если офлайн, ничего не отправляем
                if(!strcmp($device['traits']['sdm.devices.traits.Connectivity']['status'],'ONLINE')) {
                    if( !strcmp($device['traits']['sdm.devices.traits.ThermostatMode']['mode'],'OFF') ){
                        $cond2 = array(
                            "powerSwitch"   => 0,
                            "temperature"   => $cond['temp'],
                            "air-fan"       => 0,
                            "mode"          => $cond['mode'],
                            "wide_vane"     => 0,
                            "vane"          => 0
                        );
                        //var_dump($cond2);
                        print_r('set mode OFF to '.$device_addr.PHP_EOL);
                        $shClient->setDeviceStateByAddr($device_addr,$cond2);
                        usleep(200000);
                        $cond['on']=0;
                        $device_states[$device_addr] = $cond;
                    }
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

                    //if($cond['mode']!=$mode or $cond['temp']!=$temperature){
                        $cond2 = array(
                            "powerSwitch"   => 1,
                            "temperature"   => $temperature-3,
                            "air-fan"       => 0,
                            "mode"          => $mode,
                            "wide_vane"     => 0,
                            "vane"          => 0
                        );
                        
                        //set states to shs
                        echo 'set mode ', $device ['traits']['sdm.devices.traits.ThermostatMode']['mode'],' temperature ', $temperature, 'to device: ',$device_addr, PHP_EOL;
                        echo($shClient->setDeviceStateByAddr($device_addr,$cond2));
                        usleep(200000);

                        
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
                    //}
                    // else echo "State the same, skipped\n";
                    }
                    $temperature_from_NEST = $device ['traits']['sdm.devices.traits.Temperature']['ambientTemperatureCelsius'];
                    if (array_key_exists($device_id,$config['temp_sensors'])){
                        $temp_sens_addr = $config['temp_sensors'][$device_id];
                        setStatusVirtSensUDP($temp_sens_addr, "192.168.1.134", $temperature_from_NEST);
                        echo "sended temperature ".$temperature_from_NEST." to sensor addr ".$temp_sens_addr."\n";
                    }
                }
                else
                {
                    echo "Device ".$device_addr." is OFFLINE. ".PHP_EOL;
                }
            }
        }
    }

    if ($device_states != null){
        file_put_contents('/home/sh2/exe/nest/device_states.json',json_encode($device_states,JSON_PRETTY_PRINT));
    }
    $shClient->disconnect();
    $cntr+=20;
    sleep(20);
}

?>
