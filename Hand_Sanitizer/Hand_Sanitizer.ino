const int stepPin = 4; 
const int dirPin = 3; 
int but_1 = 8;
int but_2 = 9;
int state_1;
int state_2;
int trig = 5;
int echo = 6;

void setup() {
  
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(but_1,INPUT);
  pinMode(but_2,INPUT);
  pinMode(trig , OUTPUT);
  pinMode(echo,INPUT);
  
}
void loop() {

  state_1=digitalRead(but_1);
  state_2=digitalRead(but_2);
    
  if (state_1==1){
    digitalWrite(dirPin,HIGH);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
    }
  else if (state_2==1){
    digitalWrite(dirPin,LOW);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
    }
    
  else{
  
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
  
    int Time = pulseIn(echo,HIGH);
    int distance = Time*0.034/2;
  
    if(distance<=10){
      
      for(int x=0;x<=400;x++){
        digitalWrite(dirPin,HIGH);
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500);
       }
       
      //delayMicroseconds(500);
      //digitalWrite(stepPin,LOW); 
      //delayMicroseconds(500);
        
      for(int x=0;x<=400;x++){
        digitalWrite(dirPin,LOW);
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500);
       }   
       delay(1000);
     
  }
  
    }

  }
  
