#include <iostream>
#include <Windows.h>
#include <vector>
#include <tlhelp32.h>
#include <string>
#include <map>
#include "motorDriver.h"
#include "interface.h"
#include "networkManager.h"

using namespace std;

int main() {
	int throttlePercent = 0; // 0 - 100 percentage of throttle
	int heading = 0; // 0 - 360 degrees
	const int turningSensitivity = 1, throttleSensitivity = 2, tickRate = 10;
	
	interfaceInteractor intrfce;
	motorDriver mtr;

	while (1) { // for GetKeyState(), -127 changes to 1 / -128 changes to 0
		int upKey = GetKeyState(VK_UP), downKey = GetKeyState(VK_DOWN), left = GetKeyState(VK_LEFT), right = GetKeyState(VK_RIGHT);
		if (upKey == -128 || upKey == -127) {
			throttlePercent = min(throttlePercent + throttleSensitivity, 100);
		}
		if (downKey == -128 || downKey == -127) {
			throttlePercent = max(throttlePercent - throttleSensitivity, 0);
		}
		if (left == -128 || left == -127) {
			heading = (heading - turningSensitivity + 360) % 360;
		}
		if (right == -128 || right == -127) {
			heading = (heading + turningSensitivity) % 360;
		}
		intrfce.update(throttlePercent, heading);
		mtr.driveMotor(throttlePercent);
		mtr.driveRudder(heading);
		intrfce.update(throttlePercent, heading);
		Sleep(tickRate);
	}
	return 0;
}