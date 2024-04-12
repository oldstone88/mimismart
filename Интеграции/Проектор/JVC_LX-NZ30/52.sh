#!/usr/bin/php
<?php
$host = '172.20.100.223';
$port = 4661;

$consoleParam = hex2bin($argv[3]);
echo $consoleParam."\n";
$bytes = str_split($consoleParam, 2);
$CRC = 0;
foreach($bytes as $byte){
    $CRC += hexdec($byte);
}
$CRCHEX = sprintf('%02X', $CRC % 256);
$result = '';
foreach ($bytes as $byte) {
  $result .= '\x' . $byte;
}
$result .= $CRCHEX;
echo $result."\n";


# Команда на включение "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D\xC0"
# Команда на выключение "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E\xC2"

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
    echo "Ошибка создания сокета: " . socket_strerror(socket_last_error()) . "\n";
    exit;
}

$result = socket_connect($socket, $host, $port);
if ($result === false) {
    echo "Ошибка соединения с сервером: " . socket_strerror(socket_last_error($socket)) . "\n";
    exit;
}

$timeoutSeconds = 5;
$timeoutMicroseconds = 0;
$timeout = [
    'sec' => $timeoutSeconds,
    'usec' => $timeoutMicroseconds
];
socket_set_option($socket, SOL_SOCKET, SO_RCVTIMEO, $timeout);

socket_write($socket, $result, strlen($bytes));

$response = socket_read($socket, 2048);
if ($response === false) {
    echo "Таймаут получения ответа\n";
} else {
    echo "Ответ от сервера Telnet: " . $response . "\n";
}

socket_close($socket);
?>