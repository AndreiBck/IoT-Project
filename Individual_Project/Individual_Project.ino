#include <IRremote.h>


// trigger and echo pins for ultrasonic sensor
const int trigPin = 7;
const int echoPin = 8;

// pins for yellow, red and green pins
const int yellowLedPin = 9;
const int redLedPin = 10;
const int greenLedPin = 11;

// pins for the seven segments led
const int A_Pin = 2;
const int B_Pin = 3;
const int C_Pin = 4;
const int D_Pin = 5;
const int E_Pin = 6;
const int G_Pin = 12;
#define F_Pin A0

// pin for receiving side of the infrared sensor
const int receiverPin = 13;


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  pinMode(A_Pin, OUTPUT);
  pinMode(B_Pin, OUTPUT);
  pinMode(C_Pin, OUTPUT);
  pinMode(D_Pin, OUTPUT);
  pinMode(E_Pin, OUTPUT);
  pinMode(F_Pin, OUTPUT);
  pinMode(G_Pin, OUTPUT);

  IrReceiver.begin(receiverPin);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in centimeters:
  long duration, cm;
  

  // calculate the time from the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // receive the date from the infrared sensor
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int cmd = IrReceiver.decodedIRData.command;
    // switch for displaying the numbers received by the infrared sensor in the seven segments display 
    switch(cmd)
    {
      case 22:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, HIGH);
        digitalWrite(F_Pin, HIGH);
        digitalWrite(G_Pin, LOW);
        break;
      case 12:
        digitalWrite(A_Pin, LOW);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, LOW);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, LOW);
        digitalWrite(G_Pin, LOW);
        break;
      case 24:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, LOW);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, HIGH);
        digitalWrite(F_Pin, LOW);
        digitalWrite(G_Pin, HIGH);
        break;
      case 94:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, LOW);
        digitalWrite(G_Pin, HIGH);
        break;
      case 8:
        digitalWrite(A_Pin, LOW);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, LOW);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, HIGH);
        digitalWrite(G_Pin, HIGH);
        break; 
      case 28:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, LOW);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, HIGH);
        digitalWrite(G_Pin, HIGH);
        break;
      case 90:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, LOW);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, HIGH);
        digitalWrite(F_Pin, HIGH);
        digitalWrite(G_Pin, HIGH);
        break; 
      case 66:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, LOW);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, LOW);
        digitalWrite(G_Pin, LOW);
        break;  
      case 82:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, HIGH);
        digitalWrite(F_Pin, HIGH);
        digitalWrite(G_Pin, HIGH);
        break;   
      case 74:
        digitalWrite(A_Pin, HIGH);    
        digitalWrite(B_Pin, HIGH);
        digitalWrite(C_Pin, HIGH);
        digitalWrite(D_Pin, HIGH);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, HIGH);
        digitalWrite(G_Pin, HIGH);
        break;
      default:
        digitalWrite(A_Pin, LOW);    
        digitalWrite(B_Pin, LOW);
        digitalWrite(C_Pin, LOW);
        digitalWrite(D_Pin, LOW);
        digitalWrite(E_Pin, LOW);
        digitalWrite(F_Pin, LOW);
        digitalWrite(G_Pin, HIGH);
        break;  
    }
  }
 
  // light the bulbs depending on the distance
  if(cm < 10)
  {
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
  else if(cm >= 10 and cm < 25)
  {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
  else
  {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
  }

  delay(200);
}

// Source: the sketch for the example "PING"
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
