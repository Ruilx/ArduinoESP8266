#ifndef CONSTANT_H
#define CONSTANT_H

#include <WString.h>

#define USE_CONSTANT_STRING

#ifdef USE_CONSTANT_STRING
extern "C" {
#include <include/wl_definitions.h>
}
#include <ESP8266WiFiType.h>
#else
	// Saving real number string in return
	char valueNumber[12] = {0};
#endif
class Constant{

public:
	/**
	 * @brief toString
	 * @param value
	 * @return
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
