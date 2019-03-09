
int contador=0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  if (contador == 0) {
  for (int i=0; i < 10; i++){
     digitalWrite(LED_BUILTIN, HIGH);   
     delay(2500);                       
     digitalWrite(LED_BUILTIN, LOW);    
     delay(2500);                       
   }
   contador++;
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
      
  
}
