#include "main.h"

#include "controller/chassis.h"
#include "controller/rack.h"
#include "controller/arm.h"

#include "controller/misc.h"
#include "controller/vision.h"
#include "controller/path.h"


static Chassis chassis(0.6, 0.6);
static Rack rack;
static Arm arm;
static Path path;
static Camera CamFront(FRONTVISION);

// Ignore below. Just for testing stuff.
void tester() {
  std::cout << "Testing" << std::endl;
}

/*===========================================
  PREMADE FUNCTIONS
===========================================*/
void start() {            // Deploy and zero arm
  roller(-200);
  chassis.lock();
  wait(50);
  roller(-200);
  arm.move(0.4, 100, 60);
  wait(50);
  //Thread.drive(-70,100,9);
  armReset();
  chassis.drive(-70,150,9);
  wait(300);
  chassis.waitUntilSettled();
  chassis.unlock();
  chassis.drive(1000, 200);
}

/*===========================================
  RED MATCH AUTONOMOUSES
===========================================*/
void r_s_7() {
  chassis.withTolerance(3).align(165);
  //start();
  roller(200);
  // Pick up 4 cubes

  chassis.drive(1200, 155, 9);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yote", true);
  path.del("yote");

  chassis.drive(1200, 160, 9);
  // Thread.disable_arm();
  chassis.drive(-800, 200, 6);
  chassis.turn(700,200, 7);

  // Drive to small red corner and place
  roller(-23);
  chassis.drive(400,100,7);
  rack.move(RACK_UP, 130, 9);


  // Yeet outta there
  chassis.drive(-300, 200, 10);
  roller(-200);
  rack.move(RACK_DOWN, 200, 15);
  // start();
  // roller(200);
  // // Pick up 4 cubes
  //
  // drive(1200, 145, 9, 10000, 0);
  //
  // // Yoink 3 more cubes and turn right facing small red corner
  // path.run("yeety", true);
  // path.del("yeety");
  //
  // drive(1200, 140, 9, 10000, 0);
  // Thread.disable_arm();
  // turn(720,680, 7);
  //
  // // Drive to small red corner and place
  // roller(-23);
  // Thread.drive(1450, 150, 9);
  // rack(RACK_UP, 110, 6);
  //
  // // Yeet outta there
  // Thread.drive(-300, 200, 10);
  // roller(-200);
  // rack(RACK_DOWN, 200, 15);
}
void r_s_8() {            // red small 8 cube

  start();
  roller(200);
  // Pick up 4 cubes

  chassis.drive(1300, 160, 9);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeet", true);
  path.del("yeet");

  chassis.drive(1400, 145, 9);
  Thread.rack(RACK_TOWER-200, 120, 7);
  drive(-800, 200, 9, 10000, 0);
  Thread.disable_arm();
  roller(-20);
  turn(750, 200, 7);

  // Drive to small red corner and place
  roller(0);
  roller(-31);
  Thread.drive(550, 90, 6);
  rack(RACK_UP, 125, 11);
  Thread.disable_drive();
  wait(100);
  Thread.disable_rack();
  //score 7 cubes in small blue zone
  roller(-200);
  Thread.rack(RACK_DOWN, 200, 15);
  drive(-270, 200, 9);


}
void r_n_9() {            // Red No Score 9 Cube
  start();
  roller(200);
  // Pick up 4 cubes

  drive(1100, 105, 9, 10000, 0);


  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yeety", true);
  path.del("yeety");

  drive(1200, 140, 9, 10000, 0);
  Thread.disable_arm();
  turn(750, 160, 7);

  // Drive to small red corner and place
   drive(1300, 200, 9);
   roller(-100);


  // Yeet outta there
  drive(-300, 200, 10);
  roller(0);



}
void r_b_orange() {       // red big orange cube
  start();
  roller(100);
  drive(200,100,50);
  roller(0);
  turn(-150,100,8);
  Thread.arm(ARM_LOW_TOWER, 200, 60);
  drive(1200,200,3);
  turn(300,100,8);
  drive(200,200,3);
  roller(-200);
  drive(-250,200,6);
  turn(320,50,6);
  Thread.disable_arm();
  roller(0);
}

/*===========================================
  BLUE MATCH AUTONOMOUSES
===========================================*/
void b_s_7() {


    start();
    roller(200);
    // Pick up 4 cubes

    drive(1250, 145, 9, 10000, 0);

    // Yoink 3 more cubes and turn right facing small red corner
    path.run("yote", true);
    path.del("y0te");

    drive(1200, 145, 9, 10000, 0);
    Thread.disable_arm();
    turn(-690, 160, 7);

    // Drive to small red corner and place
    roller(-25);
    Thread.drive(1500, 150, 9);
    rack(RACK_UP, 100, 6);

    // Yeet outta there
    Thread.drive(-300, 200, 10);
    roller(-200);
    rack(RACK_DOWN, 200, 15);


}
void b_s_8() {            // blue small 8 cube
  start();
  roller(200);
  // Pick up 4 cubes

  drive(1100, 105, 9, 10000, 0);

  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yote", true);
  path.del("yote");

  drive(1200, 140, 9, 10000, 0);
  Thread.disable_arm();
  turn(-700, 160, 7);

  // Drive to small red corner and place
  roller(-23);
  Thread.drive(1450, 150, 9);
  rack(RACK_UP, 95, 6);

  // Yeet outta there
  Thread.drive(-300, 200, 10);
  roller(-200);
  rack(RACK_DOWN, 200, 15);
}
void b_n_9() {            // Blue No Score 9 cube
  start();
  roller(200);
  // Pick up 4 cubes

  drive(1100, 105, 9, 10000, 0);


  // Yoink 3 more cubes and turn right facing small red corner
  path.run("yote", true);
  path.del("yote");

  drive(1200, 140, 9, 10000, 0);
  Thread.disable_arm();
  turn(-680, 160, 7);

  // Drive to small red corner and place
   drive(1300, 200, 9);
   roller(-100);


  // Yeet outta there
  drive(-300, 200, 10);
  roller(0);


}
void b_b_green() {        // blue big green cube
  start();
  roller(100);
  drive(200,100,50);
  roller(0);
  turn(150,100,8);
  Thread.arm(ARM_LOW_TOWER, 200, 60);
  drive(1200,200,3);
  turn(-300,100,8);
  drive(200,200,3);
  roller(-200);
  drive(-250,200,6);
  turn(-320,50,6);
  Thread.disable_arm();
  roller(0);
}

/*===========================================
  SKILLS AUTONOMOUSES
===========================================*/
void skills1() {          // official skills

  start();

  wait(100);

  //prime robot
  roller(200);
  drive(1300,130,5);
  strafe(-80,100,5);
  drive(1200, 130, 5);
  strafe(50,100,5);
  drive(600,100,5);
  turn(520, 150, 2);
  drive(-600,100,5);
  roller(-200);
  wait(250);
  roller(0);
  Thread.drive(550,130,7);
  roller(100);
  rack(1500, 200, 11);
  roller(200);
  wait(200);
  Thread.disable_drive();
  Thread.rack(RACK_DOWN, 200, 15);
  roller(100);
  turn(70, 200, 6);
  wait(200);
  roller(10);
  wait(200);
  Thread.disable_drive();

  tower(1);
  drive(250,100,5);
  roller(-150);
  wait(400);
  Thread.drive(-250,100,5);
  armReset();
  Thread.disable_drive();
  roller(200);
  Thread.disable_rack();
  turn(-380,150,5);
  roller(0);
  roller(-31);
  Thread.drive(600, 80, 6);
  rack(RACK_UP, 135, 11);
  Thread.disable_drive();
  wait(300);
  Thread.disable_rack();

  //score 7 cubes in small blue zone
  roller(-200);
  Thread.rack(RACK_DOWN, 200, 15);
  drive(-270, 200, 9);
  wait(100);
  turn(-700, 200, 9);
  align(300, 3);
  roller(0);
  Thread.arm(1, 100, 20);
  drive(1000,200,6);
  turn(-500, 150, 7);
  align(300, 3);
  Thread.disable_arm();
  armReset();
  roller(200);
  drive(1200,90,4);
  roller(100);
  wait(200);

  // Low
  tower(1);
  turn(-220, 150, 4);
  roller(-70);
  drive(150,150,8);

  // Drive to red tower and drop out cube
  drive(-150,150,4);
  roller(200);
  Thread.arm(ARM_BOTTOM-0.2, 150, 10);
  turn(230, 150, 4);
  roller(200);
  drive(1600,90,6);
  Thread.disable_arm();
  roller(100);

  wait(300);
  tower(2);

  // Lift arm to mid tower height
  turn(330,80,7);
  drive(240,150,5);
  roller(-160);

  // Spit cube into the mid tower
  wait(500);
  Thread.arm(ARM_BOTTOM-0.2, 200, 10);
  roller(200);

  drive(-700,200,5);
  wait(100);
  roller(200);
  turn(-550, 150, 7);
  Thread.drive(1000,90,5);
  roller(-30);
  rack(RACK_UP, 110, 11);
  Thread.disable_arm();

  Thread.disable_drive();
  roller(-100);
  Thread.rack(RACK_DOWN, 200, 15);
  wait(100);
  drive(-300, 200, 2);
}
