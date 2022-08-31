/* Arduino Control House  By: http://www.elprofegarcia.com/
.... Contorl digital on/off del pin 13 al pin 6
.... Dimer de los Pin 3 y 5
.... Control de Servo por PIN 4
.... Lectura analoga del Puerto AO

Conexion del Modulo Bluetooth al Arduino 
usando Pin 0 y 1
Componentes conprados en la tienda: http://www.dinastiatecnologica.com/
*/

#include <Servo.h> 
Servo servo1;         // Crea el servo1 con las librerias de Servo.h

String cadena, led, dato;
int regulador;
int estado=0;
int estado2=0;
int retardo=100;
int humo=0;
int valor=0;

void setup(){
  servo1.attach(4);
  pinMode(A0,INPUT);        //detector de humo
  pinMode(22,OUTPUT);       //Foco del garaje
  pinMode(23,OUTPUT);       //Foco de la cocina
  pinMode(24,OUTPUT);       //Foco del baño
  pinMode(25,OUTPUT);       //Foco del cuarto
  pinMode(2,OUTPUT);        //(+) motor del garaje
  pinMode(3,OUTPUT);        //(-) motor del garaje
  pinMode(11,OUTPUT);       //(+) motor del elevador
  pinMode(5,OUTPUT);        //(-) motor del elevador
  pinMode(6,OUTPUT);        //(+) motor de la persiana
  pinMode(7,OUTPUT);        //(-) motor de la persiana
  pinMode(27,OUTPUT);       //Focos navideños
  pinMode(8,OUTPUT);        //(+) motor del ventilador
  pinMode(9,OUTPUT);        //(-) motor del ventilador
  pinMode(28,OUTPUT);       //BUZZER
  pinMode(10,OUTPUT);       //LED para controlar el dimmer
  pinMode(40,INPUT);        //IR
  Serial.begin(9600);
  Serial2.begin(9600);
  delay(1000);
 }
 void loop(){
 if(Serial.available()>0){           // Si el puerto serie esta habilitadp 
        estado = Serial.read();      // Lee lo que llega por el puerto Serie
 }
     
 if(estado== 'a'){                    // on/off de los pin 13 al pin 6
       digitalWrite(22,LOW);
 }
 if(estado== 'b' ){
       digitalWrite(22,HIGH);
 }
 if(estado== 'c'){ 
       digitalWrite(23,HIGH);
 }
 if(estado== 'd' ){
       digitalWrite(23,LOW);
 }
 if(estado== 'e'){ 
       digitalWrite(24,HIGH);
 }
 if(estado== 'f' ){
       digitalWrite(24,LOW);
 }
 if(estado== 'g' ){
       digitalWrite(25,HIGH);
 }
 if(estado== 'h' ){
       digitalWrite(25,LOW);
 }
 if(estado== 'i' ){             //////////////////////motores
        analogWrite(2,255);
        analogWrite(3,0);
 }
 if(estado== 'j' ){
       analogWrite(2,0);
       analogWrite(3,255);
      }
 if(estado== 'k' ){
        analogWrite(11,255);
        analogWrite(5,0);
 }
 if(estado== 'l' ){             ////////////////
      analogWrite(11,0);
      analogWrite(5,255);
 }
 if(estado== 'm' ){
       analogWrite(6,255);              ////////////no se usa persiana
       analogWrite(7,0);
 }
 if(estado== 'n' ){
       analogWrite(6,0);
       analogWrite(7,255);
 }
 if(estado== 'o' ){
      analogWrite(8,255);
      analogWrite(9,0);
 }
 if(estado== 'p' ){
       analogWrite(8,0);
       analogWrite(9,0);
 }
 if(estado== 'q' ){      
      digitalWrite(27,HIGH);
      }
 if(estado== 'r' ){
      digitalWrite(27,LOW);
      }
 if(estado== 's' ){
      digitalWrite(22,LOW);
      delay(5000);
      digitalWrite(23,HIGH);
      delay(1000);
      digitalWrite(22,HIGH);
      delay(1000);
      digitalWrite(23,LOW);
      digitalWrite(25,HIGH);
      delay(2000);
      digitalWrite(24,HIGH);
      delay(1000);
      digitalWrite(24,LOW);
      digitalWrite(25,LOW);
      }

 if(estado== 't' ){
        analogWrite(11,0);
        analogWrite(5,0);
       }

if(estado== 'u' ){
        analogWrite(2,0);
        analogWrite(3,0);
       }  



       
if(estado=='v'){
        analogWrite(5,20);
       }  
if(estado=='w'){
        analogWrite(5,30);
       }  
if(estado=='x'){
        analogWrite(5,60);
       }  
if(estado=='y'){
        analogWrite(5,125);
       }  
if(estado=='z'){
        analogWrite(5,255);
       }         
       
       
 
 if(estado=='1'){               //  Dimer 2 conectado al pin 3
        analogWrite(3,0);
       }
      
 if(estado=='2'){
        analogWrite(3,3);
       }   
if(estado=='3'){
        analogWrite(3,8);
       }  
if(estado=='4'){
        analogWrite(3,20);
       }  
if(estado=='5'){
        analogWrite(3,30);
       }  
if(estado=='6'){
        analogWrite(3,60);
       }  
if(estado=='7'){
        analogWrite(3,125);
       }  
if(estado=='8'){
        analogWrite(3,255);
       }    

  digitalRead(40);
if(40==HIGH){            // IR  
  digitalWrite(28,HIGH); 
  delay(300); 
  digitalWrite(28,LOW);
  
}

      
  humo=analogRead(A0);
  delay (retardo);
  estado=0;

if(humo > 200){
  digitalWrite(28,HIGH);
 }else if(humo < 200){
  digitalWrite(28,LOW);
}

if(Serial2.available()>0){
  cadena = String("");
  while (Serial2.available()){
    cadena = cadena + char(Serial2.read());
    delay(1);
  }
  partirCadena();
  regulador=dato.toInt();
  Serial2.println(regulador);
  if(led=="luz1"){
    analogWrite(10,regulador);
  }
}
 
 delay(retardo);
 }

 void partirCadena(){
  if (cadena.indexOf(" ") >=0){
    led = cadena.substring(0, (cadena.indexOf(" ")));
    dato = cadena.substring(cadena.indexOf(" ")+1);
  }
 }







