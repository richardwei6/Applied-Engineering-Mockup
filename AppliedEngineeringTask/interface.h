#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <tlhelp32.h>
#include <string>
#include <map>

using namespace std;

class interfaceInteractor { // custom interactor made for console ouput & phone updating
public:
	interfaceInteractor() {
		cout << "Welcome. Use arrow keys for turning and throttle" << endl;
		system("pause");
	}
	void update(int throttle, int heading) {
		if (throttle != prevThrottle || heading != prevHeading) {
			prevThrottle = throttle;
			prevHeading = heading;
			system("cls");
			cout << "throttle " << throttlePadding << " [" << throttleToString(throttle) << "] " << throttlePadding << " " << throttle << "%" << endl;
			cout << endl;
			cout << headingUpperPadding << "[Heading]" << headingUpperPadding << endl;
			cout << headingPadding << (heading + 330) % 360 << headingPadding << heading << headingPadding << (heading + 30) % 360 << headingPadding << endl;
		}
	}
private:
	const string headingPadding = "..........", headingUpperPadding = "-------------------", throttlePadding = "----------";
	int prevHeading = -1, prevThrottle = -1;
	string throttleToString(int throttle) {
		string o = "";
		int r = round((long double)throttle / 10);
		for (int i = 0; i < r; i++) {
			o += '=';
		}
		for (int i = 0; i < 10 - r; i++) {
			o += ' ';
		}
		return o;
	}
};
