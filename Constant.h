#ifndef CONSTANT_H
#define CONSTANT_H

#include <WString.h>

#define USE_CONSTANT_STRING

#ifdef USE_CONSTANT_STRING
extern "C" {
#include <include/wl_definitions.h>
}
#include <Esp.h>
#include <ESP8266WiFiType.h>
#include <user_interface.h>
#else
	// Saving real number string in return
	char valueNumber[12] = {0};
#endif
class Constant{

public:
	/**
	 * @brief toString
	 * @param flashMode
	 * @return const char *
	 * Description for enum FlashMode_t from <Esp.h>
	 */
	static const char *toString(const FlashMode_t flashMode){
		switch (flashMode){
			case FM_QIO: return "QIO";
			case FM_QOUT: return "QOUT";
			case FM_DIO: return "DIO";
			case FM_DOUT: return "DOUT";
			case FM_UNKNOWN:
			default: return "UNKNOWN";
		}
	}

	/**
	 * @brief toString
	 * @param value
	 * @return const char *
	 * Description for enum wl_status_t from <include/wl_definitions.h>
	 */
	static const char *toString(const wl_status_t value){
		switch(value){
			case WL_NO_SHIELD: return "WL_no_shield";
			case WL_IDLE_STATUS: return "WL_idle_status";
			case WL_NO_SSID_AVAIL: return "WL_no_ssid_available";
			case WL_SCAN_COMPLETED: return "WL_scan_completed";
			case WL_CONNECTED: return "WL_connected";
			case WL_CONNECT_FAILED: return "WL_connect_failed";
			case WL_CONNECTION_LOST: return "WL_connection_lost";
			case WL_DISCONNECTED: return "WL_disconnected";
			default: return "WL_unknown";
		}
	}

	static const char *toString(const wl_enc_type value){
		switch(value){
			case ENC_TYPE_WEP: return "ENC_type_WEP";
			case ENC_TYPE_TKIP: return "ENC_type_TKIP";
			case ENC_TYPE_CCMP: return "ENC_type_CCMP";
			case ENC_TYPE_NONE: return "ENC_type_NONE";
			case ENC_TYPE_AUTO: return "ENC_type_AUTO";
			default: return "ENC_type_unknown";
		}
	}

	static const char *toString(const wl_tcp_state value){
		switch(value){
			case CLOSED: return "TCP_state_closed";
			case LISTEN: return "TCP_state_listen";
			case SYN_SENT: return "TCP_state_syn_sent";
			case SYN_RCVD: return "TCP_state_syn_received";
			case ESTABLISHED: return "TCP_state_established";
			case FIN_WAIT_1: return "TCP_state_fin_wait_1";
			case FIN_WAIT_2: return "TCP_state_fin_wait_2";
			case CLOSE_WAIT: return "TCP_state_close_wait";
			case CLOSING: return "TCP_state_closing";
			case LAST_ACK: return "TCP_state_last_ack";
			case TIME_WAIT: return "TCP_state_time_wait";
			default: return "TCP_state_unknown";
		}
	}

	static const char *toString(const WiFiMode_t value){
		switch(value){
			case WIFI_OFF: return "WiFi_off";
			case WIFI_STA: return "WiFi_mode_STA";
			case WIFI_AP: return "WiFi_mode_AP";
			case WIFI_AP_STA: return "WiFi_mode_AP_STA";
			default: return "WiFi_mode_unknown";
		}
	}

	static const char *toString(const WiFiPhyMode_t value){
		switch(value){
			case WIFI_PHY_MODE_11B: return "WiFi_phy_mode_802.11B";
			case WIFI_PHY_MODE_11G: return "WiFi_phy_mode_802.11G";
			case WIFI_PHY_MODE_11N: return "WiFi_phy_mode_802.11N";
			default: return "WiFi_phy_mode_unknown";
		}
	}

	static const char *toString(const WiFiSleepType_t value){
		switch(value){
			case WIFI_NONE_SLEEP: return "WiFi_none_sleep";
			case WIFI_LIGHT_SLEEP: return "WiFi_light_sleep";
			case WIFI_MODEM_SLEEP: return "WiFi_modem_sleep";
			default: return "WiFi_sleep_unknwon";
		}
	}

	static const char *toString(const WiFiEvent value){
		switch(value){
			case WIFI_EVENT_STAMODE_CONNECTED: return "WiFi_event_STA_mode_connected";
			case WIFI_EVENT_STAMODE_DISCONNECTED: return "WiFi_event_STA_mode_disconnected";
			case WIFI_EVENT_STAMODE_AUTHMODE_CHANGE: return "WiFi_event_STA_mode_authorizing_mode_change";
			case WIFI_EVENT_STAMODE_GOT_IP: return "WiFi_event_STA_mode_got_IP";
			case WIFI_EVENT_STAMODE_DHCP_TIMEOUT: return "WiFi_event_STA_mode_DHCP_timeout";
			case WIFI_EVENT_SOFTAPMODE_STACONNECTED: return "WiFi_event_soft_AP_mode_STA_connected";
			case WIFI_EVENT_SOFTAPMODE_STADISCONNECTED: return "WiFi_event_soft_AP_mode_STA_disconnected";
			case WIFI_EVENT_SOFTAPMODE_PROBEREQRECVED: return "WiFi_event_soft_AP_mode_prober_equal_received";
			case WIFI_EVENT_MAX: return "WiFi_event_max";
			case WIFI_EVENT_MODE_CHANGE: return "WiFi_event_mode_change";
			default: return "WiFi_event_mode_unknown";
		}
	}

	static const char *toString(const WiFiDisconnectReason value){
		switch(value){
			case WIFI_DISCONNECT_REASON_UNSPECIFIED: return "WiFi_disconnect_reason_unspecified";
			case WIFI_DISCONNECT_REASON_AUTH_EXPIRE: return "WiFi_disconnect_reason_auth_expire";
			case WIFI_DISCONNECT_REASON_AUTH_LEAVE: return "WiFi_disconnect_reason_auth_leave";
			case WIFI_DISCONNECT_REASON_ASSOC_EXPIRE: return "WiFi_disconnect_reason_assoc_expire";
			case WIFI_DISCONNECT_REASON_ASSOC_TOOMANY: return "WiFi_disconnect_reason_assoc_too_many";
			case WIFI_DISCONNECT_REASON_NOT_AUTHED: return "WiFi_disconnect_reason_not_authed";
			case WIFI_DISCONNECT_REASON_NOT_ASSOCED: return "WiFi_disconnect_reason_not_assoced";
			case WIFI_DISCONNECT_REASON_ASSOC_LEAVE: return "WiFi_disconnect_reason_assoc_leave";
			case WIFI_DISCONNECT_REASON_ASSOC_NOT_AUTHED: return "WiFi_disconnect_reason_assoc_not_authed";
			case WIFI_DISCONNECT_REASON_DISASSOC_PWRCAP_BAD: return "WiFi_disconnect_reason_disassoc_pwrcap_bad";
			case WIFI_DISCONNECT_REASON_DISASSOC_SUPCHAN_BAD: return "WiFi_disconnect_reason_disassoc_supchan_bad";
			case WIFI_DISCONNECT_REASON_IE_INVALID: return "WiFi_disconnect_reason_ie_invalid";
			case WIFI_DISCONNECT_REASON_MIC_FAILURE: return "WiFi_disconnect_reason_mic_failure";
			case WIFI_DISCONNECT_REASON_4WAY_HANDSHAKE_TIMEOUT: return "WiFi_disconnect_reason_4_way_handshake_timeout";
			case WIFI_DISCONNECT_REASON_GROUP_KEY_UPDATE_TIMEOUT: return "WiFi_disconnect_reason_group_key_update_timeout";
			case WIFI_DISCONNECT_REASON_IE_IN_4WAY_DIFFERS: return "WiFi_disconnect_reason_ie_in_4_way_differs";
			case WIFI_DISCONNECT_REASON_GROUP_CIPHER_INVALID: return "WiFi_disconnect_reason_group_cipher_invalid";
			case WIFI_DISCONNECT_REASON_PAIRWISE_CIPHER_INVALID: return "WiFi_disconnect_reason_pairwise_cipher_invalid";
			case WIFI_DISCONNECT_REASON_AKMP_INVALID: return "WiFi_disconnect_reason_akmp_invalid";
			case WIFI_DISCONNECT_REASON_UNSUPP_RSN_IE_VERSION: return "WiFi_disconnect_reason_unsupp_rsn_ie_version";
			case WIFI_DISCONNECT_REASON_INVALID_RSN_IE_CAP: return "WiFi_disconnect_reason_invalid_rsn_ie_cap";
			case WIFI_DISCONNECT_REASON_802_1X_AUTH_FAILED: return "WiFi_disconnect_reason_802_1X_auth_failed";
			case WIFI_DISCONNECT_REASON_CIPHER_SUITE_REJECTED: return "WiFi_disconnect_reason_cipher_suite_rejected";
			case WIFI_DISCONNECT_REASON_BEACON_TIMEOUT: return "WiFi_disconnect_reason_beacon_timeout";
			case WIFI_DISCONNECT_REASON_NO_AP_FOUND: return "WiFi_disconnect_reason_no_ap_found";
			case WIFI_DISCONNECT_REASON_AUTH_FAIL: return "WiFi_disconnect_reason_auth_fail";
			case WIFI_DISCONNECT_REASON_ASSOC_FAIL: return "WiFi_disconnect_reason_assoc_fail";
			case WIFI_DISCONNECT_REASON_HANDSHAKE_TIMEOUT: return "WiFi_disconnect_reason_handshake_timeout";
			default: return "WiFi_disconnect_reason_unknown";
		}
	}

	static const char *toString(const rst_reason value){
		switch(value){
			case REASON_DEFAULT_RST: return "RESET_reason_default_reset";
			case REASON_WDT_RST: return "RESET_reason_hardware_watchdog_reset";
			case REASON_EXCEPTION_RST: return "RESET_reason_exception_reset";
			case REASON_SOFT_WDT_RST: return "RESET_reason_software_watchdog_reset";
			case REASON_SOFT_RESTART: return "RESET_reason_system_restart";
			case REASON_DEEP_SLEEP_AWAKE: return "RESET_reason_deep_sleep_awake";
			case REASON_EXT_SYS_RST: return "RESET_from_external_signal";
			default: return "RESET_unknown";
		}
	}

	static const char *toString(const flash_size_map value){
		switch(value){
			case FLASH_SIZE_4M_MAP_256_256: return "Flash 4Mbits, Map 256KBytes + 256KBytes";
			case FLASH_SIZE_2M: return "Flash 2Mbits, Map 256KBytes";
			case FLASH_SIZE_8M_MAP_512_512: return "Flash 8Mbits, Map: 512KBytes + 512KBytes";
			case FLASH_SIZE_16M_MAP_512_512: return "Flash 16MBits, Map: 512KBytes + 512KBytes";
			case FLASH_SIZE_32M_MAP_512_512: return "Flash 32MBits, Map: 512KBytes + 512KBytes";
			case FLASH_SIZE_16M_MAP_1024_1024: return "Flash 16MBits, Map: 1024KBytes + 1024KBytes";
			case FLASH_SIZE_32M_MAP_1024_1024: return "Flash 32MBits, Map: 1024KBytes + 1024KBytes";
			case FLASH_SIZE_64M_MAP_1024_1024: return "Flash 64MBits, Map: 1024KBytes + 1024KBytes";
			case FLASH_SIZE_128M_MAP_1024_1024: return "Flash 128MBits, Map: 1024KBytes + 1024KBytes";
			default: return "Flash and Map unknown";
		}
	}

	static const char *toString(const AUTH_MODE value){
		switch(value){
			case AUTH_OPEN: return "AUTH_OPEN";
			case AUTH_WEP: return "AUTH_WEP";
			case AUTH_WPA_PSK: return "AUTH_WPA_PSK";
			case AUTH_WPA2_PSK: return "AUTH_WPA2_PSK";
			case AUTH_WPA_WPA2_PSK: return "AUTH_WPA_WPA2_PSK";
			case AUTH_MAX: return "AUTH_MAX";
			default: return "AUTH_unknown";
		}
	}

	static const char *toString(const CIPHER_TYPE value){
		switch(value){
			case CIPHER_NONE: return "CIPHER_NONE";
			case CIPHER_WEP40: return "CIPHER_WEP40";
			case CIPHER_WEP104: return "CIPHER_WEP104";
			case CIPHER_TKIP: return "CIPHER_TKIP";
			case CIPHER_CCMP: return "CIPHER_CCMP";
			case CIPHER_TKIP_CCMP: return "CIPHER_TKIP_CCMP";
			case CIPHER_UNKNOWN:
			default: return "CIPHER_UNKNOWN";
		}
	}

	static const char *toString(const station_status_t value){
		switch(value){
			case STATION_IDLE: return "STATION_IDLE";
			case STATION_CONNECTING: return "STATION_CONNECTING";
			case STATION_WRONG_PASSWORD: return "STATION_WRONG_PASSWORD";
			case STATION_NO_AP_FOUND: return "STATION_NO_AP_FOUND";
			case STATION_CONNECT_FAIL: return "STATION_CONNECT_FAIL";
			case STATION_GOT_IP: return "STATION_GOT_IP";
			default: "STATION_unknown";
		}
	}

	static const char *toString(const dhcp_status value){
		switch(value){
			case DHCP_STOPPED: return "DHCP_STOPPED";
			case DHCP_STARTED: return "DHCP_STARTED";
			default: return "DHCP_unknown";
		}
	}

	static const char *toString(const dhcps_offer_option value){
		switch(value){
			case OFFER_START: return "OFFER_START";
			case OFFER_ROUTER: return "OFFER_ROUTER";
			case OFFER_END: return "OFFER_END";
			default: return "OFFER_unknown";
		}
	}

	static const char *toString(const phy_mode_t value){
		switch(value){
			case PHY_MODE_11B: return "PHY_MODE_11B";
			case PHY_MODE_11G: return "PHY_MODE_11G";
			case PHY_MODE_11N: return "PHY_MODE_11N";
			default: return "PHY_MODE_unknown";
		}
	}

	static const char *toString(const sleep_type_t value){
		switch(value){
			case NONE_SLEEP_T: return "NONE_SLEEP_T";
			case LIGHT_SLEEP_T: return "LIGHT_SLEEP_T";
			case MODEM_SLEEP_T: return "MODEM_SLEEP_T";
			default: return "SLEEP_TYPE_unknown";
		}
	}

#ifdef NONOSDK3V0
	static const char *toString(const sleep_level_t value){
		switch(value){
			case MIN_SLEEP_T: return "MIN_SLEEP_T";
			case MAX_SLEEP_T: return "MAX_SLEEP_T";
			default: return "SLEEP_LEVEL_unknown";
		}
	}
#endif

	static const char *toString(const WPS_TYPE_t value){
		switch(value){
			case WPS_TYPE_DISABLE: return "WPS_TYPE_DISABLE";
			case WPS_TYPE_PBC: return "WPS_TYPE_PBC";
			case WPS_TYPE_PIN: return "WPS_TYPE_PIN";
			case WPS_TYPE_DISPLAY: return "WPS_TYPE_DISPLAY";
			case WPS_TYPE_MAX: return "WPS_TYPE_MAX";
			default: return "WPS_TYPE_unknown";
		}
	}

	static const char *toString(const wps_cb_status value){
		switch(value){
			case WPS_CB_ST_SUCCESS: return "WPS_CB_ST_SUCCESS";
			case WPS_CB_ST_FAILED: return "WPS_CB_ST_FAILED";
			case WPS_CB_ST_TIMEOUT: return "WPS_CB_ST_TIMEOUT";
			case WPS_CB_ST_WEP: return "WPS_CB_ST_WEP";
			case WPS_CB_ST_UNK:
			default: return "WPS_CB_ST_UNK";
		}
	}

	static const char *toString(const FIXED_RATE value){
		switch(value){
			case PHY_RATE_48: return "PHY_RATE_48";
			case PHY_RATE_24: return "PHY_RATE_24";
			case PHY_RATE_12: return "PHY_RATE_12";
			case PHY_RATE_6: return "PHY_RATE_6";
			case PHY_RATE_54: return "PHY_RATE_54";
			case PHY_RATE_36: return "PHY_RATE_36";
			case PHY_RATE_18: return "PHY_RATE_18";
			case PHY_RATE_9: return "PHY_RATE_9";
			default: return "PHY_RATE_unknown";
		}
	}

	static const char *toString(const support_rate value){
		switch(value){
			case RATE_11B5M: return "RATE_11B5M";
			case RATE_11B11M: return "RATE_11B11M";
			case RATE_11B1M: return "RATE_11B1M";
			case RATE_11B2M: return "RATE_11B2M";
			case RATE_11G6M: return "RATE_11G6M";
			case RATE_11G12M: return "RATE_11G12M";
			case RATE_11G24M: return "RATE_11G24M";
			case RATE_11G48M: return "RATE_11G48M";
			case RATE_11G54M: return "RATE_11G54M";
			case RATE_11G9M: return "RATE_11G9M";
			case RATE_11G18M: return "RATE_11G18M";
			case RATE_11G36M: return "RATE_11G36M";
			default: return "RATE_unknown";
		}
	}

	static const char*toString(const WIFI_COUNTRY_POLICY value){
		switch(value){
			case WIFI_COUNTRY_POLICY_AUTO: return "WIFI_COUNTRY_POLICY_AUTO";
			case WIFI_COUNTRY_POLICY_MANUAL: return "WIFI_COUNTRY_POLICY_MANUAL";
			default: return "WIFI_COUNTRY_POLICY_unknown";
		}
	}

#ifndef USE_CONSTANT_STRING
	static const char *toString(int value, int base = 10){
		return itoa(value, valueNumber, base);
	}
#endif
};


#ifdef USE_CONSTANT_STRING
#	define CONSTANT(v) Constant::toString(v)
#else
#	define CONSTANT(v) Constant::toString((int)v)
#endif



#endif // CONSTANT_H
