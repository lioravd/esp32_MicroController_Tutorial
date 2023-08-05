
#define button 4
#define ledPin 2
int buttonState;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP); // config GPIO-4 as input pin and enable the internal pull-up resistor
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  
  if (buttonState==HIGH)
    digitalWrite(ledPin,LOW);
  
  else  
    digitalWrite(ledPin,HIGH);

}
