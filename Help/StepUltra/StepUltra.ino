const int stepPin = 4; 
const int dirPin = 3; 

int trig = 5;
int echo = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  pinMode(trig , OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  int Time = pulseIn(echo,HIGH);
  int distance = Time*0.034/2;

  Serial.println(distance);
  
  if(distance<10){
    for(int x=0;x<=400;x++){
      digitalWrite(dirPin,HIGH);
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(500);
     }
     
//    delayMicroseconds(500);
//    digitalWrite(stepPin,LOW); 
//    delayMicroseconds(500);
      
    for(int x=0;x<=400;x++){
      digitalWrite(dirPin,LOW);
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(500);
     }   
     
  }
  else{
    digitalWrite(stepPin,LOW);
  }
  delay(1000);
}
