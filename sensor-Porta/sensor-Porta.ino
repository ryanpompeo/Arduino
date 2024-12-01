#include <Servo.h>
Servo mm;
int ledVermelho = 13;
int ledVerde = 12;
int pir = 2;
int valor;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    pinMode(13, OUTPUT);
 	pinMode(12, OUTPUT);
    pinMode(pir, INPUT);
   	mm.attach(3);
   	mm.write(0);
}

void loop() {
    valor = digitalRead(pir);
    
    if (valor == HIGH) {
        digitalWrite(ledVerde, HIGH);
      	digitalWrite(ledVermelho, LOW);
        Serial.println("ESTADO PORTA - ABERTA");
      	mm.write(90);
      	delay(2000);
       	mm.write(0);
      
    } else {
        digitalWrite(ledVerde, LOW);
      	digitalWrite(ledVermelho, HIGH);
        Serial.println("ESTADO PORTA - FECHADA");
    }
    
    delay(100);
}
