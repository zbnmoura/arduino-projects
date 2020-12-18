// LED conectado ao pino 10
int led_pin = 10;

// put your setup code here, to run once:
void setup() {
  // define o pino digital como saida
  pinMode(led_pin, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  // 3 pontos
  for (int x = 0; x < 3; x++) {
    digitalWrite(led_pin, HIGH); //acende o led
    delay(150); // espera 150ms
    digitalWrite(led_pin, LOW); // apaga o LED
    delay(100); // espera 100ms
  }
  // espera 100ms para marcar o intervalo entre as letras
  delay(100);

  // 3 tracos
  for (int x = 0; x < 3; x++) {
    digitalWrite(led_pin, HIGH); //acende o led
    delay(400); // espera 400ms
    digitalWrite(led_pin, LOW); // apaga o LED
    delay(100); // espera 100ms
  }
  // espera 100ms para marcar o intervalo entre as letras
  delay(100);

  // 3 tracos
  for (int x = 0; x < 3; x++) {
    digitalWrite(led_pin, HIGH); //acende o led
    delay(1500); // espera 150ms
    digitalWrite(led_pin, LOW); // apaga o LED
    delay(100); // espera 100ms
  }
  // espera 5 segundo antes de repetir o sinal de SOS
  delay(5000);
}
