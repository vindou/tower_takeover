#include "lib_7k/util/odometry.h"
#include "lib_7k/control/chassis.h"

bool Odometry::isRunning = false;

double Odometry::deltaL = 0, Odometry::deltaR = 0;

void Odometry::start(void *ignore) {
  if(!isRunning) {
    pros::delay(500);
    Odometry *that = static_cast<Odometry*>(ignore);
    that -> run();
  }
}

void Odometry::run() {
  isRunning = true;

  while(isRunning) {
    deltaL = -1 * LF.get_position();
    deltaR = RF.get_position();

    theta = ( deltaL - deltaR ) / 11;

    posX = 2 * sin( theta / 2 ) * ( deltaL / 2 );
    posY = 2 * sin( theta / 2 ) * ( deltaR / 2 );

    pros::delay(10);
  }
}

void Odometry::stop() {
  isRunning = false;
}
