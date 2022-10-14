################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
NiboLEDDistance.lss \

FLASH_IMAGE += \
NiboLEDDistance.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NiboLEDDistance.elf secondary-outputs

# Tool invocations
NiboLEDDistance.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NiboLEDDistance.map -L/home/defaultuser/Documents/niboLib304/lib/nibo2-m128-16 -mmcu=atmega128 -o "NiboLEDDistance.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NiboLEDDistance.lss: NiboLEDDistance.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NiboLEDDistance.elf  >"NiboLEDDistance.lss"
	@echo 'Finished building: $@'
	@echo ' '

NiboLEDDistance.hex: NiboLEDDistance.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NiboLEDDistance.elf  "NiboLEDDistance.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NiboLEDDistance.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 NiboLEDDistance.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NiboLEDDistance.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
