/*
 * main.c
 */

#include "tm4c123gh6pm.h"

#define SCB_CPAC (*((volatile unsigned int*)0xE000ED88))

 /*uart0 baudrate equal 9600 and two stop bits*/
void UART0_init(){
    SYSCTL_RCGCUART_R  |=1; //enable clock for uart0
    SYSCTL_RCGCGPIO_R  |=1; //enable clock for PORTA
    UART0_CTL_R         =0; //disable uart0
    /*to make the baudrate =9600  integer = 104 ,fraction =11 */
    UART0_IBRD_R=104;
    UART0_FBRD_R=11;

    UART0_LCRH_R =60;//frame is 8 bit
    UART0_CTL_R  = (1<<9)|(1<<8)|(1<<0);//enable rx , tx , uart0

    GPIO_PORTA_DEN_R   |=0X03;
    GPIO_PORTA_AFSEL_R |=0X03;
    GPIO_PORTA_DIR_R   |=3;
    GPIO_PORTA_PCTL_R   =0X11;


}

void UART0_send(unsigned char byte ){
    while(!(UART0_FR_R &(1<<7)));
    UART0_DR_R = byte;
}

unsigned char UART0_receive(){
    while(!(UART0_DR_R &UART_FR_RXFE));
    return UART0_DR_R;
}

int main(void) {
	UART0_init();
	UART0_send(5);
	while(1);

	return 0;
}
void SystemInit(void)
{
/* Grant coprocessor access*/
/* This is required since TM4C123G has a floating point coprocessor */
SCB_CPAC |= 0x00F00000;
}
