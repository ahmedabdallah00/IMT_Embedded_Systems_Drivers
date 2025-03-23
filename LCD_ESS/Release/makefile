################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LCD/subdir.mk
-include DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LCD_ESS.lss \

FLASH_IMAGE += \
LCD_ESS.hex \

EEPROM_IMAGE += \
LCD_ESS.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD_ESS.elf secondary-outputs

# Tool invocations
LCD_ESS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_ESS.map -mmcu=atmega32 -o "LCD_ESS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_ESS.lss: LCD_ESS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_ESS.elf  >"LCD_ESS.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_ESS.hex: LCD_ESS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_ESS.elf  "LCD_ESS.hex"
	@echo 'Finished building: $@'
	@echo ' '

LCD_ESS.eep: LCD_ESS.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LCD_ESS.elf  "LCD_ESS.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_ESS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD_ESS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_ESS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
