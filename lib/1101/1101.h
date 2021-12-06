#include "1101regs.h"
#include "1101table.h"

/*** here are parameters for calculating in pre-built script ***/
#define DATA_RATE       115051
#define IF_FREQ         381000
#define CARRIER_FREQ    433000000
#define RX_BW           100000
#define DEVIATION_FREQ  15000
#define CHANNEL_FREQ    70000

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
#define FSCTRL1_CONF
#define FSCTRL0_CONF
#define FREQ2_CONF
#define FREQ1_CONF
#define FREQ0_CONF      

#define MDMCFG4_CONF    CHANBW102K |
#define MDMCFG3_CONF
#define MDMCFG2_CONF
#define MDMCFG1_CONF
#define MDMCFG0_CONF

#define DEVIATN_CONF

#define MCSM2_CONF
#define MCSM1_CONF
#define MCSM0_CONF

#define FOCCFG_CONF

#define BSCFG_CONF

#define AGCTRL2_CONF
#define AGCTRL1_CONF
#define AGCTRL0_CONF

#define WOREVT1_CONF
#define WOREVT0_CONF

#define WORCTRL_CONF

#define FREND1_CONF
#define FREND0_CONF

#define FSCAL3_CONF
#define FSCAL2_CONF
#define FSCAL1_CONF
#define FSCAL0_CONF

#define RCCTRL1_CONF
#define RCCTRL0_CONF
