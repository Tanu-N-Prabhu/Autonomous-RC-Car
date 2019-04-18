#include <AFMotor.h>

AF_DCMotor motor1(1);// create motor #1, 64KHz pw
AF_DCMotor motor2(2);// create motor #2, 8KHz pw

int vcc = 3;      //attach pin 2 to vcc
int trig = 4;     //attach pin 3 to Trig
int echo = 5;     //attach pin 4 to Echo
int gnd = 6;      //attach pin 5 to GND
int led1 = 0;     //led1 red to arduino pin 0
int led2 = 1;     //led2 red to arduino pin 1
int led3 = 2;     //led3 red to arduino pin 2

void setup()
{
  // Set led1, led2 and led3 - pin 0, 1, 2 as an output
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT);
  
  // Set the Vcc and GNC - pin 3,4 as output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // set the speed to 200/255
  motor1.setSpeed(80);

  // stopped
  motor1.run(RELEASE);

  // set the speed to 200/255
  motor2.setSpeed(255);

  // stopped
  motor2.run(RELEASE);

  //initialize serial communication:
  Serial.begin (9600);

}

void loop()
{
  // Set Motor1 to move forward
  motor1.run(FORWARD);
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(2000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29;
  
  if (distance < = 50 )
  {
    motor1.run(RELEASE);
    motor2.setSpeed(255);
    //Turn left
    motor2.run(FORWARD);
    // This is for the steering to align to the center.
    motor2.setSpeed(90);
    motor2.run(BACKWARD);
    // Tell the car to go back
    motor1.run(BACKWARD);
    delay (1000);
    motor2.run(RELEASE);
    motor1.run(RELEASE);
    delay (2000);
    if(distance < = 20 )
    {
      motor1.run(RELEASE);
      motor1.run(BACKWARD);
      brakeLights();
      delay (500);
      motor2.run(RELEASE);
      motor1.run(RELEASE);

    }
    motor2.setSpeed(255);
    // Turn right
    motor2.run(BACKWARD);
    // This is for the steering to align to the center.
    motor2.setSpeed(90);
    motor2.run(FORWARD);
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
          
