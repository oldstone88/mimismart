#!/usr/bin/php-cgi
<?php
setlocale(LC_ALL, "ru_RU");
date_default_timezone_set("Europe/Moscow");

define("BASE_DIR", "/mimismart/");
define("LOG_FILE", BASE_DIR . "logs/logs.txt");
//begin smart house server settings ##################################
define("HOST", "127.0.0.1");
define("PORT", 55555);
define("SECRET_KEY","");
define("KEYS_FILE","/mimismart/keys.txt");

require_once '/home/api/AES128.php';
require_once '/home/api/SHClient.php';

$shClient = new SHClient(HOST, PORT, SECRET_KEY, LOG_FILE);

if($shClient->run())
{
    $consoleParams = $shClient->getDataFromConsole();
    $pSignal = $consoleParams["params"]["signal"];
    file_put_contents('/mimismart/exe/DEBUG.txt', json_encode($consoleParams));
    //Уставка параметров
    $host = "192.168.1.90";
    $url = 'http://'.$host.'/sony';
    $post_data = [
        'version' => '1.0'
    ];

    if($pSignal==1)
    {
        $url = $url.'/system';
        $post_data['method'] = 'setPowerStatus';
        $post_data['id'] = 55;
        // $post_data['params'] = '[{"status": false}]';
        $post_data['params'] = array(array('status' => false ));
    }
    elseif ($pSignal==2)
    {
        $url = $url.'/system';
        $post_data['method'] = 'setPowerStatus';
        $post_data['id'] = 55;
        //$post_data['params'] = '[{"status": true}]';
        $post_data['params'] = array(array('status' => true ));
    }
    elseif ($pSignal==3)
    {
        $url=$url.'/audio';
        $post_data['method'] = 'setAudioVolume';
        $post_data['id'] = 601;
        //$post_data['params'] = '[{"volume": "+1", "target": "speaker"}]';
        $post_data['params'] = array(array('volume'=>'+1', 'target' => 'speaker'));
    }
    elseif ($pSignal==4)
    {
        $url=$url.'/audio';
        $post_data['method'] = 'setAudioVolume';
        $post_data['id'] = 601;
        //$post_data['params'] = '[{"volume": "-1", "target": "speaker"}]';
        $post_data['params'] = array(array('volume'=>'-1', 'target' => 'speaker'));
    }
    elseif ($pSignal==5)
    {
        $url=$url.'/audio';
        $post_data['method'] = 'setAudioMute';
        $post_data['id'] = 1;
        //$post_data['params'] = '[{"status": true}]';
        $post_data['params'] = array(array('status'=>true));
    }
    elseif ($pSignal==6)
    {
        $url=$url.'/avContent';
        $post_data['method'] = 'setPlayContent';
        $post_data['id'] = 101;
        //$post_data['params'] = '[{"uri": "extInput:hdmi?port=1"}]';
        $post_data['params'] = array(array('uri'=>'extInput:hdmi?port=1'));
    }
    elseif ($pSignal==7)
    {
        $url=$url.'/avContent';
        $post_data['method'] = 'setPlayContent';
        $post_data['id'] = 101;
        //$post_data['params'] = '[{"uri": "extInput:hdmi?port=2"}]';
        $post_data['params'] = array(array('uri'=>'extInput:hdmi?port=2'));
    }
    elseif ($pSignal==8)
    {
        $url=$url.'/avContent';
        $post_data['method'] = 'setPlayContent';
        $post_data['id'] = 101;
        //$post_data['params'] = '[{"uri": "extInput:hdmi?port=3"}]';
        $post_data['params'] = array(array('uri'=>'extInput:hdmi?port=3'));
    }
    elseif ($pSignal==9)
    {
        $url=$url.'/avContent';
        $post_data['method'] = 'setPlayContent';
        $post_data['id'] = 101;
        //$post_data['params'] = '[{"uri": "extInput:hdmi?port=4"}]';
        $post_data['params'] = array(array('uri'=>'extInput:hdmi?port=4'));
    }
    elseif ($pSignal==10) //setting app youtube 
    {
        $url=$url.'/appControl';
        $post_data['method'] = 'setActiveApp';
        $post_data['id'] = 601;
        $post_data['params'] = array(array('uri'=>'com.sony.dtv.com.google.android.youtube.tv.com.google.android.apps.youtube.tv.activity.ShellActivity'));
    }
    elseif ($pSignal==11) //setting app TV 
    {
        $url=$url.'/appControl';
        $post_data['method'] = 'setActiveApp';
        $post_data['id'] = 601;
        $post_data['params'] = array(array('uri'=>'com.sony.dtv.com.sony.dtv.tvx.com.sony.dtv.tvx.MainActivity'));
    }
    elseif ($pSignal==12) //setting app player 
    {
        $url=$url.'/appControl';
        $post_data['method'] = 'setActiveApp';
        $post_data['id'] = 601;
        $post_data['params'] = array(array('uri'=>'com.sony.dtv.com.sony.dtv.smartmediaapp.com.sony.dtv.smartmediaapp.MainActivity'));
    }

    $post_data = json_encode($post_data);
    $headers = [
        'Content-Type: application/json; charset=UTF-8',
        'X-Auth-PSK: 1234',
        'Content-Length: ' . strlen($post_data),
        'Host: '.$host
    ];

    //Установка параметров curl
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($curl, CURLOPT_POSTFIELDS, $post_data);
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_POST, true);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);

    //Отправка значений
    $result = curl_exec($curl);
    curl_close($curl);

    echo "post-data:".$post_data."\n";
    echo "result:".$result."\n";
    }
?>