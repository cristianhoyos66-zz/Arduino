const int inputPinOne = 3;
const int inputPinTwo = 4;
const int inputPinThree = 5;

void setup () {
  pinMode(inputPinOne, INPUT);
  pinMode(inputPinTwo, INPUT);
  pinMode(inputPinThree, INPUT);
  
  for (int i = 6; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  
}

void turnOfAll () {
  for (int i = 6; i < 14; i++) {
    digitalWrite(i, LOW);
  } 
  delay(2000);
}

void sequenceOne () {
  for (int i = 6; i < 14; i++) {
    digitalWrite(i, HIGH);
    delay(500);
  }
}

void sequenceTwo () {
  for (int i = 14; i >= 6; i--) {
    digitalWrite(i, HIGH);
    delay(500);
  }
}

void sequenceThree () {
  for (int i = 6; i < 10; i++) {
    digitalWrite(i, HIGH);
    delay(500);
  }
  for (int i = 13; i >= 10; i--) {
    digitalWrite(i, HIGH);
    delay(500);
  }
}

void sequenceFour () {
  for (int i = 13; i >= 10; i--) {
    digitalWrite(i, HIGH);
    delay(500);
  }
  for (int i = 6; i < 10; i++) {
    digitalWrite(i, HIGH);
    delay(500);
  }
}

void sequenceFive () {
 for (int i = 6; i < 14; i+=2) {
    digitalWrite(i, HIGH);
    delay(500);
  } 
}

void sequenceSix () {
  for (int i = 6; i < 14; i+=2) {
    digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
    delay(500);
  } 
}

void sequenceSeven () {
  int countDown = 8;
  for (int i = 6; i < 10; i++) {
    digitalWrite(i, HIGH);
    digitalWrite((i + (countDown-1)), HIGH);
    countDown-=2;
    delay(500);
  } 
}

void sequenceEight () {
  for (int i = 6; i < 9; i++){
    digitalWrite(i, HIGH);
  }
  delay(500);
  for (int i = 13; i >= 11; i--){
    digitalWrite(i, HIGH);
  }
  delay(500);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH); 
  delay(500); 
}

void activeSequence (int statePinOne, int statePinTwo, int statePinThree) {
  
  if (statePinOne == LOW && statePinTwo == LOW && statePinThree == LOW){
    sequenceOne();
    turnOfAll();
  }
  
  if (statePinOne == LOW && statePinTwo == LOW && statePinThree == HIGH){
    sequenceTwo();
    turnOfAll();
  }

  if (statePinOne == LOW && statePinTwo == HIGH && statePinThree == LOW){
    sequenceThree();
    turnOfAll();
  } 
 
  if (statePinOne == HIGH && statePinTwo == HIGH && statePinThree == HIGH){
    sequenceFour();
    turnOfAll();
  } 
 
  if (statePinOne == HIGH && statePinTwo == LOW && statePinThree == LOW){
    sequenceFive();
    turnOfAll();
  }

  if (statePinOne == HIGH && statePinTwo == LOW && statePinThree == HIGH){
    sequenceSix();
    turnOfAll();
  } 
 
  if (statePinOne == LOW && statePinTwo == HIGH && statePinThree == HIGH){
    sequenceSeven();
    turnOfAll();
  }

  if (statePinOne == HIGH && statePinTwo == HIGH && statePinThree == LOW){
    sequenceEight();
    turnOfAll();
  }  
    
}

void loop () {
  int statePinOne = digitalRead(inputPinOne);  
  int statePinTwo = digitalRead(inputPinTwo);
  int statePinThree = digitalRead(inputPinThree);
  
  activeSequence(statePinOne, statePinTwo, statePinThree); 
}


