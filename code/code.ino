//LDRs
const int rightLdr = A0;
const int leftLdr = A1;
//LASERS
const int rightLaser = 2;
const int leftLaser = 3;
//RELAYS
const int clockwiseEngine = 13;
const int antiClockwiseEngine = 12;

int rightLdrValue = 0;
int leftLdrValue = 0;

void setup() {
  pinMode(clockwiseEngine, OUTPUT);
  pinMode(antiClockwiseEngine, OUTPUT);
  pinMode(rightLaser, OUTPUT);
  pinMode(leftLaser, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  turnOnLasers();
  rightLdrValue = analogRead(rightLdr);
  leftLdrValue = analogRead(leftLdr);
//  Serial.println(rightLdrValue);
//  Serial.println(leftLdrValue);
//  delay(300);
  if(hasObject(rightLdrValue, leftLdrValue)){
    startMotor();
  }else{
    stopMotor();
  }
}

boolean hasObject(int right, int left){
  return (right > 500 ||  left >500);
}

void turnOnLasers(){
  digitalWrite(rightLaser, HIGH);
  digitalWrite(leftLaser, HIGH);
}
void startMotor(){
  digitalWrite(clockwiseEngine, HIGH);
}
void stopMotor(){
  digitalWrite(clockwiseEngine, LOW);
}
void revertMotor(){
  digitalWrite(clockwiseEngine, LOW);
  delay(500);
  digitalWrite(antiClockwiseEngine, HIGH);
  delay(5000);
  digitalWrite(antiClockwiseEngine, LOW);
  delay(500);
  digitalWrite(clockwiseEngine, HIGH);
}

