#include "MAX6675_thermocouples.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1; //микросхема подключена через SPI1

uint16_t  ReadTemperature = 0; //Инициализация считанных значение с SPI1
int Termopara_Correction_additive = 1; //Калибровка смещения термопары
int Termopara_Correction_multiplicative = -2; //Калибровка наклона термопары
int16_t MSBLSB; //16 бит данных
uint8_t status; //Состояния подключения
uint8_t data[2]; //Массив датчика


uint16_t ReadDataMAX6675(void)
  {
  	MAX6675_CS0
  	HAL_SPI_Receive(&hspi1, data, 2, 100);
  	MAX6675_CS1

  	if(data[0] & 1<<2) //в младшем байте[0] проверяем второй бит
    	{
    		status=1; //нет подключения
    	}
  	    else
  	    {
  	    	status=0; //подключен датчик
  	    }

  	MSBLSB = data[1] << 8 | data[0]; //Два байта определяем в один
  	MSBLSB = (0X0FFF &(MSBLSB>>3)); //Сдвигаем два байта на 3 и перемножаем, 15 бит убирается
   	return    (uint16_t)(MSBLSB/4)*Termopara_Correction_additive + Termopara_Correction_multiplicative;//Возвращаем значение в градусах с возможной калибровкой
  }
