################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Hardware/Exti/exti.c 

OBJS += \
./Core/Hardware/Exti/exti.o 

C_DEPS += \
./Core/Hardware/Exti/exti.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Hardware/Exti/%.o: ../Core/Hardware/Exti/%.c Core/Hardware/Exti/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/stm32File/firstFile/Core/Hardware/Led" -I"D:/stm32File/firstFile/Core/Hardware/Key" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

