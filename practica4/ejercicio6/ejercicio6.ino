int deteccion =0;
float distancia1 = 0; //distancia del objeto adelante
float distancia2 = 0; //distancia del objeto atras

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);  //Motor derecha
  pinMode(5, OUTPUT);  //Invertida M Derecha
  pinMode(7, OUTPUT);  //Motor izquierda
  pinMode(4, OUTPUT);  //invertida M izquierda
  pinMode(3, INPUT);  //interrupción de contacto
  pinMode(2, INPUT);  //interrupción de contacto
  attachInterrupt(digitalPinToInterrupt(3), alerta, RISING); //Sensor de contacto derecho
  attachInterrupt(digitalPinToInterrupt(2), alerta1, RISING); //Sensor de contacto izquierdo

}


void loop() {

      if(deteccion ==0)
      {
        adelante();
        distancia1 = distancia(10);
        if (distancia1 <= 10)
        {
          detener();
          delay(1000);
          atras();
          delay(1500);
          detener();
          delay(1000);
          giroIzq();
          delay(1200);
          detener();
          delay(1000);
        }
  
      }

      if(deteccion == 1)
      {
        delay(1000);
        atras();
        delay(1500);
        detener();
        delay(1000);
        giroIzq();
        delay(1200);
        detener();
        delay(1000);
        
        deteccion = 0;
      }

      if(deteccion == 2)
      {
        delay(1000);
        atras();
        delay(1500);
        detener();
        delay(1000);
        giroDer();
        delay(1500);
        detener();
        delay(1000);
        deteccion = 0;
      }
   
}

void adelante()
{
      digitalWrite(7, HIGH);
      digitalWrite(4,LOW); 
      analogWrite(10, 52); 
      digitalWrite(6, HIGH);
      digitalWrite(5,LOW); 
      analogWrite(11, 47); 
}

float distancia(int n)
{
  float suma=0;
  for(int i=0;i<n;i++)
  {
    suma=suma+analogRead(A0);
  }  
  float adc=suma/n;
  float distancia_cm = 17500 * pow(adc, -1.207); //-1.2062
  return(distancia_cm);
}

float distanciAtras(int n)
{
  float suma=0;
  for(int i=0;i<n;i++)
  {
    suma=suma+analogRead(A1);
  }  
  float adc=suma/n;
  float distancia_cm = 17500 * pow(adc, -1.207); //-1.2062
  return(distancia_cm);
}

void atras()
{
      digitalWrite(4, HIGH);
      digitalWrite(7,LOW); 
      analogWrite(10, 45); 
      digitalWrite(5, HIGH);
      digitalWrite(6,LOW); 
      analogWrite(11, 47); 
      distancia2 = distanciAtras(10);
      if (distancia2 <= 10)
        {
          detener();
          delay(1000);
          giroIzq();
          delay(1500);
          detener();
          delay(1000);
        }
}

void detener()
{
      digitalWrite(7, LOW);
      digitalWrite(4,LOW); 
       
      digitalWrite(6, LOW);
      digitalWrite(5,LOW); 
       
}

void giroIzq()
{
      digitalWrite(7, HIGH);
      digitalWrite(4,LOW); 
      analogWrite(10, 42); 
      digitalWrite(6, HIGH);
      digitalWrite(5,LOW); 
      analogWrite(11, 60); 
}

void giroDer()
{
      digitalWrite(7, HIGH);
      digitalWrite(4,LOW); 
      analogWrite(10, 55); 
      digitalWrite(6, HIGH);
      digitalWrite(5,LOW); 
      analogWrite(11, 42);  
}
void alerta()
{
   detener();
   deteccion = 2;
}

void alerta1()
{
   detener();
   deteccion = 1;
}
