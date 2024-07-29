const int ledPin = 25;
//4:ConnectorA 9:ConnectorB 10:Builtin

void setup() {
  pinMode(ledPin, OUTPUT);
}

// void loop() {
//   for(int i = 0; i < 5; i++){
//     digitalWrite(ledPin, HIGH); //ON
//     delay(500); //0.5sec
//     digitalWrite(ledPin, LOW); //OFF
//     delay(500); //0.5sec
//   }
//   delay(2000); //2sec
// }

void loop() {
  for(int i = 0; i < 5; i++){
    digitalWrite(ledPin, HIGH); //ON
    delay(50); //0.5sec
    digitalWrite(ledPin, LOW); //OFF
    delay(50); //0.5sec
  }
  delay(1000); //2sec
}