#include<Servo.h>
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
}

int NumeroSerial(){
   int disponiveis = Serial.available();
  int m = pow(10, disponiveis - 1);
  int ret = 0;
  bool podeRetornar = false;
  Serial.print("Vou ler "); Serial.print(disponiveis); Serial.println(" bytes.");
  while(disponiveis){
    ret += (Serial.read() - 48) * m;
    m /= 10;
    if(Serial.available() == 1)
      m = 1;
    podeRetornar = true;
    disponiveis--;
  }
  if(!podeRetornar)
    return -1;
  return ret;
    
}

void loop() {
  char a;
  int n;
  n = NumeroSerial();
//  Serial.println(NumeroSerial());
  if(n > 0 && n <= 90){
     myServo.write(n);
    Serial.print("Servo: "); Serial.println(myServo.read()); 
  }
  delay(150);
}
