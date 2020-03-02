/*
 * TMU.c
 *
 * Created: 1/11/2020 6:05:02 PM
 *  Author: ahmad
 */ 
#include "DIO.h"
#include "TMU.h"
#include "interrupt.h"
#include "CPUSleep.h"
void LED0(void)
{
	DIO_Toggle(GPIOB, PIN0);
}
void LED1(void)
{
	DIO_Toggle(GPIOB, PIN1);
}
void LED2(void)
{
	DIO_Toggle(GPIOB, PIN2);
}
void LED3(void)
{
	DIO_Toggle(GPIOB, PIN3);
}
void LED4(void)
{
	DIO_Toggle(GPIOB, PIN4);
}
void LED5(void)
{
	DIO_Toggle(GPIOB, PIN5);
}
void LED6(void)
{
	DIO_Toggle(GPIOB, PIN6);
}
void LED7(void)
{
	DIO_Toggle(GPIOB, PIN7);
}

int main(void)
{	sei();
	DIO_Cfg_s DIO_Info = {GPIOB, FULL_PORT, OUTPUT};
	DIO_init(&DIO_Info);
	DIO_Write(GPIOB, FULL_PORT, LOW);
	TMU_Init();
	TMU_Start(LED0, 1, PERIODIC);
	TMU_Start(LED1, 2, PERIODIC);
	TMU_Start(LED2, 3, PERIODIC);
	TMU_Start(LED3, 4, PERIODIC);
	TMU_Start(LED4, 5, PERIODIC);
	TMU_Start(LED5, 6, PERIODIC);
	TMU_Start(LED6, 7, PERIODIC);
	TMU_Start(LED7, 8, PERIODIC);
	CPUSleep_Init();
	CPUSleep_setMode(CPUSLEEP_IDLE_MODE);
    while(1)
    {
        //TODO:: Please write your application code 
		TMU_Dispatcher();
		CPUSleep_enable();
    }
}