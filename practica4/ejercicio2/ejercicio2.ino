
void setup()
{
   Serial.begin(9600);
   pinMode(8, INPUT);
   pinMode(7, INPUT);
}

void loop() {
   int buttonState1 = digitalRead(8);
   int buttonState2 = digitalRead(7);

 
      if (buttonState1 == 0 && buttonState2 == 0)
        {
         Serial.println("Estado del Sensor 1 y Sensor 2 de Contacto: Alto");
         delay(1000);
        }
      if (buttonState1 == 1 && buttonState2 == 0)
        {
         Serial.println("Estado del Sensor 2 de Contacto: Alto");
         delay(1000);
        }
      if (buttonState1 == 0 && buttonState2 == 1)
        {
         Serial.println("Estado del Sensor 1 de Contacto: Alto");
         delay(1000);
        }
      if (buttonState1 == 1 && buttonState2 == 1)
        {
         Serial.println("Estado de los Sensores de Contacto: Bajo");
         delay(1000);
        }
    

}
