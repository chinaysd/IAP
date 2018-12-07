#include "system.h"

TIMEOUT_PARA TimeOut_Para[2];
unsigned char Value;


void System_Init(void)
{
  TimeOutDet_Init();
  Led_App_Handle(LED_NUM);
  eeprom_init();
  
}


void System_Handle(void)
{
   #if 1
   if(TimeOutDet_Check(&TimeOut_Para[0]))
   {
     TimeOut_Record(&TimeOut_Para[0],1000);  
   }
   eeprom_write(0x02,0xff);
   Value = eeprom_read(0xff);
   if(Value == 0x02)
   {
      LED1_SET(0);
      LED2_SET(0);
   }
   else
   {
      LED1_SET(1);
      LED2_SET(1);
   }
   #endif
   #if 0
   rom_write(0x01,0x01);
   Value = rom_read(0x01);
   if(0x01 == Value)
   {
     LED1_SET(0);
     LED2_SET(0);
   }
   else
   {
     LED1_SET(1);
     LED2_SET(1); 
   }
   #endif
}



