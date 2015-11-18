int counter = -1;
char inChar=0;
boolean stringComplete = false;

//para display de catodo comun que se prende con unos
byte Digit[10][7] =                
{                                   
   { 1,1,1,1,1,1,0 },    // 0   
   { 0,1,1,0,0,0,0 },    // 1
   { 1,1,0,1,1,0,1 },    // 2
   { 1,1,1,1,0,0,1 },    // 3
   { 0,1,1,0,0,1,1 },    // 4
   { 1,0,1,1,0,1,1 },    // 5
   { 1,0,1,1,1,1,1 },    // 6
   { 1,1,1,0,0,0,0 },    // 7
   { 1,1,1,1,1,1,1 },    // 8
   { 1,1,1,0,0,1,1 }     // 9
};

//se niega con !Digit[N][i] para convertirlo a display de anodo comun
void Display (int N) {
  for (int i= 0 ; i<8 ; i++){
    digitalWrite(i+4 , !Digit[N][i] ) ;
  }
}

void sum () {
  counter++;
  if (counter == 10){
    counter = 0;
  }
  Display(counter);
}

void setup () {
   Serial.begin(9600);
   for (int i = 4; i<=10; i++){
    pinMode(i, OUTPUT);
   }
   attachInterrupt(0, sum, FALLING);
   sum();
}

void loop () {
  serialEvent();
  if (stringComplete) {
    if(inChar>='0' && inChar<='9'){
      counter = inChar-48;
      stringComplete = false;
    }
  } 
}

void serialEvent() {
  while (Serial.available()) {
    inChar = (char)Serial.read();
    Serial.println(inChar);
    stringComplete = true;
  }
}
