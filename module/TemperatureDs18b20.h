#ifndef TEMPERATUREDS18B20_H
#define TEMPERATUREDS18B20_H

#include <DallasTemperature.h>
#include "../GpioDefine.h"

class TemperatureDS18B20
{
	OneWire ds18b20Data;
	DallasTemperature ds18b20;

	uint8_t numOfSensors = 0;

public:
	TemperatureDS18B20(Pin data, uint8_t resolution = 9){
		this->ds18b20Data.begin(data);
		this->ds18b20.setOneWire(&this->ds18b20Data);
		this->ds18b20.begin();
		this->numOfSensors = this->ds18b20.getDS18Count();
		uint8_t maxResolution = this->ds18b20.getResolution();
		this->ds18b20.setResolution(min(resolution, maxResolution));
	}

	uint8_t getNumOfSensors() const{
		return this->numOfSensors;
	}

	void setResolution(DeviceAddress address, uint8 resolution){
		this->ds18b20.setResolution(address, resolution);
	}

	void getAddress(uint8_t no, uint8_t* address){
		this->ds18b20.getAddress(address, no);
	}

	uint16_t getUserData(DeviceAddress address, bool *ok = nullptr){
		if(ok) *ok = false;
		if(address == nullptr){
			return 0;
		}
		uint16_t userData = this->ds18b20.getUserData(address);
		if(userData != 0){
			if(ok) *ok = true;
			return userData;
		}
		return 0;
	}

	bool startTemperatureConversion(DeviceAddress address){
		return this->ds18b20.requestTemperaturesByAddress(address);
	}

	int16_t getTemperature(DeviceAddress address, bool *ok = nullptr){
		if(ok) *ok = false;
		if(address == nullptr){
			return 0;
		}
		uint16_t temperature = this->ds18b20.getTemp(address);
		if(temperature != DEVICE_DISCONNECTED_RAW){
			if(ok) *ok = true;
			return temperature;
		}
		return 0;
	}

	float getCelsiusTemperature(DeviceAddress address, bool *ok = nullptr){
		bool _ok = false;
		uint16_t raw = this->getTemperature(address, &_ok);
		if(ok) *ok = _ok;
		if(!_ok){
			return 0;
		}
		return (float) raw * 0.0078125;
	}

	float getFahrenheitTemperature(DeviceAddress address, bool *ok = nullptr){
		bool _ok = false;
		uint16_t raw = this->getTemperature(address, &_ok);
		if(ok) *ok = _ok;
		if(!_ok){
			return 0;
		}
		return ((float) raw * 0.0140625) + 32;
	}
};

#endif // TEMPERATUREDS18B20_H
