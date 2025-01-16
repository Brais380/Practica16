/********************************************************************
Programación para simular el comprotamento de la penultima práctica 
de puertas logicas incllendo un pulsador/interruptor en los pines 
10,9,8 para forzar 0 o 1 :
La salida se activa en función de tres entradas controladas por 
interruptores, de manera que cumpla la función logica. 

F = not a x not b x c + a x not b x c + a x b x not c

Entardas pin 10,9,8 (digitales)
Salida pin 11 (digital)

Autor: Brais Rey Mirón
Fecha: 16 / Enero / 2025
********************************************************************/
/* Definimos los pine que utilizamos como A,B,C;RELE para evitar confusiones */
#define A 10
#define B  9
#define C  8
#define RELE 11

bool a = 0;// Definimos a,b,c como dato booleano
bool b = 0;
bool c = 0;

void setup() {
  pinMode(A, INPUT);// Definimos que funcion tiene cada pin INPUT / OUTPUT
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(RELE, OUTPUT);
}

void loop() {
  a = digitalRead(A);// Leemos y guardamos los estados de las entradas 
  b = digitalRead(B);
  c = digitalRead(C);
  bool condicion1 = !a && !b && c ;// Guardamos como datos booleanos las condiciones por separado; Para saber cuando se cumple una combinación de entradas
  bool condicion2 = a && !b && c ;
  bool condicion3 = a && b && !c ;
  if(condicion1) {// Cuando se cumpla la condicion 1:
    digitalWrite(RELE,HIGH);// Activa el RELE
  } 
  else {// En caso de que no se cumpla la condicion 1:
  if(condicion2) {// Cuando se cumplan la condicion 2:
     digitalWrite(RELE,HIGH);// Activa el RELE
  }
  else {// En caso de que no se cumpla la condicion 2:
  if(condicion3) {// Cuando se cumpla la condicion 3:
     digitalWrite(RELE,HIGH);// Activa el RELE
  }
  else {// En caso de que no se cumpla la condicion 3:
     digitalWrite(RELE,LOW);// Desactiva el RELE
  }
  }
  }
}
