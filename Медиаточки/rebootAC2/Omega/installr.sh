#!/bin/sh
cd /www
wget "https://downloads.openwrt.org/releases/17.01.1/packages/mipsel_24kc/packages/libxml2_2.9.4-2_mipsel_24kc.ipk"
wget "https://downloads.openwrt.org/releases/17.01.1/packages/mipsel_24kc/packages/php7_7.1.1-1_mipsel_24kc.ipk"
wget "https://downloads.openwrt.org/releases/17.01.1/packages/mipsel_24kc/packages/php7-cgi_7.1.1-1_mipsel_24kc.ipk"
opkg install libxml2_2.9.4-2_mipsel_24kc.ipk
opkg install php7_7.1.1-1_mipsel_24kc.ipk
opkg install php7-cgi_7.1.1-1_mipsel_24kc.ipk
uci -q set uhttpd.main.interpreter='.php=/usr/bin/php-cgi'
uci commit uhttpd
/etc/init.d/uhttpd restart
