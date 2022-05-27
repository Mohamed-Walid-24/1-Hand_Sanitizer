int trig = 8;
int echo = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig , OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600); //Bits per second
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  int Time = pulseIn(echo,HIGH); // Time in microseconds
  int distance = Time*0.034/2; // Speed of light = 0.034 cm/microseconds
  
  Serial.println(distance); //Distance in cm
}
