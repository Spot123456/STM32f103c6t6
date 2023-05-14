#ifndef		DMA_INTERFACE_H
#define		DMA_INTERFACE_H

#include "DMA_config.h"
#include "DMA_private.h"
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);
void	DMA1_voidChannelInit(u8 channel_no ,u8 from_to);


#endif
