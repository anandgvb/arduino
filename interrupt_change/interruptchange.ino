int buttonPin = 2;     // input
int ledPin1 =  13;      //normal
int ledPin2 =  8;      //interrupt

volatile int buttonState = 0;         // variable for reading the pushbutton status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(0, pinISR, CHANGE);
}

void loop() {
  // Nothing here!
}

void pinISR() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin1,buttonState);
  digitalWrite(ledPin2,!buttonState);
  }
 
    
