#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

//Motor A
int enA = 10;   //These are the pins for our motor driver IC
int in1 = 4;
int in2 = 5;
//Motor B
int enB = 11;
int in3 = 6;
int in4 = 7;
//Servo
Servo myservo;  
int pos = 0; 

void setup() 
{
  myservo.attach(9); 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
 
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);    // Set your Serial Monitor is set at 255000
  Dabble.begin(9600);      // This is the baude rate of the HM-10
}

void loop() {
Dabble.processInput();  // This line is crucial in grabbing our data  
  
  if (GamePad.isUpPressed())       
  {
    Serial.println("Forward");
    analogWrite(enA, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, 255);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

  else if (GamePad.isDownPressed())
  {
    Serial.println("Backward");
    analogWrite(enA, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enB, 255);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }

  else if (GamePad.isLeftPressed())
  {
    Serial.println("Left");
    analogWrite(enA, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enB, 255);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

  else if (GamePad.isRightPressed())
  {
    Serial.println("Right");
    analogWrite(enA, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enB, 255);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
 else if (GamePad.isTrianglePressed())
  {
    Serial.println("Servo");
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    for (pos = 270; pos >=0 ; pos -= 1) { 
    myservo.write(pos);                
    delay(5);                         
  }
  }
  else 
  {
    Serial.println("Stopped");
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
