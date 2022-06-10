#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const int WIDTH = 500;
const int HEIGHT = 500;

struct MyConfig {  

	MyConfig() {
		ifstream fin("Config.txt");

		string str;
		int i = 0;
		while (getline(fin, str)) {

			// set screen rezolution
			if (i == 0) {
				auto it = find(str.begin(), str.end(), ':');
				auto it_c = find(str.begin(), str.end(), ',');
				string X(it + 2, it_c);
				string Y(it_c + 2, str.end());
				ScreenResolution = { stoi(X), stoi(Y) };
				ScreenScale = { ScreenResolution.first / 1920, ScreenResolution.second / 1080 };
			}

			++i;
		}

		fin.close();
		cout << "Current Resolution: " << ScreenResolution.first << ' ' << ScreenResolution.second << '\n';

	}

	pair<int, int> ScreenResolution = { 1920, 1080 };
	pair <float, float> ScreenScale = { 1, 1 };
};



