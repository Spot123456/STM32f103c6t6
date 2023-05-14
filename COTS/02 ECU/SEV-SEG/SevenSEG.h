/*
 * SevenSEG.h
 *
 * Created: 2/24/2023 6:47:15 PM
 *  Author:  Ahmed Nour
 */ 


#ifndef SEVENSEG_H_
#define SEVENSEG_H_
#include "Std_Types.h"
#include "Bit_Math.h"


#include "DIO_private.h"
#include "SevenSEG_config.h"

void sev_segment_init();
void seven_segment_enable(EN_Enable_segment EN);
void seven_segment_Disable(EN_Enable_segment EN);
void seven_segment_write_NO(u8 No);
void two_sev_seg(u8 No);



#endif /* SEVENSEG_H_ */
