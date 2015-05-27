import processing.serial.*; 
 
 float boxX;
 float boxY;
 int boxSize = 20;
 boolean mouseOverBox = false;
 color selecionado = color(0);
color n_selecionado = color(255);
int ledPin = 13;
boolean ledOn = false;
 
 Serial port; 
 
 void setup()  {
 size(300,100);
 textSize(26);
 
 // List all the available serial ports in the output pane. 
 // You will need to choose the port that the Arduino board is 
 // connected to from this list. The first port in the list is 
 // port #0 and the third port in the list is port #2. 
 println(Serial.list()); 
 
 // Open the port that the Arduino board is connected to (in this case #0) 
 // Make sure to open the port at the same speed Arduino is using (9600bps) 
 port = new Serial(this, Serial.list()[0], 9600); 
 
 }
 
 void draw() {
 if(mouseX >= 10 && mouseX <= 100 &&
 mouseY >= 10 && mouseY <= 50) {
 fill(selecionado);
 rect(10,10,100,50);
 fill(n_selecionado);
 text("ON",10,10,100,50);
 } else {
 fill(n_selecionado);
 rect(10,10,100,50);
 fill(selecionado);
 text("ON",10,10,100,50);
 }
 
 if(mouseX >= 160 && mouseX <= 260 &&
 mouseY >= 10 && mouseY <= 50) {
 fill(selecionado);
 rect(160,10,100,50);
 fill(n_selecionado);
 text("OFF",160,10,260,50);
 } else {
 fill(n_selecionado);
 rect(160,10,100,50);
 fill(selecionado);
 text("OFF",160,10,260,50);
 }
 
 if(ledOn) port.write('H');
 else port.write('L');
}
 
void mousePressed() {
 if (mouseX >= 10 && mouseX <= 100 &&
 mouseY >= 10 && mouseY <= 50) {
 ledOn = true;
 }
 if (mouseX >= 160 && mouseX <= 260 &&
 mouseY >= 10 && mouseY <= 50) {
 ledOn = false;
 }
}
