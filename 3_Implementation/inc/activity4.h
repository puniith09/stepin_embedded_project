

#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

#define F_CPU 16000000UL 	

#include<avr/io.h>
#include <util/delay.h>
#include <stdint.h>


void Init_USART(uint16_t);


char USART_Read();


void USART_Write(uint16_t);

#endif 

