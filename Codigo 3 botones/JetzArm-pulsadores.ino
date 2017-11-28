//Control de JetzArm con pulsadores.
//Black Gayo 2017

#include <Servo.h>
Servo Cadera;
Servo Hombro;
Servo Codo;
Servo Pinza;
int a,b,c,d;
int bt1a;
int bt1b;
int bt2a;
int bt2b;
int bt3a;
int bt3b;
int bt4a;
int bt4b;
int incremento=3;

void setup(){
Cadera.attach(3);
Hombro.attach(5);
Codo.attach(6);
Pinza.attach(9);
pinMode(2,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
digitalWrite(A0, INPUT_PULLUP);
digitalWrite(A1, INPUT_PULLUP);
digitalWrite(A2, INPUT_PULLUP);
digitalWrite(A3, INPUT_PULLUP);
digitalWrite(A4, INPUT_PULLUP);
digitalWrite(A5, INPUT_PULLUP);

a=90;
b=90;
c=110;
d=90;
}

void loop() {
lectura();
correccion();
Cadera.write(a);
Hombro.write(b);
Codo.write(c);
Pinza.write(d);
delay(200);
}


void lectura(){
  delay(5);
  bt1a=digitalRead(A0);
  bt1b=digitalRead(A1);
  if(bt1a==LOW)a=a+incremento;
  if(bt1b==LOW)a=a-incremento;

  bt2a=digitalRead(A2);
  bt2b=digitalRead(A3);
  if(bt2a==LOW)b=b+incremento;
  if(bt2b==LOW)b=b-incremento;

  bt3a=digitalRead(A4);
  bt3b=digitalRead(A5);
  if(bt3a==LOW)c=c+incremento;
  if(bt3b==LOW)c=c-incremento;
  
  bt4a=digitalRead(2);
  bt4b=digitalRead(4);
  if(bt4a==LOW)d=d+incremento;
  if(bt4b==LOW)d=d-incremento;
  
      
  }

void correccion(){
  delay(5);
  if(a>=175)a=175;
  if(a<=5)a=5;
  if(b>=175)b=175;
  if(b<=5)b=5;
  if(c>=175)c=175;
  if(c<=5)c=5;
  if(d>=175)d=175;
  if(d<=5)d=5;
    
  
  }
