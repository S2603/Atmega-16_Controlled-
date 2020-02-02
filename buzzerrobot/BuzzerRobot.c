#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0b00000000;
DDRB=0b11111111;
PORTD=0b11111111;
int c=0;
while(1)
{
c=PIND;
if(c==0b11111100)
PORTB=0b00001010;
if(c==0b11111101)
PORTB=0b00001001;
if(c==0b11111110)
PORTB=0b00000110;
if(c==0b11111111)
PORTB=0b00011010;
}
}