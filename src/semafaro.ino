int led_delay = 10000; // tempo entre as alteracoes
int red_pin = 10;
int yellow_pin = 9;
int green_pin = 8;

void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
}

void loop() {
  digitalWrite(red_pin, HIGH);
  delay(led_delay);

  digitalWrite(yellow_pin, HIGH);
  delay(2000);

  digitalWrite(green_pin, HIGH);
  digitalWrite(red_pin, LOW);
  digitalWrite(yellow_pin, LOW);
  delay(led_delay);

  digitalWrite(yellow_pin, HIGH);
  digitalWrite(green_pin, LOW);
  delay(2000);


  digitalWrite(yellow_pin, LOW);
}
