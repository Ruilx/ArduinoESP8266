#!/bin/bash

esptool_path="C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/tools/esptool/2.5.0-3-20ed2b9"
board="nodemcu" # {nodemcu, none, ck, wifio}
baudrate=256000
serial="COM11"
address="0x00000"

target="./build/WifiApi8266.ino.bin"

$esptool_path/esptool \
-vv \
-cd "$board" \
-cb $baudrate \
-cp "$serial" \
-ca $address \
-cf "$target"
