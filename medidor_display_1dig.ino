#include <Arduino.h>
#include <SevSeg.h>

// He cambiado el display led desde uno de 4 digitos a uno de solamente 1 digito. Para esto necesito reconfigurar algunos canales de salida y eliminar otro.
// No agregué el punto decimal

// Pin de sensor

int sensorPin = A0;
int sensorValue = 0;

// Pins para construir número

int pinA = 12;
int pinB = 10;
int pinC = 3;
int pinD = 4;
int pinE = 5;                                
int pinF = 11;
int pinG = 7; // cambiado
//int pinDP = .3;

// Pins para encender número.

int D1 = 9;
int D2 = 8;

// SETUP
// Canales

void setup() {
  
  // Inicializa la comunicación serie para monitorear los datos
  Serial.begin(9600); 

  //set all segments & digits as outputs

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  //pinMode(pinDP, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);

}


// FUNCIONES -----------------------------------------------------------------------------------------------------------

// NÚMEROS
void zero() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, LOW); }
void one() { digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }
void two() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH); }
void three() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH); }
void four() { digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }
void five() { digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }
void six() { digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }
void seven() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }
void eight() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }
void nine() { digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }

// Apagado
void all_off() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }

// Canales
void d1() { digitalWrite(D1, LOW); digitalWrite(D2, LOW); }


int PUT = 0;

void loop() {
  
  // Lee el valor del sensor de luz (de 0 a 1023)
  sensorValue = analogRead(sensorPin);

  // Imprime el valor del sensor para monitoreo
  Serial.println(sensorValue);

  PUT = sensorValue;
  if (PUT <= 100) { d1(); zero(); delay(100); }
  else if (PUT <= 200) { d1(); one(); delay(100); }
  else if (PUT <= 300) { d1(); two(); delay(100); }
  else if (PUT <= 400) { d1(); three(); delay(100); }
  else if (PUT <= 500) { d1(); four(); delay(100); }
  else if (PUT <= 600) { d1(); five(); delay(100); }
  else if (PUT <= 700) { d1(); six(); delay(100); }
  else if (PUT <= 800) { d1(); seven(); delay(100); }
  else if (PUT <= 900) { d1(); eight(); delay(100); }
  else if (PUT <= 1023) { d1(); nine(); delay(100); }

}