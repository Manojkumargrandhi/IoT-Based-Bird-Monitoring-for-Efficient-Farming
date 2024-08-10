#include <Servo.h>
float sig=0;
int pos = 0;
int thr=620;
int servo=13;
int repeat=0;
int speaker=9;

Servo servo_13;

void setup()
{
  servo_13.attach(13);
  pinMode(A0,INPUT);
  pinMode(servo,OUTPUT);
  pinMode(speaker,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  sig=analogRead(A0);
  Serial.println(sig);
  delay(500);
  if (sig>thr)
  {
    servo=1;
   digitalWrite(speaker,HIGH);
    for(repeat=0;repeat<=2;repeat+=1)
    {
  for (pos = 0; pos <= 180; pos += 1)
   {
    // tell servo to go to position in variable 'pos'
    servo_13.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 180; pos >= 0; pos -= 1) 
  {
    // tell servo to go to position in variable 'pos'
   
    servo_13.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  }
  }
   digitalWrite(speaker,LOW);
  
}