#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "SR04.h"


int tonePin = 10;
int LED_white = 3;
int LED_red = 5;


#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
   Serial.begin(9600);
   delay(100);
}

void lcd_screen_warning()
{
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("WARNING");
}

void lcd_screen_safe()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("SAFE DISTANCE");
}

void led_white()
{
    digitalWrite(LED_white, HIGH);
    delay(100);
    digitalWrite(LED_white,LOW);
}


void led_red()
{
    digitalWrite(LED_red, HIGH);
    delay(100);
    digitalWrite(LED_red,LOW);
}

void buzz()
{
    tone(10, 100,100);
}


void loop()
{

   a=sr04.Distance();
   if(a<12`){
    led_red();
    lcd_screen_warning();
    buzz();
    delay(50);
    Serial.print(a);
    Serial.println("cm");
    delay(10);
    
   }
   else{

    led_white();
    lcd_screen_safe();
    delay(50);
    Serial.print(a);
    Serial.println("cm");
    delay(10);
    
   }

   
   
   

  
  
  
}
