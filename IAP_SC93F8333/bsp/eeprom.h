#ifndef	_EEPROM_H_
#define	_EEPROM_H_

#include "SC93F833X_C.h"
#include "intrins.h"

#define _b00001100      0x0c


void eeprom_init(void);


/*****************************************************************************************
 * ROM写数据程序
 * 参数1：要写入的地址
 * 参数2：要写入的数据
 */
void rom_write(unsigned char eep_dat,unsigned int eep_add);
/*****************************************************************************************
 * ROM读数据程序
 * 参数1：要读取的地址
 * 返回值：读取到的数据
 */
unsigned char rom_read(unsigned int eep_add);


/*****************************************************************************************
 * EEPROM写数据程序
 * 参数1：要写入的地址
 * 参数2：要写入的数据
 */
void eeprom_write(unsigned char eep_dat,unsigned char eep_add);


/*****************************************************************************************
 * EEPROM读数据程序
 * 参数1：要读取的地址
 * 返回值：读取到的数据
 */
unsigned char eeprom_read(unsigned char eep_add);


/*****************************************************************************************
 * EEPROM数据全擦除
 *  
 *  
 */
void eeprom_erase(void);



#endif