/* Функция измерения напряжения питания микроконтроллера и оботражение напряжения
   в виде кол-ва горящих LED. 1 LED равен 0.1 Вольту аккумулятора.
   14 горящих LED - 4.2V или более (полностью заряжен аккумулятор);
    1 горящий LED - 2.9V или менее (полностью разряжен аккумулятор).

    Использовал прямое обращение к пинам через регистры, что бы код работал на много быстрее,
    занимал на много меньше места и был на много компактнее.
*/

void Battery() {
  //Вычисляем исходные данные
  ADMUX = (1 << REFS0) | (0 << REFS1) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (0 << MUX0);
  long buffersamp = 0;
  for (int n = 0x0; n <= 0xff; n++ ) {
    ADCSRA |= (1 << ADSC) | (1 << ADEN);    //Начинаем новую конверсию

    while (bit_is_set(ADCSRA, ADSC));
    buffersamp += ADC;
  }
  buffersamp >>= 4;         //16368 полная шкала (14 бит)
  ADCSRA &= ~(1 << ADEN);   // отключаем АЦП

  //Получаем точное напряжение и переводим его в целое число для сравнения.
  float  Vin = (float)(REFERENCE_VOLTAGE * 16368) / buffersamp;    // Расчёт конечного напряжения
  byte Vop = (byte)(Vin * 10);    // Переводим дробную часть в целое для корректного сравнения в "if else" (сравнивать float в if НЕЛЬЗЯ, будут некорректные значения)

  //Сравниваем напряжение
  //К примеру 4.2v * 10 = 42; 3.7v * 10 = 37. Это необходимо, так как с float очень сложно получить точный результат в "if else"
  if (Vop >= 42) {        // Аккумулятор полностью заряжен (4.2V или более)
    PORTB = B11111111;    // Все 14 светодиодов на панелях горят
    PORTD = B11111111;
  }
  else  if (Vop == 41) {   // Горят 13 LED (4.1V)
    PORTB = B11111110;
    PORTD = B11111111;
  }
  else if (Vop == 40) {   // Горят 12 LED (4.0V)
    PORTB = B11111111;
    PORTD = B10111111;
  }
  else if (Vop == 39) {   // Горят 11 LED (3.9V)
    PORTB = B11111110;
    PORTD = B10111111;
  }
  else if (Vop == 38) {   // Горят 10 LED (3.8V)
    PORTB = B11111111;
    PORTD = B01011111;
  }
  else if (Vop == 37) {   // Горят 9 LED (3.7V)
    PORTB = B11111110;
    PORTD = B01011111;
  }
  else if (Vop == 36) {   // Горят 8 LED (3.6V)
    PORTB = B11111111;
    PORTD = B00011111;
  }
  else if (Vop == 35) {   // Горят 7 LED (3.5V)
    PORTB = B11111110;
    PORTD = B00011111;
  }
  else if (Vop == 34) {   // Горят 6 LED (3.4V)
    PORTB = B00000000;
    PORTD = B00010011;
  }
  else if (Vop == 33) {   // Горят 5 LED (3.3V)
    PORTB = B00000100;
    PORTD = B00010001;
  }
  else if (Vop == 32) {   // Горят 4 LED (3.2V)
    PORTB = B00000000;
    PORTD = B00010001;
  }
  else if (Vop == 31) {   // Горят 3 LED (3.1V)
    PORTB = B00000100;
    PORTD = B00000010;
  }
  else if (Vop == 30) {   // Горят 2 LED (3.0V)
    PORTB = B00000000;
    PORTD = B00000010;
  }
  else if (Vop <= 29) {   // Аккумулятор полностью разряжен
    PORTB = B00000100;    // Горит 1 LED (2.9V или менее)
    PORTD = B00000000;
  }
}