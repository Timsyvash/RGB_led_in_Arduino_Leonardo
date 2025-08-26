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
  digitalWrite(redPin, HIGH); // Для анода: 255 = вимкнено
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void loop() {
  // вставлення сюди свій основний код для багаторазового виконання:
  Serial.println(msg);
  while (Serial.available()==0) {

  }
  myColor = Serial.readStringUntil('\n'); // Зчитуємо до нового рядка
  myColor.trim(); // Видаляємо пробіли та \r, \n

  bool isOff = (digitalRead(redPin) == HIGH && digitalRead(greenPin) == HIGH && digitalRead(bluePin) == HIGH);

  if(myColor=="red") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }
  if(myColor=="green") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  if(myColor=="blue") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }
  if(myColor=="off") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }

  if(myColor=="yellow") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  if(myColor=="cyan") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }

  if(myColor=="magenta") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 155);
  }

  if(myColor=="violet") {
    analogWrite(redPin, 127);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }

  if(myColor=="aqua") {
    analogWrite(redPin, HIGH);
    analogWrite(greenPin, 155);
    analogWrite(bluePin, 175);
  }

  if(myColor=="on" && isOff) {
    analogWrite(redPin, rand() * 255);
    analogWrite(greenPin, rand() * 255);
    analogWrite(bluePin, rand() * 255);
  }
  if (myColor == "on" && !isOff) {
    Serial.println("Світлодіод уже увімкнено! Введіть off перед on.");
  }
  if(myColor!="red" && myColor!="green" && myColor!="blue" && myColor!="off" && myColor!="yellow" && myColor!="cyan" && myColor!="magenta" && myColor!="violet" && myColor!="aqua" && myColor!="on") {
    Serial.println("Невідомий колір. Спробуйте red, green, blue, yellow, cyan, magenta, violet, aqua, on або off.");
  }
}
 