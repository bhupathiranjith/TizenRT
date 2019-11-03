/******************************************************************************
 * Copyright (c) 2013-2016 Realtek Semiconductor Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/
#ifndef __HAL_PHY_H__
#define __HAL_PHY_H__

#define RF6052_MAX_TX_PWR 0x3F
#define RF6052_MAX_REG_88E 0xFF
#define RF6052_MAX_REG_92C 0x7F

#define RF6052_MAX_REG \
	(RF6052_MAX_REG_88E > RF6052_MAX_REG_92C) ? RF6052_MAX_REG_88E : RF6052_MAX_REG_92C

#define GET_RF6052_REAL_MAX_REG(_Adapter) \
	IS_HARDWARE_TYPE_8188E(_Adapter) ? RF6052_MAX_REG_88E : RF6052_MAX_REG_92C

#define RF6052_MAX_PATH 2

/*--------------------------Define Parameters-------------------------------*/
typedef enum _BAND_TYPE {
	BAND_ON_2_4G = 0,
	BAND_ON_5G,
	BAND_ON_BOTH,
	BANDMAX
} BAND_TYPE,
	*PBAND_TYPE;

typedef enum _RF_TYPE {
	RF_TYPE_MIN = 0,   // 0
	RF_8225 = 1,	   // 1 11b/g RF for verification only
	RF_8256 = 2,	   // 2 11b/g/n
	RF_8258 = 3,	   // 3 11a/b/g/n RF
	RF_6052 = 4,	   // 4 11b/g/n RF
	RF_PSEUDO_11N = 5, // 5, It is a temporality RF.
	RF_CHIP_MAX
} RF_TYPE_E,
	*PRF_TYPE_E;

#define TX_1S 0
#define TX_2S 1
#define TX_3S 2
#define TX_4S 3

typedef enum _BaseBand_Config_Type {
	BaseBand_Config_PHY_REG = 0, //Radio Path A
	BaseBand_Config_AGC_TAB = 1, //Radio Path B
	BaseBand_Config_AGC_TAB_2G = 2,
	BaseBand_Config_AGC_TAB_5G = 3,
	BaseBand_Config_PHY_REG_PG
} BaseBand_Config_Type,
	*PBaseBand_Config_Type;

typedef enum _WIRELESS_MODE {
	WIRELESS_MODE_UNKNOWN = 0x00,
	WIRELESS_MODE_A = 0x01,
	WIRELESS_MODE_B = 0x02,
	WIRELESS_MODE_G = 0x04,
	WIRELESS_MODE_AUTO = 0x08,
	WIRELESS_MODE_N_24G = 0x10,
	WIRELESS_MODE_N_5G = 0x20,
	WIRELESS_MODE_AC_5G = 0x40,
	WIRELESS_MODE_AC_24G = 0x80,
	WIRELESS_MODE_AC_ONLY = 0x100,
} WIRELESS_MODE;

typedef struct RF_Shadow_Compare_Map {
	// Shadow register value
	u32 Value;
	// Compare or not flag
	u8 Compare;
	// Record If it had ever modified unpredicted
	u8 ErrorOrNot;
	// Recorver Flag
	u8 Recorver;
	//
	u8 Driver_Write;
} RF_SHADOW_T;

typedef struct _R_ANTENNA_SELECT_OFDM {
	u32 r_tx_antenna:4;
	u32 r_ant_l:4;
	u32 r_ant_non_ht:4;
	u32 r_ant_ht1:4;
	u32 r_ant_ht2:4;
	u32 r_ant_ht_s1:4;
	u32 r_ant_non_ht_s1:4;
	u32 OFDM_TXSC:2;
	u32 Reserved:2;
} R_ANTENNA_SELECT_OFDM;

typedef struct _R_ANTENNA_SELECT_CCK {
	u8 r_cckrx_enable_2:2;
	u8 r_cckrx_enable:2;
	u8 r_ccktx_enable:4;
} R_ANTENNA_SELECT_CCK;

#endif //__HAL_PHY_H__
