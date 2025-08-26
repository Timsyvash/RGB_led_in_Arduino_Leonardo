#include <Arduino.h>

int redPin=8;
int greenPin=9;
int bluePin=10;
String myColor;
String msg="What color do you want?";
void setup() {
  // вставлення сюди свій код налаштування для одноразового запуску:
  Serial.begin(9600);
  delay(1000);
  while (!Serial) { // Чекаємо, поки порт буде готовий (для Leonardo)
    ; // Нічого не робимо
  }
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  // Початкове вимкнення світлодіода
  analogWrite(redPin, 255); // Для анода: 255 = вимкнено
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}

void loop() {
  // вставлення сюди свій основний код для багаторазового виконання:
  Serial.println(msg);
  while (Serial.available()==0) {

  }
  myColor = Serial.readStringUntil('\n'); // Зчитуємо до нового рядка
  myColor.trim(); // Видаляємо пробіли та \r, \n
  Serial.println("Введено: [" + myColor + "]"); // Діагностика вводу

  if(myColor=="red") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  if(myColor=="green") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  if(myColor=="blue") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  if(myColor=="off") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }

}
 