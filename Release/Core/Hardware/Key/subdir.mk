################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Hardware/Key/key.c 

OBJS += \
./Core/Hardware/Key/key.o 

C_DEPS += \
./Core/Hardware/Key/key.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Hardware/Key/%.o: ../Core/Hardware/Key/%.c Core/Hardware/Key/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/stm32File/firstFile/Core/Hardware/Led" -I"D:/stm32File/firstFile/Core/Hardware/Key" -I"D:/stm32File/firstFile/Core/Hardware/Myiic" -I"D:/stm32File/firstFile/Core/Hardware/At24c02" -I"D:/stm32File/firstFile/Core/Hardware/Norflash" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

