
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
}

void loop() {

    adelante();
    delay(1300);
    detenido();
    delay(600);
    giroIzq();
    delay(600);
    detenido();
    delay(600);
    adelante();
    delay(1000);
    detenido();
    delay(600);
    giroIzq();
    delay(670);
    detenido();
    delay(600);
    adelante();
    delay(1500);
    detenido();
    delay(600);
    giroIzq();
    delay(670);
    detenido();
    delay(600);
    adelante();
    delay(900);
    detenido();
    delay(600);
    giroIzq();
    delay(670);
    
       
}

void adelante()
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(3, 50);

  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  analogWrite(5, 65);  
  
}

void giroIzq()
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(3, 50);

  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  analogWrite(5, 25); 
  
}

void giroDer()
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(3, 25);

  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  analogWrite(5, 50); 
  
}

void detenido()
{
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  analogWrite(3, 0);

  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  analogWrite(5, 0); 

}
