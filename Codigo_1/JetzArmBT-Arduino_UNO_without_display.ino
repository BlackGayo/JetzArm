//Programa #1 Control JetzArm por Bluetooth y Android.
//La conexion se realiza de acuerdo a el diagrama, sin embargo se puede cambiar a comodidad del usuario.
//.................................................................
//....................Black Gayo...................................
//.................................................................

#include <Servo.h>
Servo cadera,hombro,codo,pinza;
char unChar;
String readString;

void setup() {
Serial.begin(9600);  
cadera.attach(3);
hombro.attach(5);
codo.attach(6);
pinza.attach(9);
pinMode(13,OUTPUT);

}



void loop() {


digitalWrite(13,HIGH);

if (Serial.available()>0) {  
    unChar = Serial.read();
    
    if(unChar=='A'){ 
      motor1();
    }
    
    if(unChar=='B'){ 
      motor2();
    }
    
    if(unChar=='C'){ 
      motor3();
    }

    if(unChar=='D'){ 
      motor4();
    }
                        }  

             }



void motor1(){
        delay(5);   
        while (Serial.available()) { 
          //delayMicroseconds(100);                  
          char c = Serial.read();  
          readString += c;        
        }
        if (readString.length() >0) {
          Serial.println(readString.toInt());  
          cadera.write(readString.toInt());
          readString="";
        }
}

void motor2(){
        delay(5); 
        while (Serial.available()) { 
          //delayMicroseconds(100);                  
          char c = Serial.read();  
          readString += c;         
        }
        if (readString.length() >0) { 
          Serial.println(readString.toInt());  
          hombro.write(readString.toInt()); 
          
          readString=""; 
        } 
}

void motor3(){
        delay(5); 
        while (Serial.available()) { 
          //delayMicroseconds(100);                  
          char c = Serial.read();  
          readString += c;        
        }
        if (readString.length() >0) { 
          Serial.println(readString.toInt());  
          codo.write(readString.toInt());
          readString=""; 
        } 
}

void motor4(){
        delay(5); 
        while (Serial.available()) { 
          //delayMicroseconds(100);                  
          char c = Serial.read();  
          readString += c;        
        }
        if (readString.length() >0) { 
          Serial.println(readString.toInt());  
          pinza.write(readString.toInt());          
          readString=""; 
        } }

