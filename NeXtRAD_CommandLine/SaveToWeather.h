#ifndef SAVETOWEATHER
#define SAVETOWEATHER

#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>   

using namespace std;

struct Weather
{
	string sDouglasSeaState;
	string sWindSpeed;
	string sWindDir;
	string sWaveHeight;
	string sWaveDir;
	string sWavePeriod;
	string sAirTemperature;
	string sAirPressure;
};

bool InitWeather(Weather *myWeather);
bool AllocWeather(Weather *myWeather);
bool LoadWeatherStr(char *sSQLcommand, Weather *myWeather, char *strialpkid);

#endif
