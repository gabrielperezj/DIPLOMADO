
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);  //Motor derecha
  pinMode(5, OUTPUT);  //Invertida M Derecha
  pinMode(7, OUTPUT);  //Motor izquierda
  pinMode(4, OUTPUT);  //invertida M izquierda
  pinMode(3, INPUT);  //interrupción de contacto
  pinMode(2, INPUT);  //interrupción de infrarrojo
  Serial.println("Ingresa el valor1 en radianes y valor2 en distancia separados por espacio para el movimiento del motor:  ");
}


void loop() {

   if (Serial.available())
   {
      float a[2];

      for(int i=0; i<=2; i++)
      {
        a[i] = Serial.parseFloat();
      }

      float radianes=a[0];
      float distancia=a[1];

      move_robot(radianes,distancia);
   }
      
             
}

   

void move_robot(float radianes, float distancia)
{ 
     Serial.println("Ejecutando");

     float tiempo = (radianes*2500)/6.2832;
     float tiempo1 = (distancia*6000)/100;
      digitalWrite(7, LOW);
      digitalWrite(4,LOW); 
      digitalWrite(6, HIGH);
      digitalWrite(5,LOW); 
      analogWrite(11, 60);
      delay(tiempo);
      detener();
       
      delay(1000);

      digitalWrite(7, HIGH);
      digitalWrite(4,LOW);
      analogWrite(10, 45); 
      digitalWrite(6, HIGH);
      digitalWrite(5,LOW); 
      analogWrite(11, 47);
      delay(tiempo1);

      detener();
      
}


void detener()
{
      digitalWrite(7, LOW);
      digitalWrite(4,LOW); 
       
      digitalWrite(6, LOW);
      digitalWrite(5,LOW); 
       
}
