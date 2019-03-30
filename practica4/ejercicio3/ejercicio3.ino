int n = 20;
     
void setup()
{
   Serial.begin(9600);
   pinMode(2, INPUT);  //sensor de contacto izquierdo
   pinMode(3, INPUT);  //sesnro de contacto derecho
   Serial.println("Ingresa un comando para conocer el sensor: ");
}
 
 
void loop()
{

  if(Serial.available())
    {
      String data = Serial.readStringUntil(' ');

      if(data.equals("shs") == true)
      {
        String data1 = Serial.readStringUntil(' ');
        int numero=Serial.parseInt();

        float sensor = show_sensor(data1,numero);
        Serial.println(sensor);

      }
  
   }
          
}

float show_sensor(String data1,int numero)
{
       if(data1.equals("contact") == true)
        {
          if(numero == 1)
          {
           int buttonState = digitalRead(2);
           Serial.print("Estado del Sensor de Contacto Izquierdo: ");
           return buttonState;
          }
          if(numero == 2)
          {
           int buttonState = digitalRead(3);
           Serial.print("Estado del Sensor de Contacto Derecho: ");
           return buttonState;
          }
          else 
          {
            Serial.println("No reconozco el número");

          }
           
        }

        if(data1.equals("infrared") == true)
        {
          if(numero == 1)
          {
           float sensorValue = analogRead(A1);
           float suma=0;
           for(int i=0;i<n;i++)
           {
              suma=suma+analogRead(A0);
           }  
           float adc=suma/n;
           float distancia_cm = 17500 * pow(adc, -1.207); //-1.2062
           Serial.print("Distancia Medida del sensor delantero: ");
           return distancia_cm;
          }
          if(numero == 2)
          {
           float sensorValue = analogRead(A2);
           float suma=0;
           for(int i=0;i<n;i++)
           {
              suma=suma+analogRead(A0);
           }  
           float adc=suma/n;
           float distancia_cm = 17500 * pow(adc, -1.207); //-1.2062
           Serial.print("Distancia Medida del sensor trasero: ");
           return distancia_cm;
          }
          else
          {
           Serial.println("No reconozco el número");
            
          }

         
           
        }
  
}
