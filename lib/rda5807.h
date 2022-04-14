
/* register 0 */
#define CHIPID     0x00
/* register 1 */
// Audio Output High-Z Disable.
#define DHIZ        0x8000
// Mute Disable.
#define DMUTE       0x4000
// Mono Select.
#define MONO        0x2000
// Bass Boost.
#define BASS        0x1000
// 0=RCLK clock is always supply
#define RCLK_MODE   0x0800
// 1=RCLK clock use the directly input mode
#define RCLK_DIRECT 0x0400
// Seek Up.
#define SEEKUP      0x0200
// Seek.
#define SEEK        0x0100
// Seek Mode
#define SKMODE      0x0080
// clock mode
#define CLK_MODE_32768  0x0000
#define CLK_MODE_12M    0x0010
#define CLK_MODE_24M    0x0050
#define CLK_MODE_13M    0x0020
#define CLK_MODE_26M    0x0060
#define CLK_MODE_19P2M  0x0030
#define CLK_MODE_38P4M  0x0070
// RDS/RBDS enable
#define RDS_EN      0x0004
// New Demodulate Method Enable
#define NEW_METHOD  0x0003
// Soft reset.
#define SOFT_RESET  0x0002
// Power Up Enable.
#define ENABLE      0x0001

/* register 3 */
// Channel Select.
#define CHAN_SHIFT  6
// Directly Control Mode
#define DIRECT_MODE 0x0020
// Tune
#define TUNE        0x0010
// Band Select.
#define BAND_EU     0x0000
#define BAND_JP     0x0004
#define BAND_WIDE   0x0008
#define BAND_SU     0x000c

/* register 4 */
// Seek/Tune Complete Interrupt Enable.
#define STCIEN      0x4000
// 1 = RBDS mode enable
#define RBDS        0x2000
// 1 = RDS fifo mode enable.
#define RDS_FIFO_EN 0x1000
// De-emphasis.
#define DE          0x0800
// 1 = clear RDS fifo
#define RDS_FIFO_CLR 0x0400
// If 1, softmute enable
#define SOFTMUTE_EN 0x0200
// AFC disable.
#define AFCD        0x0100
// I2S enable.
#define I2S_ENABLE  0x0040
// General Purpose I/O 3
#define GPIO3_HIZ   0x0000
#define GPIO3_ST    0x0010
#define GPIO3_LOW   0x0020
#define GPIO3_HI    0x0030
// General Purpose I/O 2.
#define GPIO2_HIZ   0x0000
#define GPIO2_INT   0x0004
#define GPIO2_LOW   0x0008
#define GPIO2_HI    0x000c
// General Purpose I/O 2.
#define GPIO1_HIZ   0x0000
#define GPIO1_LOW   0x0002
#define GPIO1_HI    0x0003

/* register 5 */
// Interrupt mode
#define INT_MODE    0x8000
// add the RSSI seek mode.
#define SEEK_MODE   0x2000
// Seek SNR threshold value
#define SEEKTH_SHIFT 8
// LNA input port selection bit
#define LNA_PORT_SEL_NO     0x0000
#define LNA_PORT_SEL_LNAN   0x0040
#define LNA_PORT_SEL_LNAP   0x0080
#define LNA_PORT_SEL_DP     0x00c0
// Lna working current bit
#define LNA_ICSEL_BIT1P8M   0x0000
#define LNA_ICSEL_BIT2P1M   0x0010
#define LNA_ICSEL_BIT2P5M   0x0020
#define LNA_ICSEL_BIT3M     0x0030
// DAC Gain Control Bits (Volume).
#define VOLUME_SHIFT        0

/* register 6 */
// Open reserved register mode.
#define OPEN_MODE       0x6000
// I2S slave or master.
#define SLAVE_MASTER    0x1000
// Ws relation to l/r channel.
#define WS_LR           0x0800
// If 1, inverte sclk internally.
#define SCLK_I_EDGE     0x0400
// If 1, I2S output signed 16-bit audio data.
#define DATA_SIGNED     0x0200
// If 1, inverte ws internally.
#define WS_I_EDGE       0x0100
// WS_STEP in kbps
#define I2S_SW_CNT48    0x0080
#define I2S_SW_CNT44    0x0070
#define I2S_SW_CNT32    0x0060
#define I2S_SW_CNT24    0x0050
#define I2S_SW_CNT22    0x0040
#define I2S_SW_CNT16    0x0030
#define I2S_SW_CNT12    0x0020
#define I2S_SW_CNT11    0x0010
#define I2S_SW_CNT8     0x0000
// If 1, invert ws output when as master.
#define SW_O_EDGE       0x0008
// If 1, invert sclk output when as master.
#define SCLK_O_EDGE     0x0004
// If 1, L channel data delay 1T.
#define L_DELY          0x0002
// If 1, R channel data delay 1T.
#define R_DELY          0x0001

/* register 7 */
// Threshold for noise soft blend setting, unit 2dB
#define TH_SOFRBLEND_SHIFT  10
// 1 = 65~76 MHz;
#define MODE_65M_50M        0x0200
// Seek threshold for old seek mode
#define SEEK_TH_OLD_SHIFT   2
// If 1, Softblend enable
#define SOFTBLEND_EN        0x0002
// If 1, then freq setting changed.
#define FREQ_MODE           0x0001

/* register 8 */
// freq_direct

/* register A */
// RDS ready
#define RDSR        0x8000
// Seek/Tune Complete.
#define STC         0x4000
// Seek Fail.
#define SF          0x2000
// RDS Synchronization
#define RDSS        0x1000
// When RDS enable
#define BLK_E       0x0800
// Stereo Indicator.
#define ST          0x0400
// Read Channel.
#define READCHAN_MSK 0x3ff

/* register B */
// RSSI
#define RSSI_SHIFT  9
// 1 = the current channel is a station
#define FM_TRUE     0x0100
// 1=ready
#define FM_READY    0x0080
// 1= the block id of register 0cH,0dH,0eH,0fH is E
#define ABCD_E      0x0010
// Block Errors Level of RDS_DATA_0
#define BLERA_0ERR  0x0000
#define BLERA_2ERR  0x0004
#define BLERA_5ERR  0x0008
#define BLERA_6ERR  0x000c
// Block Errors Level of RDS_DATA_1
#define BLERA_0ERR  0x0000
#define BLERA_2ERR  0x0001
#define BLERA_5ERR  0x0002
#define BLERA_6ERR  0x0003
/* register C */
// RDSA
/* register D */
// RDSB
/* register E */
// RDSC
/* register F */
// RDSD
