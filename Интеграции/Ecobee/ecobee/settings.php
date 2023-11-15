<?php

date_default_timezone_set('Europe/Kiev');

define("BASE_DIR", "");
define("XML_FILE", "/home/sh2/logic.xml");//set chmod 666
define("LOG_FILE", "/home/sh2/logs/log.txt");

//begin smart house server settings ##################################
define("HOST", "192.168.1.125");
define("PORT", 55555);
define("SECRET_KEY","1234567890123456");
//end shs settings ####################################

$globalSettings = array();
$globalSettings["shs"] = array();
$globalSettings["shs"]["host"] = HOST;
$globalSettings["shs"]["port"] = PORT;
$globalSettings["shs"]["secret_key"] = SECRET_KEY;
$globalSettings["shs"]["logFile"] = LOG_FILE;
$globalSettings["debug"] = TRUE;
$globalSettings["logFile"] = LOG_FILE;

require_once '/home/api/AES128.php';
require_once '/home/api/SHClient.php';

?>
