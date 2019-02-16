void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  float sensorValue = analogRead(A0);
  float voltaje = sensorValue*5/1023;
  Serial.println(voltaje);
  if(voltaje>3) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if(voltaje<=3) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  delay(1000);        
}
