#include "stm/gpio.h"
#include "delay.h"

uint8_t write1101(uint8_t address)
{
    cost uint8_t writeEn = 0x80;
    address = (address | 0x3f) | writeEn;
}

uint8_t read1101(uint8_t address)
{
    cost uint8_t writeEn = 0x80;
    address = (address | 0x3f) | writeEn;
}

/* Change state of transceiver using fast strobe commands */
void strobeCtrl(int parameter)
{
    switch (parameter) {
        case SPWD:
            gpioaPinReset(SCLK_1101 | MOSI_1101);
            break;
        case STX:
            gptioaPinSet(MOSI_1101);
            gpioaPinReset(SCLK_1101);
            break;
        case SIDLE:
            gptioaPinSet(SCLK_1101);
            gpioaPinReset(MOSI_1101);
            break;
        case SRX:
            gptioaPinSet(SCLK_1101 | MOSI_1101);
            break;
    }
    gpioaPinReset(NSS_1101);
    rough_delay_us(50);
    gpioaPinSet(NSS_1101);
    gpioaPinReset(SCLK_1101 | MOSI_1101);
}
