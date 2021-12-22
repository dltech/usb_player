#!/usr/bin/env python3
#
# Part of CC1101 library, Ti SmartRF studio bypass. The pre built
# script for calculating RF parameters (frequences, filter bandwidth, etc.).
#
# Copyright 2021 Mikhail Belkin <dltech174@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

import configparser
import math

# read rf parameters from ini file in order to calculate regs
config = configparser.ConfigParser()
config.read('rf_config.ini')
rfParam = config['DEFAULT']
ifFreq = int(rfParam['ifFreq'])
afcOffs = int(rfParam['afcOffs'])
oscFreq = int(rfParam['oscFreq'])
carrierFreq = int(rfParam['carrierFreq'])
rxBw = int(rfParam['rxBw'])
dataRate = int(rfParam['dataRate'])
deviationFreq = int(rfParam['deviationFreq'])
channelFreq = int(rfParam['channelFreq'])
rxBw = int(rfParam['rxBw'])

# calculating register values from parameters
ifCalc = int(int(int(ifFreq)* int(1024)) / int(oscFreq)) & int(0x0f)
afcOffsCalc = int(int(afcOffs) / int(int(oscFreq) / int(16384))) & int(0xff)
carrierCalc = int((int(carrierFreq)*int(65536)) / int(oscFreq)) & int(0x3fffff)
rxBwE = int(math.log((int(oscFreq)/int(32)/int(rxBw)), 2)) & int(0x03)
rxBwM = int(int(oscFreq)*(int(2)**rxBwE)*int(8) - int(4)) & int(0x03)
dataRateE = int(math.log((int(dataRate)*int(1048576)/int(oscFreq)),2)) & int(0x0f)
dataRateM = int(int(dataRate)*(int(2)**(28-dataRateE))/int(oscFreq) - 256) & int(0xff)
deviationE = int(math.log((int(deviationFreq)*int(16384)/int(oscFreq)),2)) & int(0x07)
deviationM = int(int(deviationFreq)*(int(2)**(17-dataRateE))/int(oscFreq) - 8) & int(0x07)
channelE = int(math.log((int(channelFreq)*int(1024)/int(oscFreq)),2)) & int(0x03)
channelM = int(int(channelFreq)*(int(2)**(18-channelE))/int(oscFreq) - 256) & int(0xff)

# output of registers with calculated parameters in C macro readable form
header = "/*\n * Part of CC1101 library, automatically generated rf parameters.\n *\n * Copyright 2021 Mikhail Belkin <dltech174@gmail.com> \n\
 *\n * Licensed under the Apache License, Version 2.0 (the \"License\");\n * you may not use this file except in compliance with the License.\n\
 * You may obtain a copy of the License at\n *\n *     http://www.apache.org/licenses/LICENSE-2.0\n\
 *\n * Unless required by applicable law or agreed to in writing, software\n * distributed under the License is distributed on an \"AS IS\" BASIS, # NOTE:\n\
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n * See the License for the specific language governing permissions and\n\
 * limitations under the License.\n */\n\n"
macroPre = "#define\t"
macroPost = "_CALCULATED\t"
ifReg = "FSCTRL1"
afcOffsReg = "FSCTRL0"
carrierReg1 = "FREQ2"
carrierReg2 = "FREQ1"
carrierReg3 = "FREQ0"
rxBwReg = "MDMCFG4"
dataRateReg = "MDMCFG3"
channelReg1 = "MDMCFG1"
channelReg2 = "MDMCFG0"
deviationReg = "DEVIATN"

output = open("1101table.h", "wt")
output.write(header)
output.write(macroPre+ifReg+macroPost+hex(ifCalc)+"\n")
output.write(macroPre+afcOffsReg+macroPost+hex(afcOffsCalc)+"\n")
output.write(macroPre+carrierReg1+macroPost+hex(carrierCalc>>16)+"\n")
output.write(macroPre+carrierReg2+macroPost+hex((carrierCalc>>8)&0xff)+"\n")
output.write(macroPre+carrierReg3+macroPost+hex(carrierCalc&0xff)+"\n")
output.write(macroPre+rxBwReg+macroPost+hex((rxBwE<<6) + (rxBwM<<4) + dataRateE)+"\n")
output.write(macroPre+dataRateReg+macroPost+hex(dataRateM)+"\n")
output.write(macroPre+channelReg1+macroPost+hex(channelE)+"\n")
output.write(macroPre+channelReg2+macroPost+hex(channelM)+"\n")
output.write(macroPre+deviationReg+macroPost+hex((deviationE<<4) + deviationM)+"\n")
