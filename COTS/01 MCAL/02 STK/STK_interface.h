#ifndef		STK_INTERFACE_H
#define		STK_INTERFACE_H




void	STK_voidInit();
void	STK_voidSetBusyWait(u32	Ticks);
void	STK_voidSetIntervalSingle(u32	Ticks, void (*Pf)(void));
void	STK_voidSetIntervalPeriodic(u32	Ticks, void (*Pf)(void));
void	STK_voidStopInterval();
u32		STK_u32GetElapsedTime();
u32		STK_u32GetRemainingTime();


#endif
