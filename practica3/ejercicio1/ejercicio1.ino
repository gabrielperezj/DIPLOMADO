void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);  //invertida
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);  //invertida
  pinMode(12, OUTPUT);

}

void loop() {

  digitalWrite(13, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(2, LOW);
  analogWrite(10, 50);
  analogWrite(11, 50);

}
