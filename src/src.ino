#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

const int trigPin =9;
const int echoPin =10;

long duration;
int distance;
int turnDelay = 2000; 

void setup()
{
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  motor1.setSpeed(150);
  motor2.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);

}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance:");
  Serial.println(distance);
  
  // This is the spot for the motors to show their magic.
  if(distance <= 30)
  {
    //Motor should stop.
    stoped();
    brakeLight();
  }
  else
  {
      // Motor should go front and take a left or right turn.
    
  }
  
void stoped() 
{
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      delay(500);
}
  
 void leftStoped()
{
  motor2.run(RELEASE);
  delay(200);
}
  
void left() 
{
     motor2.setSpeed(255);
     motor2.run(BACKWARD);
     delay(500);
}

void leftStraight()
{
   motor2.run(RELEASE);
   delay(500);
}
  
void right() 
{
      motor2.run(FORWARD);
      motor.setSpeed(255);  
      delay(60);
}

void straight()
{
    motor1.run(FORWARD);
    delay(50);
}
  
void back()
{
  motor1.run(BACKWARD);
  delay(300);
}
  
void brakeLight()
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);   
    digitalWrite(led3, HIGH);  
    delay(80); 

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(80);  
  }
  
}
