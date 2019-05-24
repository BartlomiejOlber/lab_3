################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bot/brain.cpp \
../src/bot/screen_capture.cpp 

OBJS += \
./src/bot/brain.o \
./src/bot/screen_capture.o 

CPP_DEPS += \
./src/bot/brain.d \
./src/bot/screen_capture.d 


# Each subdirectory must supply rules for building sources it contributes
src/bot/%.o: ../src/bot/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


