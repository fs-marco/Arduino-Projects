#include<Servo.h>
const int ledPin = 13; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into
Servo myservo;
int angServo;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  myservo.attach(9);
  pinMode(ledPin, OUTPUT);
  angServo = 1;
  myservo.write(angServo);
}

void loop() {
  Serial.println(myservo.read());
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      analogWrite(ledPin, 255);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      analogWrite(ledPin, 0);
    }
    
    if (incomingByte == 'D') {
      if(angServo-10 > 0){
        angServo -= 10;
      }
      else if(angServo-10 == 0){
          angServo = 1;
      }
      myservo.write(angServo);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'S') {
      if(angServo+10 <= 90){
        if(angServo == 1){
          angServo--;
        }
        angServo += 10;
        myservo.write(angServo);
      }
    }
  }
}
