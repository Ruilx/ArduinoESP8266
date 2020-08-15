#ifndef ABOUT_H
#define ABOUT_H

#include <HardwareSerial.h>
#include <Esp.h>
#include "Utils.h"
#include "Constant.h"

/* GT-Clock 8266
 * @author: Ruilx <RuilxAlxa@qq.com>
 * @create at: 2020/06/26
 *
 */

#define ApplicationName "GT-Clock 8266"
#define StudioName "GT-Soft"
#define Version "Dev 0.1"

#define GithubWebsite "http://github.com/Ruilx/GT-Clock"
#define OfficalWebsite "http://ruilx.top/product/GT-Clock"

#define Email "RuilxAlxa@hotmail.com"

#define Team {"Ruilx Alxa", "Norman Zhi", "Gan"}

#define PrintKV(k, ...) \
	Serial.print(k); \
	Serial.print(" = "); \
	Serial.println(__VA_ARGS__)

void printBanner(){
	if(!Serial.availableForWrite()){
		return;
	}
	Serial.println("    ______                               _ ____");
	Serial.println("   / ____/________  ________  __________(_) __/");
	Serial.println("  / __/ / ___/ __ \\/ ___/ _ \\/ ___/ ___/ / /_");
	Serial.println(" / /___(__  ) /_/ / /  /  __(__  |__  ) / __/");
	Serial.println("/_____/____/ .___/_/   \\___/____/____/_/_/");
	Serial.println("          /_/                  * GT-Clock 8266");
}

void printGtClockBanner(){
	if(!Serial.availableForWrite()){
		return;
	}
	Serial.println("  ____ _____      ____ _            _");
	Serial.println(" / ___|_   _|    / ___| | ___   ___| | __");
	Serial.println("| |  _  | |_____| |   | |/ _ \\ / __| |/ /");
	Serial.println("| |_| | | |_____| |___| | (_) | (__|   <");
	Serial.println(" \\____| |_|      \\____|_|\\___/ \\___|_|\\_\\");
	Serial.println();
}

void printChipInfo(){
	if(!Serial.availableForWrite()){
		return;
	}
	Serial.println("======== ESP8266 Chip ========");
	uint32_t chipId = ESP.getChipId();
	PrintKV("Chip ID", ESP.getChipId(), HEX);
	PrintKV("SDK version", ESP.getSdkVersion());
	PrintKV("Core version", ESP.getCoreVersion());
	PrintKV("Full version", ESP.getFullVersion());
	PrintKV("Boot version", ESP.getBootVersion());
	PrintKV("Boot mode", ESP.getBootMode());
	PrintKV("CPU freq", numberUnitFormat(ESP.getCpuFreqMHz(), 2, 1000, 2));
	PrintKV("Flash chip ID", ESP.getFlashChipId(), HEX);
	PrintKV("Flash chip vendor ID", ESP.getFlashChipVendorId(), HEX);
	PrintKV("Flash chip real size", numberUnitFormat(ESP.getFlashChipRealSize()));
	PrintKV("Flash chip size", numberUnitFormat(ESP.getFlashChipSize()));
	PrintKV("Flash chip speed", numberUnitFormat(ESP.getFlashChipSpeed(), 2, 1000));
	PrintKV("Flash chip mode", CONSTANT(ESP.getFlashChipMode()));

	PrintKV("Sketch size", ESP.getSketchSize());
	PrintKV("Sketch MD5", ESP.getSketchMD5());

	PrintKV("Reset reason", ESP.getResetReason());
	PrintKV("Reset Info", ESP.getResetInfo());

	rst_info *rstInfo = ESP.getResetInfoPtr();
	PrintKV("Reset DPEC", rstInfo->depc, HEX);
	PrintKV("Reset EPC1", rstInfo->epc1, HEX);
	PrintKV("Reset EPC2", rstInfo->epc2, HEX);
	PrintKV("Reset EPC3", rstInfo->epc3, HEX);
	PrintKV("Reset Cause", rstInfo->exccause, HEX);
	PrintKV("Reset Addr", rstInfo->excvaddr, HEX);
	PrintKV("Reset Reason", rstInfo->reason, HEX);
}


#endif // ABOUT_H
