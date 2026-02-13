#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int tonePin = 11;
int LED = 6;

LiquidCrystal_I2C lcd(0x27, 16, 2);
```
int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);  
  pinMode(button2, INPUT_PULLUP);  
  pinMode(button3, INPUT_PULLUP);  
  pinMode(button4, INPUT_PULLUP);

}

char incomingByte;

void led_1()
{
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
}

void buzz_1()
{
    tone(11, 100,1000);
}

void led_2()
{
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED,LOW);
}

void buzz_2()
{
    tone(11, 100,2000);
}
void led_3()
{
    digitalWrite(LED, HIGH);
    delay(3000);
    digitalWrite(LED,LOW);
}

void buzz_3()
{
    tone(11, 100,3000);
}

void led_4()
{
    digitalWrite(LED, HIGH);
    delay(4000);
    digitalWrite(LED,LOW);
}

void buzz_4()
{
    tone(11, 100,4000);
}


void loop() {
   if (Serial.available() > 0) {

incomingByte = Serial.read();
Serial.println(incomingByte);

  if (incomingByte == '1') 
  {
    buzz_1();
    led_1();
    lcd.begin();
    lcd.backlight();
    lcd.print("1 second");
  }
  if (incomingByte == '2') 
  {
    buzz_2();
    led_2();
    lcd.begin();
    lcd.backlight();
    lcd.print("2 seconds");
    
  }
  if (incomingByte == '3') 
  {
    buzz_3();
    led_3();
    lcd.begin();
    lcd.backlight();
    lcd.print("3 seconds");
    
    
  }
  if (incomingByte == '4') 
  {
    buzz_4();
    led_4();
    lcd.begin();
    lcd.backlight();
    lcd.print("4 seconds");
  }
  

}
}
