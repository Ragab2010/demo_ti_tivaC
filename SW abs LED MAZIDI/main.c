#include <TM4C123GH6PM.h>
int main(void)
{
unsigned int value;
SYSCTL->RCGCGPIO |= 0x20; /* enable clock to GPIOF */
GPIOF->LOCK = 0x4C4F434B; /* unlock commit register */
GPIOF->CR = 0x01; /* make PORTF0 configurable */
GPIOF->DIR = 0x02; /* set PORTF1 pin as output (LED) pin */
/* and PORTF0 as input, SW2 is on PORTF0 */
GPIOF->DEN = 0x03; /* set PORTF pins 1-0 as digital pins */
GPIOF->PUR = 0x01; /* enable pull up for pin 0 */
while(1)
{
//value = GPIOF->DATA; /* read data from PORTF */
//value = ~value; /* switch is low active; LED is high active */
//value = value << 1; /* shift it left to display on red LED */GPIOF->DATA = value; /* put it on red LED */
//
		while(!(GPIOF->DATA & 1))
			GPIOF->DATA=2;
		GPIOF->DATA =0;
}
} 
/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
SCB->CPACR |= 0x00F00000;
}