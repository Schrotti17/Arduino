#include <Arduino.h>
#include <SoftwareSerial.h>
#include "car.h"

SoftwareSerial hc05(4, 5);

//char Incoming_value = 0;
void setup() {
  Serial.begin(9600);
  hc05.begin(9600);
}

void loop() {

  Car legoCar;
  if (hc05.available())
  {
    char c;
    c = hc05.read();
    Serial.println(c);

    switch (c) 
    {
    case '1':
      legoCar.forwards();
      break;
    case '2':
      legoCar.turn_left();
      break;
    case '3':
      legoCar.turn_right();
      break;
    case '4':
      legoCar.backwards();
      break;
    }
  }
}

void sonars() {
  //  duration = sonar5.ping_median(iterations);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound

  /* distance = (duration / 2) * 0.0343;

    // Send results to Serial Monitor
    Serial.print("Distance = ");
    if (distance >= 400 || distance <= 2) {
     Serial.println("Out of range");
    }
    else {
     Serial.print(distance);
     Serial.println(" cm");
     delay(500);
    }
    delay(500);*/
}
