################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clientes.c \
../src/controller.c \
../src/main.c \
../src/pedidos.c \
../src/utn.c 

OBJS += \
./src/clientes.o \
./src/controller.o \
./src/main.o \
./src/pedidos.o \
./src/utn.o 

C_DEPS += \
./src/clientes.d \
./src/controller.d \
./src/main.d \
./src/pedidos.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


