#include "main.h"

#define RACK 18
#define RACKPOT 1

#define RACK_DOWN 950
#define RACK_TOWER 1650
#define RACK_UP 3300

extern pros::Motor RackMotor;
extern pros::ADIPotentiometer Pot;

class Rack {
  public:
    Rack();
    ~Rack();

    Rack& withTol(double tolerance_ = 5);

    Rack& move(double target_, int speed_, int rate_ = 9);

    void waitUntilSettled();

    void reset();

    void setBrakeType(pros::motor_brake_mode_e_t type_);

    bool getState();
    int getPot();

    static void start(void *ignore);
    void run();
    void stop();

    void move(int speed);

  private:
    static bool isRunning;
    static bool isSettled;
    static bool isActive;

    static double kP;

    static double tolerance;

    static double target;
    static int speed, rate;

    static double error, output, slewOutput;

};