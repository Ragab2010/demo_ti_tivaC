/*
 * main.c
 */

#include "C:\ti\TivaWare_C_Series-2.1.3.156\inc\TM4C123GH6PM.h"
#include "stdint.h"
int main(void) {
/*    SYSCTL->RCGCGPIO = (1<<5);
    GPIOF->DIR  |= (1<<2);// MAKE PF2 OUTPUT (GREEN LED)
    GPIOF->DIR  |= (1<<0);//make PF0 AS INPUT (SWITCH)
    GPIOF->DEN   = (1<< 0 | 1<<2);//MAKE PF0 , PF2  DIGITAL I/O
    GPIOF->PUR   = (1<< 0);//PULL-UP FOR SW1 PF0
    GPIOF->DATA &=~(1<<2);*/


    SYSCTL_RCGCGPIO_R = (1<<5);
   // GPIO_PORTF_AHB_DIR_R  |=(1<<2);
    GPIO_PORTF_AHB_DIR_R  |=(1<<1);
    GPIO_PORTF_AHB_DEN_R  =(1<<1);
   // GPIO_PORTF_AHB_PUR_R   = (1<< 3);//PULL-UP FOR SW1 PF0
    //GPIO_PORTF_AHB_DATA_R &=~(1<<2);
    for(;;){

//        while(!(GPIO_PORTF_AHB_DATA_R  & (1<<3))){
//            GPIO_PORTF_AHB_DATA_R |=(1<<2);
//        }
       GPIO_PORTF_AHB_DATA_R |=(1<<1);
    }


	return 0;
}

void SystemInit(void)
{
    /* Grant coprocessor access */
    /* This is required since TM4C123G has a floating point coprocessor */
    NVIC_CPAC_R |= 0x00F00000;
}
