#include <DistanceGP2Y0A41SK.h>

DistanceGP2Y0A41SK Dist;    //Declaration for IR
DistanceGP2Y0A41SK Dist2;
int distance1;
int distance2;

const int pwPin1 = 3;      //Declaration for ultrasonic //right
const int pwPin2 = 5;                                   //left
int triggerPin1 = 2;
long sensor1, sensor2, d1, d2;
int flag=0;

void setup () {
  Serial.begin(9600);
  pinMode(pwPin1, INPUT);
  pinMode(pwPin2, INPUT);
  pinMode(triggerPin1, OUTPUT);
  Dist.begin(A0);                //right
  Dist2.begin(A1);              //left
}

void read_sensor(){
  sensor1 = pulseIn(pwPin1, HIGH);
  d1 = sensor1/58; //makes the reported range the distance in centimeters
  delay(20); //helped make the range readings more stable
  sensor2 = pulseIn(pwPin2, HIGH);
  d2 = sensor2/58;
}

void start_sensor(){
  digitalWrite(triggerPin1,HIGH);
  delay(1);
  digitalWrite(triggerPin1,LOW);
}

void ir_read(){
  distance1 = Dist.getDistanceCentimeter();
  delay(270);
  distance2 = Dist2.getDistanceCentimeter();
  delay(270);
}

char inByte = ' ';   
void loop () 
{
  start_sensor();
  read_sensor();
      Serial.print(d1);
      Serial.print(" ");
      Serial.print(d2);
      Serial.print(" ");
      
      ir_read();
  
      Serial.print(distance1);
      Serial.print(" ");
      Serial.print(distance2);
      Serial.print("\n");
      if(distance1 > 20 || distance2 > 20)
          {
             if (d1 > 70 || d2 > 70)
                 {
                   Serial.write("w");
                 }
          
                   if(d1 > 70 && d2 <= 70)
                         {
                             Serial.write("d");
                         }
                           else if(d1 <= 70 && d2 > 70)
                                 {
                                   Serial.write("a");
                                 }
                   if(d1 < 70 && d2 < 70)
                         {
                           if(d1>d2)
                           {
                               Serial.write("d");
                         }      
                           else 
                           {
                               Serial.write("a");
                         }  
                         }
          }

       else if (distance1 < 15 || distance2 < 15)
              {
                 Serial.write("s");
                 
              }   
                
}
