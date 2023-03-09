void setup() {
  //Объявляем pin'ы LED Панелий и бузера как ВЫХОД
  pinMode(RED_centerLED, OUTPUT);
  pinMode(RED_LED1_6, OUTPUT);
  pinMode(RED_LED2_5, OUTPUT);
  pinMode(RED_LED3_4, OUTPUT);

  pinMode(BLUE_centerLED, OUTPUT);
  pinMode(BLUE_LED8_13, OUTPUT);
  pinMode(BLUE_LED9_12, OUTPUT);
  pinMode(BLUE_LED10_11, OUTPUT);

  pinMode(buzz, OUTPUT);

  //Объявляем pin'ы с кнопками как ВХОД
  pinMode(res_But, INPUT);
  pinMode(set_But, INPUT);

  //Получаем шумы для рандомайзера с неинициализированного аналогового входа
  rnd_Red.setSeed(analogRead(A1));    // Сид с порта A1 для RED Панели 1
  rnd_Blue.setSeed(analogRead(A4));   // Сид с порта A1 для BLUE Панели 2
}


void Animation () {
  //Анимация костей перед выпадом рандома и звуковое сопровождение анимации (если звук выключен, то просто анимация)
  if (BlueToggle == false) {    // Если Вкл. обе Панели, то выводим анимацию на оба кубика
    //Отключаем все светодиоды на Панелях
    PORTB = B00000000;          // Выключаем все LED на порту "B"
    PORTD = B00000000;          // Выключаем все LED на порту "D"

    for (byte turn = 0; turn < 3; turn++) {        // Выполняем цикл анимации 3 раза по кругу
      for (byte i = 0; i < sizeof(pinTWO); i++) {  // По очереди включаем, ждём и выключаем каждый pin с LED
        digitalWrite(pinTWO[i], HIGH);             // Вкл. светодиод
        if (BuzzToggle == false) {
          tone(buzz, 700, 40);                     // Вкл. звуковой сигнал на Buzzer частотой в 700 Гц на 40мс
        }
        delay(40);                                 // Ждём 40мс
        digitalWrite(pinTWO[i], LOW);              // Выкл. светодиод
      }
    }
  }

  if (BlueToggle == true) {   // Если Вкл. только Панель 1, то выводим анимацию на RED кубик
    //Отключаем все светодиоды на Панелях
    PORTB = B00000000;           // Выключаем все LED на порту "B"
    PORTD = B00000000;           // Выключаем все LED на порту "D"

    for (byte turn = 0; turn < 3; turn++) {        // Выполняем цикл анимации 3 раза по кругу
      for (byte i = 0; i < sizeof(pinONE); i++) {  // По очереди включаем, ждём и выключаем каждый pin с LED
        digitalWrite(pinONE[i], HIGH);             // Вкл. светодиод
        if (BuzzToggle == false) {
          tone(buzz, 700, 70);                     // Вкл. звуковой сигнал на Buzzer частотой в 700 Гц на 70мс
        }
        delay(70);                                 // Ждём 70мс
        digitalWrite(pinONE[i], LOW);              // Выкл. светодиод
      }
    }
  }
}
