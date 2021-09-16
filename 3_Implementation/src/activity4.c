


#include "activity4.h"

int i = 0;

void Init_USART(uint16_t baud_rate){
    
    UBRR0L = baud_rate;
    UBRR0H = (baud_rate>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);

    
    UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0);
}

char USART_Read(){
    
    while(!(UCSR0A & (1<<RXC0))){
        
    }
    return UDR0;
}

void USART_Write(uint16_t temp){
    if(temp>=0 && temp<=200){
        unsigned char temperature[] = "Temperature is 20 degree Celsius"; 
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = temperature[i];            
            i++;                             
        }
    }
    else if(temp>=210 && temp<=500){
        unsigned char temperature[] = "Temperature is 25 degree Celsius"; 
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = temperature[i];           
            i++;                             
        }
    }
    else if(temp>=510 && temp<=700){
        unsigned char temperature[] = "Temperature is 29 degree Celsius"; 
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = temperature[i];            
            i++;                             
        }
    }
    else if(temp>=710 && temp<=1024){
        unsigned char temperature[] = "Temperature is 33 degree Celsius"; 
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = temperature[i];            
            i++;                             
        }
    }
    else{
        unsigned char temperature[] = "Temperature is not within the limit";  
        i = 0;
        while(temperature[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = temperature[i];            
            i++;                             
        }
    }
    while (!( UCSR0A & (1<<UDRE0)));   
		 UDR0 = '\n';   
    while (!( UCSR0A & (1<<UDRE0)));  
		 UDR0 = '\r';					    
    _delay_ms(2000);
}

