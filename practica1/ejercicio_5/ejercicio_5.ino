const int buttonPin = 2;     
const int ledPin =  13;      

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(0,funcion,RISING);
}

void loop() {

  
  delay(2000);
  digitalWrite(ledPin, LOW);
  
}

void funcion(){
  
  digitalWrite(ledPin, HIGH);
  
  
}
