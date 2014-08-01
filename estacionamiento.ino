#include <Servo.h>

const byte contadorPin[] = {2,3,4,5,6,7,8};
const byte valor[10]= {B00111111, B00000110, B01011011, B01001111, B01100110, B01101101, B01111101, B00000111, B01111111, B01101111};
byte mascara = 1; 
int switchEstado1=0;
int switchEstado2=0;
int ocupado=8;
Servo myServo;

void setup()
{
  Serial.begin(9600);
  int i = 0;
  for ( i = 0; i < 7; i++)
    pinMode(contadorPin[i], OUTPUT);
    
     pinMode(9,INPUT); 
     pinMode(10,INPUT);
     
     myServo.attach(12); 
     contador(8);
}


void loop()
{
 
  switchEstado1=digitalRead(9);
  switchEstado2=digitalRead(10);
  if(switchEstado1==HIGH && ocupado!=0)
  {
   myServo.write(177);
   delay(3000);
   myServo.write(80);
   ocupado --;
   contador(ocupado);
    Serial.print(ocupado);
    
  }
  
  else
     if(switchEstado2==HIGH && ocupado<8){
       myServo.write(177);
       delay(3000);
       myServo.write(80);
       ocupado++;
       contador(ocupado);
       Serial.print(ocupado);
     }
  
 
}


void contador(int numero){
  byte j=0;
 for (mascara = 0000001; mascara>0; mascara <<= 1) {
   
      if (valor[numero] & mascara){ 
          digitalWrite(contadorPin[j],HIGH); 
         }
      else{ 
           digitalWrite(contadorPin[j],LOW);
          }
         j++;
       } 
}
