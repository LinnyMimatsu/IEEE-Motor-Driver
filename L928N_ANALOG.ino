int enA = 2;
int in1 = 3;
int in2 = 4;

#define VRX_PIN A1
#define VRY_PIN A0

int xValue = 0;
int yValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

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

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(100);

  } else if(mappedX < 120){

  //analogWrite(enA, mappedX);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(100);
  }else {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}

} 
