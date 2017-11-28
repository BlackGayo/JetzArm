//Control de JetzArm con potenciometros.
//Black Gayo 2017

#include <Servo.h>
Servo Cadera;
Servo Hombro;
Servo Codo;
Servo Pinza;
int senal1,senal2,senal3,senal4;

void setup(){
Cadera.attach(3);
Hombro.attach(5);
Codo.attach(6);
Pinza.attach(9);

}

void loop() {
lectura();
Cadera.write(senal1);
Hombro.write(senal2);
Codo.write(senal3);
Pinza.write(senal4);

delay(20);
}


void lectura(){
  //Lectura de potenciometro 1
  senal1=analogRead(A0);
  senal1=map(senal1,0,1023,5,175);
  //Lectura de potenciometro 2
  senal2=analogRead(A1);
  senal2=map(senal2,0,1023,5,175);
  //Lectura de potenciometro 3
  senal3=analogRead(A2);
  senal3=map(senal3,0,1023,5,175);
  //Lectura de potenciometro 4
  senal4=analogRead(A3);
  senal4=map(senal4,0,1023,5,175);
      
  }
