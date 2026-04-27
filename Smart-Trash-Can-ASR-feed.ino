#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);  // RX, TX

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
// #define data A0
// #define data1 A1
Servo myservo;
Servo myservo2;
// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;  // variable to store the servo position

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  myservo.attach(7);
  myservo2.attach(8);
   myservo2.write(100);
   myservo.write(7);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // myservo.write(7);
  // attaches the servo on pin 9 to the servo object

  pinMode(9, INPUT);
  // pinMode(data,INPUT);
  // pinMode(data1,INPUT);
  //  mySerial.begin(9600);
}


void loop() {
  if (mySerial.available()) {
    int data = mySerial.read();
    Serial.write(data);
    
    if (data == 1) {
      mySerial.write(1);
    } else if (data == 2) {
      mySerial.write(1);
      for (pos = 7; pos <= 70; pos += 1) {  // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);  // tell servo to go to position in variable 'pos'
        delay(15);           // waits 15ms for the servo to reach the position
      }
      delay(500);


      for (pos = 240; pos <= 240; pos += 1) {  // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo2.write(pos);  // tell servo to go to position in variable 'pos'
        delay(15);            // waits 15ms for the servo to reach the position
      }
      delay(500);


      for (pos = 240; pos >= 100; pos -= 1) {  // goes from 180 degrees to 0 degrees
        myservo2.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(15);                             // waits 15ms for the servo to reach the position
      }
      for (pos = 70; pos >= 7; pos -= 1) {  // goes from 180 degrees to 0 degrees
        myservo.write(pos);                 // tell servo to go to position in variable 'pos'
        delay(15);                          // waits 15ms for the servo to reach the position
      }
    } else if (data == 3) {
      mySerial.write(1);
      for (pos = 0; pos <= 100; pos += 1) {  // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);  // tell servo to go to position in variable 'pos'
        delay(15);           // waits 15ms for the servo to reach the position
      }
      delay(15000);
      for (pos = 100; pos >= 0.; pos -= 1) {  // goes from 180 degrees to 0 degrees
        myservo.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(15);                            // waits 15ms for the servo to reach the position
      }
    }
  }

//  Serial.println(digitalRead(data));

if (digitalRead(9) == 0) {
  for (pos = 7; pos <= 70; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);           // waits 15ms for the servo to reach the position
  }
  delay(500);


  for (pos = 240; pos <= 240; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);            // waits 15ms for the servo to reach the position
  }
  delay(500);


  for (pos = 240; pos >= 100; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo2.write(pos);                   // tell servo to go to position in variable 'pos'
    delay(15);                             // waits 15ms for the servo to reach the position
  }
  for (pos = 70; pos >= 7; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15ms for the servo to reach the position
  }

}
}
