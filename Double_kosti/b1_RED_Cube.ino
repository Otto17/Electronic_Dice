//Функция отображения выпавшего значения на RED кубике и анимация со звуком (если включён)

void RED_Cube () {
  byte seed_RED = rnd_Red.get(1, 7);   // Генерируем рандомные числа от 1 до 6 и записываем в переменную

  //Вывод результата на светодиоды и завершающий звуковой сигнал
  switch (seed_RED) {   // Получаем данные от псевдо-рандомайзера, какое значение получим, тот case и выполняем
    case 1:
      digitalWrite(RED_centerLED, HIGH);    // Вкл. LED7 и показываем на результат: 1
      dela_1();                             // Ждём, после того как прекратился звук после анимации
      buzEnd();                             // Подаём одиночный сигнал и отключаем его
      dela_2();                             // Опять ждём в тишине
      buzEnd();                             // И пвторяем, подавая одиночный сигнал, затем отключаем его
      break;                                // Выходим из оператора "case"
    case 2:
      digitalWrite(RED_LED2_5, HIGH);       // Вкл. LED2 и LED5 и показываем на результат: 2
      dela_1();
      buzEnd();
      dela_2();
      buzEnd();
      break;
    case 3:
      digitalWrite(RED_centerLED, HIGH);    // Вкл. LED2, LED5, LED7 и показываем на результат: 3
      digitalWrite(RED_LED2_5, HIGH);
      dela_1();
      buzEnd();
      dela_2();
      buzEnd();
      break;
    case 4:
      digitalWrite(RED_LED1_6, HIGH);       // Вкл. LED1, LED3, LED4, LED6 и показываем на результат: 4
      digitalWrite(RED_LED3_4, HIGH);
      dela_1();
      buzEnd();
      dela_2();
      buzEnd();
      break;
    case 5:
      digitalWrite(RED_centerLED, HIGH);    // Вкл. LED1, LED3, LED4, LED6, LED7 и показываем на результат: 5
      digitalWrite(RED_LED1_6, HIGH);
      digitalWrite(RED_LED3_4, HIGH);
      dela_1();
      buzEnd();
      dela_2();
      buzEnd();
      break;
    case 6:
      digitalWrite(RED_LED1_6, HIGH);       // Вкл. LED1, LED2, LED3, LED4, LED5, LED6 и показываем на результат: 6
      digitalWrite(RED_LED2_5, HIGH);
      digitalWrite(RED_LED3_4, HIGH);
      dela_1();
      buzEnd();
      dela_2();
      buzEnd();
      break;
  }
}
