#!/usr/bin/php
<?php
$consoleParam = hex2bin($argv[3]);
//Часть передачи в telnet
exec("screen -S Denon -X eval 'stuff " . $consoleParam . "\015'");
?>