 /* 
 Project : Pick N Place Robot
 */
int motor1Pin1 = 8; // pin 2 on L293D IC
int motor1Pin2 = 7; // pin 7 on L293D IC
int enable1Pin = 9; // pin 1 on L293D IC
int motor2Pin1 = 5; // pin 10 on L293D IC
int motor2Pin2 = 4; // pin 15 on L293D IC
int enable2Pin = 6; // pin 9 on L293D IC
int motor3Pin1 = 14; // pin 2 on L293D IC
int motor3Pin2 = 13; // pin 7 on L293D IC
int enable3Pin = 15; // pin 1 on L293D IC
int motor4Pin1 = 11; // pin 10 on L293D IC
int motor4Pin2 = 10; // pin 15 on L293D IC
int enable4Pin = 12; // pin 9 on L293D IC
int state;
int flag=0;
void setup() {
    pinMode(motor1Pin1, OUTPUT),pinMode(motor1Pin2, OUTPUT),pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT),pinMode(motor2Pin2, OUTPUT),pinMode(enable2Pin, OUTPUT);
    pinMode(motor3Pin1, OUTPUT),pinMode(motor3Pin2, OUTPUT),pinMode(enable3Pin, OUTPUT);
    pinMode(motor4Pin1, OUTPUT),pinMode(motor4Pin2, OUTPUT),pinMode(enable4Pin, OUTPUT);
    Stop();
    Serial.begin(9600);
}
void loop() {
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }  
    
    if (state == 'F'){
      Forward();
      if(flag == 0)Serial.println("Go Forward"),flag=1;
    }
    
    else if (state == 'B'){
      Reverse();
      if(flag == 0)Serial.println("Go Reverse"),flag=1;
    }
    
    else if (state == 'L'){
      Left();
      if(flag == 0)Serial.println("Go Left"),flag=1;
    }
    
    else if (state == 'R'){
      Right();
      if(flag == 0)Serial.println("Go Right"),flag=1;
    }
    
    else if (state == 'S'){
      Stop();
      if(flag == 0)Serial.println("STOP!"),flag=1;
    }
    
    else if (state == 'P'){
      Pick();
      if(flag == 0)Serial.println("Pick"),flag=1;
    }
    
    else if (state == 'Q'){
      Place();
      if(flag == 0)Serial.println("Place"),flag=1;
    }
    
    else if (state == 'H'){
      Hold();
      if(flag == 0)Serial.println("Hold"),flag=1;
    }
    
    else if (state == 'I'){
      Free();
      if(flag == 0)Serial.println("Unhold"),flag=1;
    }
    
}
void Forward(){
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
}
void Reverse(){
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
}
void Left(){
  digitalWrite(motor1Pin1, HIGH); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
}
void Right(){
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(enable1Pin, HIGH);
  digitalWrite(enable2Pin, HIGH);
}
void Pick(){
  digitalWrite(motor3Pin1, LOW); 
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(enable3Pin, HIGH);
}
void Place(){
  digitalWrite(motor3Pin1, HIGH); 
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(enable3Pin, HIGH);
}
void Hold(){
  digitalWrite(motor4Pin1, LOW); 
  digitalWrite(motor4Pin2, HIGH);
  digitalWrite(enable4Pin, HIGH);
}
void Free(){
  digitalWrite(motor4Pin1, HIGH); 
  digitalWrite(motor4Pin2, LOW);
  digitalWrite(enable4Pin, HIGH);
}
void Stop(){    // Stop the motors
  digitalWrite(enable1Pin, LOW);
  digitalWrite(enable2Pin, LOW);
  digitalWrite(enable3Pin, LOW);
  digitalWrite(enable4Pin, LOW);
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW); 
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
}
