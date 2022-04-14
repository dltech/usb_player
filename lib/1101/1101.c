/*
 * Part of CC1101 library, rf transceiver control functions and main interrupt.
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

#include "stm/gpio.h"
#include "delay.h"
#include "1101.h"

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

void strobeCmd(uint8_t cmd)
{
    
}

/* Change state of transceiver using fast strobe commands */
void strobeCtrl(int parameter)
{
    switch (parameter) {
        case SPWD:
            gpioaPinReset(SCLK_1101 | MOSI_1101);
            break;
        case STX:
            gpioaPinSet(MOSI_1101);
            gpioaPinReset(SCLK_1101);
            break;
        case SIDLE:
            gpioaPinSet(SCLK_1101);
            gpioaPinReset(MOSI_1101);
            break;
        case SRX:
            gpioaPinSet(SCLK_1101 | MOSI_1101);
            break;
        case SRES:
            gpioaPinReset(MOSI_1101);
            rough_delay_us(param1101.strobeTactUs);
            gpioaPinReset(NSS_1101);
            rough_delay_us(param1101.strobeTactUs);
            gpioaPinSet(NSS_1101);
            rough_delay_us(param1101.strobeApplyUs);
            gpioaPinReset(NSS_1101);
            return;
    }
    gpioaPinReset(NSS_1101);
    rough_delay_us(param1101.strobeApplyUs);
    gpioaPinSet(NSS_1101);
    gpioaPinReset(SCLK_1101 | MOSI_1101);
}
