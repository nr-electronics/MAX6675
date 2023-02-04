/**
 ******************************************************************************
 *  @file MAX6675.h
 *  @brief Библиотека для работы с MAX6675 (Преобразователь температуры для термопар K-типа)
 *  @author Николай Русин
 *  @date 29.01.2023
 *
 ******************************************************************************
 * @attention
 *
 *  MAX6675 выполняет компенсацию холодного спая и оцифровывает сигнал термопары K-типа.
 *  Данные выводятся в 12-битном виде (Motorla), совместимом с SPI, формат только для чтения.
 *  Разрешение температуры кратно 0.25 °С. 
 *  Используется в промышленности, бытовой технике, системах отопления, вентиляции и кондиционировании.
 *  Горячий спай термопары способен измерять температуру от 0°C до +1023,75°C, при этом 
 *  холодный конец (температура окружающей среды платы, на которой установлен MAX6675),
 *  может находиться в диапазоне от -20°C до +85°C (температура работы - MAX6675).
 *  MAX6675 корректирует измерения по температуре холодного спая.
 * 
 *  SPI HAL: SCK =  4.3 MHz - Максимальная скорость, прескалером (Prescaler for Baud Rate) делаем любую поменьше
 *           CS(NSS) в активном состоянии подтянут к земле
 *           First Bit  MSB First
 *           Clock polarity (CPOL) = Low (0)
 *           Clock Phase (CPHA) = 2 Edge (0)
 *  Работа с данными происходит в 16-битном формате, в CubeMX.
 * 
 *  Частота преобразования микросхемы: 0.17секунды (нет необходимости опрашивать чаще, чем это значение)
 * 
 *
 *  YouTube: https://www.youtube.com/@NRelectronics
 *  GitHub: https://github.com/nr-electronics/MAX6675/
 *  ВК: https://vk.com/nr.electronics 
 *  Документация: https://static.chipdip.ru/lib/105/DOC001105916.pdf
 *  
 ******************************************************************************
 */
/*----------------------Пример использования данной библиотеки----------------------*/
/*
 * HAL:
   extern uint16_t ReadTemperature;
   ...
   ReadTemperature=ReadDataMAX6675();
   HAL_Delay(300);
*/
/*----------------------Пример использования данной библиотеки----------------------*/
#ifndef __MAX6675_thermocouples_H
#define __MAX6675_thermocouples_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

#define MAX6675_CS1   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4,GPIO_PIN_SET);
#define MAX6675_CS0   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4,GPIO_PIN_RESET);


#ifdef __cplusplus
}
#endif

#endif
