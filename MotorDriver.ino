
//left Motor
int RPWML = 3;
int LPWML = 5; 

//right Motor
int RPWMR = 6;
int LPWMR = 9;

int REN = 2;

void setup() {
  
    //left
  pinMode(RPWML, OUTPUT);
  pinMode(LPWML, OUTPUT);
    
  pinMode(REN, OUTPUT);

  //Right
  pinMode(RPWMR, OUTPUT);
  pinMode(LPWML, OUTPUT);

  digitalWrite(REN, HIGH);
}

void loop() {   
  //left
  // Move Forward at 50% speed
  analogWrite(RPWML, 0);
  analogWrite(LPWML, 255);

  //right
  // Move Forward at 50% speed
  analogWrite(RPWMR, 255);
  analogWrite(LPWMR, 0);
  
  delay(1000);
}
