const int l1=2;
const int l2=3;   //naming left motor pins
const int r1=0;   //naming right motor pins
const int r2=1;
void Forward()              //Forward
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void Stop()                //Stop
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);   
  digitalWrite(r2,LOW);
}
void Reverse()             //Reverse
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void Right()               //Right
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void Left()               //Left
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void setup()
{
  Serial.begin(9600); //Baud Rate
  pinMode(l1,OUTPUT);//LEFT MOTOR
  pinMode(l2,OUTPUT); 
  pinMode(r1,OUTPUT); //Right motor
  pinMode(r2,OUTPUT);
}
void loop() //Infinite loop
{
  while(!Serial.available())
  {
    //do nothing
  }
  char c=Serial.read();   //Check if any key is pressed and copy the character value into c
  Serial.println(c);
  if(c=='A')
  {
    Left();             //Left
  }
  else if(c=='D')
  {
    Right();            //Right
  }
  else if(c=='W')
  {
    Forward();          //Forward
  }
  else if(c=='S')
  {
    Reverse();          //Reverse
  }
  else 
  Stop();
}
