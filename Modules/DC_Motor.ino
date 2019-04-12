#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup()
{
    
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor1.run(RELEASE);
    motor2.run(RELEASE);

}

void loop()
{
      straight();
      left();
      right();
      reverse();
      stopped();

}

void stopped() 
{
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      delay(500);
}

void left() 
{
     motor2.run(BACKWARD);
     delay(500);
}

void right() 
{
      motor2.run(FORWARD);
      delay(500);
}

void straight()
{
    
    motor1.run(FORWARD);
    delay(500);
    
}

void reverse()
{

  motor1.run(BACKWARD);
  delay(500);
  
}

Credits: https://learn.adafruit.com/adafruit-motor-shield/using-dc-motors