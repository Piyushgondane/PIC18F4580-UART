#include<p18f4580.h>

#define Tx TRISCbits.RC6 = 0
#define Rx TRISCbits.RC7 = 1

void delay(int a);
void main()
{
	char str[] = "PIYUSH";
	int i;

	TXSTA = 0X24;//TX ENA. ASY. HIGH SPEED
	RCSTA = 0X90;//RX ENA. 8 BIT CONFIG TX/RX
	SPBRG = 0X81;//D B.R. = 9600

while(1)
{ 	
	for(i=0;str[i]!=0;i++)
	{
	TXREG = str[i];
	delay(75);
	while(PIR1bits.TXIF == 0);
	PIR1bits.TXIF = 0; //CLEAR FLAG
	}
	while(1);
}
}
void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<=a;j++);
}


	