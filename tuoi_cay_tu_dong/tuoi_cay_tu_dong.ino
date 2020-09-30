#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "Servo.h"

#define servo1 9
#define relay 10

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;  // create servo object to control a servo

/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
 
/* khai báo các biến thời gian */
int second, minute, hour, day, wday, month, year; //giây, phút, giờ, thứ, ngày, tháng, năm
int humi1, humi2, temp;                             //Biến lưu nhiệt độ, độ ẩm đo hiện tại và lưu trong EEPROM
               //Biến lưu chế độ hoạt động của hệ thống, đếm thời gian

void setup() {
  // put your setup code here, to run once:
  
  Wire.begin();
 // Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  myservo.attach(9);
  myservo.write(0);
  pinMode(relay, OUTPUT);
  setTime(10, 3, 20, 5, 27, 9, 18); // 15:05:45 T4 06-12-2017
}

void loop() {
  // put your main code here, to run repeatedly:
  readDS1307();
  readSoilHumi1();
  readSoilHumi2();
  disPlay();
  
  if(humi1 < 60){
    digitalWrite(relay, LOW);
    myservo.write(45);
    lcd.setCursor(13,0);
    lcd.print("Bat");
    lcd.setCursor(15,1);
    lcd.print("1");
    delay(2000);
    }

  if(humi2 < 60){
    digitalWrite(relay, LOW);
    myservo.write(135);
    lcd.setCursor(13,0);
    lcd.print("Bat");
    lcd.setCursor(15,1);
    lcd.print("2");
    delay(2000);
    }
  
   if((humi1 > 70) && (humi2 > 70)){
    digitalWrite(relay, HIGH);
    myservo.write(0);
    lcd.setCursor(13,0);
    lcd.print("Tat");
    lcd.setCursor(15,1);
    lcd.print(" ");
   }
}



