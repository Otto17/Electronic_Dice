//Данный BLUE кубик обязательно должен загораться первый, после него RED, что бы избавится от задвоения музыки и задержки анимации между кубиками

void BLUE_Cube () {
  if (BlueToggle == false) {   // Если флаг опущен, то задействуем синую панель
    byte seed_BLUE = rnd_Blue.get(1, 7);   // Генерируем рандомные числа от 1 до 6 и записываем в переменную

    //Вывод результата на светодиоды и завершающий звуковой сигнал
    switch (seed_BLUE) {   // Получаем данные от псевдо-рандомайзера, какое значение получим, тот case и выполняем
      case 1:
        digitalWrite(BLUE_centerLED, HIGH);   // Вкл. LED14 и показываем на результат: 1
        break;                                // Выходим из оператора "case"
      case 2:
        digitalWrite(BLUE_LED9_12, HIGH);     // Вкл. LED9 и LED12 и показываем на результат: 2
        break;
      case 3:
        digitalWrite(BLUE_centerLED, HIGH);   // Вкл. LED9, LED12, LED14 и показываем на результат: 3
        digitalWrite(BLUE_LED9_12, HIGH);
        break;
      case 4:
        digitalWrite(BLUE_LED8_13, HIGH);      // Вкл. LED8, LED10, LED11, LED13 и показываем на результат: 4
        digitalWrite(BLUE_LED10_11, HIGH);
        break;
      case 5:
        digitalWrite(BLUE_centerLED, HIGH);    // Вкл. LED8, LED10, LED11, LED13, LED14 и показываем на результат: 5
        digitalWrite(BLUE_LED8_13, HIGH);
        digitalWrite(BLUE_LED10_11, HIGH);
        break;
      case 6:
        digitalWrite(BLUE_LED8_13, HIGH);       // Вкл. LED8, LED9, LED10, LED11, LED12, LED13 и показываем на результат: 6
        digitalWrite(BLUE_LED9_12, HIGH);
        digitalWrite(BLUE_LED10_11, HIGH);
        break;
    }
  }
}
