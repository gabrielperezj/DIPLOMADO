
void setup() {
  Serial.begin(9600);
 }

void loop() {
  float sensorValue = analogRead(A0);
  float tempC= (sensorValue*125)/1023;
  float tempF=(tempC*(9/5))+32;
  Serial.print("Temperatura °C: ");
  Serial.println(tempC);
  Serial.print("Temperatura °F: ");
  Serial.println(tempF);
  delay(1000);
}
