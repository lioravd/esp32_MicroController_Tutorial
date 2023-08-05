#define button 4
#define ledPin 2
int buttonState;
int ledstate = LOW;
int flag=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP); // config GPIO-4 as input pin and enable the internal pull-up resistor
  pinMode(ledPin,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  buttonState = digitalRead(button);
  if(buttonState ==LOW){
    flag=1;
    ledstate = ~ledstate;
  }

  while(buttonState ==LOW){
    buttonState = digitalRead(button);
  }

  if(flag==1){
    digitalWrite(ledPin,ledstate);
    flag=0;
  }
}