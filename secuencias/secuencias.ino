
const int firsButtonPin = 2;
const int secondButtonPin = 4;
  
void setup () {
  pinMode(firsButtonPin, INPUT);
  pinMode(secondButtonPin, INPUT);
  for (int i = 6; i < 14; i++) {
    pinMode(i, OUTPUT);      
  }
}

void turnOffAll(){
   for (int i = 6; i < 14; i++) {
      digitalWrite(i, LOW);
      delay(500);
    } 
}

void secuencia (int secuencia){
  switch(secuencia) {
    case 1:
      for (int i = 6; i < 14; i++) {
        digitalWrite(i, HIGH);
        delay(500);
      }
      turnOffAll();
      break;
    case 2:
      for (int i = 13; i > 2; i--) {
        digitalWrite(i, HIGH);
        delay(500);
      }
      turnOffAll();
      break;
    case 3:
      for (int i = 6; i < 9; i++) {
        digitalWrite(i, HIGH);
        delay(500);
      }
      for (int i = 13; i > 7; i--) {
        digitalWrite(i, HIGH);
        delay(500);
      }
      turnOffAll();
      break;
    case 4:
      for (int i = 13; i > 7; i--) {
        digitalWrite(i, HIGH);
        delay(500);
      }
      for (int i = 6; i < 9; i++) {
        digitalWrite(i, HIGH);
        delay(500);
      }
      turnOffAll();
      break;
  }
}

void loop () {
  int firsButtonState = digitalRead(firsButtonPin);  
  int secondButtonState = digitalRead(secondButtonPin);
  
  if (firsButtonState == LOW && secondButtonState == LOW){
    secuencia(1);
  }
  
  if (firsButtonState == HIGH && secondButtonState == HIGH){
    secuencia(2);
  }
  
  if (firsButtonState == HIGH && secondButtonState == LOW){
    secuencia(3);
  }  
  
  if (firsButtonState == LOW && secondButtonState == HIGH){
    secuencia(4);
  }  
  
}
