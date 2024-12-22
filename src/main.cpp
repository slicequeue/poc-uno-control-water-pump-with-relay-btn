#include <Arduino.h>

#define RELAY_PIN 7
#define PUSH_BTN_PIN 12

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(PUSH_BTN_PIN, INPUT_PULLUP);
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  int btnState = digitalRead(PUSH_BTN_PIN);
  Serial.print("btnState: ");
  Serial.println(btnState);
  if (btnState == LOW) { // 풀다운에 의한 버튼 눌릴 경우
    Serial.println("Button pushed! Relay ON!");
    // 3초 릴레이 가동 후 종료
    digitalWrite(RELAY_PIN, LOW);
    delay(3000);
  }
  delay(1);

  // [릴레이 단독 테스트 완료]
  // Serial.println("Relay ON!");
  // digitalWrite(RELAY_PIN, HIGH);
  // delay(2000);
  // Serial.println("Relay OFF!");
  // digitalWrite(RELAY_PIN, LOW);
  // delay(1000);
}