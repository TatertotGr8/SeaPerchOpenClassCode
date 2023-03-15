#include <XBOXUSB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
USB Usb;
XBOXUSB Xbox(&Usb);
const int ENA_PIN = 23;
const int ENB_PIN = 25;

const int ENA_Balls_PIN = 27;
const int ENB_Balls_PIN = 29;

const int ENA_Cock_PIN = 31;
const int ENB_Cock_PIN = 33;

const int ENA_Dick_PIN = 35;
const int ENB_Dick_PIN = 37;

const int IN1_PIN = 22;
const int IN2_PIN = 24;
const int IN3_PIN = 26;
const int IN4_PIN = 28;

const int IN1_Balls_PIN = 30;
const int IN2_Balls_PIN = 32;
const int IN3_Balls_PIN = 34;
const int IN4_Balls_PIN = 36;

const int IN1_Cock_PIN = 38;
const int IN2_Cock_PIN = 40;
const int IN3_Cock_PIN = 42;
const int IN4_Cock_PIN = 44;

const int IN1_Dick_PIN = 46;
const int IN2_Dick_PIN = 48;
const int IN3_Dick_PIN = 50;
const int IN4_Dick_PIN = 52;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt ;

  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
    
  pinMode(ENB_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT); 
    
  pinMode(ENA_Balls_PIN, OUTPUT);  
  pinMode(IN1_Balls_PIN,OUTPUT);
  pinMode(IN2_Balls_PIN,OUTPUT);
    
  pinMode(ENB_Balls_PIN, OUTPUT); 
  pinMode(IN3_Balls_PIN,OUTPUT);
  pinMode(IN4_Balls_PIN,OUTPUT);
    
  pinMode(ENA_Balls_PIN, OUTPUT); 
  pinMode(IN1_Cock_PIN,OUTPUT);
  pinMode(IN2_Cock_PIN,OUTPUT);
    
  pinMode(ENB_Cock_PIN, OUTPUT); 
  pinMode(IN3_Cock_PIN,OUTPUT);
  pinMode(IN4_Cock_PIN,OUTPUT);
    
  pinMode(ENA_Dick_PIN, OUTPUT); 
  pinMode(IN1_Cock_PIN,OUTPUT);
  pinMode(IN2_Cock_PIN,OUTPUT);
    
  pinMode(ENB_Dick_PIN, OUTPUT); 
  pinMode(IN3_Cock_PIN,OUTPUT);
  pinMode(IN4_Cock_PIN,OUTPUT);

  }
  Serial.print(F("\r\nXBOX USB Library Started"));
}

void loop() {
  Usb.Task();
  if (Xbox.Xbox360Connected) {
    /*if (Xbox.getButtonPress(LT) || Xbox.getButtonPress(RT)) {
      Serial.print("LT: "); 
    analogWrite(ENA_Cock_PIN, 255);*/

    //Back Y Motors Up 
    Serial.print(Xbox.getButtonPress(LT));
    analogWrite(ENB_Cock_PIN, 255);  
    pinMode(IN3_Cock_PIN,HIGH);
    pinMode(IN4_Cock_PIN,LOW);
    
    analogWrite(ENA_Dick_PIN, 255);
    pinMode(IN1_Cock_PIN,HIGH);
    pinMode(IN2_Cock_PIN,LOW);
  
    //Back Y Motors Down 
    Serial.println(Xbox.getButtonPress(RT)); 
    analogWrite(ENB_Cock_PIN, 255); 
    pinMode(IN3_Cock_PIN,LOW);
    pinMode(IN4_Cock_PIN,HIGH); 
    
    analogWrite(ENA_Dick_PIN, 255);
    pinMode(IN1_Cock_PIN,LOW);
    pinMode(IN2_Cock_PIN,HIGH);
  
      if (Xbox.getAnalogHat(LeftHatY) > 7500 || Xbox.getAnalogHat(LeftHatY) < -7500) {
        Serial.print(F("LeftHatY: "));
        Serial.print(Xbox.getAnalogHat(LeftHatY));
      analogWrite(ENB_Balls_PIN, 255);
      }
   
      if (Xbox.getAnalogHat(RightHatY) > 7500 || Xbox.getAnalogHat(RightHatY) < -7500) {
      analogWrite(ENA_PIN, 255);
      Serial.print(Xbox.getAnalogHat(RightHatY));
      }
    }

    //All Motor Up: Up D pad 
    if (Xbox.getButtonClick(UP)) {
      Xbox.setLedOn(LED1);
      analogWrite(ENB_Cock_PIN, 255);
      digitalWrite(IN3_Cock_PIN, LOW);
      digitalWrite(IN4_Cock_PIN, HIGH);

      analogWrite(ENB_Dick_PIN, 255); 
      analogWrite(ENA_Cock_PIN, 255);
      analogWrite(ENB_Dick_PIN, 255);

    } 
    //All Motor DOWN: Down D pad 
    if (Xbox.getButtonClick(DOWN)) {
      Xbox.setLedOn(LED4);
      analogWrite(ENB_Cock_PIN, 255);
      analogWrite(ENB_Dick_PIN, 255); 
      analogWrite(ENA_Cock_PIN, 255);
      analogWrite(ENB_Dick_PIN, 255);
    }

    //Front Y Up 
    if (Xbox.getButtonClick(LB)) 
    analogWrite(ENB_Dick_PIN, 255); 
    analogWrite(ENA_Cock_PIN, 255); 
    
    //Front Y Down 
    if (Xbox.getButtonClick(RB))
    analogWrite(ENB_Dick_PIN, 255); 
    analogWrite(ENA_Cock_PIN, 255); 

    //Arm
    if (Xbox.getButtonClick(A)){
      analogWrite(ENB_PIN, 255);
      digitalWrite(IN3_PIN, LOW);
      digitalWrite(IN4_PIN, HIGH); 
    }
    else if (Xbox.getButtonClick(B)) {
      analogWrite(ENB_PIN, 255);
      digitalWrite(IN3_PIN, LOW);
      digitalWrite(IN4_PIN, HIGH);
    }
    else{
      digitalWrite(IN3_PIN, LOW);
      digitalWrite(IN4_PIN, LOW);
    }
  delay(1);
  } 
} 
