
int baselineTemp = 0;
int celsius = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3,OUTPUT);
  
}

void loop()
{
  baselineTemp = 40;
  celsius = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print(celsius);
  Serial.print(" \n");
  int analog = analogRead(A0);
  Serial.println(analog);
  delay(1000);
  if(analog > 300 && celsius > 20){
  Serial.println("buzzer on");
  Serial.println("LED ON");
  digitalWrite(3,HIGH);
  tone(4, 220, 100);
  delay(1000);
  }
  else{
   Serial.println("buzzer off");
   Serial.println("LED OFF");
   digitalWrite(3,LOW);
  }
}