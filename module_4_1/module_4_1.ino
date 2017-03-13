#include <Grove_LED_Bar.h>

Grove_LED_Bar bar(9, 8, 0);

void setup() {
  Serial.begin(9600);
  bar.begin();
}

void loop() {
  int sound = analogRead(A0);
  bar.setLevel(sound / 10);
  delay(100);
}
