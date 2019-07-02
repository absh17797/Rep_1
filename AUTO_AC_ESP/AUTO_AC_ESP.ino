#include <UbidotsMicroESP8266.h>
#include <IRremote.h>           //Library for IR Remote

#define TOKEN  "A1E-TvDESFa7qD2CibLpVV8a0ORdq4rCni"  // Put here your Ubidots TOKEN
#define WIFISSID "nobita" // Put here your Wi-Fi SSID
#define PASSWORD "abhishek" // Put here your Wi-Fi password
Ubidots client(TOKEN);


IRsend irsend;
int sensor = 6;  
int LED = 13;
boolean status=false;
boolean temp; 
long timer=2000;
void setup() 
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);

  client.wifiConnection(WIFISSID, PASSWORD);
}
void loop()
{
if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(2000);
  for (int i=0;i<30;i++)
  {
  if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(2000);
  if(digitalRead(sensor) == HIGH ){ delay(2500); if(digitalRead(sensor) == HIGH ) { timer=0; Serial.println("Timer set to ZERO");  break; }}
   
  }
  Serial.print((timer/1000));
  Serial.println("s");
  int t = timer/1000;
  client.add("No-Movement", t);
  client.sendAll(true);
  
  timer=timer+2000;
  }
  if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(3000);

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
