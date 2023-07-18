int ledPin=2;  //Led pin in GPIO 2

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);

  Serial.begin(115200);
}

void loop() {
  //print hello world
  Serial.println("Hello world");


  
  //Blink led
  digitalWrite(ledPin,HIGH);
  delay(500);
  digitalWrite(ledPin,LOW);
  delay(500);
}
 