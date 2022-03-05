
//Motor A
int enA = 9;
int in1 = 4;
int in2 = 5;
//Motor B
int enB = 10;
int in3 = 6;
int in4 = 7;
//joystick!
int VRx = A0;
int VRy = A1;
//Motor Speeds
int MotorSpeedA = 0;
int MotorSpeedB = 0;

int xPosition = 512;
int yPosition = 512;

void setup() 
{
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Motor A
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Motor B
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
}

void moveforward(){
  //motorA
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //motorB
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
  //speed?
  MotorSpeedA = map(yPosition, 564, 1023,0, 180);
  MotorSpeedB = map(yPosition, 564, 1023,0, 180);  
}

void movebackward(){
  //motorA
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //motorB
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
  //speed?
  yPosition = yPosition -460;
  yPosition = yPosition * -1;
  MotorSpeedA = map(yPosition, 0, 460,0, 180);
  MotorSpeedB = map(yPosition, 0, 460,0, 180);  
}

void stopped(){
  MotorSpeedA = 0;
  MotorSpeedB = 0;
}

void left(){
  xPosition = xPosition -460;
  xPosition = xPosition * -1;
  xPosition = map(xPosition, 0, 460,0, 180); 
   
  MotorSpeedA = MotorSpeedA - xPosition;
  MotorSpeedB = MotorSpeedB + xPosition; 
//never exceed 0-255 speed
  if (MotorSpeedA < 0)MotorSpeedA = 0;
  if (MotorSpeedB > 180)MotorSpeedB = 180;
}

void right(){
  xPosition = map(xPosition, 564, 1023,0, 180); 
   
  MotorSpeedA = MotorSpeedA + xPosition;
  MotorSpeedB = MotorSpeedB - xPosition; 
//never exceed 0-255 speed
  if (MotorSpeedA > 180)MotorSpeedA = 180;
  if (MotorSpeedB < 0)MotorSpeedB = 0;
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);

  if (yPosition <460){
    movebackward();
  }
  else if (yPosition >564){
    moveforward();
  }
  else{
    stopped();
  }
  if (xPosition <460){
    left();
  }
  else if (xPosition > 564){
    right();
  }
 
  analogWrite(enA, MotorSpeedA);
  analogWrite(enB, MotorSpeedB);
}
