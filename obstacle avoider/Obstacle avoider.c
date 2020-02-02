#include <avr/io.h>
#include <util/delay.h>
void main()
{
  DDRD=0b00000000;  //Setting partt D as input part
  DDRB=0b11111111;  //Setting part B as an output part
  PORTD=0b11111111; //Pulling up all parts of part D
  int c;
  while (1)
  {
    c = PIND;
    if (c == 0b11111111)   //No obstacle
      PORTB = 0b00001010;  //Forward
    if (c == 0b11111110)   //Obstacle to the right
      PORTB = 0b00000110;  //Turn left
    if (c == 0b11111101)   //Obstacle at the centre
    {
      PORTB = 0b00000101;  //Go back and turn right
      _delay_ms(300);
      PORTB = 0b00001001;
      _delay_ms(200);
    }
    if (c == 0b11111100)   //Obstacle at centre and right 
    {
      PORTB = 0b00000101;  //Go back and turn left
      _delay_ms(300);
      PORTB = 0b00000110;
      _delay_ms(200);
    }
    if (c == 0b11111011)   //Obstacle at left
      PORTB = 0b00001001;  //Turn right
    if (c == 0b11111010)   //Obstacle on both sides of robot
    {
      PORTB = 0b00000101;  //Go back and turn right
      _delay_ms(300);
      PORTB = 0b00001001;
      _delay_ms(200);
    }
    if (c == 0b11111001)   //Obstacle on centre and left
    {
      PORTB = 0b00000101;   //Go back and turn right
      _delay_ms(300);
      PORTB = 0b00001001;
      _delay_ms(200);
    }
    if (c == 0b11111000)   //Obstacle on alll sides
    {
      PORTB = 0b00000101;   //U turn
      _delay_ms(800);
      PORTB = 0b00001001;
      _delay_ms(1000);
    }
  }
}
