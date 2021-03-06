void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);  //invertida
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);  //invertida
  pinMode(12, OUTPUT);
  Serial.println("Ingresa un comando para el manejo del motor: ");
}

void loop() {

  if (Serial.available())
   {
      String data = Serial.readStringUntil(' ');

      if(data.equals("A1") == true)
      {
        String data1 = Serial.readStringUntil(' ');

        if(data1.equals("speed") == true)
        {
          
          float numero=Serial.parseFloat();  //lee un numero decimal

          if(numero == 0)
          {
            stopA1(numero);
          }
          else if(numero > 0 && numero <=127)
          {
            float speed1 = (numero*255)/127;
            giroDerA1(speed1);   
            
          }
          else if(numero < 0 && numero >= -127)
          {
            float speed1 = (numero*-255)/127;
            giroIzqA1(speed1);   
            
          }
          else
          {
             Serial.println("Valor incorrecto");

          }

        }
        else
        {
          Serial.println("Valor incorrecto");
        }
      }

      if(data.equals("A2") == true)
      {
        String data1 = Serial.readStringUntil(' ');

        if(data1.equals("speed") == true)
        {
          
          float numero=Serial.parseFloat();  //lee un numero decimal

          if(numero == 0)
          {
            stopA2(numero);
          }
          else if(numero > 0 && numero <=127)
          {
            float speed2 = (numero*255)/127;
            giroDerA2(speed2);   
            
          }
          else if(numero < 0 && numero >= -127)
          {
            float speed2 = (numero*-255)/127;
            giroIzqA2(speed2);   
            
          }
          else
          {
             Serial.println("Valor incorrecto");

          }
        }
        else
        {
          Serial.println("Valor incorrecto");
        }
      }
      
     
     
   }  

}


void giroDerA1(float speed1)
{
  digitalWrite(13, HIGH);
  digitalWrite(3, LOW);
  analogWrite(11, speed1); 
}

void stopA1(float speed1)
{
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);
  analogWrite(11, speed1); 

}

void giroIzqA1(float speed1)
{
  digitalWrite(13, LOW);
  digitalWrite(3, HIGH);
  analogWrite(11, speed1); 
}



void giroDerA2(float speed2)
{
  digitalWrite(12, HIGH);
  digitalWrite(2, LOW);
  analogWrite(10, speed2); 
}

void giroIzqA2(float speed2)
{
  digitalWrite(12, LOW);
  digitalWrite(2, HIGH);
  analogWrite(10, speed2); 
}

void stopA2(float speed2)
{
  digitalWrite(12, LOW);
  digitalWrite(2, LOW);
  analogWrite(10, speed2); 
   
}
