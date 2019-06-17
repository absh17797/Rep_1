 A#include <IRremote.h>           //Library for IR Remote
IRsend irsend;
int sensor = 6;  
int LED = 13;
boolean status=false;
boolean temp; 
int timer=2000;
void setup() 
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
}
void loop()
{
if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(2000);
  for (int i=1;i<150;i++)
  {
  if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(2000);
  if(digitalRead(sensor) == HIGH ){timer=0; Serial.println("Timer set to ZERO");  break; }
   
  }
  Serial.println(timer);
  timer=timer+2000;
  }
  if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(5000);

  Serial.println("Waiting......");

  irsend.sendNEC(0x88C0051,28); 
  Serial.println("OFF    REMOTE SIGNAL SENT");
  timer=0;
  Serial.print("Timer again set too zero after off");
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  }
  }
  }
