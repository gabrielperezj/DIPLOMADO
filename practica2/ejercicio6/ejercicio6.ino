float sensorValue;
float tempC;
float tempF;
float v0;
int buttonState = 0;

        
void setup()
{
   Serial.begin(9600);
   pinMode(2, INPUT);
   pinMode(13, OUTPUT);
   Serial.println("Ingresa un comando: ");
}
 
 
void loop()
{
   buttonState = digitalRead(2);
   
   if (Serial.available())
   {
      
      String data = Serial.readStringUntil('\n');
      
      if(data.equals("shs temp") == true)
      {
        sensorValue = analogRead(A0);
        tempC= (sensorValue*125)/1023;
        tempF=(tempC*(9/5))+32;
        Serial.print("Temperatura °C: ");
        Serial.println(tempC);
        Serial.print("Temperatura °F: ");
        Serial.println(tempF);
        Serial.println("Ingresa un comando: ");

        delay(1000);
      }
      else if(data.equals("shs photora") == true)
      {
        sensorValue = analogRead(A1);
        v0= (sensorValue*4.54)/1023;
        Serial.print("Voltaje de Salida de la fotoresistencia: ");
        Serial.println(v0);
        delay(1000);
      }
      else if(data.equals("shs infrared") == true)
      {
        sensorValue = analogRead(A2);
        Serial.print("Distancia Medida: ");
        Serial.println(exp(8.5841-log(sensorValue)));
        delay(1000);
      }
      else if(data.equals("shs contact") == true)
      {
        if (buttonState == HIGH)
        {
         Serial.println("Estado del Sensor de Contacto: Alto");
         delay(1000);
        }
        else
        {
         Serial.println("Estado del Sensor de Contacto: Bajo");
         delay(1000);
        }
      }
      else if(data.equals("shs photord") == true)
      {
        sensorValue = analogRead(A1);  //lectura de la fotoresistencia
        float umbral = analogRead(A3); //lectura de umbral del potenciometro
        float comparador;
        float v0= (umbral*4.96)/1017;
        float v1= (sensorValue*4.54)/1023;
        
        if(v1>=v0)
        {
            comparador = 5.00;
        }
        else
        {
          comparador = 0.00;
        }

        Serial.print("\n");
        Serial.print("Umbral: ");
        Serial.println(v0);
        Serial.print("V1 FotoResistencia: ");
        Serial.println(v1);
        Serial.print("Comparador: ");
        Serial.println(comparador);
       
      }
        
    
      else
      {
        Serial.println("No reconozco el comando");
      }
      
      
   }

  
   
   
}
