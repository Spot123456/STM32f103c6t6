
#ifndef I2C_PRIVATE_h
#define	I2C_PRIVATE_h





typedef struct
{
	u32		CR1;
	u32		CR2;
	u32		OAR1;
	u32		OAR2;
	u32		DR;
	u32		SR1;
	u32		SR2;
	u32		CCR;
	u32		TRISE;


}I2C_Type;

#define			I2C1     ((I2C_Type*)(0x40005400))





#endif // ! I2C_PRIVATE_h