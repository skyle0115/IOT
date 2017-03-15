#include<Grove_LED_Bar.h>

Grove_LED_Bar bar(9, 8, 0);

//int inPin = 7;
//int val = 0;

void setup() {
  // put your setup code here, to run once:
  bar.begin();
  pinMode(2, INPUT);
  //pinMode(inPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == HIGH)
  {
    for (int i = 0; i <= 10; i++)
    {
      if(digitalRead(2) == LOW)
      {
        break;
      }
      bar.setLevel(i);
      delay(100);
    }
  }
  else
  {
    bar.setLevel(10);
  }

  delay(1000);

}
