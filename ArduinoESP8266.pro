TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
	main.h \
	module/TemperatureDS18B20.h \
    GpioDefine.h \
    About.h \
    Constant.h \
    Wifi1.h

SOURCES += main.cpp \
	WifiApi8266.ino \
	module/TemperatureDS18B20.cpp

DISTFILES += \
	build.sh \
	flash.sh

DEFINES += \
	__ets__ \
	ICACHE_FLASH \
	F_CPU=160000000L \
	LWIP_OPEN_SRC \
	TCP_MSS=536 \
	LWIP_FEATURES=1 \
	LWIP_IPV6=0 \
	ARDUINO=10810 \
	ARDUINO_ESP8266_GENERIC \
	ARDUINO_ARCH_ESP8266 \
	ARDUINO_BOARD=ESP8266_GENERIC \
	LED_BUILTIN=2 \
	FLASHMODE_DIO \
	ESP8266
	QtCreator

QMAKE_CXXFLAGS += \
	-fno-rtti \
	-falign-functions=4 \
	-std=c++11 \
	-ffunction-sections \
	-fdata-sections \
	-fexceptions

INCLUDEPATH += \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/tools/sdk/include \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/tools/sdk/lwip2/include \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/tools/sdk/libc/xtensa-lx106-elf/include \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/cores/esp8266 \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/variants/generic \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/Wire \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/SPI \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/ESP8266WiFi/src \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/ESP8266WebServer/src \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/ESP8266HTTPClient/src \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/ESP8266mDNS/src \
	C:/Users/Ruilx/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/libraries/ESP8266WiFiMesh/src \
	C:/Users/Ruilx/Documents/Arduino/libraries \
	C:/Users/Ruilx/Documents/Arduino/libraries/OneWire \
	C:/Users/Ruilx/Documents/Arduino/libraries/uRTCLib/src \
	C:/Users/Ruilx/Documents/Arduino/libraries/ArduinoJson/src \
	C:/Users/Ruilx/Documents/Arduino/libraries/NTPClient \
	C:\Users\Ruilx\Documents\Arduino\libraries\Arduino-Temperature-Control-Library \
	$$PWD
