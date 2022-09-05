#include <legopowerfunctions.h>
#include "car.h"
#include "NewPing.h"

#define MAX_DISTANCE 400
#define TRG1 12
#define ECH1 12
#define TRG2 11
#define ECH2 11
#define TRG3 10
#define ECH3 10
#define TRG4 9
#define ECH4 9
#define TRG5 8
#define ECH5 8

NewPing left(TRG1, ECH1, MAX_DISTANCE);
NewPing middle_left(TRG2, ECH2, MAX_DISTANCE);
NewPing front(TRG3, ECH3, MAX_DISTANCE);
NewPing middle_right(TRG4, ECH4, MAX_DISTANCE);
NewPing right(TRG5, ECH5, MAX_DISTANCE);
LEGOPowerFunctions lego(7);

float dur_left, dis_left;
float dur_mid_left, dis_mid_left;
float dur_front, dis_front;
float dur_mid_right, dis_mid_right;
float dur_right, dis_right;
int iterations = 10;

void Car::forwards() {
  for(int i=0;i<3;i++){
    if(checkSonars()){
        break;
    }
    lego.SingleOutput(0, PWM_REV6, RED , CH1);
    delay(500);
    lego.SingleOutput(0, PWM_FLT, RED, CH1);
  }
  //delay(1300);
  //lego.SingleOutput(0, PWM_FLT, RED, CH1);
}
void Car::turn_right() {
  lego.SingleOutput(0, PWM_REV5, BLUE, CH1);
  delay(1500);
  lego.SingleOutput(0, PWM_FLT, BLUE, CH1);
}
void Car::turn_left() {
  lego.SingleOutput(0, PWM_FWD5, BLUE, CH1);
  delay(1500);
  lego.SingleOutput(0, PWM_FLT, BLUE, CH1);
}
void Car::backwards() {
  lego.SingleOutput(0, PWM_FWD5, RED, CH1);
  delay(1300);
  lego.SingleOutput(0, PWM_FLT, RED, CH1);
}

void Car::left_sonar() {
  dur_left = left.ping_median(iterations);
  dis_left = (dur_left / 2) * 0.0343;
}
void Car::mid_left_sonar() {
  dur_mid_left = middle_left.ping_median(iterations);
  dis_mid_left = (dur_mid_left / 2) * 0.0343;
}
float Car::front_sonar() {
  dur_front = front.ping_median(iterations);
  return (dur_front / 2) * 0.0343;
}
void Car::mid_right_sonar() {
  dur_mid_right = middle_right.ping_median(iterations);
  dis_mid_right = (dur_mid_right / 2) * 0.0343;
}
void Car::right_sonar() {
  dur_right = right.ping_median(iterations);
  dis_right = (dur_right / 2) * 0.0343;
}
bool Car::checkSonars() {
  mid_left_sonar();
  front_sonar();
  mid_right_sonar();

  if (dis_mid_left <= 15 || dis_front <= 18 || dis_mid_right <= 15) return true;
  return false;
}