void setup() {
  Serial.begin(9600);
 }

void loop() {
  float sensorValue = analogRead(A0);
  float sensorValueFR = analogRead(A1);
  float comparador = analogRead(A2);


  float v0= (sensorValue*4.96)/1017;
  float v1= (sensorValueFR*4.54)/1023;

  if(comparador>=240)
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


  delay(3000);
}
