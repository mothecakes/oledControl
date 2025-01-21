################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/sprites/sprites.c 

OBJS += \
./Core/sprites/sprites.o 

C_DEPS += \
./Core/sprites/sprites.d 


# Each subdirectory must supply rules for building sources it contributes
Core/sprites/%.o Core/sprites/%.su Core/sprites/%.cyclo: ../Core/sprites/%.c Core/sprites/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/Joseph Sary/STM32CubeIDE/workspace_1.16.1/oledControl/Core/sprites" -I"C:/Users/Joseph Sary/STM32CubeIDE/workspace_1.16.1/oledControl/Drivers/OLED" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-sprites

clean-Core-2f-sprites:
	-$(RM) ./Core/sprites/sprites.cyclo ./Core/sprites/sprites.d ./Core/sprites/sprites.o ./Core/sprites/sprites.su

.PHONY: clean-Core-2f-sprites

