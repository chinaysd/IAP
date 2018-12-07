#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "sc93f833x_c.h"

#define LED_NUM      2
#define LED_ERROR    1
#define LED_SUCCESS  0

#define LED1_PORT    P5
#define LED1_PIN     P50
#define LED1_SET(X)  ((X)?(LED1_PIN = 1):(LED1_PIN = 0))

#define LED2_PORT    P5
#define LED2_PIN     P51
#define LED2_SET(X)  ((X)?(LED2_PIN = 1):(LED2_PIN = 0))

typedef struct
{
   unsigned char ID;
}
LED_PARA_t;


unsigned char Led_App_Handle(unsigned char sum);



#endif