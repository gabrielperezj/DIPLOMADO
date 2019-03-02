int speed1 = 50;
int speed2 = 50;


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
      String data = Serial.readStringUntil('\n');
      if(data.equals("motor A1 on right") == true)
      {
        giroDerA1();
        Serial.println("Giro Derecha MOTOR A1");
      }
      else if(data.equals("motor A1 on left") == true)
      {
        giroIzqA1();
        Serial.println("Giro Izquierda MOTOR A1");
      }
      else if(data.equals("motor A1 off") == true)
      {
        stopA1();
        Serial.println("MOTOR A1 Detenido");
      }

      if(data.equals("motor A2 on right") == true)
      {
        giroDerA2();
        Serial.println("Giro Derecha MOTOR A2");
      }
      else if(data.equals("motor A2 on left") == true)
      {
        giroIzqA2();
        Serial.println("Giro Izquierda MOTOR A2");
      }
      else if(data.equals("motor A2 off") == true)
      {
        stopA2();
        Serial.println("MOTOR A2 Detenido");
      }
      else if(data.equals("STOP") == true)
      {
        stopA1();
        stopA2();
        Serial.println("MOTORES DETENIDOS");
      }
      
      else
      {
        Serial.println("No reconozco el comando");
      }
   }

}


void giroDerA1()
{
  digitalWrite(13, HIGH);
  digitalWrite(3, LOW);
  analogWrite(11, speed1); 
}

void giroIzqA1()
{
  digitalWrite(13, LOW);
  digitalWrite(3, HIGH);
  analogWrite(11, speed1); 
}

void stopA1()
{
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);
   
}

void giroDerA2()
{
  digitalWrite(12, HIGH);
  digitalWrite(2, LOW);
  analogWrite(10, speed2); 
}

void giroIzqA2()
{
  digitalWrite(12, LOW);
  digitalWrite(2, HIGH);
  analogWrite(10, speed2); 
}

void stopA2()
{
  digitalWrite(12, LOW);
  digitalWrite(2, LOW);
   
}
