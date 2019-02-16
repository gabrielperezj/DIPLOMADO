

const int analogOutPin = 9; 

int sensorValue = 0;               

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  float sensorValue = analogRead(A0);
  float tiempo = sensorValue*5000/1023;

  for (int i=0; i<=255; i++)
  {
     analogWrite(analogOutPin, i);
     delay(10);
  }
 delay(tiempo);
 for (int i=255; i>=0; i--)
  {
     analogWrite(analogOutPin, i);
     delay(10);
  }
  delay(tiempo);

  
 
}
