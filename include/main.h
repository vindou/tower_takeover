#pragma once
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

// Nice things below
#include "api.h"
#include "pros/apix.h"
#include "pros/rtos.h"
#include "okapi/api.hpp"

void macroTask(void* ignore);

extern pros::Task controlDrive;
extern pros::Task armAsync;

// It's Everyday Functions Bro
void wait(int ms);
void print(const char * text);

// Image declaration
LV_IMG_DECLARE(title);
LV_IMG_DECLARE(intro);

LV_IMG_DECLARE(michael1);
LV_IMG_DECLARE(michael2);

// Motor ports & ADI
#define LFPORT 9
#define LBPORT 10
#define RFPORT 3
#define RBPORT 4

#define RACK 11
#define ARM 12

#define FLAPL 1
#define FLAPR 2

#define RACKPOT 1

#define ROLLERLINE 2

#define ULTRALPING 5
#define ULTRALECHO 6

#define ULTRARPING 3
#define ULTRARECHO 4

#define FRONTVISION 13

using namespace okapi;

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include <vector>

#include <stdio.h>
#include <stdarg.h>

#endif

#endif  // _PROS_MAIN_H_
