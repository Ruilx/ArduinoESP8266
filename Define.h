#ifndef DEFINE_H
#define DEFINE_H

#include <stdint.h>

typedef struct DateTime_t {
	uint16_t year;
	uint8_t  month;
	uint8_t  day;
	uint8_t  week;
	uint8_t  hour;
	uint8_t  minute;
	uint8_t  second;
} DateTime;

#endif // DEFINE_H
