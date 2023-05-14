
#include "Delay.h"


void	_delay_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}



