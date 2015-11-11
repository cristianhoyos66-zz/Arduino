int counter = -1;

//para display de catodo comun que se prende con unos
byte Digit[10][7] =                
{                                   
   { 1,1,1,1,1,1,0 },    // 0   
   { 0,1,1,0,0,0,0 },    // 1
   { 1,1,0,1,1,0,1 },    // 2
   { 1,1,1,1,0,0,1 },    // 3
   { 0,0,1,0,0,1,1 },    // 4
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
   for (int i = 4; i<=10; i++){
    pinMode(i, OUTPUT);
   }
   attachInterrupt(0, sum, FALLING);
}

void loop () {
    
}
