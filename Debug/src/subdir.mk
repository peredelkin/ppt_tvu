################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/spi.c \
../src/system_stm32f4xx.c \
../src/tic12400.c 

S_UPPER_SRCS += \
../src/startup_stm32f429_439xx.S 

OBJS += \
./src/main.o \
./src/spi.o \
./src/startup_stm32f429_439xx.o \
./src/system_stm32f4xx.o \
./src/tic12400.o 

S_UPPER_DEPS += \
./src/startup_stm32f429_439xx.d 

C_DEPS += \
./src/main.d \
./src/spi.d \
./src/system_stm32f4xx.d \
./src/tic12400.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7-m -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wuninitialized -Wall -Wmissing-declarations -Wpointer-arith -Wfloat-equal  -g -ggdb -I"C:\Users\Ruslan\eclipse-workspace\PPT_TVU\inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -march=armv7-m -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -ffreestanding -fno-builtin -Wuninitialized -Wall -Wmissing-declarations -Wpointer-arith -Wfloat-equal  -g -ggdb -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


