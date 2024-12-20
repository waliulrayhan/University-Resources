#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

#define trigPin 3
#define echoPin 2


void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop()
{
  long duration, distance;
  float met;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  met = distance/100.00;
  lcd.setCursor(0,0);
  lcd.print("Distance Is : ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.setCursor(4,1);
  lcd.print("CM");
  lcd.setCursor(10,1);
  lcd.print(met);
  lcd.setCursor(15,1);
  lcd.print("M");
  delay(600);
  lcd.clear();
}