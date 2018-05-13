#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield featherWing1 = Adafruit_MotorShield(0x62);
Adafruit_MotorShield featherWing2 = Adafruit_MotorShield(0x64);
Adafruit_MotorShield featherWing3 = Adafruit_MotorShield(0x68);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *lazySusan = featherWing1.getMotor(1);
Adafruit_DCMotor *motor1 = featherWing2.getMotor(1);
Adafruit_DCMotor *motor2 = featherWing2.getMotor(2);
Adafruit_DCMotor *motor3 = featherWing2.getMotor(3);
Adafruit_DCMotor *motor4 = featherWing2.getMotor(4);
Adafruit_DCMotor *motor5 = featherWing3.getMotor(1);
Adafruit_DCMotor *motor6 = featherWing3.getMotor(2);

const byte ButtonGreen = 1;
const byte ButtonYellow = 2;
const byte ButtonRed = 3;
const byte num_input = 3;

int btnPin[] = { 0, 5, 6, 9 };// need 3 input pins if 3 questions are asked
uint8_t ledPin = 13;
int buttonState[] = { 0, 0, 0, 0 };
int lastButtonState[] = { 0, 0, 0, 0 };
int btn = 0;
int i = 0;
int counter = 0;
int sequence[] = {0, 0, 0};
int seq_int;

void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  delay(1000);
  Serial.println("Starting");
  pinMode(ledPin, OUTPUT);
  for (btn = 8; btn <= 10;  btn++) {
    pinMode(btn, INPUT);
  }

  featherWing1.begin();  // create with the default frequency 1.6KHz
  featherWing2.begin();
  featherWing3.begin();
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  lazySusan->setSpeed(140);
  motor1->setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);
  motor5->setSpeed(255);
  motor6->setSpeed(255);
}

// the loop function runs over and over again forever
void loop() {

  //  Serial.println("Reading 8 ");
  //  Serial.println(digitalRead(8));
  //  delay(1000);
  //  Serial.println("Reading 9 ");
  //  Serial.println(digitalRead(9));
  //  delay(1000);
  //  Serial.println("Reading 10 ");
  //  Serial.println(digitalRead(10));
  //  Serial.println("waiting for input");
  delay(100);
  if (wasBtnPushed(ButtonGreen) > 0) {
    Serial.println("ButtonGreen is pressed ");
    sequence[counter] = ButtonGreen;
    counter = counter + 1;
  }
  delay(100);
  if (wasBtnPushed(ButtonYellow) > 0) {
    Serial.println("ButtonYellow is pressed ");
    sequence[counter] = ButtonYellow;
    counter = counter + 1;
  }
  delay(100);
  if (wasBtnPushed(ButtonRed) > 0) {
    Serial.println("ButtonRed is pressed ");
    sequence[counter] = ButtonRed;
    counter = counter + 1;
  }
  delay(10);
  if (counter == num_input)
  {
    Serial.println("3 buttons are pressed and sequence is ");
    for (i = 0; i < 3; i++) {
      Serial.println(sequence[i]);
    }

    // convert the sequence into an unique number for easy usage (see picture of sticky note in repository for button-integer relation)
    seq_int = (sequence[2] - 1) * 9 + (sequence[1] - 1) * 3 + sequence[0] - 1;
    Serial.println("equivalent seq int is:");
    Serial.println(seq_int);

    if (seq_int == 13) { //
      lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(50000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(1250);
      lazySusan->run(RELEASE); 
      motor5->run(BACKWARD);
      delay(50000);
      motor5->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(1250); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(75000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 

      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(3000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
    }
    if (seq_int == 17) {
      lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(25000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(1250);
      lazySusan->run(RELEASE); 
      motor5->run(BACKWARD);
      delay(25000);
      motor5->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(1250); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(50000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 

      lazySusan->run(FORWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
      motor4->run(BACKWARD);
      delay(5000);
      motor4->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
    }
    if (seq_int == 23) {
      lazySusan->run(FORWARD); 
      delay(1200);
      lazySusan->run(RELEASE); 
      motor5->run(BACKWARD);
      delay(50000);
      motor5->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(1200); //full revolution

      lazySusan->run(FORWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE); 
      motor3->run(FORWARD);
      delay(3000);
      motor3->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(2600); //full revolution


      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(3000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
    }
    if (seq_int == 22) {
      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(100000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 

      lazySusan->run(FORWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE); 
      motor3->run(FORWARD);
      delay(5000);
      motor3->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE);
    }
    if (seq_int == 26) {
      lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(50000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
      motor4->run(BACKWARD);
      delay(5000);
      motor4->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(3600);
      lazySusan->run(RELEASE);  

      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(4000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE);
    }
    if (seq_int == 16) {
      lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(50000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
      motor4->run(BACKWARD);
      delay(5000);
      motor4->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(3600);
      lazySusan->run(RELEASE);  

      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(4000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 

      lazySusan->run(FORWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE); 
      motor3->run(FORWARD);
      delay(5000);
      motor3->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE);

      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(75000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE);
    }
    if (seq_int == 9) {
      lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(50000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution

      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(100000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE);
    }
    if (seq_int == 0) {
      lazySusan->run(FORWARD); 
      delay(1250);
      lazySusan->run(RELEASE); 
      motor5->run(BACKWARD);
      delay(100000);
      motor5->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(1250); //full revolution

      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(4000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE);
    }
    if (seq_int == 12) {
      lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(100000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(4000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE);
    }
    if (seq_int == 1) {
      lazySusan->run(FORWARD); 
      delay(1250);
      lazySusan->run(RELEASE); 
      motor5->run(BACKWARD);
      delay(50000);
      motor5->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(1250); //full revolution

      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(100000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE);
    }
    if (seq_int == 5) {
       lazySusan->run(FORWARD); 
      delay(550); //full revolution
      lazySusan->run(RELEASE); 
      motor6->run(BACKWARD);
      delay(15000);
      motor6->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(550); //full revolution
      
      lazySusan->run(FORWARD); 
      delay(1250);
      lazySusan->run(RELEASE); 
      motor5->run(BACKWARD);
      delay(15000);
      motor5->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(1250); //full revolution

      lazySusan->run(FORWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE); 
      motor3->run(FORWARD);
      delay(15000);
      motor3->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE);

      lazySusan->run(FORWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
      motor4->run(BACKWARD);
      delay(25000);
      motor4->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
      
      lazySusan->run(FORWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 
      motor2->run(BACKWARD);
      delay(15000);
      motor2->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(4500);
      lazySusan->run(RELEASE); 

      lazySusan->run(FORWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
      motor1->run(BACKWARD);
      delay(15000);
      motor1->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(5350);
      lazySusan->run(RELEASE); 
    }
    if (seq_int == 8) {
      lazySusan->run(FORWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 
      motor4->run(FORWARD);
      delay(40000);
      motor4->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(3600);
      lazySusan->run(RELEASE); 

      lazySusan->run(FORWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE); 
      motor3->run(FORWARD);
      delay(40000);
      motor3->run(RELEASE);
      lazySusan->run(BACKWARD); 
      delay(2600); //full revolution
      lazySusan->run(RELEASE);
    }
    
    //flash the led while code is running
    
    for (i = 0; i < 2; i++) {
      digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      delay(100);              // wait for a second
    }
    Serial.println("task is done or wait for new input ");

    counter = 0;
  }
}
int wasBtnPushed(int x) {
  buttonState[x] = digitalRead(btnPin[x]);
  if (buttonState[x] != lastButtonState[x]) {
    lastButtonState[x] = buttonState[x];
    if (buttonState[x] == LOW) {
      delay(100);
      return x;
    }
  }
  return 0;
}
