/*
 * Скетч для проверки (отключает по одному) по очереди все LED и так по кругу
 */
#define ss 3000

void setup() {
  // put your setup code here, to run once:
  /*
     DDRx – регистр направления порта. С его помощью вы указываете микроконтроллеру
     чем является порт – входом или выходом, при этом «1» - выход, а «0» - вход.
  */
  //Порт B и D имеют 8 ножек, идут от большего к меньшему.
  DDRB = B11111111;   // Цифра 1 - значит ВЫХОД, цифра 0 - ВХОД
  DDRD = B11111111;   // Все пины обозначины как ВЫХОД

  /*
     PORTx – Управление состоянием вывода. Если пин находится в режиме «Выхода»,
     то 1 и 0 определяют наличие этих же сигналов на выходе.
     Если же пин находится в режиме «Входа», то 1 подключает подтягивающий резистор
     (тоже что и INPUT_PULLUP рассмотренный выше), если 0 – высокоимпедансное состояние (аналог INPUT);
  */
  PORTB = B00000000;    // Так как все пины обозначены как ВЫХОД, то цифра 0 значит - LOW
  PORTD = B00000000;    // На всех пинах состояние LOW
  delay(ss);
}

void loop() {
  // Горят 14 LED
  PORTB = B11111111;    // Все 14 светодиодов на панелях горят
  PORTD = B11111111;
  delay(ss);

  // Горят 13 LED
  PORTB = B11111110;
  PORTD = B11111111;
  delay(ss);

  // Горят 12 LED
  PORTB = B11111111;
  PORTD = B10111111;
  delay(ss);

  // Горят 11 LED
  PORTB = B11111110;
  PORTD = B10111111;
  delay(ss);

  // Горят 10 LED
  PORTB = B11111111;
  PORTD = B01011111;
  delay(ss);

  // Горят 9 LED
  PORTB = B11111110;
  PORTD = B01011111;
  delay(ss);

  // Горят 8 LED
  PORTB = B11111111;
  PORTD = B00011111;
  delay(ss);

  // Горят 7 LED
  PORTB = B11111110;
  PORTD = B00011111;
  delay(ss);

  // Горят 6 LED
  PORTB = B00000000;
  PORTD = B00010011;
  delay(ss);

  // Горят 5 LED
  PORTB = B00000100;
  PORTD = B00010001;
  delay(ss);

  // Горят 4 LED
  PORTB = B00000000;
  PORTD = B00010001;
  delay(ss);

  // Горят 3 LED
  PORTB = B00000100;
  PORTD = B00000010;
  delay(ss);

  // Горят 2 LED
  PORTB = B00000000;
  PORTD = B00000010;
  delay(ss);

  // Аккумулятор полностью разряжен
  PORTB = B00000100;    // Горит 1 LED
  PORTD = B00000000;
  delay(ss);

}