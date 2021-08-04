#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
#include "Servo.h" //서보 라이브러리
 
Servo myservo; //서보객체
byte blueTx=2;   //Tx (블투 보내는핀 설정)
byte blueRx=3;   //Rx (블투 받는핀 설정)
SoftwareSerial bluetooth(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String data="";
byte flag=0;



void setup() {
  myservo.attach(9);   //서보 시그널 핀설정
  bluetooth.begin(9600); //블루투스 시리얼 개방
//  Serial.begin(9600);
  Serial.begin(9600);
  myservo.write(130);
}

int pos=1990;
//int latestPos=0; 

void loop() {
if(flag==0){
//        Serial.println("Stop : "+pos);
  }
  else if(flag==2){ //return
        pos=1990;
        myservo.write(pos);
        delay(2000);
  }
  else if(flag==1){ //go
    if(pos>=1000){
      pos-=10;

      myservo.writeMicroseconds(pos);

        delay(2000);
      
    }
  }
  else if(flag==3){
      if(pos<=2000){

     pos+=10;
     myservo.writeMicroseconds(pos);

       delay(2000);
      }
      
 
    }
  else{
      flag=0;
    }

//  Serial.println(flag);
  


  // put your main code here, to run repeatedly:
  if(bluetooth.available()){

    data=bluetooth.readStringUntil('\n');
    Serial.println(data);

      delay(50);
    if(data.equals("STOP")){
      flag=0;
    }
    else if(data.equals("GO")){
      flag=1;
    }
    else if(data.equals("RETURN")){
      flag=2;
    }
    else if(data.equals("BACK")){
    flag=3;
  }
   


  
  }

 
}
