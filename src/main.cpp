#include <iarduino_RTC.h>

// Shift register pins 74hc595
int dataPin = 9;   // 14 вывод на регистре
int clockPin = 11; // 11 вывод на регистре
int latchPin = 12; // 12 вывод на регистре

// Clock pins
int CLK = 7;
int DAT = 6;
int RST = 5;

iarduino_RTC time(RTC_DS1302, RST, CLK, DAT);

void setup()
{
  Serial.begin(9600);

  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Init time
  time.begin();

  // Setup time
  // СЕК, МИН, ЧАС, ДЕНЬ, МЕС, ГОД, ДН
  // time.settime(0, 10, 10, 10, 1, 21, 1);
}

void loop()
{
  time.gettime();
  byte hours = time.Hours;
  byte minutes = time.minutes;

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, minutes);
  shiftOut(dataPin, clockPin, LSBFIRST, hours);
  digitalWrite(latchPin, HIGH);
}
