#include <Arduino.h>

#define PUSH_BTN_PIN 12

/*
 * [JQC3F-05VDC-C 릴레이] 
 * - 릴레이 모듈 Active LOW 이므로 다음과 같이 정의
 */ 
#define RELAY_PIN 7
#define RELAY_ACTIVE LOW    // 릴레이 활성화 신호 정의
#define RELAY_DEACTIVE HIGH // 릴레이 비활성화 신호 정의

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(PUSH_BTN_PIN, INPUT_PULLUP);
}

void loop() {
  digitalWrite(RELAY_PIN, RELAY_DEACTIVE);
  int btnState = digitalRead(PUSH_BTN_PIN);
  Serial.print("btnState: ");
  Serial.println(btnState);
  if (btnState == LOW) { // 풀다운에 의한 버튼 눌릴 경우
    Serial.println("Button pushed! Relay ON!");
    // 3초 릴레이 가동 후 종료
    digitalWrite(RELAY_PIN, RELAY_ACTIVE);
    delay(3000);
  }
  delay(1); // 버튼 입력을 감지하는 폴링 방식에서는 루프가 너무 빨리 도는 것이 시스템 자원 낭비 delay(1);으로 CPU를 쉬게 하는 것이 더 효율적
}