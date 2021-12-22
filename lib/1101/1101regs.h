#ifndef H_1101_REGS
#define H_1101_REGS
/*
 * Part of CC1101 library, register definitions.
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

// crystal oscillator frequency in MHz
#define XOSC        26000000
// coefficients for parameters calculation
#define OFFS_COEF       XOSC/16384
#define CARRIER_COEF    XOSC/65536

/************************* Register definitions *******************************/

/* GDO2 output pin configuration */
#define IOCFG2          0x00
// Invert output, i.e. select active low
#define GDO2_INV                    0x40
// pin assignment
#define GDO_CFG_RX_FIFO_HALF        0x00
#define GDO_CFG_RX_FIFO_HALF_EMPTY  0x01
#define GDO_CFG_TX_FIFO_HALF        0x02
#define GDO_CFG_TX_FIFO_HALF_FULL   0x03
#define GDO_CFG_RX_FIFO_FULL        0x04
#define GDO_CFG_TX_FIFO_EMPTY       0x05
#define GDO_CFG_SYNC_WORD           0x06
#define GDO_CFG_RX_PACK             0x07
#define GDO_CFG_PREAMPLE_OK         0x08
#define GDO_CFG_CLEAR_CHANNEL       0x09
#define GDO_CFG_PLL_LOCK            0x0a
#define GDO_CFG_SERIAL_CLOCK        0x0b
#define GDO_CFG_SERIAL_INPUT        0x0c
#define GDO_CFG_SERIAL_OUTPUT       0x0d
#define GDO_CFG_CARRIER_SENSE       0x0e
#define GDO_CFG_CRC_OK              0x0f
#define GDO_CFG_RX_HARD_DATA1       0x16
#define GDO_CFG_RX_HARD_DATA0       0x17
#define GDO_CFG_PA_PD               0x1b
#define GDO_CFG_LNA_PD              0x1c
#define GDO_CFG_RX_SYMBOL_TICK      0x1d
#define GDO_CFG_WOR_EVNT0           0x24
#define GDO_CFG_WOR_EVNT1           0x25
#define GDO_CFG_CLK_256             0x26
#define GDO_CFG_CLK_32K             0x27
#define GDO_CFG_CHIP_RDYN           0x29
#define GDO_CFG_XOSC_STABLE         0x2b
#define GDO_CFG_HIGH_IMPEDANCE      0x2e
#define GDO_CFG_HW_RX_TX_SW         0x2f
#define GDO_CFG_CLK_XOSC_DIV1       0x30
#define GDO_CFG_CLK_XOSC_DIV1P5     0x31
#define GDO_CFG_CLK_XOSC_DIV2       0x32
#define GDO_CFG_CLK_XOSC_DIV3       0x33
#define GDO_CFG_CLK_XOSC_DIV4       0x34
#define GDO_CFG_CLK_XOSC_DIV6       0x35
#define GDO_CFG_CLK_XOSC_DIV8       0x36
#define GDO_CFG_CLK_XOSC_DIV12      0x37
#define GDO_CFG_CLK_XOSC_DIV16      0x38
#define GDO_CFG_CLK_XOSC_DIV24      0x39
#define GDO_CFG_CLK_XOSC_DIV32      0x3a
#define GDO_CFG_CLK_XOSC_DIV48      0x3b
#define GDO_CFG_CLK_XOSC_DIV64      0x3c
#define GDO_CFG_CLK_XOSC_DIV96      0x3d
#define GDO_CFG_CLK_XOSC_DIV128     0x3e
#define GDO_CFG_CLK_XOSC_DIV192     0x3f

/* GDO1 output pin configuration */
#define IOCFG1          0x01
// Set high (1) or low (0) output drive strength on the GDO pins.
#define GDO_DS                      0x80
// Invert output, i.e. select active low
#define GDO1_INV                    0x40

/* GDO0 output pin configuration */
#define IOCFG0          0x02
// Enable analog temperature sensor.
#define TEMP_SENSOR_ENABLE          0x80
// Invert output, i.e. select active low
#define GDO0_INV                    0x40

/* RX FIFO and TX FIFO thresholds */
#define FIFOTHR         0x03
#define ADC_RETENTION    0x40
// RX Attenuation
#define CLOSE_IN_RX_0DB  0x00
#define CLOSE_IN_RX_6DB  0x10
#define CLOSE_IN_RX_12DB 0x20
#define CLOSE_IN_RX_18DB 0x30
// Set the threshold for the TX FIFO and RX FIFO.
#define FIFO_THR_TX61    0x00
#define FIFO_THR_TX57    0x01
#define FIFO_THR_TX53    0x02
#define FIFO_THR_TX49    0x03
#define FIFO_THR_TX45    0x04
#define FIFO_THR_TX41    0x05
#define FIFO_THR_TX37    0x06
#define FIFO_THR_TX33    0x07
#define FIFO_THR_TX29    0x08
#define FIFO_THR_TX25    0x09
#define FIFO_THR_TX21    0x0a
#define FIFO_THR_TX17    0x0b
#define FIFO_THR_TX13    0x0c
#define FIFO_THR_TX9     0x0d
#define FIFO_THR_TX5     0x0e
#define FIFO_THR_TX1     0x0f
#define FIFO_THR_RX4     0x00
#define FIFO_THR_RX8     0x01
#define FIFO_THR_RX12    0x02
#define FIFO_THR_RX16    0x03
#define FIFO_THR_RX20    0x04
#define FIFO_THR_RX24    0x05
#define FIFO_THR_RX28    0x06
#define FIFO_THR_RX32    0x07
#define FIFO_THR_RX36    0x08
#define FIFO_THR_RX40    0x09
#define FIFO_THR_RX44    0x0a
#define FIFO_THR_RX48    0x0b
#define FIFO_THR_RX52    0x0c
#define FIFO_THR_RX56    0x0d
#define FIFO_THR_RX60    0x0e
#define FIFO_THR_RX64    0x0f

/* Sync word, high byte */
#define SYNC1           0x04
/* Sync word, low byte */
#define SYNC0           0x05

/* Packet length */
#define PKTLEN          0x06

/* Packet automation control reg1 */
#define PKTCTRL1        0x07
// Preamble quality estimator threshold.
#define PQT_OFFS        5
// Enable automatic flush of RX FIFO when CRC is not OK.
#define CRC_AUTOFLUSH   0x08
// When enabled, two status bytes will be appended to the payload of the packet.
#define APPEND_STATUS   0x04
// Controls address check configuration of received packages.
#define ADR_CHK_NO              0x00
#define ADR_CHK_NO_BROADCAST    0x01
#define ADR_CHK_0_BROADCAST     0x02
#define ADR_CHK_FF_BROADCAST    0x03

/* Packet automation control reg2 */
#define PKTCTRL0        0x08
// Turn data whitening on / off
#define WHITE_DATA              0x40
// Format of RX and TX data
#define PKT_FORMAT_NORMAL       0x00
#define PKT_FORMAT_SYNC_SERIAL  0x10
#define PKT_FORMAT_RANDOM_TX    0x20
#define PKT_FORMAT_ASYNC_SERIAL 0x30
// CRC calculation in TX and CRC check in RX enabled
#define CRC_EN                  0x04
// Configure the packet length
#define LENGTH_CONFIG_FIXED     0x00
#define LENGTH_CONFIG_VARIABLE  0x01
#define LENGTH_CONFIG_INFINITE  0x02

/* Device address */
#define ADDR            0x09

/* Channel number */
#define CHANNR          0x0a
// The 8-bit unsigned channel number

/* Frequency synthesizer control reg1 */
#define FSCTRL1         0x0b
// The desired IF frequency to employ in RX.
#define FREQ_IF(rx_if)  ((uint8_t)((((uint32_t)rx_if)*1024)/XOSC))

/* Frequency synthesizer control reg0 */
#define FSCTRL0         0x0c
// Frequency offset (2s-complement).
#define FREQOFFP(freq) ((uint8_t)(0x7f&(freq/OFFS_COEF)))
#define FREQOFFN(freq) ((uint8_t)(0x80|(~(freq/OFFS_COEF))))

/* Frequency control word, high byte */
#define FREQ2           0x0d
// carrier frequency
#define FREQ2_CALC(carrier)  (0x3f&((carrier/CARRIER_COEF)>>16))
/* Frequency control word, middle byte */
#define FREQ1           0x0e
#define FREQ1_CALC(carrier)  (0xff&((carrier/CARRIER_COEF)>>8))
/* Frequency control word, low byte */
#define FREQ0           0x0f
#define FREQ0_CALC(carrier)  (0xff&(carrier/CARRIER_COEF))

/* Modem configuration reg4 */
#define MDMCFG4         0x10
// Sets the decimation ratio for the delta-sigma ADC input.
#define CHANBW812K  0x00
#define CHANBW650K  0x10
#define CHANBW542K  0x20
#define CHANBW464K  0x30
#define CHANBW406K  0x40
#define CHANBW325K  0x50
#define CHANBW271K  0x60
#define CHANBW232K  0x70
#define CHANBW203K  0x80
#define CHANBW162K  0x90
#define CHANBW135K  0xa0
#define CHANBW116K  0xb0
#define CHANBW102K  0xc0
#define CHANBW81K   0xd0
#define CHANBW68K   0xe0
#define CHANBW58K   0xf0
// The exponent of the user specified symbol rate

/* Modem configuration reg3 */
#define MDMCFG3         0x11
// The mantissa of the user specified symbol rate.

/* Modem configuration reg2 */
#define MDMCFG2         0x12
// Disable digital DC blocking filter before demodulator.
#define DEM_DCFILT_OFF              0x80
// The modulation format of the radio signal
#define MOD_FORMAT_2FSK             0x00
#define MOD_FORMAT_GFSK             0x10
#define MOD_FORMAT_OOK              0x30
#define MOD_FORMAT_4FSK             0x40
#define MOD_FORMAT_MSK              0x70
// Enables Manchester encoding/decoding.
#define MANCHESTER_EN               0x08
// Combined sync-word qualifier mode.
#define SYNC_MODE_NO                0x00
#define SYNC_MODE_15_16SYNC         0x01
#define SYNC_MODE_16_16SYNC         0x02
#define SYNC_MODE_30_32SYNC         0x03
#define SYNC_MODE_NO_SYNC_CARRIRER  0x04
#define SYNC_MODE_15_16SYNC_CARRIER 0x05
#define SYNC_MODE_16_16SYNC_CARRIER 0x06
#define SYNC_MODE_30_32SYNC_CARRIER 0x07

/* Modem configuration reg1 */
#define MDMCFG1         0x13
// Enable Forward Error Correction
#define FEC_EN          0x80
// Sets the minimum number of preamble bytes to be transmitted
#define NUM_PREAMBLE2   0x00
#define NUM_PREAMBLE3   0x10
#define NUM_PREAMBLE4   0x20
#define NUM_PREAMBLE6   0x30
#define NUM_PREAMBLE8   0x40
#define NUM_PREAMBLE12  0x50
#define NUM_PREAMBLE16  0x60
#define NUM_PREAMBLE24  0x70
// 2 bit exponent of channel spacing

/* Modem configuration reg0 */
#define MDMCFG0         0x14
// 8-bit mantissa of channel spacing.

/* Modem deviation setting */
#define DEVIATN         0x15
// Deviation exponent.
// Mantissa of the nominal frequency deviation

/* Main Radio Control State Machine configuration reg2 */
#define MCSM2           0x16
// RX termination based on RSSI measurement for ASK/OOK.
#define RX_TIME_RSSI    0x10
// check sync only or PQI and sync word
#define RX_TIME_QUAL    0x08
// Timeout for sync word search in RX.
#define RX_TIME3P61     0x00
#define RX_TIME1P80     0x01
#define RX_TIME0P90     0x02
#define RX_TIME0P45     0x03
#define RX_TIME0P22     0x04
#define RX_TIME0P11     0x05
#define RX_TIME0P05     0x06
#define RX_TIME18P0     0x00
#define RX_TIME9P0      0x01
#define RX_TIME4P5      0x02
#define RX_TIME2P3      0x03
#define RX_TIME1P1      0x04
#define RX_TIME0P6      0x05
#define RX_TIME0P3      0x06
#define RX_TIME32P5     0x00
#define RX_TIME16P2     0x01
#define RX_TIME8P1      0x02
#define RX_TIME4P1      0x03
#define RX_TIME2P0      0x04
#define RX_TIME1P0      0x05
#define RX_TIME0P5      0x06
#define RX_TIME48P9     0x00
#define RX_TIME23P4     0x01
#define RX_TIME11P7     0x02
#define RX_TIME5P9      0x03
#define RX_TIME2P9      0x04
#define RX_TIME1P5      0x05
#define RX_TIME0P7      0x06
#define RX_TIME_END     0x07

/* Main Radio Control State Machine configuration reg1 */
#define MCSM1           0x17
// Clear channel indication
#define CCA_MODE_ALWAYS        0x00
#define CCA_MODE_RSSI          0x10
#define CCA_MODE_PACKET        0x20
#define CCA_MODE_ALWAYS_PACKET 0x30
// Select what should happen when a packet has been received
#define RXOFF_MODE_IDLE         0x00
#define RXOFF_MODE_FSTXON       0x04
#define RXOFF_MODE_TX           0x08
#define RXOFF_MODE_RX           0x0c
// Select what should happen when a packet has been sent
#define TXOFF_MODE_IDLE         0x00
#define TXOFF_MODE_FSTXON       0x01
#define TXOFF_MODE_TX           0x02
#define TXOFF_MODE_RX           0x03

/* Main Radio Control State Machine configuration reg0  */
#define MCSM0           0x18
// Automatically calibrate when going to RX or TX, or back to IDLE
#define FS_AUTOCAL_NEVER        0x00
#define FS_AUTOCAL_FROM_IDLE    0x10
#define FS_AUTOCAL_TO_IDLE      0x20
#define FS_AUTOCAL_4TH_TO IDLE  0x30
// Start-up time for XOSC
#define PO_TIMEOUT_2P4US        0x00
#define PO_TIMEOUT_29US         0x04
#define PO_TIMEOUT_155US        0x08
#define PO_TIMEOUT_620US        0x0c
// Enables the pin radio control option.
#define PIN_CTRL_EN             0x02
// Force the XOSC to stay on in the SLEEP state.
#define XOSC_FORCE_ON           0x01

/* Frequency Offset Compensation configuration */
#define FOCCFG          0x19
// Freeze the frequency offset compensation.
#define FOC_BS_CS_GATE      0x20
// Freq. compensation loop gain before sync word.
#define FOC_PRE_1K          0x00
#define FOC_PRE_2K          0x08
#define FOC_PRE_3K          0x10
#define FOC_PRE_4K          0x18
// Freq. compensation loop gain after sync word.
#define FOC_POST_K          0x04
// Saturation point (max compensated offset)
#define FOC_LIMIT_0         0x00
#define FOC_LIMIT_BW_DIV8   0x01
#define FOC_LIMIT_BW_DIV4   0x02
#define FOC_LIMIT_BW_DIV2   0x03

/* Bit Synchronization configuration */
#define BSCFG           0x1a
// Clock recovery loop integral gain before sync word.
#define BS_PRE_1KI      0x00
#define BS_PRE_2KI      0x40
#define BS_PRE_3KI      0x80
#define BS_PRE_4KI      0xc0
// Clock recovery loop proportional gain before sync word.
#define BS_PRE_1KP      0x00
#define BS_PRE_2KP      0x10
#define BS_PRE_3KP      0x20
#define BS_PRE_4KP      0x30
// Clock recovery loop integral gain after sync word
#define BS_POST_KI      0x00
#define BS_POST_KI_DIV2 0x08
// Clock recovery loop proportional gain after sync word
#define BS_POST_KP      0x04
// Data rate offset saturation (max data rate difference)
#define BS_LIMIT_0P     0x00
#define BS_LIMIT_3P     0x01
#define BS_LIMIT_6P     0x02
#define BS_LIMIT_13P    0x03

/* AGC control reg2 */
#define AGCTRL2         0x1b
// Allowable DVGA settings
#define MAX_DVGA_GAIN_ALL       0x00
#define MAX_DVGA_GAIN_1_HIGH    0x40
#define MAX_DVGA_GAIN_2_HIGH    0x80
#define MAX_DVGA_GAIN_3_HIGH    0xc0
// Maximum allowable LNA + LNA 2 gain
#define MAX_LNA_GAIN_MAX        0x00
#define MAX_LNA_GAIN_2P6DB      0x08
#define MAX_LNA_GAIN_6P1DB      0x10
#define MAX_LNA_GAIN_7P4DB      0x18
#define MAX_LNA_GAIN_9P2DB      0x20
#define MAX_LNA_GAIN_11P5DB     0x28
#define MAX_LNA_GAIN_14P6DB     0x30
#define MAX_LNA_GAIN_17P1DB     0x38
// Target amplitude from channel filter
#define MAGN_TARGET_24DB        0x00
#define MAGN_TARGET_27DB        0x01
#define MAGN_TARGET_30DB        0x02
#define MAGN_TARGET_33DB        0x03
#define MAGN_TARGET_36DB        0x04
#define MAGN_TARGET_38DB        0x05
#define MAGN_TARGET_40DB        0x06
#define MAGN_TARGET_42DB        0x07

/* AGC control reg1 */
#define AGCTRL1         0x1c
// Selects between two different strategies for LNA and LNA 2 gain adjustment.
#define AGC_LNA_PRIORITY            0x40
// Carrier sense relative threshold
#define CARRIER_SENSE_REL_THR_DIS   0x00
#define CARRIER_SENSE_REL_THR_6DB   0x10
#define CARRIER_SENSE_REL_THR_10DB  0x20
#define CARRIER_SENSE_REL_THR_14DB  0x30
// Carrier sense absolute threshold
#define CARRIER_SENSE_ABS_THR_DIS   0x08
#define CARRIER_SENSE_ABS_THR_M7DB  0x09
#define CARRIER_SENSE_ABS_THR_M6DB  0x0a
#define CARRIER_SENSE_ABS_THR_M5DB  0x0b
#define CARRIER_SENSE_ABS_THR_M4DB  0x0c
#define CARRIER_SENSE_ABS_THR_M3DB  0x0d
#define CARRIER_SENSE_ABS_THR_M2DB  0x0e
#define CARRIER_SENSE_ABS_THR_M1DB  0x0f
#define CARRIER_SENSE_ABS_THR_0DB   0x00
#define CARRIER_SENSE_ABS_THR_1DB   0x01
#define CARRIER_SENSE_ABS_THR_2DB   0x02
#define CARRIER_SENSE_ABS_THR_3DB   0x03
#define CARRIER_SENSE_ABS_THR_4DB   0x04
#define CARRIER_SENSE_ABS_THR_5DB   0x05
#define CARRIER_SENSE_ABS_THR_6DB   0x06
#define CARRIER_SENSE_ABS_THR_7DB   0x07

/* AGC control reg0 */
#define AGCTRL0         0x1d
// Sets the level of hysteresis on the magnitude deviation.
#define HYST_LEVEL_NO        0x00
#define HYST_LEVEL_LOW       0x40
#define HYST_LEVEL_MEDIUM    0x80
#define HYST_LEVEL_LARGE     0xc0
// Channel filter samples
#define WAIT_TIME_8SAMPLES   0x00
#define WAIT_TIME_16SAMPLES  0x10
#define WAIT_TIME_24SAMPLES  0x20
#define WAIT_TIME_32SAMPLES  0x30
// Control when the AGC gain should be frozen.
#define AGC_FREEZE_NO        0x00
#define AGC_FREEZE_SYNC      0x04
#define AGC_FREEZE_ANALOGUE  0x08
#define AGC_FREEZE_ALL       0x0c
// Sets the averaging length for the amplitude from the channel filter.
#define FILTER_LENGTH_8SAMP  0x00
#define FILTER_LENGTH_16SAMP 0x01
#define FILTER_LENGTH_32SAMP 0x02
#define FILTER_LENGTH_64SAMP 0x03

/* High byte Event 0 timeout */
#define WOREVT1         0x1e
/* Low byte Event 0 timeout */
#define WOREVT0         0x1f

/* Wake On Radio control */
#define WORCTRL         0x20
// Power down signal to RC oscillator.
#define RC_PD         0x80
// Event 1 timeout.
#define EVENT1_0P11MS 0x00
#define EVENT1_0P17MS 0x10
#define EVENT1_0P22MS 0x20
#define EVENT1_0P33MS 0x30
#define EVENT1_0P44MS 0x40
#define EVENT1_0P67MS 0x50
#define EVENT1_0P89MS 0x60
#define EVENT1_1P33MS 0x70
// Enables or disables the RC oscillator calibration.
#define RC_CAL        0x08
// Controls the Event 0 resolution
#define WOR_RES0      0x00
#define WOR_RES1      0x01
#define WOR_RES2      0x02
#define WOR_RES3      0x03

/* Front end RX configuration */
#define FREND1          0x21
// Adjusts front-end LNA PTAT current output.
#define LNA_CURRENT0            0x00
#define LNA_CURRENT1            0x40
#define LNA_CURRENT2            0x80
#define LNA_CURRENT3            0xc0
// Adjusts front-end PTAT outputs.
#define LNA2MIX_CURRENT0        0x00
#define LNA2MIX_CURRENT1        0x10
#define LNA2MIX_CURRENT2        0x20
#define LNA2MIX_CURRENT3        0x30
// Adjusts current in RX LO buffer (LO input to mixer).
#define LODIV_BUF_CURRENT_RX0   0x00
#define LODIV_BUF_CURRENT_RX1   0x04
#define LODIV_BUF_CURRENT_RX2   0x08
#define LODIV_BUF_CURRENT_RX3   0x0c
// Adjusts current in mixer.
#define MIX_CURRENT0            0x00
#define MIX_CURRENT1            0x01
#define MIX_CURRENT2            0x02
#define MIX_CURRENT3            0x03

/* Front end TX configuration */
#define FREND0          0x22
// The value to use in this field is given by the SmartRF Studio software.
// LODIV_BUF_CURRENT_TX
// Selects PA power setting.
#define PA_POWER_MSK    0x07

/* Frequency synthesizer calibration reg3 */
#define FSCAL3          0x23
// The value to write in this field before calibration is given by the SmartRF
// Studio software.
/* Frequency synthesizer calibration reg2 */
#define FSCAL2          0x24
// Choose high (1) / low (0) VCO
#define VCO_CORE_H_EN   0x20
// The value to write in this field before calibration is given by the SmartRF
// Studio software.
/* Frequency synthesizer calibration reg1 */
#define FSCAL1          0x25
// The value to write in this field before calibration is given by the SmartRF
// Studio software.

/* Frequency synthesizer calibration reg0 */
#define FSCAL0          0x26
// The value to use in this register is given by the SmartRF Studio software.

/* RC oscillator configuration reg1 */
#define RCCTRL1         0x27
/* RC oscillator configuration reg0 */
#define RCCTRL0         0x28
// RC oscillator configuration.

/********************** test registers (for gebug) ****************************/
/* Frequency synthesizer calibration control */
#define FSTEST          0x29
// For test only. Do not write to this register.

/* Production test */
#define PTEST           0x2a
// Writing 0xBF to this register makes the on-chip temperature sensor available
// in the IDLE state.
#define PTEST_DEFAULT   0x7f
#define PTEST_TEST1     0xbf

/* AGC test */
#define AGCTEST         0x2b
//For test only. Do not write to this register.

/* Various test settings reg2 */
#define TEST2           0x2c
// The value to use in this register is given by the SmartRF Studio software

/* Various test settings reg1 */
#define TEST1           0x2d
// The value to use in this register is given by the SmartRF Studio software

/* Various test settings reg0 */
#define TEST0           0x2e
// Enable VCO selection calibration stage
#define VCO_SEL_CAL_EN  0x02

/************************** Status registers **********************************/
/* Part number for CC1101 */
#define PARTNUM         0xf0

/* Current version number */
#define VERSION         0xf1

/* Frequency Offset Estimate */
#define FREQEST         0xf2
// The estimated frequency offset (2’s complement) of the carrier.
#define freq_offs(reg)  (((uint32_t)reg)*OFFS_COEF)

/* Demodulator estimate for Link Quality */
#define LQI             0xf3
// The last CRC comparison matched.
#define CRC_OK      0x80
// The Link Quality Indicator
#define LQI_EST_MSK 0x3f

/* Received signal strength indication */
#define RSSI            0xf4

/* Control state machine state */
#define MARCSTATE       0xf5
// Main Radio Control FSM State
#define MARC_STATE_SLEEP            0x00
#define MARC_STATE_IDLE             0x01
#define MARC_STATE_XOFF             0x02
#define MARC_STATE_VCOON_MC         0x03
#define MARC_STATE_REGON_MC         0x04
#define MARC_STATE_MANCAL           0x05
#define MARC_STATE_VCOON            0x06
#define MARC_STATE_REGON            0x07
#define MARC_STATE_STARTCAL         0x08
#define MARC_STATE_BWBOOST          0x09
#define MARC_STATE_FS_LOCK          0x0a
#define MARC_STATE_IFADCON          0x0b
#define MARC_STATE_ENDCAL           0x0c
#define MARC_STATE_RX               0x0d
#define MARC_STATE_RX_END           0x0e
#define MARC_STATE_RX_RST           0x0f
#define MARC_STATE_TXRX_SWITCH      0x10
#define MARC_STATE_RXFIFO_OVERFLOW  0x11
#define MARC_STATE_FSTXON           0x12
#define MARC_STATE_TX               0x13
#define MARC_STATE_TX_END           0x14
#define MARC_STATE_RXTX_SWITCH      0x15
#define MARC_STATE_TXFIFO_UNDERFLOW 0x16

/* High byte of WOR timer */
#define WORTIME1        0xf6
/* Low byte of WOR timer */
#define WORTIME0        0xf7

/* Current GDOx status and packet status */
#define PKTSTATUS       0xf8
// The last CRC comparison matched.
// Carrier sense.
#define CS          0x40
// Preamble Quality reached.
#define PQT_REACHED 0x20
// Channel is clear
#define CCA         0x10
// Start of Frame Delimiter.
#define SFD         0x08
// Current GDO2 value.
#define GDO2        0x04
// Current GDO0 value.
#define GDO0        0x01

/* Current setting from PLL calibration module */
#define VCO_VC_DAC      0xf9
// Status register for test only.

/* Underflow and number of bytes in the TX FIFO */
#define TXBYTES         0xfa
// unerflow
#define TXFIFO_UNDERFLOW    0x80
// Number of bytes in TX FIFO
#define NUM_TXBYTES_MSK     0x7f

/* Overflow and number of bytes in the RX FIFO */
#define RXBYTES         0xfb
// owerflow
#define RXFIFO_OVERFLOW     0x80
// Number of bytes in RX FIFO
#define NUM_RXBYTES         0x7f

/* Last RC oscillator calibration result reg1 */
#define RCCTRL1_STATUS  0xfc
/* Last RC oscillator calibration result reg0 */
#define RCCTRL0_STATUS  0xfd
// Contains the value from the last run of the RC oscillator calibration routine.

/************************* Fast commands **************************************/
/* Reset chip. */
#define SRES    0x30
/* Enable and calibrate frequency synthesizer. */
#define SFSTXON 0x31
/* Turn off crystal oscillator. */
#define SXOFF   0x32
/* Calibrate frequency synthesizer and turn it off. */
#define SCAL    0x33
/* Enable RX. */
#define SRX     0x34
/* Enable TX. */
#define STX     0x35
/* Exit RX/TX. */
#define SIDLE   0x36
/* Start automatic RX polling sequence. */
#define SWOR    0x38
/* Enter power down mode. */
#define SPWD    0x39
/* Flush the RX FIFO buffer. */
#define SFRX    0x3a
/* Flush the TX FIFO buffer. */
#define SFTX    0x3b
/* Reset real time clock to Event1 value. */
#define SWORRST 0x3c
/* No operation. */
#define SNOP    0x3d

#endif
