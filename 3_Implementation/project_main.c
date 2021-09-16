


#include "activity1.h"
#include "activity2.h"
#include<avr/io.h>
#include "activity3.h"
#include <util/delay.h>
#include "activity4.h"

void initialize(void)
{
    
    DDRD=DDRD|(1<<4);
    DDRC=DDRC&~(1<<4);
    DDRC=DDRC &~(1<<5);
    InitADC();
    init_pwm();
    Init_USART(103);

}


int main(void)
{
    uint16_t temp;
    
    initialize();
    while(1)
    {
        if(SWITCH_ON && HEATER_ON) 
        {
            temp = 0;
            ledchange(LED_ON);
            temp=ReadADC(0);
            pwm(temp);
            _delay_ms(200);
            USART_Write(temp);
            }
        else
        {
            ledchange(LED_OFF);
        }
    }
    return 0;
}
