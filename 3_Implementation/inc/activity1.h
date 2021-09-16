#ifndef __LEDSTAT_H_
#define __LEDSTAT_H_

#include <avr/io.h>
#include "activity1.h"



#define LED_ON 	(0x01)			
#define LED_OFF	(0x00)			
#define F_CPU 16000000UL 	
#define LED_PORT (PORTD)    
#define LED_PIN  (PORTD4)   
#define SWITCH_ON (PINC&(1<<5)) 
#define HEATER_ON (PINC&(1<<4)) 


void ledchange(uint8_t v);


#endif 
