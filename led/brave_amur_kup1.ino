// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  Serial.println("LED ON");
  digitalWrite(2, HIGH);
  delay(1000); 
  Serial.println("LED OFF");
  digitalWrite(2, LOW);
  delay(1000); 
}