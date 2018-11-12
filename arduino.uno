
  #include <Servo.h> 
  #include <SoftwareSerial.h>

  SoftwareSerial BT(3,2);
  Servo rightServo;        // create servo object to control a servo 
  Servo leftServo;                // a maximum of eight servo objects can be created 
   
  void setup() { 
    // put your setup code here, to run once:
    BT.begin(9600);
    Serial.begin(9600);
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    
    rightServo.attach(3);  // attaches the servo on pin 9 to the servo object 
    leftServo.attach(5);
     
  } 
   
  void loop() { 
    if(BT.available()){
      char input = BT.read();
      Serial.println(input);
      switch(input){
        case 'U':
          fw();
          break;
        case 'D':
          bw();
          break;
        case 'L':
          left();
          break;
        case 'R':
          right();
          break;
        default:
          stop();
          break;
      }
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
    leftServo.write(91);
  }

  void right(){
    rightServo.write(91);
    leftServo.write(180);
  }

  void stop(){
    rightServo.write(91);
    leftServo.write(91);
  }
