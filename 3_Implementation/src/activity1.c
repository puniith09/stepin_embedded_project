
#include<avr/io.h>
#include "activity1.h"

void ledchange(uint8_t v)
{
	LED_PORT = (v << LED_PIN);
}
