#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include<Servo.h>
Servo servo;
SoftwareSerialGsm(9, 10); //(TX,RX)
charphone_no[] = "7756899034"; //replace with phone no. to get sms
#define trigPin 12
#define echoPin 11
intconst trigPin1 = 7;
intconst echoPin1 = 8;
long duration1;//dist1=person,
long distance1;
long duration; //dist=garbage threshold
long distance;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int flag =0;
TinyGPSgps; //Creates a new instance of the TinyGPS object

void setup()
{
Serial.begin(9600);
servo.attach(3);
Gsm.begin(9600)
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led3,HIGH);
digitalWrite(led4,HIGH);
delay(1000);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,HIGH);
delay(500);
}

void loop()
{
digitalWrite(trigPin, LOW);
delay(10);
digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin,HIGH);
distance= duration*0.034/2;
Serial.println(duration);
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
delay(100);
Serial.println("-----");
digitalWrite(trigPin1, LOW);
delay(10);
digitalWrite(trigPin1, HIGH);
delay(100);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1,HIGH);
distance1= duration1*0.034/2;
Serial.println(duration1);
Serial.print("Distance1: ");
Serial.print(distance1);
Serial.println(" cm");
delay(100);
Serial.println("-----");
if(distance>30)
{ digitalWrite(led1,LOW);
delay(100);
digitalWrite(led2,LOW);
delay(100);
digitalWrite(led3,LOW);
delay(100);
}
if(distance<10)
{
digitalWrite(led1,HIGH);
delay(100);
digitalWrite(led2,LOW);
delay(100);
digitalWrite(led3,LOW);
delay(100);
boolnewData = false;
unsigned long chars;
unsigned short sentences, failed;

// For one second we parse GPS data and report some key values


for (unsigned long start = millis(); millis() - start < 1000;)
{
while (Serial.available())
{ char c = Serial.read();
Serial.print(c);
if (gps.encode(c))
newData = true; }
}
if (newData) //If newData is true
{
float flat, flon;
unsigned long age;
gps.f_get_position(&flat, &flon, &age);
Gsm.print("AT+CMGF=1\r");
delay(400);
Gsm.print("AT+CMGS=\"");
Gsm.print(phone_no);
Gsm.println("\"");
delay(300);
Gsm.print("http://maps.google.com/maps?q=loc:");
// Gsm.print("Latitude = ");
Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
//Gsm.print(" Longitude = ");


Serial.print(",");
Gsm.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
delay(200);
Gsm.println((char)26); // End AT command with a ^Z, ASCII code 26
delay(200);
Gsm.println();
delay(200);
}
Serial.println(failed);
// Serial.println("** No characters received from GPS: check wiring **");
}
if (distance>=10 && distance<20)
{ digitalWrite(led2,HIGH);
delay(100);
digitalWrite(led1,LOW);
delay(100);
digitalWrite(led3,LOW);
delay(100);
}
if(distance>=20 && distance<30)
{ digitalWrite(led3,HIGH);
delay(100);
digitalWrite(led1,LOW);


delay(100);
digitalWrite(led2,LOW);
delay(100);
}
if (distance1>= 0 && distance1<20)
{flag=1; }
else
{flag=0; }
if (distance >=10 && distance<40 && distance1>=0 && distance1<20)
{
servo.write(50);
delay(100);
Serial.println("Open the Lid of the dustbin");
}
Else
{ if (flag==0)
{ servo.write(160);
delay(100);
Serial.println("Close the Lid of the dustbin")
}
}
delay(160);
}
