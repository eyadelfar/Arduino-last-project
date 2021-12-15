#include <Servo.h> // Servo

int brightness = 0; // LED

int pos = 0; // Servo
Servo servo_9; // Servo
int sensorValue = 0;
int led = 2;
int cm = 0; //US

int ldr = A0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
} //US

void setup()
{
  
  pinMode(led, OUTPUT); // LED
  pinMode(ldr,INPUT);
  servo_9.attach(9); // Servo
  
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(ldr);

  cm = (readUltrasonicDistance(11, 10)/2)/ 29.1  ;

 { 
  for (pos = 0; pos <= 100; pos += 1) {
    servo_9.write(pos); 
    if(sensorValue >700 && cm <100 )
     goto CONDITION;
    delay(10);

  }
  for (pos = 100; pos >= 0; pos -= 1) {
    servo_9.write(pos);
  if(sensorValue >700 && cm <100 )
     goto CONDITION;
    delay(10); 

  }
  
 }

  CONDITION:
  if( sensorValue >700 && cm <= 100 )  // Change the value as per your requirement
  {
       digitalWrite(led, HIGH);
       Serial.print("LDR Sensor Readings: ");
       Serial.println(sensorValue);
       Serial.println("Led ON");
       Serial.print("Distance: ");
       Serial.print(cm);
       Serial.print(" cm");
       Serial.println();
  }

  else
  {
       digitalWrite(led, LOW);
       Serial.print("LDR Sensor Readings: ");
       Serial.println(sensorValue);
       Serial.println("Led OFF");
       Serial.print("Distance: ");
       Serial.print(cm);
       Serial.print(" cm");
       Serial.println();
  }
}
