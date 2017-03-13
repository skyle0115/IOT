#include<Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(3);
  myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LightValue = analogRead(A0);
  Serial.println("The Light Value :");
  Serial.println(LightValue);
  int max_degree = 90+(LightValue*90/1023);
  int min_degree = 90-(LightValue*90/1023);
  for(int i=min_degree;i<max_degree;i++)
  {
    myservo.write(i);
    delay(15);
  }
  for(int i=max_degree;i>=min_degree;i--)
  {
    myservo.write(i);
    delay(15);
  }
  delay(100);
}
