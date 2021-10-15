#ifndef H_ADC_REGS
#define H_ADC_REGS
/*
 * Part of Belkin STM32 HAL, ADC register definitions of STM32F1xx MCUs.
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

#include "memorymap.h"

#define GPIOA_CRLe   MMIO32(ADC1_BASE + 0x00)
#define GPIOA_CRLee   MMIO32(ADC2_BASE + 0x00)
#define GPIOA_CRLeee   MMIO32(ADC3_BASE + 0x00)


#endif
