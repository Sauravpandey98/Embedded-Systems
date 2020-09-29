int enable =11;//connect to ENA of motor driver
int input1=13;//connect to IN1
int input2=12;//connect to IN2

void setup() {
 pinMode(enable,OUTPUT);
 pinMode(input1,OUTPUT);
 pinMode(input2,OUTPUT);
 

}

void loop() {
  //to make motor rotate clockwise
  digitalWrite(enable,HIGH);
  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  delay(5000);

  // to make motor rotate anticlockwise
  digitalWrite(enable,HIGH);
  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH);
  delay(5000);

  //to rotate the motor with varying speed
  for(int i=0;i<255;i++){
    analogWrite(enable,i);
    delay(100);
  }
  
  
  

}
