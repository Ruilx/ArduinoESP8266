#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <WString.h>

#include "Define.h"

enum RtcDevice{
	RtcDevice_DS3231 = 0,
	RtcDevice_STM32 = 1,
};

enum Fontface{
	Font_Unknown = 0,
	Font_RProBold = 1,
	Font_RBold = 2,
	Font_RBoldSerif = 3,
	Font_RCBold = 4,
	Font_RStd = 5,
	Font_RuilxFixedSys = 6,
	Font_RHSans = 7,
	Font_CasioLCD = 8,
	Font_Minecraftia = 9,
	Font_RSans = 10,
	Font_R4511 = 11,
	Font_RSansPro = 12,
	Font_RPro = 13,
	Font_OCRA = 14,
	Font_RHand = 15,
	Font_RSMG = 16,
	Font_RSMGBold = 17,
	Font_RKanji = 18,
	Font_RKanjiPro = 19,
	Font_RHalfBold = 20,
	Font_RLSD = 21,
	Font_RBlock = 22,
	Font_RSmall = 23,
	Font_RSidy = 24,
	Font_RShiftSym = 25,
	Font_RSq = 26,
	Font_RSqPro = 27,
	Font_RSqStd = 28,
	Font_RSqSerif = 29,
	Font_Georgia = 30,
	Font_R6H = 31,
	Font_Simsun = 32,
	Font_Commodore64 = 33,
	Font_NesPixel = 34,
	Font_Devanagari = 35,
	Font_Arabic = 36,
	Font_Minecraft = 37,
	Font_RSq6H = 38,

	Font_KanaU3041U30FF = 64,
	Font_Kana = Font_KanaU3041U30FF,

	Font_SmallNumber = 70,
	Font_MidNumber = 71,
};

enum TimeStyle{
	TimeStyle_HoursMinutesAndSmallSeconds24H = 1,
	TimeStyle_HoursMinutesAndSmallSeconds12H = 2,
	TimeStyle_HoursMinutes12HWithSign = 3,
	TimeStyle_HoursMinutesAndBigSeconds24H = 4,
	TimeStyle_HoursMinutesAndMiddleSeconds24H = 5,
	TimeStyle_HoursAndMinutes24H = 6,
	TimeStyle_HoursAndMinutesNesPixel24H = 7,
	TimeStyle_HoursAndMinutesNesPixel12HWithSign = 8,
	TimeStyle_HoursAndMinutesCommodore6424H = 9,
	TimeStyle_HoursAndMinutesCommodore6412HWithSign = 10,
	TimeStyle_HoursMinutesAndSmallSecondsCommodore6424H = 11,
};

/**
 * @brief The TimeAlign enum
 * 7-height time align style
 * +--------------+--------------+
 * | ....##...... | ............ |
 * | ..##..##.... | ....##...... |
 * | ##......##.. | ..##..##.... |
 * | ##......##.. | ##......##.. |
 * | ##########.. | ##......##.. |
 * | ##......##.. | ##########.. |
 * | ##......##.. | ##......##.. |
 * | ............ | ##......##.. |
 * +--------------+--------------+
 * |  Align_Top   | Align_Bottom |
 * +--------------+--------------+
 */
enum TimeAlign{
	TimeAlign_Top = 0,
	TImeAlign_Bottom = 1,
};

/**
 * @brief The DateFormat enum
 * DateFormat Description
 *
 * Format:
 * YYYY : Full numeric year.  eg: 2019
 * YY   : Abbr numeric year.  eg: 19
 * MMM  : Abbr letter month.  eg: Dec
 * MM   : Full numeric month. eg: 12
 * DD   : Full numeric day.   eg: 31
 * KYYYY: Full kanji year.    eg: 二〇一九
 * KYY  : Offsetting kanji year: eg: 元
 * KMM  : Kanji month.        eg: 十二
 * KDD  : Kanji date.         eg: 三十一
 * EEE  : Japanese eras Kanji. eg: 令和
 * EE   : Japanese eras Kana. eg: れいわ
 * E    : Japanese eras abbreviation. eg: R
 *
 * Spliter Symbol:
 * m: minus symbol '-'
 * s: slash symbol '/'
 * d: dot symbol   '.'
 * c: comma symbol ','
 * k: kanji unit symbol '年'/'月'/'日'
 */
enum DateFormat{
	DateFormat_YYYY_m_MM_m_DD = 1,       // 2019-12-31
	DateFormat_YY_m_MM_m_DD = 2,         // 19-12-31
	DateFormat_YYYY_s_MM_s_DD = 3,       // 2019/12/31
	DateFormat_YY_s_MM_s_SS = 4,         // 19/12/31
	DateFormat_DD_s_MM_s_YYYY = 5,       // 31/12/2019
	DateFormat_DD_s_MM_s_YY = 6,         // 31/12/19
	DateFormat_MM_s_DD_s_YYYY = 7,       // 12/31/2019
	DateFormat_MM_s_DD_s_YY = 8,         // 12/31/19
	DateFormat_MMM_d_DD_c_YYYY = 9,      // Dec. 31, 2019
	DateFormat_DD_MMM_c_YYYY = 10,       // 31 Dec, 2019
	DateFormat_YYYY_k_MM_k_DD_k = 11,    // 2019年12月31日
	DateFormat_KYYYY_k_KMM_k_KDD_k = 12, // 二〇一九年十二月三十一日
	DateFormat_EEEKYY_k_MM_k_DD_k = 13,  // 令和元年12月31日
	DateFormat_EEYY_k_MM_k_DD_k = 14,    // れいわ1年12月31日
	DateFormat_EYY_d_MM_d_dd = 15,       // R1.12.31
};

enum WeekFormat{
	WeekFormat_Abbr = 1,     // Sun. Mon. Tue. ...
	WeekFormat_Normal = 2,   // Sunday Monday ...
	WeekFormat_Chinese = 3,  // 周日 周一 ...
	WeekFormat_Kanji = 4,    // 日 月 火 ...
};

enum WeekPosition{
	// Tuesday Dec. 31, 2019
	WeekPosition_BeforeDate = 1,
	// Dec. 31, 2019 Tuesday
	WeekPosition_AfterDate = 2,
};

enum TempDevice{
	TempDevice_DS3231 = 0,
	TempDevice_DS18B20 = 1,
	TempDevice_STM32 = 2,
};

enum TempUnit{
	TempUnit_Celsius = 0,
	TempUnit_Fahrenheit = 1,
	TempUnit_Kelvin = 2,
	TempUnit_Column = 3,
};

enum TempSchedule{
	TempSchedule_NoSchedule = 0,
	TempSchedule_EveryHour = 1,
	TempSchedule_8Everyday = 2,
	TempSchedule_8_16Everyday = 3,
};

enum HourlyReminding{
	HourlyReminding_Mute = 0,
	HourlyReminding_Beep = 1,
};

typedef struct Config_t {
	struct tm dateTime1;
	DateTime datetime;
	uint8_t wifiConnected = 0;
	uint8_t internetConnected = 0;
	uint8_t autoSNTP = 0;
	int8_t  utcHourAdj = 0;
	uint8_t utcMinuteAdj = 0;
	int8_t  summerTimeAdj = 0;
	String  p1TimeServer;
	String  p2TimeServer;
	RtcDevice rtcDevice = RtcDevice::RtcDevice_DS3231;

	Fontface timeFont = Fontface::Font_RuilxFixedSys;
	TimeStyle timeStyle = TimeStyle::TimeStyle_HoursMinutesAndSmallSeconds24H;
	TimeAlign timeAlignment = TimeAlign::TimeAlign_Top;
	bool hour2Digit = true;

	Fontface normalFont = Fontface::Font_RuilxFixedSys;

	DateFormat dateFormat = DateFormat::DateFormat_YYYY_m_MM_m_DD;
	bool monthDay2Digit = true;

	WeekFormat weekFormat = WeekFormat::WeekFormat_Normal;
	WeekPosition weekPosition = WeekPosition::WeekPosition_AfterDate;

	TempDevice tempDevice = TempDevice::TempDevice_DS18B20;
	TempUnit tempUnit = TempUnit::TempUnit_Celsius;
	TempSchedule tempSchedule = TempSchedule::TempSchedule_NoSchedule;

	HourlyReminding hourlyReminding = HourlyReminding::HourlyReminding_Mute;

	bool slientAtNight = true;
	uint32_t slientFlag = 0xFFFFFF;

	bool automaticBrightness = false;
	uint8_t brightness = 0xFF;
	uint8_t brightnessAdjust = 0x00;

	bool automaticOrientation = false;
	uint8_t orientation = 1;

	String ssid;
	String password;
	String dns;

	float rtcCali;
} Config;

Config config;


#endif // CONFIG_H
