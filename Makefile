#paths
TARGET = player.elf
TARGET_DIR = result
LIB_DIR = lib
REG_DIR	= $(LIB_DIR)/regs
ODIR = bin

# code is here
SOURCES = main.c
SOURCES += $(LIB_DIR)/rcc.c
SOURCES += $(LIB_DIR)/delay.c

INCLUDES   = -I $(LIB_DIR)/
INCLUDES  += -I $(REG_DIR)/

# VENDOR SPECIFIC CODE
CMSIS_INC  = $(LIB_DIR)/CMSIS_5/CMSIS/Core/Include
VENDOR_DIR = $(LIB_DIR)/STM32F105_CMSIS
SOURCES += $(VENDOR_DIR)/startup_stm32f105.c
SOURCES += $(VENDOR_DIR)/system_stm32f105.c
INCLUDES  += -I $(VENDOR_DIR)
INCLUDES  += -I $(CMSIS_INC)
LD_SCRIPT = $(VENDOR_DIR)/gcc_arm.ld
DEFINES = ARMCM3

# Parameters
CFLAGS +=-ffunction-sections -fdata-sections
CFLAGS +=-Wall -Wextra -Werror -Wconversion -Wundef -Wformat=2 -Wformat-truncation
CFLAGS +=-Wdouble-promotion -Wshadow -Wimplicit-function-declaration
CFLAGS +=-Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
CFLAGS +=-fno-common -Os -ffreestanding
CFLAGS +=-mcpu=cortex-m3 -mthumb
CFLAGS +=-mfloat-abi=soft -std=gnu2x
CFLAGS +=-D$(DEFINES)
CFLAGS +=-ggdb3
LFLAGS  = -T"$(LD_SCRIPT)" --specs=nano.specs -Wl,--gc-sections
LFLAGS += -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
#utilities
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc

### making-taking aaaa #########################################################

#object files list
OBJECTS = $(SOURCES:%.c=$(ODIR)/%.o)

#main rule
all: $(TARGET)
#compile
$(ODIR)/%.o: %.c
	@echo "[CC] $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) $(DEFS) -c $< -o $@
#link
$(TARGET): $(OBJECTS)
	@echo "[LD] $@"
	@mkdir -p $(TARGET_DIR)
	@$(LD) $(CFLAGS) $(LFLAGS) $(OBJECTS) -o $(TARGET_DIR)/$@

# Clean rule
#.PHONY:
clean:
	@rm -rf $(ODIR)
	@rm -r $(TARGET_DIR)/$(TARGET)
