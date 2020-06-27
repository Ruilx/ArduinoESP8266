#!/bin/bash

arduino_home="D:/arduino-1.8.2"
arduino_local_path="$APPDATA/../Local/Arduino15"
arduino_user_path="$USERPROFILE/Documents/Arduino"

arduino_builder_path="$arduino_home/arduino-builder"

hardware_arduino_path="$arduino_home/hardware"
hardware_user_path="$arduino_local_path/packages"
tools_builder_path="$arduino_home/tools-builder"
tools_avr_path="$arduino_home/hardware/tools/avr"
tools_user_path="$arduino_local_path/packages"
builtin_libraries_path="$arduino_home/libraries"
arduino_libraries_path="$arduino_user_path/libraries"

user_libraries_path="$PWD"

hardware_name="esp8266:esp8266:generic" # Hardware Name
hardware_xtal=160                       # CPU Freq(Mhz) {80, 160}
hardware_vt="flash"                     # VTables {flash, heap, iram}
hardware_exception="enabled"            # Exception {enabled, disabled}
hardware_reset_method="nodemcu"         # Reset Method {ck, nodemcu, none, dtrset}
hardware_crystal_freq=26                # Crystal Freq(Mhz) {26, 40}
hardware_flash_freq=40                  # Flash Freq(Mhz) {40, 80}
hardware_flash_mode="dio"               # Flash Mode {dout, dio, qout, qio}
hardware_eesz="4M"                      # Flash Size {512K, 1M, 2M, 4M, 8M, 16M}
hardware_led=2                          # Builtin LED Port {2}
hardware_ip="lm2f"
hardware_dbg="disabled"
hardware_lvl="None____"
hardware_wipe="none"                    # Erase Flash
hardware_baud=256000                    # Upload Speed (bps) {115200, 9600, 57600, 256000, 512000, 921600}

fqbn=$hardware_name:xtal=$hardware_xtal,vt=$hardware_vt,exception=$hardware_exception,ResetMethod=$hardware_reset_method,CrystalFreq=$hardware_crystal_freq,FlashFreq=$hardware_flash_freq,FlashMode=$hardware_flash_mode,eesz=$hardware_eesz,led=$hardware_led,ip=$hardware_ip,dbg=$hardware_dbg,lvl=$hardware_lvl,wipe=$hardware_wipe,baud=$hardware_baud

ide_ver=10802

build_path="$PWD/build"
build_cache="$PWD/cache"
warnings="none"

prefs_warn_data_percentage=75
prefs_esptool_path="$hardware_user_path/esp8266/tools/esptool/2.5.0-3-20ed2b9"
prefs_esptool_gcc_path="$hardware_user_path/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9"
prefs_mkspiffs_path="$hardware_user_path/esp8266/tools/mkspiffs/2.5.0-3-20ed2b9"

ino_file="ArduinoESP8266.ino"

if [ ! -d $build_path ]; then
	mkdir -p $build_path
fi
if [ ! -d $build_cache ]; then
	mkdir -p $build_cache
fi

$arduino_builder_path \
-dump-prefs \
-logger=machine \
-hardware $hardware_arduino_path \
-hardware $hardware_user_path \
-tools $tools_builder_path \
-tools $tools_avr_path \
-tools $tools_user_path \
-built-in-libraries $builtin_libraries_path \
-libraries $arduino_libraries_path \
-libraries $user_libraries_path \
-fqbn=$fqbn \
-ide-version=$ide_ver \
-build-path $build_path \
-warnings=$warnings \
-build-cache $build_cache \
-prefs=build.warn_data_percentage=$prefs_warn_data_percentage \
-prefs=runtime.tools.esptool.path=$prefs_esptool_path \
-prefs=runtime.tools.xtensa-lx106-elf-gcc.path=$prefs_esptool_gcc_path \
-prefs=runtime.tools.mkspiffs.path=$prefs_mkspiffs_path \
-verbose \
$ino_file #| # awk -F "[ ][|][|][|][ ]" '{if($2 != ""){print "\""$2"\\n\"", $3}else{print "\""$0"\""}}' | sed 's/{[0-9]*}/%s/g' | sed 's/[][]//g' | xargs printf
#while read line; do \
#	ready=$(echo $line | grep "===")
#	if [ "x$ready" != "x" ]; then
#		#echo $line | awk -F "[ ][|][|][|][ ]" '{print "print(\""$2"\"",".format(*" ,$3, "))"}' | python
#		echo $line | awk -F "[ ][|][|][|][ ]" '{print "\""$2"\\n\"", $3}' | sed 's/{[0-9]*}/%s/g' | sed 's/[][]//g' | xargs printf
#	else
#		echo $line
#	fi
#done

$arduino_builder_path \
-compile \
-logger=machine \
-hardware $hardware_arduino_path \
-hardware $hardware_user_path \
-tools $tools_builder_path \
-tools $tools_user_path \
-built-in-libraries $builtin_libraries_path \
-libraries $arduino_libraries_path \
-libraries $user_libraries_path \
-fqbn=$fqbn \
-ide-version=$ide_ver \
-build-path $build_path \
-warnings=$warnings \
-build-cache $build_cache \
-prefs=build.warn_data_percentage=$prefs_warn_data_percentage \
-prefs=runtime.tools.esptool.path=$prefs_esptool_path \
-prefs=runtime.tools.xtensa-lx106-elf-gcc.path=$prefs_esptool_gcc_path \
-prefs=runtime.tools.mkspiffs.path=$prefs_mkspiffs_path \
-verbose \
$ino_file #|
#while read line; do \
#	ready=$(echo $line | grep "===")
#	if [ "x$ready" != "x" ]; then
#		#echo $line | awk -F "[ ][|][|][|][ ]" '{print "print(\""$2"\"",".format(*" ,$3, "))"}' | python
#		echo $line | awk -F "[ ][|][|][|][ ]" '{print "\""$2"\\n\"", $3}' | sed 's/{[0-9]*}/%s/g' | sed 's/[][]//g' | xargs printf
#	else
#		echo $line
#	fi
#done
