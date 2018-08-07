#include <Servo.h> 

Servo servo1;

int trigPin = 2; //triggor pin
int echoPin = 3; // echo pin
long timeperiod, cm, inches; 
int ut=12;

int in1=4,in2=5,in3=6,in4=7,dir=0,det=0;
int minPulse = 600;   
int maxPulse = 2400;  

int userInput[3];    
int startbyte;      
int servo;           
int pos;             
int i; 
int angle=90;
int pinState = LOW;


int mint=0;
void setup() 
{ 
  pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(ut,OUTPUT);

  servo1.attach(9, minPulse, maxPulse);

  Serial.begin(9600);
   digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
   pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
} 

void loop() 
{ 
  analogWrite(10,255);
 analogWrite(11,255);

  if (Serial.available() > 2) {
    startbyte = Serial.read();
    if (startbyte == 255) {
      for (i=0;i<2;i++) {
        userInput[i] = Serial.read();
      }
      servo = userInput[0];
      pos = userInput[1];
      if (pos == 255) { servo = 255; }

      switch (pos) {
       case 10:

        
       dir=1;
       digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
        digitalWrite(in1,HIGH);
         digitalWrite(in2,LOW);
         digitalWrite(in3,LOW);
         digitalWrite(in4,HIGH);
        delay(30);
       digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);        
        pos=0;   
         break;
        
        case 20:
            //pos=5;
       dir=0;
      digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);        
         delay(30);
       digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);            
            pos=0;
         break;
         
         
         
       case 30:
            
      {      
       if(dir==0){
      digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
      digitalWrite(in1,LOW);
       digitalWrite(in2,HIGH);
       digitalWrite(in3,HIGH);
       digitalWrite(in4,LOW);        
         delay(30);
       digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);            
            pos=0;}
         else if(dir==1){   
        digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);
        digitalWrite(in1,HIGH);
         digitalWrite(in2,LOW);
         digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        delay(30);
       digitalWrite(in1,LOW);
       digitalWrite(in2,LOW);
       digitalWrite(in3,LOW);
       digitalWrite(in4,LOW);  
        }

       break;
       
    }
       
       case 11:
digitalWrite(ut, HIGH);
digitalWrite(ut, LOW);
det=1;
int duration, distance;
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if(distance>30){
 digitalWrite(ut, HIGH);
 digitalWrite(ut, LOW);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH); 
 delay(100);
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
     pos=0;
     break;
 }
 else{
  
  digitalWrite(ut, HIGH);
  digitalWrite(ut, LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
      pos=0;
      break;}
      }

    }
  }
}

