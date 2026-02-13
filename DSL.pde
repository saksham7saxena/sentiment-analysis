import processing.serial.*;

Serial port;
PFont font;

String data="";

void setup(){
  
 size(1000,700);
 background(33,33,33);
 stroke(0);
 noFill();
 font = createFont("Raleway", 24);
 printArray(Serial.list());   //prints all available serial ports
 port = new Serial(this, "COM4", 9600);  //i have connected arduino to com3, it would be different in linux and mac os

 all_buttons();

}

void draw(){ 
  
  fill(245,245,245);
  textFont(font);
  text("Select the number of seconds you want the devices to run!", 80, 60); 
  
}

void mousePressed() {
   all_buttons();
}

void all_buttons(){
 button1(100,200,800,75,"Run devices for one second",40,'1');
 button1(100,300,800,75,"Run devices for two second",40,'2');
 button1(100,400,800,75,"Run devices for three second",40,'3');
 button1(100,500,800,75,"Run devices for four second",40,'4');
}

void button1(float x, float y, float w, float h, String word, int textsize, char letter){

 fill(84,110,122);
 rect(x,y,w,h);
 fill(236,240,241);
 textSize(textsize);
 text(word, x, y, w, h); 
 
    if(mouseX>x && mouseX <x+w && mouseY>y && mouseY <y+h){
       port.write(letter);
        fill(231,76,60);
        rect(x,y,w,h);
        fill(236,240,241);
        textSize(textsize);
        text(word, x, y, w, h);
     }

}

void serialEvent(Serial myPort)
{
  data=port.readStringUntil('\n');
  println(data);
}
