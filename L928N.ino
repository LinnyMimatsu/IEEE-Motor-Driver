
//left motor
int enA = 2;
int in1 = 3;
int in2 = 4;

//right motor
int enB = 5;
int in3 = 6;
int in4 = 7;

#define VRX_PIN A1
#define VRY_PIN A0

int xValue = 0;
int yValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //left motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  //right motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  int mappedX = map(xValue, 0, 1023, 0, 255);
  int mappedY = map(yValue, 0, 1023, 0, 255);

  Serial.print("x = ");
  Serial.print(mappedX);
  Serial.print(", y = ");
  Serial.println(mappedY);


  

  if(mappedX > 130) {

  analogWrite(enA, mappedX);
  analogWrite(enB, mappedX);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);

  } else if(mappedX < 120){

  //analogWrite(enA, mappedX);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);

  }else if(mappedY > 130){

  analogWrite(enA, mappedY);
  analogWrite(enB, mappedY);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  } else if(mappedY < 120){

  //analogWrite(enA, mappedY);
  //analogWrite(enB, mappedY);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  }else {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

} 