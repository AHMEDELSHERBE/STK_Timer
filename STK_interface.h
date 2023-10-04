/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 18 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/


void MSTK_voidInit();														/*Enable for Timer(Case busy Waite)*/
void MSTK_voidSetBusyWait(u32 Copy_u32Value , u8 Copy_u8Unit);				/*Like delay*/
void MSTK_voidSetSingleInterval(u32 Copy_u32Value , u8 Copy_u8Unit);		/*Timer After 500ms*/
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Value , u8 Copy_u8Unit);		/*Timer all 500ms*/
u32  MSTK_u32GetElapsedTime();
u32  MSTK_u32GetRemainingTime(u32 startTime,u32 elapsedTime);

void MSTK_voidResetFlag();
void MSTK_voidStop();

/* DEFINATION  BY UNITS  */
typedef enum{
	us ,
	ms ,
	s
}MSTK_tUnits;
