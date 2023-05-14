



#include "DMA_interface.h"

#ifndef		NULL
#define		NULL	(void *)0
#endif

static	void	(*DMA1_CallBack)(void)	=	NULL;

void	DMA1_voidChannelInit(u8 channel_no ,u8 from_to)
{
	/*
	Memory to Memory
	priority very high
	Size (Source & Destination) u32
	MINC, PINC enabled
	Direction read from Peripheral
	Transfere Complete Interrupt
	Channel Disable
	*/
	//DMA1 ->	Channel[0].CCR = 0x00007AC2;  // test DMA


	// memory to memory : i.e memory work without being triggered
	// REQ by the peripheral

	SET_BIT(DMA1->Channel[channel_no].CCR,14);

	// periority : very high
	SET_BIT(DMA1->Channel[channel_no].CCR,13);
	SET_BIT(DMA1->Channel[channel_no].CCR,12);

	// MSIZE & PSIZE --> u32
	//MSIZE --> memory size u32
	SET_BIT(DMA1->Channel[channel_no].CCR,11);
	CLR_BIT(DMA1->Channel[channel_no].CCR,10);
	//PSIZE --> peripheral size u32
	SET_BIT(DMA1->Channel[channel_no].CCR,9);
	CLR_BIT(DMA1->Channel[channel_no].CCR,8);

	switch(from_to)
	{
	case Arr_TO_Arr :
		SET_BIT(DMA1->Channel[channel_no].CCR,7);	//DINC (MINC)
		SET_BIT(DMA1->Channel[channel_no].CCR,6);	//SINC (PINC)
		break;
	case Peri_TO_Arr :
		SET_BIT(DMA1->Channel[channel_no].CCR,7);	//DINC (MINC)
		CLR_BIT(DMA1->Channel[channel_no].CCR,6);	//SINC (PINC)
		break;
	case Arr_TO_Peri	 :
		CLR_BIT(DMA1->Channel[channel_no].CCR,7);	//DINC (MINC)
		SET_BIT(DMA1->Channel[channel_no].CCR,6);	//SINC (PINC)
		break;
	case Peri_TO_Peri :
		CLR_BIT(DMA1->Channel[channel_no].CCR,7);	//DINC (MINC)
		CLR_BIT(DMA1->Channel[channel_no].CCR,6);	//SINC (PINC)
		break;
	default: // error handler
		break;
	}
	//circular mode off
	CLR_BIT(DMA1->Channel[channel_no].CCR,5);

	//read from the peripheral
	CLR_BIT(DMA1->Channel[channel_no].CCR,4);

	// open (enable) the flag complete , half , error
	SET_BIT(DMA1->Channel[channel_no].CCR,3);	// error
	SET_BIT(DMA1->Channel[channel_no].CCR,2);	// half
	SET_BIT(DMA1->Channel[channel_no].CCR,1);	// full

}

void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[0].CCR,0);
	
	DMA1 -> Channel[0].CPAR	=	SrcAdd;			// source add
	DMA1 -> Channel[0].CMAR	=	DestAdd;		// destination add
	
	/*	Load the Block Length				*/
	DMA1 -> Channel[0].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  Enabled to strat transfere*/
	SET_BIT(DMA1 -> Channel[0].CCR,0);	
}

void	DMA1_voidSetCallBack(void (*pf)(void))
{
	if (pf != NULL)
	{
		DMA1_CallBack = pf;
	}
}


void	DMA1_Channel0_IRQHandler()
{
	/*		Toggle led		*/

	// error flag
	if ((GET_BIT(DMA1->ISR,1))==1)
	{
		//
	}else if ((GET_BIT(DMA1->ISR,2))==1)
	{
		//
	}else if ((GET_BIT(DMA1->ISR,3))==1)
	{
		//Report Error DMA1 transfere error
	}
	DMA1_CallBack();


}





