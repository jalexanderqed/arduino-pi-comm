const int ledPin = 13;
volatile int counter = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(3), count, RISING);
}

void loop()
{
  Serial.print("Count: ");
  Serial.println(counter);
/*  if (Serial.available())
  {
     flash(Serial.read() - '0');
  }*/
  delay(1000);
}

void flash(int n)
{
  for (int i = 0; i < n; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}

void count(){
  counter++;
}