int car_red = 12; // estabelece o semaforo para carros
int car_yellow = 11;
int car_green = 10;
int ped_red = 9; // estabelece o semaforo para pedestres
int ped_green = 8;
int button = 2; // pino do botao
int cross_time = 5000; // tempo para que os pedestres atravessem
unsigned long change_time; // tempo de conclusao do ultimo ciclo para pedestres

void setup() {
  pinMode(car_red, OUTPUT);
  pinMode(car_yellow, OUTPUT);
  pinMode(car_green, OUTPUT);
  pinMode(ped_red, OUTPUT);
  pinMode(ped_green, OUTPUT);
  pinMode(button, INPUT); // botao no pino 2
  // acende a luz verde
  digitalWrite(car_green, HIGH);
  digitalWrite(ped_red, HIGH);
}

void loop() {
  int state = digitalRead(button);
  /* verifica se o botao foi pressionado e se transcorreram 5 segundos desde a ultima vez que isso ocorreu*/
  if (state == HIGH && (millis() - change_time) > 5000) {
    // chama a funcao para alterar as luzes
    changeLights();
  }
}

void changeLights() {
  digitalWrite(car_green, LOW); // apaga o verde
  digitalWrite(car_yellow, HIGH); // acende o amarelo
  delay(2000); // espera 2 segundos

  digitalWrite(car_yellow, LOW); // apaga o amarelo
  digitalWrite(car_red, HIGH); // acende o vermelho
  delay(1000); // espera 1 segundo por seguranca

  digitalWrite(ped_red, LOW); // apaga o vermelho de pedestres
  digitalWrite(ped_green, HIGH); // acende o verde dos pedestres
  delay(cross_time); // espera um intervalo de tempo predefinido

  // pisca o verde dos pedestres
  for (int x = 0; x < 10; x++) {
    digitalWrite(ped_green, HIGH);
    delay(250);
    digitalWrite(ped_green, LOW);
    delay(250);
  }
  // acende o vermelho dos pedestres
  digitalWrite(ped_red, HIGH);
  delay(500);

  digitalWrite(car_yellow, HIGH); // acende o amarelo
  digitalWrite(car_red, LOW); // apaga o vermelho
  delay(1000);
  digitalWrite(car_green, HIGH); // acende o verde
  digitalWrite(car_yellow, LOW); // apaga o vermelho
  // registra o tempo desde a ultima alteracao no semafaro
  change_time = millis();
  // depois retorna para o loop principal do programa
}
