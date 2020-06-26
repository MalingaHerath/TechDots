/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int greenLedPin = 8;
int yellowLedPin = 9;
int redLedPin = 10;
int blueLedPin = 13;
int buzzer = 6;

int lightSensorPin = A0;
int analogValue = 0;
int temp = 0;
int tempsensor = A1;

int inches = 0;
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 6);
  // Print a message to the LCD.
  lcd.print("Weight of the Bin:");
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin,OUTPUT);
  pinMode(redLedPin,OUTPUT);
  pinMode(blueLedPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(analogValue);
 
  
  analogValue = analogRead(lightSensorPin);
  temp = analogRead(tempsensor);
  temp = temp * 0.48828125;
  if(analogValue < 50){            
    
    lcd.setCursor(2, 1);
  	lcd.print("KG");
    lcd.setCursor(4, 2);
  	lcd.print(" ");
  }
  else if(analogValue >= 50 && analogValue <= 100){
    lcd.setCursor(2, 1);
  	lcd.print("KG");
    lcd.setCursor(4, 1);
  	lcd.print(" ");
  }
  else{
     lcd.setCursor(3, 1);
  	 lcd.print("KG");
     digitalWrite(buzzer,HIGH);
  }
 
  
   // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
  
  if (inches<33.33){
  digitalWrite(redLedPin, HIGH); 
  }
  else if(inches>33.33 && inches<66.66){
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  
  }
  else{
  digitalWrite(greenLedPin, HIGH); 
  digitalWrite(redLedPin, LOW);

  }
  
  if (temp >= 45 && temp <=60 ){
  digitalWrite(blueLedPin, HIGH);
    
  }
  
  else if (temp < 40 || temp > 60 ){
  digitalWrite(redLedPin, HIGH);
  delay(100);  
  digitalWrite(redLedPin, LOW);
  }
  
   delay(200);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(blueLedPin,LOW);
  digitalWrite(buzzer,LOW);
}
 