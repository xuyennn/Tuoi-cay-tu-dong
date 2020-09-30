int readSoilHumi1(){
  int a = 0, i;
  for(i = 0; i<20; i++){
    a += analogRead(A0);
    delay(50);
  }
  a = a/20;
  //Serial.println(a);
  humi1 = (1024-a)/10;
  //return soil_humi;
}

int readSoilHumi2(){
  int a = 0, i;
  for(i = 0; i<20; i++){
    a += analogRead(A1);
    delay(50);
  }
  a = a/20;
  //Serial.println(a);
  humi2 = (1024-a)/10;
  //return soil_humi;
}
