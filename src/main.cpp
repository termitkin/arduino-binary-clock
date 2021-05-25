#include <DS3231.h>

// Shift register pins 74hc595
int dataPin = 9;   // 14 вывод на регистре
int clockPin = 11; // 11 вывод на регистре
int latchPin = 12; // 12 вывод на регистре

DS3231 clock(SDA, SCL);

void setup()
{
  Serial.begin(9600);

  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  clock.begin();

  // День недели
  clock.setDOW(MONDAY);
  // Часы, минуты, секунды
  clock.setTime(12, 10, 0);
  // День, месяц, год
  clock.setDate(25, 5, 2021);
}
void loop()
{
  Time time = clock.getTime();

  byte hours = time.hour;
  byte minutes = time.min;

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, minutes);
  shiftOut(dataPin, clockPin, LSBFIRST, hours);
  digitalWrite(latchPin, HIGH);
}
