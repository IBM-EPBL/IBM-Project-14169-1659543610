
void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
}

void loop()
{
  int analog = analogRead(A0);
  Serial.println(analog);
  delay(1000);
  long duration, distance;
  digitalWrite(13, LOW);        
  delayMicroseconds(2);              
  digitalWrite(13, HIGH);
  delayMicroseconds(10);           
  digitalWrite(13, LOW);
  duration = pulseIn(12, HIGH);
  distance = (duration/2) / 29.1;
  if(analog > 300 && distance > 200 ){
  Serial.println("out of range");
  Serial.println("LED OFF");
  digitalWrite(3,LOW);
  }
  else{
   Serial.println("buzzer ON");
   Serial.println("LED ON");
   tone(4, 220, 100);
   delay(1000);
   digitalWrite(3,HIGH);
  }
}