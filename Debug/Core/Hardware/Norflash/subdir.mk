################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Hardware/Norflash/norflash.c 

OBJS += \
./Core/Hardware/Norflash/norflash.o 

C_DEPS += \
./Core/Hardware/Norflash/norflash.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Hardware/Norflash/%.o: ../Core/Hardware/Norflash/%.c Core/Hardware/Norflash/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/stm32File/firstFile/Core/Hardware/Led" -I"D:/stm32File/firstFile/Core/Hardware/Key" -I"D:/stm32File/firstFile/Core/Hardware/At24c02" -I"D:/stm32File/firstFile/Core/Hardware/Myiic" -I"D:/stm32File/firstFile/Core/Hardware/Norflash" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

