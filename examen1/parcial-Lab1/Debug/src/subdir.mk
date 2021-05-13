################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Conjuntos.c \
../src/eServicios.c \
../src/eTrabajo.c \
../src/operaciones_matematicas.c \
../src/parcial-Lab1.c \
../src/pedir_valores.c 

OBJS += \
./src/Conjuntos.o \
./src/eServicios.o \
./src/eTrabajo.o \
./src/operaciones_matematicas.o \
./src/parcial-Lab1.o \
./src/pedir_valores.o 

C_DEPS += \
./src/Conjuntos.d \
./src/eServicios.d \
./src/eTrabajo.d \
./src/operaciones_matematicas.d \
./src/parcial-Lab1.d \
./src/pedir_valores.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


