################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../H_BRIDGE/H_BRIDGE_program.c 

OBJS += \
./H_BRIDGE/H_BRIDGE_program.o 

C_DEPS += \
./H_BRIDGE/H_BRIDGE_program.d 


# Each subdirectory must supply rules for building sources it contributes
H_BRIDGE/%.o: ../H_BRIDGE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


