#!/usr/bin/env python3

import configparser
import math

# read rf parameters from ini file in order to calculate regs
config = configparser.ConfigParser()
config.read('rf_config.ini')
rfParam = config['DEFAULT']

# calculate register values from parameters
ifCalc = int((int(rfParam['ifFreq'])* int(1024)) / int(rfParam['oscFreq'])) & int(0x0f)
afcOffsCalc = int(int(rfParam['afcOffs']) / (int(rfParam['oscFreq']) / int(16384))) & int(0xff)
carrierCalc = int((int(rfParam['carrierFreq'])*int(65536)) / int(rfParam['oscFreq'])) & int(0x3fffff)
rxBwE = int(math.log((int(rfParam['oscFreq'])/int(32)/int(rfParam['rxBw'])), 2)) & int(0x03)
rxBwM = int(int(rfParam['oscFreq'])*(int(2)**rxBwE)*int(8) - int(4)) & int(0x03)
dataRateE = int(math.log((int(rfParam['dataRate'])*int(1048576)/int(rfParam['oscFreq'])),2)) & int(0x0f)
dataRateM = int(int(rfParam['dataRate'])*(int(2)**(28-dataRateE))/int(rfParam['oscFreq']) - 256) & int(0xff)
deviationE = int(math.log((int(rfParam['deviationFreq'])*int(16384)/int(rfParam['oscFreq'])),2)) & int(0x07)
deviationM = int(int(rfParam['deviationFreq'])*(int(2)**(17-dataRateE))/int(rfParam['oscFreq']) - 8) & int(0x07)
channelE = int(math.log((int(rfParam['channelFreq'])*int(1024)/int(rfParam['oscFreq'])),2)) & int(0x03)
channelM = int(int(rfParam['channelFreq'])*(int(2)**(18-dataRateE))/int(rfParam['oscFreq']) - 256) & int(0xff)

# output registers with calculated parameters in C macro readable form
macroPre = "#define "
macroPost = "_CALCULATED "
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
output.write(macroPre+ifReg+macroPost+hex(ifCalc)+"\n")
output.write(macroPre+afcOffsReg+macroPost+hex(afcOffsCalc)+"\n")
output.write(macroPre+carrierReg1+macroPost+hex(carrierCalc>>16)+"\n")
output.write(macroPre+carrierReg2+macroPost+hex((carrierCalc>>7)&0xff)+"\n")
output.write(macroPre+carrierReg3+macroPost+hex(carrierCalc&0xff)+"\n")
output.write(macroPre+rxBwReg+macroPost+hex((rxBwE<<6) + (rxBwM<<4) + dataRateE)+"\n")
output.write(macroPre+dataRateReg+macroPost+hex(dataRateM)+"\n")
output.write(macroPre+channelReg1+macroPost+hex(channelE)+"\n")
output.write(macroPre+channelReg2+macroPost+hex(channelM)+"\n")
output.write(macroPre+deviationReg+macroPost+hex((deviationE<<4) + deviationM)+"\n")
