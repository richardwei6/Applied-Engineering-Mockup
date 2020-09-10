#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <tlhelp32.h>
#include <string>
#include <map>

using namespace std;

class motorDriver {
public:
	motorDriver() {
		// constructor - here, initalize PWM, i2c, etc.. interface with motor
	}
	bool driveMotor(int percent) { // set motor
		return setPWM(percentToPulselen(percent));
	}
	void driveRudder(int degree) { // change rudder position to turn boat relative to north if rudder is controlled electronically

	}
private:
	int percentToPulselen(int percent) {
		// convert percentage of throttle to respective pulse length
		return 290;
	}
	bool setPWM(int pulselen) {
		// insert code here for interaction with motor
		// if interacting with the motor fails, return false otherwise return true
		return 1;
	}
};
