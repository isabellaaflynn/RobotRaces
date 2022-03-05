//joystick!
int VRx = A0;
int VRy = A1;
//Motor A
int enA = 9;
int in1 = 4;
int in2 = 5;
//Motor B
int enB = 10;
int in3 = 6;
int in4 = 7;
//Motor Speeds
int MotorSpeedA = 0;
int MotorSpeedB = 0;


int xPosition = 0;
int yPosition = 0;

int mapX = 0;
int mapY = 0;

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


void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);

  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, 512, -512);
//backwards motion
if (yPosition <= -250){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); }
//forward motion
if (yPosition <= 250){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW); }
else if (yPosition<250 && yPosition>-150){
   digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
 
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW); }

  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.println(mapY);


  delay(100);
  
}
