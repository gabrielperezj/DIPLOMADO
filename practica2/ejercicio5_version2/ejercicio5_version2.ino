//sensor de distancia infrarrojo con funcion exponencial
void setup()
{
  Serial.begin(9600);
}

void loop()
{
   float sensorValue=analogRead(A0);
   Serial.println(exp(8.5841-log(sensorValue)));
   delay(1000);
}
