#include "eeprom.h"

unsigned char code eep_flag[1]={0x12};

void eeprom_init(void)//EEPROM初始化
{
	if(eep_flag[0]==0x00)//判断是否第1次上电
	{
		eeprom_erase();//如果是第1次上电，清除EEPROM
		rom_write( 0xFF, (unsigned int)(eep_flag));	
	}
	if(eep_flag[0]==0x00)//判断是否第1次上电
	{
		eeprom_erase();//如果是第1次上电，清除EEPROM
		rom_write( 0xFF, (unsigned int)(eep_flag));	
	}	
}

/*****************************************************************************************
 * ROM写数据程序
 * 参数1：要写入的地址
 * 参数2：要写入的数据
 */
void rom_write(unsigned char eep_dat,unsigned int eep_add)
{	
	OPINX  = 0xC2;
	OPREG |= _b00001100;	
	
	IAPDAT=eep_dat;		
	IAPADH=eep_add/0x100;		
	IAPADL=eep_add%0x100;		
	IAPKEY=0xF0;		
												
	IAPCTL=0x0A;		
	_nop_();			
	_nop_();	
	_nop_();
	_nop_();
	
	OPINX  = 0xC2;
	OPREG &= ~_b00001100;					
}
/*****************************************************************************************
 * ROM读数据程序
 * 参数1：要读取的地址
 * 返回值：读取到的数据
 */
unsigned char rom_read(unsigned int eep_add)
{
	unsigned char eep_dat;
	unsigned int code *POINT=0x0000;
	
	eep_dat=*(POINT+eep_add);	
		
	return eep_dat;	
}
/*****************************************************************************************
 * EEPROM写数据程序
 * 参数1：要写入的地址
 * 参数2：要写入的数据
 */
void eeprom_write(unsigned char eep_dat,unsigned char eep_add)
{
	EA=0;				
	IAPADE=0x02;		
	IAPDAT=eep_dat;		
	IAPADH=0x00;		
	IAPADL=eep_add;		
	IAPKEY=0xF0;		
												
	IAPCTL=0x0A;		
	_nop_();			
	_nop_();	
	_nop_();
	_nop_();
	
	IAPADE=0x00;		
	EA=1;				
}



/*****************************************************************************************
 * EEPROM读数据程序
 * 参数1：要读取的地址
 * 返回值：读取到的数据
 */
unsigned char eeprom_read(unsigned char eep_add)
{
	unsigned char eep_dat;
	unsigned char code *POINT=0x0000;
	
	EA=0;			
	IAPADE= 0x02;	
	eep_dat=*(POINT+eep_add);	
	IAPADE= 0x00;	
	EA=1;			
	return eep_dat;	
}

/*****************************************************************************************
 * EEPROM数据全擦除
 *  
 *  
 */
void eeprom_erase(void)
{
	unsigned char eep_add;
	for(eep_add=0;eep_add<128;eep_add++)
	{
		eeprom_write(0x00,eep_add);
	}
}


