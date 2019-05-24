################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/test_army.cpp \
../test/test_brain.cpp \
../test/test_building.cpp \
../test/test_castle.cpp \
../test/test_game_object.cpp \
../test/test_guarded_building.cpp \
../test/test_hero.cpp \
../test/test_main.cpp \
../test/test_screen_capture.cpp \
../test/test_troop.cpp 

OBJS += \
./test/test_army.o \
./test/test_brain.o \
./test/test_building.o \
./test/test_castle.o \
./test/test_game_object.o \
./test/test_guarded_building.o \
./test/test_hero.o \
./test/test_main.o \
./test/test_screen_capture.o \
./test/test_troop.o 

CPP_DEPS += \
./test/test_army.d \
./test/test_brain.d \
./test/test_building.d \
./test/test_castle.d \
./test/test_game_object.d \
./test/test_guarded_building.d \
./test/test_hero.d \
./test/test_main.d \
./test/test_screen_capture.d \
./test/test_troop.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


