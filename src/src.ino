#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
#define trigPin 9
#define echoPin 10
int led1 = 0;
int led2 = 1;
int led3 = 2;

void setup(){
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motor1.setSpeed(80);

  motor1.run(RELEASE);

  motor2.setSpeed(255);

  motor2.run(RELEASE);
}

void loop()
{
  brakeLights();
  motor1.run(FORWARD);
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  


  if (distance <=30 )
  {
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor1.run(BACKWARD);
    delay (1000);
    motor2.run(RELEASE);
    motor1.run(RELEASE);
    delay (2000);
    if(distance <=10 )
    {
      motor1.run(RELEASE);
      motor1.run(BACKWARD);
      delay (500);
      motor2.run(RELEASE);
      motor1.run(RELEASE);

    }

    motor2.run(BACKWARD);
    motor1.run(FORWARD);
    delay (1000);
    motor2.run(RELEASE);

  }
}

void brakeLights()
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
          
