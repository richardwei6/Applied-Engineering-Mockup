#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <tlhelp32.h>
#include <string>
#include <map>


using namespace std;

class networking { // main purpose of this class is to create a socket to interact with whatever device on the same network
public:
	networking() { // constructor

	}
	bool sendData(int throttle, int heading) {
		// use sockets to communicate within a network OR use a webserver as a buffer between devices
	}
private:

};
