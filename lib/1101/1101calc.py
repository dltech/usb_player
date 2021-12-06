import configparser
import math

# read rf parameters from ini file in order to calculate regs
config = configparser.ConfigParser()
config.read('rf_config.ini')
rfParam = config[DEFAULT]

# calculate register values from parameters
ifCalc = int((long(rfParam[ifFreq])* long(1024)) / long(rfParam[oscFreq])) & int(0x0f)
afcOffsCalc = int(long(rfParam[afcOffs]) / (long(rfParam[oscFreq]) / long(16384))) & int(0xff)
carrierCalc = int((long(rfParam[carrierFreq])*long(65536)) / long(rfParam[oscFreq])) & int(0x3fffff)
rxBwE = int(math.log((long(rfParam[oscFreq])/long(32)/long(rxBw)), 2)) & int(0x03)
rxBwM = int(long(rfParam[oscFreq])*(long(2)**rxBwE)*long(8) - long(4)) & int(0x03)
dataRateE = int(math.log((long(rfParam[dataRate])*long(1048576)/long(rfParam[oscFreq])),2)) & int(0x0f)
dataRateM = int(long(rfParam[dataRate])*(long(2)**(28-dataRateE))/long(rfParam[oscFreq]) - 256) & int(0xff)
deviationE = int(math.log((long(rfParam[deviationFreq])*long(16384)/long(rfParam[oscFreq])),2)) & int(0x0f)
deviationM = int(long(rfParam[deviationFreq])*(long(2)**(17-dataRateE))/long(rfParam[oscFreq]) - 8) & int(0xff)
channelE = int(math.log((long(rfParam[channelFreq])*long(1024)/long(rfParam[oscFreq])),2)) & int(0x03)
channelM = int(long(rfParam[channelFreq])*(long(2)**(18-dataRateE))/long(rfParam[oscFreq]) - 256) & int(0xff)

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
deviationReg1 = "MDMCFG1"
deviationReg2 = "MDMCFG0"
channelReg = "DEVIATN"
output = open("1101table.h", "wt")
