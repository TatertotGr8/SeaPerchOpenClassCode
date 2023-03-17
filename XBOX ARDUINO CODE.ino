#include <XBOXUSB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h> 

USB Usb;
XBOXUSB Xbox(&Usb);
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


void setup(){

  Serial.begin(115200);
  #if !defined(__MIPSEL__)
  while (!Serial); 
  #endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXBOX USB Library Started"));

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
  pinMode(IN1_D_PIN, OUTPUT);
  pinMode(IN2_D_PIN, OUTPUT);

  pinMode(ENB_D_PIN, OUTPUT);
  pinMode(IN3_D_PIN, OUTPUT);
  pinMode(IN4_D_PIN, OUTPUT); 
}
void loop() {
  Usb.Task(); 
  
  
    //all on 
    if (Xbox.getButtonClick(START)) {
      digitalWrite(IN1_PIN, HIGH);
      digitalWrite(IN2_PIN, LOW);
      digitalWrite(IN3_PIN, HIGH);
      digitalWrite(IN4_PIN, LOW);
      digitalWrite(IN1_B_PIN, HIGH);
      digitalWrite(IN2_B_PIN, LOW);
      digitalWrite(IN3_B_PIN, HIGH);
      digitalWrite(IN4_B_PIN, LOW);
      digitalWrite(IN1_C_PIN, LOW);
      digitalWrite(IN2_C_PIN, HIGH);
      digitalWrite(IN3_C_PIN, HIGH);
      digitalWrite(IN4_C_PIN, LOW);
      digitalWrite(IN1_D_PIN, HIGH);
      digitalWrite(IN2_D_PIN, LOW); 
      delay(1); 
      analogWrite(ENA_PIN, 255);
      analogWrite(ENB_PIN, 255);
      analogWrite(ENA_B_PIN, 255);
      analogWrite(ENB_B_PIN,255);
      analogWrite(ENA_C_PIN,255);
      analogWrite(ENB_C_PIN, 255);
      analogWrite(ENA_D_PIN, 255);
      analogWrite(ENB_D_PIN, 255);  
      delay(1);
  }    
  delay(1);
 
  //all off
  if (Xbox.getButtonClick(BACK)) {
    Xbox.setLedBlink(ALL);
    Serial.println(F("Back")); 
    Serial.println(F("BACK")); 
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(IN3_PIN, LOW);
    digitalWrite(IN4_PIN, LOW);
    digitalWrite(IN1_B_PIN, LOW);
    digitalWrite(IN2_B_PIN, LOW);
    digitalWrite(IN3_B_PIN, LOW);
    digitalWrite(IN4_B_PIN, LOW);
    digitalWrite(IN1_C_PIN, LOW);
    digitalWrite(IN2_C_PIN, LOW);
    digitalWrite(IN3_C_PIN, LOW);
    digitalWrite(IN4_C_PIN, LOW);
    digitalWrite(IN1_D_PIN, LOW);
    digitalWrite(IN2_D_PIN, LOW);
    digitalWrite(IN3_D_PIN, LOW);
    digitalWrite(IN4_D_PIN, LOW);
    delay(1); 
    analogWrite(ENA_PIN, 0);
    analogWrite(ENB_PIN, 0);
    analogWrite(ENA_B_PIN, 0);
    analogWrite(ENB_B_PIN,0);
    analogWrite(ENA_C_PIN,0);
    analogWrite(ENB_C_PIN, 0);
    analogWrite(ENA_D_PIN, 0);
    analogWrite(ENB_D_PIN, 0);  
    delay(1);
    } 

  //Back Y Down 
  if (Xbox.getButtonPress(LT)) {
    //left back Y Down
    digitalWrite(IN3_B_PIN, HIGH);
    digitalWrite(IN4_B_PIN, LOW); 
    analogWrite(ENB_B_PIN, 255);
    //Right back Y Down
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
    analogWrite(ENA_PIN, 255);    
    delay(3);
  }  
  delay(1);
  
  //front Y Down
  if (Xbox.getButtonPress(RT)) {
  Serial.print("\tRT: ");
  Serial.println(Xbox.getButtonPress(RT));
  //Front Right Y
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH); 
  analogWrite(ENB_PIN, 255); 
  //Front Left Y 
  digitalWrite(IN1_B_PIN, HIGH);
  digitalWrite(IN2_B_PIN, LOW);  
  analogWrite(ENA_B_PIN, 255);
  delay(3);
  } 
  delay(1);
  
 //All Y up
 if (Xbox.getButtonClick(B)) {
  Xbox.setLedOn(LED1);
  Xbox.setLedOn(LED2);
  Xbox.setLedOn(LED3);
  Xbox.setLedOn(LED4);
  Serial.println(F("Up"));
  //Back Right Y
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  //Front Right Y
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH);
  //Front Left Y 
  digitalWrite(IN1_B_PIN, LOW);
  digitalWrite(IN2_B_PIN, HIGH);
  //Back Left Y
  digitalWrite(IN3_B_PIN, LOW);
  digitalWrite(IN4_B_PIN, HIGH);
  analogWrite(ENA_PIN, 255);  
  analogWrite(ENB_PIN, 255); 
  analogWrite(ENA_B_PIN, 255); 
  analogWrite(ENB_B_PIN, 255);  
  delay(3);
  } 
  delay(1);
    
  //All Y down
  if (Xbox.getButtonClick(A)) { 
  Xbox.setLedMode(ROTATING);
  Serial.println(F("Down")); 
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
  analogWrite(ENA_PIN, 255);  
  analogWrite(ENB_PIN, 255); 
  analogWrite(ENA_B_PIN, 255); 
  analogWrite(ENB_B_PIN, 255);  
  delay(3);
  }
    delay(1);
    
    //Back Y up
  if (Xbox.getButtonPress(LB)){ 
    Serial.println(F("LB"));   
    //left back Y 
    digitalWrite(IN3_B_PIN, LOW);
    digitalWrite(IN4_B_PIN, HIGH); 
    analogWrite(ENB_B_PIN, 255);
    //Right back Y 
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
    analogWrite(ENA_PIN, 255);  
    delay(3);
  } 
  delay(1);

  //front Y up  
  if (Xbox.getButtonPress(RB)){ 
    Serial.println(F("RB"));   
    //Front Right Y
    digitalWrite(IN3_PIN, HIGH);
    digitalWrite(IN4_PIN, LOW);   
    analogWrite(ENA_B_PIN, 255);
    //Front Left Y 
    digitalWrite(IN1_B_PIN, LOW);
    digitalWrite(IN2_B_PIN, HIGH);
    analogWrite(ENB_PIN,255); 
    delay(3);
  }   
    delay(1);
     
    //arm down 
  if (Xbox.getButtonPress(X)){ 
      Serial.println(F("X")); 
      //unknownn: arm?
      digitalWrite(IN3_D_PIN, HIGH);
      digitalWrite(IN4_D_PIN, LOW);
      analogWrite(ENA_D_PIN,255); 
      delay(1000);  
      digitalWrite(IN3_D_PIN, LOW);
      digitalWrite(IN4_D_PIN, LOW);
      analogWrite(ENA_D_PIN,0); 
     delay(3); 
    }
     
  //arm Down: uncontrolled 
  if (Xbox.getButtonPress(B)){  
    Serial.println(F("B")); 
    //unknown: arm? 
    digitalWrite(IN3_D_PIN, LOW);
    digitalWrite(IN4_C_PIN, HIGH);
    analogWrite(ENA_D_PIN,255);  
    delay(3);
    }     
    
    
  //arm Up 
  if (Xbox.getButtonPress(Y)){  
    Serial.println(F("Y")); 
    //unknown: arm? 
    digitalWrite(IN3_D_PIN, LOW);
    digitalWrite(IN4_D_PIN, HIGH);
    analogWrite(ENA_D_PIN,255); 
    delay(1000);  
    digitalWrite(IN3_D_PIN, LOW);
    digitalWrite(IN4_D_PIN, LOW);
    analogWrite(ENA_D_PIN,0); 
    delay(3);
    }

//arm up: uncontrolled 
  if (Xbox.getButtonPress(A)){  
    Serial.println(F("A")); 
    //unknown: arm? 
    digitalWrite(IN3_D_PIN, HIGH);
    digitalWrite(IN4_D_PIN, LOW);
    analogWrite(ENA_D_PIN,255);  
    delay(3);
    }    
    delay(1); 
      
      
    //32768 max
    if (Xbox.getAnalogHat(LeftHatY) > 7500) {
    digitalWrite(IN1_D_PIN, LOW);
    digitalWrite(IN2_D_PIN, HIGH); 
    analogWrite(ENA_D_PIN, 255);
    Serial.print(F("LeftHatY positive: "));
    Serial.print(Xbox.getAnalogHat(LeftHatY));
    Serial.print("\t");

    delay(1);
    }

    if (Xbox.getAnalogHat(LeftHatY) < -7500) {
    digitalWrite(IN1_D_PIN, HIGH);
    digitalWrite(IN2_D_PIN, LOW); 
    analogWrite(ENA_D_PIN, 255);
    Serial.print(F("LeftHatY negative: "));
    Serial.print(Xbox.getAnalogHat(LeftHatY));
    Serial.print("\t"); 

    delay(1);
    }

    delay(1); 
  if (Xbox.getAnalogHat(RightHatY) > 7500) {
    Serial.print(F("RightHatY positive: "));
    Serial.print(Xbox.getAnalogHat(RightHatY));
    digitalWrite(IN3_C_PIN, HIGH);
    digitalWrite(IN4_C_PIN, LOW);
    analogWrite(ENB_C_PIN, 255);
    
    delay(1);
    }

  if (Xbox.getAnalogHat(RightHatY) < -7500) {
    Serial.print(F("RightHatY positive: "));
    Serial.print(Xbox.getAnalogHat(RightHatY));
    digitalWrite(IN3_C_PIN, LOW);
    digitalWrite(IN4_C_PIN, HIGH);
    analogWrite(ENB_C_PIN, 255);
                 
    delay(1);
       
  }


  //front Y off
  if (Xbox.getButtonPress(UP)){ 
    Serial.println(F("UP"));   
    //Front Right Y
    analogWrite(ENA_B_PIN, 0); 
    //Front Left Y 
    analogWrite(ENB_PIN, 0);
    delay(3);
  }   
  

//back Y off
  if (Xbox.getButtonPress(DOWN)){ 
    Serial.println(F("DOWN")); 
    analogWrite(ENB_B_PIN, 0);
    analogWrite(ENA_PIN, 0); 
    delay(3);

  }   
  delay(1);
}
