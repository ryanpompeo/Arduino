#include <TM1637Display.h>

#define CLK 2
#define DIO 3
#define TRIG_PIN 9
#define ECHO_PIN 10

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  display.setBrightness(0x0f);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duracao;
  int distancia;
  const int numeroLeitura = 10;
  long duracaoTotal = 0;

  for (int i = 0; i < numeroLeitura; i++) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duracao = pulseIn(ECHO_PIN, HIGH);

    duracaoTotal += duracao;

    delay(10);
  }

   duracao =  duracaoTotal / numeroLeitura;

  if (duracao == 0 ||duracao > 30000) {
    distancia = 0;
  } else {
    distancia = (duracao / 2) * 0.0344;
  }

  display.showNumberDec(distancia, false);

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(1000);
}