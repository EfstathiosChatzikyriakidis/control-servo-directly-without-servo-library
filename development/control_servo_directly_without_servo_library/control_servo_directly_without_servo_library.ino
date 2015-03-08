/*
 *  Control Servo Directly (Without Servo Library).
 *
 *  Copyright (C) 2010 Efstathios Chatzikyriakidis (contact@efxa.org)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

const int servoPin = 7;    // the pin number (no PWM) of the servo.
const long delayTime = 10; // servo movement delay time in millis.

int myAngle = 0;    // angle of the servo (roughly in degrees) 0-180.
int pulseWidth = 0; // angle to microseconds.

// startup point entry (runs once).
void setup() {
  // set servo pin as output.
  pinMode(servoPin, OUTPUT);
}

// loop the main sketch.
void loop()
{
  // cycle through every angle (rotate the servo 180 slowly).
  for (myAngle = 0; myAngle <= 180; myAngle++) {  
    servoPulse(servoPin, myAngle);
  }

  // cycle through every angle (rotate the servo 180 slowly).
  for (myAngle = 180; myAngle >= 0; myAngle--) {  
    servoPulse(servoPin, myAngle);
  }
}

// move the servo.
void servoPulse(int servoPin, int myAngle) {
  pulseWidth = (myAngle * 11) + 500; // converts angle to microseconds.
  digitalWrite(servoPin, HIGH);      // set servo high.
  delayMicroseconds(pulseWidth);     // wait a very small amount.
  digitalWrite(servoPin, LOW);       // set servo low.
  delay(delayTime);                  // refresh cycle of typical servos.
}
