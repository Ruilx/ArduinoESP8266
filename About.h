#ifndef ABOUT_H
#define ABOUT_H

#include <HardwareSerial.h>

/* Espressif ESP8266 GT-Clock
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

void banner(HardwareSerial *serial){
	if(serial == nullptr || !serial->availableForWrite()){
		return;
	}
	serial->println("    ______                               _ ____");
	serial->println("   / ____/________  ________  __________(_) __/");
	serial->println("  / __/ / ___/ __ \\/ ___/ _ \\/ ___/ ___/ / /_");
	serial->println(" / /___(__  ) /_/ / /  /  __(__  |__  ) / __/");
	serial->println("/_____/____/ .___/_/   \\___/____/____/_/_/");
	serial->println("          /_/                  * GT-Clock 8266");
}

void gtClockBanner(HardwareSerial *serial){
	if(serial == nullptr || !serial->availableForWrite()){
		return;
	}
	Serial.println("  ____ _____      ____ _            _");
	Serial.println(" / ___|_   _|    / ___| | ___   ___| | __");
	Serial.println("| |  _  | |_____| |   | |/ _ \\ / __| |/ /");
	Serial.println("| |_| | | |_____| |___| | (_) | (__|   <");
	Serial.println(" \\____| |_|      \\____|_|\\___/ \\___|_|\\_\\");
	Serial.println();
}

void chipInfo(HardwareSerial *serial){
	if(serial == nullptr || !serial->availableForWrite()){
		return;
	}
	serial->println("======== ESP8266 Chip ========");
	uint32_t chipId = ESP.getChipId();
	Serial.print("CHIP ID: ");
	Serial.println(chipId, HEX);
	const char *sdkVer = ESP.getSdkVersion();
	Serial.print("SDK VER: ");
	Serial.println(sdkVer);
	String coreVersion = ESP.getCoreVersion();
	Serial.print("CORE VER: ");
	Serial.println(coreVersion);
	String fullVersion = ESP.getFullVersion();
	Serial.print("FULL VER: ");
	Serial.println(fullVersion);
	uint8_t bootVersion = ESP.getBootVersion();
	Serial.print("BOOT VER: ");
	Serial.println(bootVersion);
	uint8_t bootMode = ESP.getBootMode();
	Serial.print("BOOT MODE: ");
	Serial.println(bootMode);
	uint8_t cpuFreqMhz = ESP.getCpuFreqMHz();
	Serial.print("CPU FREQ: ");
	Serial.print(cpuFreqMhz);
	Serial.println("Mhz");
	uint32_t flashChipId = ESP.getFlashChipId();
	Serial.print("FLASH CHIP ID: ");
	Serial.println(flashChipId, HEX);
	uint8_t flashChipVendorId = ESP.getFlashChipVendorId();
	Serial.print("FLASH CHIP VENDOR ID: ");
	Serial.println(flashChipVendorId, HEX);
	uint32_t flashChipRealSize = ESP.getFlashChipRealSize();
	Serial.print("FLASH CHIP REAL SIZE: ");
	Serial.println(flashChipRealSize);
	uint32_t flashChipSize = ESP.getFlashChipSize();
	Serial.print("FLASH CHIP SIZE: ");
	Serial.println(flashChipSize);
	uint32_t flashChipSpeed = ESP.getFlashChipSpeed();
	Serial.print("FLASH CHIP SPEED: ");
	Serial.println(flashChipSpeed);
	FlashMode_t flashChipMode = ESP.getFlashChipMode();
	Serial.print("FLASH CHIP MODE: ");
	switch (flashChipMode){
		case FM_QIO: Serial.println("QIO"); break;
		case FM_QOUT: Serial.println("QOUT"); break;
		case FM_DIO: Serial.println("DIO"); break;
		case FM_DOUT: Serial.println("DOUT"); break;
		case FM_UNKNOWN: Serial.println("UNKNOWN"); break;
		default: Serial.println("NOT IN LIST");
	}

	uint32_t sketchSize = ESP.getSketchSize();
	Serial.print("SKETCH SIZE: ");
	Serial.println(sketchSize);
	String sketchMd5 = ESP.getSketchMD5();
	Serial.print("SKETCH MD5: ");
	Serial.println(sketchMd5);

	String resetReason = ESP.getResetReason();
	Serial.print("RESET REASON: ");
	Serial.println(resetReason);
	String resetInfo = ESP.getResetInfo();
	Serial.print("RESET INFO: ");
	Serial.println(resetInfo);

	rst_info *rstInfo = ESP.getResetInfoPtr();
	Serial.print("RESET INFO -> DPEC: 0x");
	Serial.println(rstInfo->depc, HEX);
	Serial.print("RESET INFO -> EPC1: 0x");
	Serial.println(rstInfo->epc1, HEX);
	Serial.print("RESET INFO -> EPC2: 0x");
	Serial.println(rstInfo->epc2, HEX);
	Serial.print("RESET INFO -> EPC3: 0x");
	Serial.println(rstInfo->epc3, HEX);
	Serial.print("RESET INFO -> EXCAUSE: 0x");
	Serial.println(rstInfo->exccause, HEX);
	Serial.print("RESET INFO -> EXCVADDR: 0x");
	Serial.println(rstInfo->excvaddr, HEX);
	Serial.print("RESET INFO -> REASON: ");
	Serial.println(rstInfo->reason);
}


#endif // ABOUT_H
