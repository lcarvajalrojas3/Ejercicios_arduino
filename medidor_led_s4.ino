#include <Arduino.h>
#include <SevSeg.h>

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
int pinG = 2;
//int pinDP = .3;

// Pins para encender número.

int D1 = 9;
int D2 = 8;
int D3 = 7; 
int D4 = 6;

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
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

}


// FUNCIONES -----------------------------------------------------------------------------------------------------------

// NÚMEROS
void zero() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH); }
void one() { digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }
void two() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, LOW); }
void three() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, LOW); }
void four() { digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }
void five() { digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }
void six() { digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }
void seven() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH); }
void eight() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }
void nine() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }

// Apagado
void all_off() { digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW); }

// Canales
void d4() { digitalWrite(D1, HIGH); digitalWrite(D2, HIGH); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); }
void d3() { digitalWrite(D1, LOW); digitalWrite(D2, HIGH); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); }
void d2() { digitalWrite(D1, LOW); digitalWrite(D2, LOW); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); }
void d1() { digitalWrite(D1, LOW); digitalWrite(D2, LOW); digitalWrite(D3, LOW); digitalWrite(D4, HIGH); }


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