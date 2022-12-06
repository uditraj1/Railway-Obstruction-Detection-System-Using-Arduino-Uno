const int trigPin = 9;
const int echopin= 10;
const int trigPin1 = 11;
const int echopin1= 12;
int t;
int d;
int t1;
long duration;
long duration1;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echopin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echopin1, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin,LOW);
delay(1000);
digitalWrite(trigPin,HIGH);
delay(1000);
digitalWrite(trigPin,LOW);
t=pulseIn(echopin,HIGH);
d=t*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print(“Distance1: ”);
//Serial.println(d);
digitalWrite(trigPin1,LOW);
delay(1000);
digitalWrite(trigPin1,HIGH);
delay(1000);
digitalWrite(trigPin1,LOW);
t=pulseIn(echopin1,HIGH);
distance=t*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print(“Distance2: ”);
//Serial.println(distance);
if(d<=10)
{
Serial.print(“A”);
delay(1000);
}
if(distance<=10)
{
Serial.print(“B”);
delay(1000);
}
}

CODE (RECEIVER):

//#############___________zigbee rx____________################
#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 5, 4, 3, 2); // sets the interfacing pins
Include<SoftwareSerial.h>
char c;
int i=0;
float mems;
int memspin=A0;
void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
pinMode(6, OUTPUT); // Sets the trigPin as an Output
pinMode(13, OUTPUT); // Sets the trigPin as an Output
pinMode(10, INPUT); //eye Blink
pinMode(7, INPUT); // Vibration
pinMode(A0, INPUT); // Vibration
lcd.setCursor(0,0);
lcd.print(“DRIVER”);
delay(1000);
//lcd.clear();

}
void loop()
{
if(Serial.available()>0)
{
c=Serial.read();
Serial.print(c);
if (c==’A’)
{
digitalWrite(6,LOW);
digitalWrite(13,HIGH);
delay(2000);
digitalWrite(13,LOW);
lcd.setCursor(0,1);
lcd.print(“UV1 ENGINE1 OFF”);
delay(500);
lcd.clear();
}
if (c==’B’)
{
digitalWrite(6,LOW);
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
lcd.setCursor(0,1);
lcd.print(“UV2ENGINE1OFF”);
delay(500);
lcd.clear();
}
}
digitalWrite(6,HIGH);
if(digitalRead(7)==LOW)
{
digitalWrite(6,LOW);
lcd.setCursor(0,0);
lcd.print(“Vibration ”);
lcd.setCursor(0,1);
lcd.print(“detected”);
delay(2000);
lcd.clear();
digitalWrite(6,HIGH);
}
mems=analogRead(memspin);
lcd.setCursor(0,0);
lcd.print(“Angle ”);
lcd.setCursor(0,1);
lcd.print(mems);
delay(2000);
lcd.clear();
if(mems>500)
{
digitalWrite(6,LOW);
delay(2000);
digitalWrite(6,HIGH);
}
if(digitalRead(10)==LOW )
{
i++;
lcd.setCursor(0,0);
lcd.print(“IR Level ”);
lcd.setCursor(0,1);
lcd.print(i);
delay(2000);
lcd.clear();
if(i>5)
{
digitalWrite(6,LOW);
lcd.setCursor(0,0);
lcd.print(“Drowsiness ”);
lcd.setCursor(0,1);
lcd.print(“detect”);
digitalWrite(13,HIGH);
delay(2000);
digitalWrite(13,LOW);
digitalWrite(6,LOW);
lcd.clear();
i=0;
}
}
}
