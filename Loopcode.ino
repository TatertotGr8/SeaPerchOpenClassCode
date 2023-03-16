const int ENA_PIN = 23;
const int IN1_PIN = 22;
const int IN2_PIN = 24;

const int ENB_PIN = 25;
const int IN3_PIN = 26;
const int IN4_PIN = 28;

const int ENA_B_PIN = 27;
const int IN1_B_PIN = 30;
const int IN2_B_PIN = 32;

const int ENB_B_PIN = 29;
const int IN3_B_PIN = 34;
const int IN4_B_PIN = 36;

const int ENA_C_PIN = 31;
const int IN1_C_PIN = 38;
const int IN2_C_PIN = 40;

const int ENB_C_PIN = 33;
const int IN3_C_PIN = 42;
const int IN4_C_PIN = 44;

const int ENA_D_PIN = 35;
const int IN1_D_PIN = 46;
const int IN2_D_PIN = 48;

const int ENB_D_PIN = 37;
const int IN3_D_PIN = 50;
const int IN4_D_PIN = 52;




void setup() {
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  pinMode(ENB_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);

  pinMode(ENA_B_PIN, OUTPUT);
  pinMode(IN1_B_PIN, OUTPUT);
  pinMode(IN2_B_PIN, OUTPUT);

  pinMode(ENB_B_PIN, OUTPUT);
  pinMode(IN3_B_PIN, OUTPUT);
  pinMode(IN4_B_PIN, OUTPUT);

  pinMode(ENA_C_PIN, OUTPUT);
  pinMode(IN1_C_PIN, OUTPUT);
  pinMode(IN2_C_PIN, OUTPUT);

  pinMode(ENB_C_PIN, OUTPUT);
  pinMode(IN3_C_PIN, OUTPUT);
  pinMode(IN4_C_PIN, OUTPUT);

  pinMode(ENA_D_PIN, OUTPUT);
  pinMode(IN1_C_PIN, OUTPUT);
  pinMode(IN2_C_PIN, OUTPUT);

  pinMode(ENB_D_PIN, OUTPUT);
  pinMode(IN3_D_PIN, OUTPUT);
  pinMode(IN4_D_PIN, OUTPUT);
}

void loop() {
  //Back Right Y
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);

  //Front Right Y
  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);

  //Front Left Y 
  digitalWrite(IN1_B_PIN, HIGH);
  digitalWrite(IN2_B_PIN, LOW);

  //Back Left Y
  digitalWrite(IN3_B_PIN, HIGH);
  digitalWrite(IN4_B_PIN, LOW);


 
  //unkkown 
  digitalWrite(IN1_C_PIN, HIGH);
  digitalWrite(IN2_C_PIN, LOW);


  //right foward 
  digitalWrite(IN3_C_PIN, HIGH);
  digitalWrite(IN4_C_PIN, LOW);

    
  //unknown 
  digitalWrite(IN1_D_PIN, HIGH);
  digitalWrite(IN2_D_PIN, LOW);


    //Left Foward  
    digitalWrite(IN3_D_PIN, HIGH);
    digitalWrite(IN4_D_PIN, LOW); 
      




  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(ENA_PIN, 255);

    analogWrite(ENA_PIN, 255);
    analogWrite(ENB_PIN, 255);

    analogWrite(ENA_B_PIN, 255);
    analogWrite(ENB_B_PIN, 255);

    analogWrite(ENA_C_PIN, 255);
    analogWrite(ENB_C_PIN, 255);

    analogWrite(ENA_D_PIN, 255);
    analogWrite(ENB_D_PIN, 255);
  }
}
