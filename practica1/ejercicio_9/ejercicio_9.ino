
const int analogOutPin = 9; 

int sensorValue = 0;        
int outputValue = 0;        

void setup() {
  Serial.begin(9600);
}

void loop() {

  for (int i=0; i<=255; i++)
  {
     analogWrite(analogOutPin, i);
     delay(10);
  }
 delay(2000);
 for (int i=255; i>=0; i--)
  {
     analogWrite(analogOutPin, i);
     delay(10);
  }
  delay(3000);

  
 
}
