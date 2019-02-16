const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int contador=0;
int j=0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  attachInterrupt(0,funcion,RISING);
}

void loop() {

  
  
  if (contador == 1) {
  for (int i=0; i < 10; i++){
     digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(2500);                       // wait for a second
     digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
     delay(2500);                       // wait for a second
   }
   contador++;
  }
  if (j== 1 && contador >=2){
    digitalWrite(LED_BUILTIN, HIGH);
  }     // wait for a second
  
}

void funcion(){

  contador = 1;
  j = 1;
    
}
