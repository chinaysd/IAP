#include "eeprom.h"

unsigned char code eep_flag[1]={0x12};

void eeprom_init(void)//EEPROM��ʼ��
{
	if(eep_flag[0]==0x00)//�ж��Ƿ��1���ϵ�
	{
		eeprom_erase();//����ǵ�1���ϵ磬���EEPROM
		rom_write( 0xFF, (unsigned int)(eep_flag));	
	}
	if(eep_flag[0]==0x00)//�ж��Ƿ��1���ϵ�
	{
		eeprom_erase();//����ǵ�1���ϵ磬���EEPROM
		rom_write( 0xFF, (unsigned int)(eep_flag));	
	}	
}

/*****************************************************************************************
 * ROMд���ݳ���
 * ����1��Ҫд��ĵ�ַ
 * ����2��Ҫд�������
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
 * ROM�����ݳ���
 * ����1��Ҫ��ȡ�ĵ�ַ
 * ����ֵ����ȡ��������
 */
unsigned char rom_read(unsigned int eep_add)
{
	unsigned char eep_dat;
	unsigned int code *POINT=0x0000;
	
	eep_dat=*(POINT+eep_add);	
		
	return eep_dat;	
}
/*****************************************************************************************
 * EEPROMд���ݳ���
 * ����1��Ҫд��ĵ�ַ
 * ����2��Ҫд�������
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
 * EEPROM�����ݳ���
 * ����1��Ҫ��ȡ�ĵ�ַ
 * ����ֵ����ȡ��������
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
 * EEPROM����ȫ����
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


