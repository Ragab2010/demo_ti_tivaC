
/* PORTF data register */
#define PORTFDAT (*((volatile unsigned int*)0x400253FC))
/* PORTF data direction register */
#define PORTFDIR (*((volatile unsigned int*)0x40025400))
/* PORTF digital enable register */
#define PORTFDEN (*((volatile unsigned int*)0x4002551C))
/* run mode clock gating register */
#define RCGCGPIO (*((volatile unsigned int*)0x400FE608))
/* coprocessor access control register */
#define SCB_CPAC (*((volatile unsigned int*)0xE000ED88))
	

void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++){} /* do nothing for 1 ms */
}

 
/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access*/
/* This is required since TM4C123G has a floating point coprocessor */
SCB_CPAC |= 0x00F00000;
}



int main(){
	RCGCGPIO |=(1<<5);
	PORTFDIR |=(1<<1)|(1<<2)|(1<<3);//make the three led as output
	PORTFDIR &=~((1<<0)|(1<<4));
	/* set PORTF pin3-1 as digital pins */
	PORTFDEN = 0x0E;
	while(1){
		while(PORTFDAT &(1<<0)){
			PORTFDAT =(1<<1);
		}
		PORTFDAT =(1<<2);
	}
		
return  0;
}





