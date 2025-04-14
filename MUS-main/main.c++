#include <LiquidCrystal.h>

// Inicializa a biblioteca com os números dos pinos de interface do Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = A0;   // Pinagem do sensor de umidade do solo
int ledPin = 7;      // Pinagem do LED

void setup() {
  lcd.begin(16, 2);              // Configura o LCD com 16 colunas e 2 linhas
  pinMode(ledPin, OUTPUT);       // Configura o pino do LED como saída
  Serial.begin(9600);            // Inicia a comunicação serial para debug
}

void loop() {
  int sensorValue = analogRead(sensor);   // Lê o valor do sensor
  int humidity = map(sensorValue, 0, 1023, 0, 100); // Converte o valor lido para porcentagem
  
  lcd.clear();   // Limpa o display LCD
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(humidity);
  lcd.print("%");

  if (humidity < 50) {
    lcd.setCursor(0, 1);
    lcd.print("Solo Seco");
    digitalWrite(ledPin, HIGH);  // Liga o LED
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Solo Umido");
    digitalWrite(ledPin, LOW);   // Desliga o LED
  }
  
  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(1000);  // Espera por 1 segundo antes de fazer uma nova leitura
}
