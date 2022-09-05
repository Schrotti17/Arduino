#ifndef car_h
#define car_h

class Car{

  public:
    void forwards();
    void turn_right();
    void turn_left();
    void backwards();

    void left_sonar();
    void mid_left_sonar();
    float front_sonar();
    void mid_right_sonar();
    void right_sonar();
    bool checkSonars();
};
#endif