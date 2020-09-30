void disPlay(){
  lcd.setCursor(0,0);
  //Hiển thị thứ
  if(wday == 1) lcd.print("CN");
  else {
    lcd.print("T");
    lcd.print(wday);  
  }
  delay(10);
  
  //Hiển thị ngày/tháng/năm
  lcd.setCursor(3,0);
  lcd.print(day);
  delay(10);
  lcd.print("/");
  delay(10);
  lcd.print(month);
  delay(10);
  lcd.print("/");
  delay(10);
  lcd.print(year);
  delay(10);
  lcd.print("  ");
  delay(10);
  
  //Hiển thị giờ:phút:giây
  lcd.setCursor(0,1);
  lcd.print(hour);
  delay(10);
  lcd.print(":");
  delay(10);
  lcd.print(minute);
  delay(10);
//  lcd.print(":");
//  delay(10);
//  lcd.print(second);
//  delay(10);
  lcd.print("  ");
  delay(10);

  //Hiển thị độ ẩm
  lcd.setCursor(7,1);
  lcd.print(humi1);
  delay(10);
  lcd.print("% ");
  delay(10);

  lcd.setCursor(11,1);
  lcd.print(humi2);
  delay(10);
  lcd.print("% ");
  delay(10);
  
  //Hiển thị trạng thái máy bơm
  lcd.setCursor(13,0);
  delay(10);
  if(!digitalRead(relay)){
    lcd.setCursor(13,0);
    lcd.print("Bat");
    }
  if(digitalRead(relay)){
    lcd.setCursor(13,0);
    lcd.print("Tat");
    }
}
