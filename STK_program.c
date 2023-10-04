/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 18 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* Lower Layers */
#include <time.h>
/* Peripheral */
#include "STK_interface.h"
#include "STK_config.h"
#include "STK_priv.h"

void MSTK_voidStop(){
	/* Stop STK */
	CLR_BIT(MSTK->CTRL , 0);	//CLEAR DATA ---0

	/* Disable Interrupt */
	CLR_BIT(MSTK->CTRL , 1);		//CLEAR ALL DATA IF HAD A PERIVIACE DATA
}

void MSTK_voidResetFlag(){
	u8 Loc_u8Flag ;
	Loc_u8Flag = GET_BIT(MSTK->LOAD,16);
}

/*INTIAL TIMER
 * CLEAR BIT 2 AT REGISTER 2
 * CTRL OR WITH SHIFT COUNTER BY 2 DIGITS
 * */
void MSTK_voidInit(){

	/* Configure Clock Source */
	CLR_BIT(MSTK->CTRL , 2);
	MSTK->CTRL |= (COUNTER_INPUT<<2);
}
void MSTK_voidSetBusyWait(u32 Copy_u32Value , u8 Copy_u8Unit){
	/* Stop STK */
	CLR_BIT(MSTK->CTRL , 0);	//CLEAR DATA AT BIT 0

	// 1 --> us --> 1
	// 1 --> ms --> 1000
	// 1 --> s  --> 1000000
	/*TIMER ------TIME BY MICRO SECOND */
	/* Reload Value */
	switch(Copy_u8Unit){
	case us : MSTK->LOAD = (Copy_u32Value * 1) 		 ; break ;
	case ms : MSTK->LOAD = (Copy_u32Value * 1000)    ; break ;
	case s  : MSTK->LOAD = (Copy_u32Value * 1000000) ; break ;
	}

	/* Disable Interrupt */
	CLR_BIT(MSTK->CTRL,1);

	/* Enable STK */
	SET_BIT(MSTK->CTRL,0);

	/* Busy Wait */
	while(GET_BIT(MSTK->CTRL,16)==0);

	MSTK_voidResetFlag();
	//Set Flag after do timer
}


void MSTK_voidSetSingleInterval(u32 Copy_u32Value , u8 Copy_u8Unit){
	/* Stop STK */
	CLR_BIT(MSTK->CTRL , 0);

	// 1 --> us --> 1
	// 1 --> ms --> 1000
	// 1 --> s  --> 1000000

	/* Reload Value */
	switch(Copy_u8Unit){
	case us : MSTK->LOAD = (Copy_u32Value) 		     ; break ;
	case ms : MSTK->LOAD = (Copy_u32Value * 1000)    ; break ;
	case s  : MSTK->LOAD = (Copy_u32Value * 1000000) ; break ;
	}

	/* Enable Interrupt */
	SET_BIT(MSTK->CTRL,1);

	/* Enable STK */
	SET_BIT(MSTK->CTRL,0);

}
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Value , u8 Copy_u8Unit){
	/* Stop STK */
	CLR_BIT(MSTK->CTRL , 0);

	// 1 --> us --> 1
	// 1 --> ms --> 1000
	// 1 --> s  --> 1000000

	/* Reload Value -1 */
	switch(Copy_u8Unit){
	case us : MSTK->LOAD = (Copy_u32Value-1) 		     ; break ;
	case ms : MSTK->LOAD = ((Copy_u32Value * 1000)-1)    ; break ;
	case s  : MSTK->LOAD = ((Copy_u32Value * 1000000)-1) ; break ;
	}

	/* Enable Interrupt */
	SET_BIT(MSTK->CTRL,1);

	/* Enable STK */
	SET_BIT(MSTK->CTRL,0);
}
u32  MSTK_u32GetElapsedTime()
{
		clock_t start, end;
	    double elapsed_time;

	    start = clock();
	    // Code to measure the elapsed time
	    end = clock();
	    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	    return 0;
}

u32  MSTK_u32GetRemainingTime(u32 startTime,u32 elapsedTime)
{
	 u32 remainingTime = startTime - elapsedTime;
	 return COUNTER_INPUT;
}


