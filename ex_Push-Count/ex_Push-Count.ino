#include <Wire.h>
#include <SSD1306.h> //ESP8266 and ESP32 OLED driver for SSD1306 displays

SSD1306 display(0x3c, 26, 25); //(I2C, SDA, SCL)
//Uses I2C, connectorB only

const int swPin = 32;

int iCount = 0;
int iResetJudge = 0;
 
void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  // 初期表示
  display.init(); //Initialization
  display.setFont(ArialMT_Plain_24); //Set Font
  display.drawString(0, 0, "0");
  display.display(); //Draw
}

void loop() {

  if (digitalRead(swPin) == HIGH) {
    Serial.println("Pushed"); 
    iResetJudge++;
    delay(200);

    if(iResetJudge == 10){
      // 2秒以上ボタンを押しした場合
      // カウントをリセット
      iCount = 0;
      iResetJudge = 0;
      Serial.println("push count reset!"); 

      // OLEDにリセットを表示
      display.init(); //Initialization
      display.drawString(0, 0, String(iCount));
      display.drawString(0, 21, "Reset!"); 
      display.display(); //Draw

      delay(1000);

      Serial.println("----------");
    }

  } else if (digitalRead(swPin) == LOW) {
    Serial.println("Not Pushed");
    // delay(200);

    if(iResetJudge > 0){
      // 短く押した場合
      // カウントを+1回する
      iCount++;
      iResetJudge = 0;

      // OLEDにカウントを表示
      display.init(); //Initialization
      display.drawString(0, 0, String(iCount));
      display.display(); //Draw

      Serial.println("----------");

    }
    delay(200);

  }
}