#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "delay.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
int main()
{
   /* PeriodicInterval
	ALL 500 ms do LED on    
     */
/* MSTK_voidSetPeriodicInterval(500,ms);			/*all 500ms do his action
void SysTick_Handler (void)
 {	 static u8 state =1;
 	 if(state==1)
 	 { state=0;
	MGPIO_voidSetPinDirection(PORTA,1 , GPIOA_OUTPUT_2MHZ , GPIOA_OUTPUT_PUSH_PULL);
 	MGPIO_voidSetPinValue(PORTA,1,1);		
 	 }
 	MSTK_voidResetFlag();		//set flag after do Timer
 }*/
 
 //--------------Single Interval--------------------------
/*	After 500 ms do LED on    
     */
/* MSTK_voidSetPeriodicInterval(500,ms);			/*all 500ms do his action
void SysTick_Handler (void)
 {	 static u8 state =1;
	if(state==0){
					MSTK_voidStop();
				}
 	 if(state==1)
 	 { state=0;
		MGPIO_voidSetPinDirection(PORTA,1 , GPIOA_OUTPUT_2MHZ , GPIOA_OUTPUT_PUSH_PULL);
		MGPIO_voidSetPinValue(PORTA,1,1);		
 	 }
 	MSTK_voidResetFlag();		//set flag after do Timer
 }*/
 
	/*BusyWait*/
	MSTK_voidInit();
	MGPIO_voidSetPinDirection(PORTA,0 , GPIOA_OUTPUT_2MHZ , GPIOA_OUTPUT_PUSH_PULL);
	while()
	{
	  MGPIO_voidSetPinValue(PORTA,1,1);
		MSTK_voidSetBusyWait(500,ms);			/*delay by 500ms*/
	}
}
/*
-----------RemaindingTime------------------
 int h = 0, m = 1;
    remainingTime (h, m);
    return 0;
Approach: 
 -Since the total minutes in a 24 hour complete day is 24 * 60 = 1440 minutes
 -Calculate the time completed in minutes
 -Calculate the time remaining in the form of minutes as total minutes – time completed
 -Convert the time remaining in the form of HH::MM



*/
