//#include <DallasTemperature.h>
#include <user_interface.h>
#include <ESP8266WiFi.h>
#include <FS.h>
#include "main.h"
#include "GpioDefine.h"
#include "About.h"
#include "Utils.h"
#include "Config.h"

#include <list>
#include <map>

//#include "Arranger.h"


#include <uRTCLib.h>

#define Wifi WiFi

void shutdown(){
	while(1){
		system_soft_wdt_feed();
		delay(10);
		yield();
	}
}

os_timer_t timer1;
void ICACHE_FLASH_ATTR timer1_cb(void){
	static uint32_t oldRtcTime = 0;
	uint32_t rtcTime = system_get_rtc_time();
	Serial.print("RTC Time: ");
	Serial.println(rtcTime);
	Serial.print("loss: ");
	Serial.println(rtcTime - oldRtcTime);
	Serial.print("Current miliSecond: ");
	Serial.println(rtcTime * config.rtcCali / 1000);
	Serial.print("loss milisecond: ");
	Serial.println((rtcTime - oldRtcTime) * config.rtcCali / 1000);
	oldRtcTime = rtcTime;
}

bool alreadyInInterrupt = false;
void ICACHE_RAM_ATTR gpio_cb(void){
	detachInterrupt(digitalPinToInterrupt(0));
	Serial.print("GPIO Interrupt: ");
	Serial.println(ESP.getCycleCount());
	alreadyInInterrupt = false;
	attachInterrupt(digitalPinToInterrupt(0), gpio_cb, FALLING);
}

//Task task1(TASK_SECOND, TASK_FOREVER, [](){
//	static uint32_t oldRtcTime = 0;
//	uint32_t rtcTime = system_get_rtc_time();
//	Serial.print("Task[1] scheduled ");
//	Serial.print(task1.getRunCounter());
//	Serial.println(" times.");
//	Serial.print("RTC Time: ");
//	Serial.println(rtcTime);
//	Serial.print("loss: ");
//	Serial.println(rtcTime - oldRtcTime);
//	oldRtcTime = rtcTime;
//});

//Task task2(2 * TASK_SECOND, TASK_FOREVER, [](){
//	Serial.print("Task[2] scheduled ");
//	Serial.print(task2.getRunCounter());
//	Serial.println(" times.");
//});

void setup(){
	Serial.begin(115200);
	Serial.println("");

	Serial.printf("Build datetime: %s %s\n", __DATE__, __TIME__);

	setupGpio();

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

	printBanner();

	printChipInfo();


	uint32_t cycleCount = ESP.getCycleCount();
	Serial.print("CYCLE COUNT: ");
	Serial.println(cycleCount);

	pinMode(LED_BUILTIN, OUTPUT);

	os_timer_disarm(&timer1);
	os_timer_setfn(&timer1, (os_timer_func_t *)timer1_cb, nullptr);
	os_timer_arm(&timer1, 1000, 1);

	Serial.print("FREE HEAP: ");
	Serial.println(ESP.getFreeHeap());

//	attachInterrupt(digitalPinToInterrupt(5), gpio_cb, FALLING);

	String value = numberUnitFormat(12345678);
	Serial.print("String value = ");
	Serial.println(value);

	std::list<int> intList;
	intList.push_back(1);
	intList.push_back(2);

	std::map<String, int> intMap;
	intMap.insert(std::pair<String, int>("AString", 'A'));
	intMap.insert(std::pair<String, int>("BString", 'B'));
	intMap.insert(std::pair<String, int>("CString", 'C'));
	intMap.insert(std::pair<String, int>("DString", 'D'));
	intMap.insert(std::pair<String, int>("EString", 'E'));

	yield();

	for(auto i: intList){
		Serial.println(i);
	}

	for(auto i: intMap){
		Serial.print("[ ");
		Serial.print(i.first);
		Serial.print("] : ");
		Serial.println(i.second);
	}

	yield();

	attachInterrupt(digitalPinToInterrupt(0), gpio_cb, FALLING);

	//arranger.addTask("Task1", task1);
	//arranger.addTask("Task2", task2);

	Serial.println("=================== meminfo =====");
	system_print_meminfo();
	Serial.println("=================================");

	uint32_t rtcClockCaliProc = system_rtc_clock_cali_proc();
	Serial.println("============ RTC Clock Cali Proc ");
	Serial.println(rtcClockCaliProc, BIN);
	config.rtcCali = (float)rtcClockCaliProc / 4096.0f;
	Serial.println(config.rtcCali);
	Serial.println("=================================");
}

void loop(){
	//arranger.execute();
}

