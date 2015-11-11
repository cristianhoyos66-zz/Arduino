int pin = 13;
volatile int state = LOW;

void blink () {
  state = !state;
}

void setup () {
  pinMode(pin, OUTPUT);
 // attachInterrupt(0, blink, CHANGE);
  attachInterrupt(0, blink, FALLING);
}

void loop () {
  digitalWrite(pin, state);
}


