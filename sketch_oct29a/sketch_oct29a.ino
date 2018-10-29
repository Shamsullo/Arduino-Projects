
#include <Servo.h> 
#include <SoftwareSerial.h>

SoftwareSerial BT(3,2);
Servo rightServo;        // create servo object to control a servo 
Servo leftServo;                // a maximum of eight servo objects can be created 
 
void fw();
void bw();
void left();
void right();
void stop();
 
void setup() 
{ 
  // put your setup code here, to run once:
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  
  rightServo.attach(3);  // attaches the servo on pin 9 to the servo object 
  leftServo.attach(5);
   
} 
 
void loop() 
{ 
    if(BT.available()){
      char input = BT.read();
      Serial.println(input);
      
      int RL = 0;
      
      if( input == 'U'){
        fw();
        RL = 1;
        if (input == 'u')
          stop();
      }else if( input == 'D'){
        bw();
        RL = -1;
        if (input == 'd')
          stop();
      }
      
      if( input == 'R'){
        right();
        if (input == 'r'){
          if (RL == 1){
            fw();
          }else if (RL == -1){
            bw();
        }
      }else if( input == 'L'){
        left();
           if (input == 'r'){
          if (RL == 1){
            fw();
          }else if (RL == -1){
            bw();
        }
      }
      
      if (intput == 'U'){
        stop();
      }
        

} 


void fw(){
    rightServo.write(0);
    leftServo.write(180);
}

void bw(){
    rightServo.write(180);
    leftServo.write(0);

}

void left(){
    rightServo.write(0);
    leftServo.write(90);
}

void right(){
    rightServo.write(90);
    leftServo.write(180);
}

void stop(){
    rightServo.write(90);
    leftServo.write(90);
}

