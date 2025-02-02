#include <Arduino.h>

// Pines del sensor y display
int sensorPin = A0;
int sensorValue = 0;

const int segmentPins[] = {12, 10, 3, 4, 5, 11, 2}; // Segmentos A-G
const int digitPins[] = {9, 8, 7, 6};              // Dígitos D1-D4

// Mapas de segmentos para los números del 0 al 9
const byte numberPatterns[10] = {
    B00111111, // 0
    B00000110, // 1
    B01011011, // 2
    B01001111, // 3
    B01100110, // 4
    B01101101, // 5
    B01111101, // 6
    B00000111, // 7
    B01111111, // 8
    B01101111  // 9
};

void setup() {
    Serial.begin(9600);

    // Configurar pines como salidas
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
    for (int i = 0; i < 4; i++) {
        pinMode(digitPins[i], OUTPUT);
    }
}

void displayNumber(int number) {
    // Descomponer el número en dígitos
    int digits[4] = {0, 0, 0, 0};
    for (int i = 3; i >= 0; i--) {
        digits[i] = number % 10;
        number /= 10;
    }

    // Multiplexar los dígitos
    for (int i = 0; i < 4; i++) {
        // Encender solo el dígito actual
        for (int j = 0; j < 4; j++) {
            digitalWrite(digitPins[j], HIGH);
        }
        digitalWrite(digitPins[i], LOW);

        // Mostrar el patrón de segmentos para el dígito actual
        byte pattern = numberPatterns[digits[i]];
        for (int j = 0; j < 7; j++) {
            digitalWrite(segmentPins[j], (pattern >> j) & 1);
        }
        delay(5); // Pequeño retraso para el multiplexado
    }
}

void loop() {
    // Leer el valor del sensor de luz
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    // Mostrar el valor del sensor en el display
    displayNumber(sensorValue);

    // Reducir la velocidad del loop
    delay(50);
}
