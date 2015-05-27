void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int luz =  analogRead(A0);
  int led = ((luz)%255);
  Serial.println(led - 140);
  analogWrite(3, led - 140);
  delay(1000);
  
}
