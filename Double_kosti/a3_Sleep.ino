//Функция для ухода в глубокий сон

void sleep_On () {
  // Проверим не пора ли спать
  if (millis() - timer > TIME_BEFORE_SLEEP) {   // Если пора, то...

    //Выключаем все светодиоды
    PORTB = B00000000;        // Выключаем все LED на порту "B"
    PORTD = B00000000;        // Выключаем все LED на порту "D"

    //Просыпаться будем при при изменении сигнала на входе "res_But" от LOW к HIGH
    attachInterrupt(digitalPinToInterrupt(res_But), myISR, LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // Функция выбора режимов сна (выбран самый глубокий сон - Power-Down)
    ADCSRA &= ~(1 << ADEN);   // отключаем АЦП перед сном, что даёт нам сильную экономию по потреблению питания в режиме сна.
    sleep_mode();             // Переводим МК в сон

    //Как только проснулись после сна по нажатию кнопки, запрещаем обработку внешнего прерывания
    detachInterrupt(digitalPinToInterrupt(res_But));

    //Тут можно добавить свой код:
    timer = millis();     // Записывает текущее время в "timer"
    buttonPrev = false;   // Опускаем флаг Reset
    ResetPusk = true;     // Поднимаем флаг для автоброска кубика(ков) после сна
  }
}
