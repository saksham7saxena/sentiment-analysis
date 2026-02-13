void setup() 
{
  Serial.begin(9600);         
  pinMode(LED_BUILTIN, OUTPUT);   
    
}

void loop()
{
  if(Serial.available()>0)
    {
      char data = Serial.read(); 
      Serial.println(data);    
      switch (data)
      {
        case '0':
                digitalWrite(LED_BUILTIN, HIGH);
                break;          
        case '1':
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);    
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);  
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);
                digitalWrite(LED_BUILTIN, HIGH);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);  
                delay(200);                                                            
                break;

        case '2':
                digitalWrite(LED_BUILTIN, LOW);
                break;                    
      } 
    }  
}
