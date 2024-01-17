#include<LPC214x.h>
#include<stdio.h>
/*float rate;
float size=0;*/
unsigned char receive()
{
	while(!(U0LSR&0X01));
/*size += (sizeof(U0RBR)*8);  *i tried to display the data rate using this logic by calculating the number of bits transmitted every 2 seconds 
	T0PR=0x00000002;             with the help of timer module but i dont know if its correct as i have some problem with my keil software as it 
	T0MR0=0x00989680;            doesn't print the printf statement.*
	if(T0TC>=1)
	{
		rate=size/2;
		printf("%f",rate);
		T0MCR=0x03;
		size=0;
	}
	T0TCR=0x01;*/
	return(U0RBR);
}
void transmit(unsigned char ch)
{
	while(!(U0LSR&0x20));
	U0THR=ch;
}
void main()
{
	unsigned char key;
	float a;
	PINSEL0=5;
	U0LCR=0x83;
	U0DLM=0x01;
	U0DLL=0x87;//baud rate 2400
	U0LCR=0x03;
	while(1)
	{
		key=receive();
		transmit(key);
	}
}