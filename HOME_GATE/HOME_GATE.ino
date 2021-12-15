#define EN1 5
#define EN2 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define buzzer 2
void setup()
{
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(EN1, OUTPUT); 
  pinMode(EN2, OUTPUT); 
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600); 
}
void openGate(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN1,75);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN2,70);
    
 delay(250);
    digitalWrite(IN1, LOW);
    digitalWrite(IN3, LOW);
}
void closeGate(){
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
    analogWrite(EN1,75);

    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    analogWrite(EN2,70);
    
 delay(250);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
}
void loop()
{
  tone(buzzer, 660);
  delay(700);
  tone(buzzer, 550);
  delay(700);
  tone(buzzer, 440);
  delay(700);
  noTone(buzzer);
  delay(2000); 
  openGate();
  delay(1000);
  closeGate();
  delay(2000);
}
