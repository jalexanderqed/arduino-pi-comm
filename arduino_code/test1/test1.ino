volatile int counter = 0;
const int encPin1 = 2;
const int encPin2 = 3;
const int lMotor1 = 9;
const int lMotor2 = 8;
const int lMotorC = 6;

void setup()
{
  pinMode(encPin1, INPUT_PULLUP);
  pinMode(encPin2, INPUT);
  pinMode(lMotor1, OUTPUT);
  pinMode(lMotor2, OUTPUT);
  pinMode(lMotorC, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encPin1), count, RISING);
}

void loop()
{
  Serial.print("Count: ");
  Serial.println(counter);
  if((millis() / 5000) % 2 == 0){
    digitalWrite(lMotor1, HIGH);
    digitalWrite(lMotor2, LOW);
  }
  else{
    digitalWrite(lMotor1, LOW);
    digitalWrite(lMotor2, HIGH);
  }
  analogWrite(lMotorC, 200);
  
  delay(50);
}

void count(){
  if(digitalRead(encPin2)){
    counter++;
  }
  else{
    counter--;
  }
}	
