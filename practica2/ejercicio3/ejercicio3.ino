void setup() {
  Serial.begin(9600);
 }

void loop() {
  float sensorValue = analogRead(A0);
  float v0= (sensorValue*4.54)/1023;
  Serial.println(v0);
  delay(1000);
}
