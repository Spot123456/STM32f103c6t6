#ifndef		NVIC_PRIVATE_H
#define		NVIC_PRIVATE_H


#define			NVIC_BASE_ADD			(0xE000E100)

#define			NVIC_ISER0				*((u32 *)(NVIC_BASE_ADD + 0x000))
#define			NVIC_ISER1				*((u32 *)(NVIC_BASE_ADD + 0x004))

#define			NVIC_ICER0				*((u32 *)(NVIC_BASE_ADD + 0x080))
#define			NVIC_ICER1				*((u32 *)(NVIC_BASE_ADD + 0x084))

#define			NVIC_ISPR0				*((u32 *)(NVIC_BASE_ADD + 0x100))
#define			NVIC_ISPR1				*((u32 *)(NVIC_BASE_ADD + 0x104))


#define			NVIC_ICPR0				*((u32 *)(NVIC_BASE_ADD + 0x180))
#define			NVIC_ICPR1				*((u32 *)(NVIC_BASE_ADD + 0x184))

#define			NVIC_IABR0				*((u32 *)(NVIC_BASE_ADD + 0x200))
#define			NVIC_IABR1				*((u32 *)(NVIC_BASE_ADD + 0x204))

#define			NVIC_IPR				((u8 *)(NVIC_BASE_ADD + 0x300))

#define			GRB_16_SUB_00			(0x05FA0300)
#define			GRB_08_SUB_02			(0x05FA0400)
#define			GRB_04_SUB_04			(0x05FA0500)
#define			GRB_02_SUB_08			(0x05FA0600)
#define			GRB_00_SUB_16			(0x05FA0700)
#endif




