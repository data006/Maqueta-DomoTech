#include <Servo.h> 
Servo servo1;         // Crea el servo1 con las librerias de Servo.h

int estado=0;
int retardo=100;
int analogo=0;

void setup(){
  servo1.attach(4);
  pinMode(A0, INPUT);          //Entrada del detector de humo
  pinMode(22, OUTPUT);         //Foco del garaje
  pinMode(23, OUTPUT);         //Foco de la cocina
  pinMode(24, OUTPUT);         //Foco del baño
  pinMode(25, OUTPUT);         //Foco del cuarto
  pinMode(26, OUTPUT);         //Buzzer de alarmas
  pinMode(2, OUTPUT);          //(+) motor del garaje
  pinMode(3, OUTPUT);          //(-) motor del garaje
  pinMode(4, OUTPUT);          //(+) motor del elevador
  pinMode(5, OUTPUT);          //(-) motor del elevador
  pinMode(6, OUTPUT);          //(+) motor de la persiana
  pinMode(7, OUTPUT);          //(-) motor de la persiana
  pinMode(27, OUTPUT);         //Focos navideños
  pinMode(10, OUTPUT);         //LED para controlar el dimmer
  pinMode(8, OUTPUT);          //(+) motor del ventilador
  pinMode(9, OUTPUT);          //(-) motor del ventilador
  
  Serial.begin(9600);         //Inicia la conexión serial
  delay(1000);                //Delay de inicialización
}

void loop(){
  if(Serial.available()>0){   //Si el bluetooth envió algo haz lo siguiente:
    estado = Serial.read();   //El valor de la variable "estado" ahora valdrá lo que llegue del bluetooth

    int valor=Serial.read()-48;
    valor=map(valor,0,10,0,254);
    analogWrite(10,valor);
  }
  
  if(estado=="a"){             //Si la variable "estado" vale "a", haz lo siguiente:
    digitalWrite(22, HIGH);    //Prende el foco del garaje
  }

  if(estado=="b"){             //Si la variable "estado" vale "b", haz lo siguiente:
    digitalWrite(22, LOW);     //Apaga el foco del garaje
  }

  if(estado=="c"){             //Si la variable "estado" vale "c", haz lo siguiente:
    digitalWrite(23, HIGH);    //Prende el foco de la cocina
  }

  if(estado=="d"){             //Si la variable "estado" vale "d", haz lo siguiente:
    digitalWrite(23, LOW);     //Apaga el foco de la cocina
  }

  if(estado=="e"){             //Si la variable "estado" vale "e", haz lo siguiente:
    digitalWrite(24, HIGH);    //Prende el foco del baño
  }

  if(estado=="f"){             //Si la variable "estado" vale "f", haz lo siguiente:
    digitalWrite(24, LOW);     //Apaga el foco del baño
  }

  if(estado=="g"){             //Si la variable "estado" vale "g", haz lo siguiente:
    digitalWrite(25, HIGH);    //Prende el foco del cuarto
  }

  if(estado=="h"){             //Si la variable "estado" vale "h", haz lo siguiente:
    digitalWrite(25, LOW);     //Apaga el foco del cuarto
  }

  if(estado=="i"){             //Si la variable "estado" vale "i", haz lo siguiente:
    analogWrite(2, 255);       //(+) motor del garaje
    analogWrite(3, 0);         //(-) motor del garaje
  }

  if(estado=="j"){             //Si la variable "estado" vale "j", haz lo siguiente:
    analogWrite(2, 0);         //(-) motor del garaje
    analogWrite(3, 255);       //(+) motor del garaje
  }

  if(estado=="k"){             //Si la variable "estado" vale "k", haz lo siguiente:
    analogWrite(4, 255);       //(+) motor del elevador
    analogWrite(5, 0);         //(-) motor del elevador
  }

  if(estado=="l"){             //Si la variable "estado" vale "l", haz lo siguiente:
    analogWrite(4, 0);         //(-) motor del elevador
    analogWrite(5, 255);       //(+) motor del elevador
  }

  if(estado=="m"){             //Si la variable "estado" vale "m", haz lo siguiente:
    analogWrite(6, 255);       //(+) motor de la persiana
    analogWrite(7, 0);         //(-) motor de la persiana
  }

  if(estado=="n"){             //Si la variable "estado" vale "n", haz lo siguiente:
    analogWrite(6, 0);         //(-) motor de la persiana
    analogWrite(7, 255);       //(+) motor de la persiana
  }

  if(estado=="o"){             //Si la variable "estado" vale "o", haz lo siguiente:
    analogWrite(8, 255);       //(+) motor del ventilador
    analogWrite(9, 0);         //(-) motor del ventilador
  }

  if(estado=="p"){             //Si la variable "estado" vale "p", haz lo siguiente:
    analogWrite(8, 0);         //(-) motor del ventilador
    analogWrite(9, 255);       //(+) motor del ventilador
  }

  if(estado=="q"){             //Si la variable "estado" vale "q", haz lo siguiente:
    digitalWrite(27, HIGH);    //Prende los focos navideños
  }

  if(estado=="r"){             //Si la variable "estado" vale "r", haz lo siguiente:
    digitalWrite(27, LOW);     //Apaga los focos navideños
  }

  int adc_mq =analogRead(A0);  //Creamos la variable "adc_mq" donde se guardará la lectura de humo

  if(adc_mq > 200){            //Si detecta mas de 200 de humo haz lo siguiente:
    digitalWrite(26, HIGH);    //Prende el buzzer de alarma
  }else if(adc_mq < 200){      //Sino detecta mas de 200 de humo haz lo siguiente:
    digitalWrite(26, LOW);     //Apaga el buzzer de alarma
  }

  
}
