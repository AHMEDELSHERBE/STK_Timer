/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 18 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/

/* Registers */
typedef struct{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
	volatile u32 CALIB ;
}MSTK_tReg;

#define MSTK  ((volatile MSTK_tReg*)0xE000E010)		/*based Adress*/
/*MSTK pointer to MSTK_tReg */
#define AHB_DIV_8  0		/*Advanced high Bus (core peripheral)/8*/
#define AHB_DIV_1  1
