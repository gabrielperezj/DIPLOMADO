//sensor de distancia linealizado por partes
int n = 10;
float m= -0.1052;
float b= 49.6;
float m1= -0.1322;
float b1=55.964;
float m2= -0.2209;
float b2=73.68; 
float m3= -0.3149;
float b3=89.819; 
float m4=-0.05720;
float b4=36.1956; 
float m5=-0.0320;
float b5=26.8826;

void setup() {
  Serial.begin(9600);
 }

void loop() {

  float distancia;

  if(promedio(n)<527 && promedio(n)>=371)
  {
   distancia = (promedio(n)*m5)+b5;
   Serial.print("\n");
   Serial.println(distancia); 
  }

  if(promedio(n)<371 && promedio(n)>=285)
  {
   distancia = (promedio(n)*m4)+b4;
   Serial.print("\n");
   Serial.println(distancia); 
  }
  
  if(promedio(n)<285 && promedio(n)>=230)
  {
   distancia = (promedio(n)*m)+b;
   Serial.print("\n");
   Serial.println(distancia); 
  }

  else if(promedio(n)<230 && promedio(n)>=198)
  {
   distancia = (promedio(n)*m1)+b1;
   Serial.print("\n");
   Serial.println(distancia); 
  }

  else if(promedio(n)<198 && promedio(n)>=173)
  {
   distancia = (promedio(n)*m2)+b2;
   Serial.print("\n");
   Serial.println(distancia); 
  }

  else if(promedio(n)<173 && promedio(n)>=137)
  {
   distancia = (promedio(n)*m3)+b3;
   Serial.print("\n");
   Serial.println(distancia); 
  }
  
  delay(1000);
}

float promedio (int n)
{
  float muestras=0;
  for(int i=0; i<=n; i++)
  {
    muestras = muestras + analogRead(A0);
  }
  return (muestras/n);
}
