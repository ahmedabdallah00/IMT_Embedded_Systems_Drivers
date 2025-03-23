################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include GIE/subdir.mk
-include EXTI/subdir.mk
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
Interupt.lss \

FLASH_IMAGE += \
Interupt.hex \

EEPROM_IMAGE += \
Interupt.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Interupt.elf secondary-outputs

# Tool invocations
Interupt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Interupt.map -mmcu=atmega32 -o "Interupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Interupt.lss: Interupt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Interupt.elf  >"Interupt.lss"
	@echo 'Finished building: $@'
	@echo ' '

Interupt.hex: Interupt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Interupt.elf  "Interupt.hex"
	@echo 'Finished building: $@'
	@echo ' '

Interupt.eep: Interupt.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Interupt.elf  "Interupt.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Interupt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Interupt.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Interupt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
