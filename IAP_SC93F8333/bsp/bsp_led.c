#include "bsp_led.h"


LED_PARA_t Led_Para[LED_NUM];


static unsigned char Led_Init(unsigned char id)
{
    if(id > LED_NUM)
    {
       return 1;
    }
	if(0 == id)
	{
	  P5CON |= 0X01;
	  P5PH  &= ~0X01;
	  LED1_SET(1);
	}
	else if(1 == id)
    {
      P5CON |= 0X02;
	  P5PH  &= ~0X02;
	  LED2_SET(1);
    }
	return 0;
}

static unsigned char Led_App_Init(LED_PARA_t *P)
{
  static unsigned char Led_Init(unsigned char ID);
  return  Led_Init(P->ID);
}

unsigned char Led_App_Handle(unsigned char sum)
{
    static unsigned char i;
	if(sum > LED_NUM)
		return 1;
	for(i = 0;i < sum;i ++)
	{
	   Led_Para[i].ID = i;
	   Led_App_Init(&Led_Para[i]);
	}
	if(i != sum)
	{
	    return 1;
	}
	else
	{
	    return 0;
	}
}










