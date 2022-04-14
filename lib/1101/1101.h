#ifndef H_1101
#define H_1101

#include "1101regs.h"
#include "1101table.h"
/*
 * Part of CC1101 library, main header.
 *
 * Copyright 2021 Mikhail Belkin <dltech174@gmail.com>
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
 */

/*** complete config ***/
#define IOCFG2_CONF     GDO_CFG_HIGH_IMPEDANCE
#define IOCFG1_CONF     GDO_CFG_HIGH_IMPEDANCE
#define IOCFG0_CONF     TEMP_SENSOR_ENABLE | GDO_CFG_HIGH_IMPEDANCE
#define FIFOTHR_CONF    CLOSE_IN_RX_0DB | FIFO_THR_TX29
#define SYNC1_CONF      0xad
#define SYNC0_CONF      0xed
#define PKTLEN_CONF     64
#define PKTCTRL1_CONF   (4 << PQT_OFFS) | CRC_AUTOFLUSH | ADR_CHK_FF_BROADCAST
#define PKTCTRL0_CONF   PKT_FORMAT_NORMAL | CRC_EN | LENGTH_CONFIG_FIXED
#define ADDR_CONF       5
#define CHANNR_CONF     0
#define FSCTRL1_CONF    FSCTRL1_CALCULATED
#define FSCTRL0_CONF    FSCTRL0_CALCULATED
#define FREQ2_CONF      FREQ2_CALCULATED
#define FREQ1_CONF      FREQ1_CALCULATED
#define FREQ0_CONF      FREQ0_CALCULATED
#define MDMCFG4_CONF    MDMCFG4_CALCULATED
#define MDMCFG3_CONF    MDMCFG3_CALCULATED
#define MDMCFG2_CONF    MOD_FORMAT_4FSK | SYNC_MODE_30_32SYNC
#define MDMCFG1_CONF    NUM_PREAMBLE3 | MDMCFG1_CALCULATED
#define MDMCFG0_CONF    MDMCFG0_CALCULATED
#define DEVIATN_CONF    DEVIATN_CALCULATED

#define MCSM2_CONF
#define MCSM1_CONF
#define MCSM0_CONF

#define FOCCFG_CONF

#define BSCFG_CONF

#define AGCTRL2_CONF
#define AGCTRL1_CONF
#define AGCTRL0_CONF
// default values
#define WOREVT1_CONF    0x87
#define WOREVT0_CONF    0x6b
#define WORCTRL_CONF    0xfb
// obtained from smartRF
#define FREND1_CONF     LNA_CURRENT1 | LNA2MIX_CURRENT1 | LODIV_BUF_CURRENT_RX1 | MIX_CURRENT2
#define FREND0_CONF     0x10
#define FSCAL3_CONF     0xea
#define FSCAL2_CONF     0x2a
#define FSCAL1_CONF     0x00
#define FSCAL0_CONF     0x1f
#define RCCTRL1_CONF    0x41
#define RCCTRL0_CONF    0x00

/* pin settings */
#define NSS_1101    GPIO1
#define SCLK_1101   GPIO2
#define MOSI_1101   GPIO3
#define GD0_1101    GPIO4

/* fast mode switch options */
enum {
    SPWD = 11,  // power down
    STX,        // go to tx state
    SIDLE,      // go to idle state
    SRX,        // go to RX state
    SRES        // reset command strobe
};

void strobeCtrl(int parameter);
void strobeCmd(uint8_t cmd);


const struct parameters{
    const int strobeApplyUs = 60;
    const int strobeTactUs = 10;
} param1101;

#endif
