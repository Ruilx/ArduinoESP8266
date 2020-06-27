//#include <DallasTemperature.h>
#include <user_interface.h>
#include <ESP8266WiFi.h>
#include <Esp.h>
#include <FS.h>
#include "main.h"
#include "GpioDefine.h"
#include "About.h"

#include <vector>
#include <map>

#define Wifi WiFi

void shutdown(){
	while(1){
		system_soft_wdt_feed();
		delay(10);
	}
}

#define MAX_AP_SIZE 30


os_timer_t timer1;

uint8 bLed = 0;

void ICACHE_FLASH_ATTR timer1_cb(void){
	bLed = ~bLed & 0x1;
	digitalWrite(BUILTIN_LED, bLed);
	Serial.print("Current Cycle: ");
	Serial.println(ESP.getCycleCount());
}

void setupGPIO(){
	pinMode(LEDPin, OUTPUT);
	digitalWrite(LEDPin, LOW);
	pinMode(BTNPin, INPUT);

}

ADC_MODE(ADC_VCC)

void setup(){
	Serial.begin(115200);
	Serial.println("");

	setupGPIO();

	banner(&Serial);

	uint16_t vcc = ESP.getVcc();

	Serial.print("VCC: ");
	Serial.println(vcc / 1023.0);

	chipInfo(&Serial);

	rst_info *rstInfo = ESP.getResetInfoPtr();

	if(rstInfo->reason == REASON_WDT_RST ||
			rstInfo->reason == REASON_SOFT_WDT_RST ||
			rstInfo->reason == REASON_EXCEPTION_RST){
		Serial.println("Last reset is not a normal operation, please check the exception weather code caused.");
		Serial.println("Push GPIO 0 button to continue...");
		while(!digitalRead(BTNPin)){
			delay(10);
		}
	}


	uint32_t cycleCount = ESP.getCycleCount();
	Serial.print("CYCLE COUNT: ");
	Serial.println(cycleCount);

	pinMode(LED_BUILTIN, OUTPUT);

//	os_timer_disarm(&timer1);
//	os_timer_setfn(&timer1, (os_timer_func_t *)timer1_cb, nullptr);
//	os_timer_arm(&timer1, 1000, 1);

	SPIFFS.begin();
	Dir root = SPIFFS.openDir("/");
	while(root.next()){
		Serial.println(root.fileName());
		Serial.println(root.fileSize());
		Serial.println("======================");
		File f = root.openFile("r");
		while(f.available()){
			Serial.print(f.readString());
		}
		f.close();
		Serial.println();
		Serial.println("======================");
	};

//	Serial.println("Wifi AP:");
//	Wifi.begin();
//	int8_t wifiaps = Wifi.scanNetworks();
//	for(uint8_t i = 0; i < wifiaps; i++){
//		Serial.println("======================");
//		Serial.print("SSID: ");
//		Serial.println(Wifi.SSID(i));
//		Serial.print("EncryptionType: ");
//		Serial.println(Wifi.encryptionType(i));
//		Serial.print("RSSI: ");
//		Serial.println(Wifi.RSSI(i));
//		Serial.print("BSSID: ");
//		Serial.println((const char*)Wifi.BSSID(i));
//		Serial.print("BSSID str: ");
//		Serial.println(Wifi.BSSIDstr(i));
//		Serial.print("Channel: ");
//		Serial.println(Wifi.channel(i));
//		Serial.print("Is Hidden: ");
//		Serial.println(Wifi.isHidden(i)?"True":"False");
//	}
//	Serial.println("=====================");
//	Serial.print("WiFi Sleep Type: ");
//	switch(Wifi.getSleepMode()){
//		case WIFI_NONE_SLEEP: Serial.println("WiFi none sleep."); break;
//		case WIFI_LIGHT_SLEEP: Serial.println("WiFi light sleep."); break;
//		case WIFI_MODEM_SLEEP: Serial.println("WiFi modem sleep."); break;
//		default: Serial.println("WiFi sleep unknown.");
//	}
//	Wifi.disconnect(true);
//	Serial.print("WiFi Sleep Type: ");
//	switch(Wifi.getSleepMode()){
//		case WIFI_NONE_SLEEP: Serial.println("WiFi none sleep."); break;
//		case WIFI_LIGHT_SLEEP: Serial.println("WiFi light sleep."); break;
//		case WIFI_MODEM_SLEEP: Serial.println("WiFi modem sleep."); break;
//		default: Serial.println("WiFi sleep unknown.");
//	}

	Serial.print("FREE HEAP: ");
	Serial.println(ESP.getFreeHeap());

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for(auto i = v.cbegin(); i != v.cend(); i++){
		Serial.println(*i);
	}

	std::map<int, String> m;
	m[1] = String("ABC");
	m[2] = String("DEF");

	for(auto i = m.cbegin(); i != m.cend(); i++){
		Serial.printf("[%d] => %s", (*i).first, (*i).second.begin());
	}

	Serial.print("FREE HEAP: ");
	Serial.print(ESP.getFreeHeap());

	Serial.print("getCPUFreq: ");
	Serial.println(system_get_cpu_freq());
	Serial.print("Ready to turn to 160HZ...");
	delay(5000);
	if(system_update_cpu_freq(SYS_CPU_160MHZ)){
		Serial.print("Update Success.");
	}else{
		Serial.print("Update failed.");
	}
	Serial.print("CURRENT CPU Freq: ");
	Serial.print(system_get_cpu_freq());
	delay(5000);
	if(system_update_cpu_freq(SYS_CPU_80MHZ)){
		Serial.print("Downgrade Success");
	}else{
		Serial.print("Downgrade Failed");
	}
	Serial.print("CURRENT CPU Freq: ");
	Serial.print(system_get_cpu_freq());
}

void loop(){
	static uint8_t ledStatus = HIGH;
	digitalWrite(LED_BUILTIN, ledStatus);
	ledStatus = (~ledStatus) & 0x1;
	delay(1000);
}

