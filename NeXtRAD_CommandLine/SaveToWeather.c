#include "SaveToWeather.h"
#include "SimpleIni.h"

bool InitWeather(Weather *myWeather)
{
	myWeather->sDouglasSeaState = "0";
	myWeather->sWindSpeed = "0";
	myWeather->sWindDir = "0";
	myWeather->sWaveHeight = "0";
	myWeather->sWaveDir = "0";
	myWeather->sWavePeriod = "0";
	myWeather->sAirTemperature = "0";
	myWeather->sAirPressure = "0";

	return true;
}

bool AllocWeather(Weather *myWeather)
{
	std::ifstream check("NeXtRAD.ini");

	if (!check.good())
	{
		printf("Please check header file location and try again.\n");
	 	exit(EXIT_FAILURE);
	}	

	CSimpleIniA ini;
	ini.LoadFile("NeXtRAD.ini");

	myWeather->sDouglasSeaState = ini.GetValue("Weather", "DOUGLAS_SEA_STATE");
	myWeather->sWindSpeed = ini.GetValue("Weather", "WIND_SPEED");
	myWeather->sWindDir = ini.GetValue("Weather", "WIND_DIR");
	myWeather->sWaveHeight = ini.GetValue("Weather", "WAVE_HEIGHT");
	myWeather->sWaveDir = ini.GetValue("Weather", "WAVE_DIR");
	myWeather->sWavePeriod = ini.GetValue("Weather", "WAVE_PERIOD");
	myWeather->sAirTemperature = ini.GetValue("Weather", "AIR_TEMPERATURE");
	myWeather->sAirPressure = ini.GetValue("Weather", "AIR_PRESSURE");

	return true;
}

bool LoadWeatherStr(char *sSQLcommand, Weather *myWeather, char *strialpkid)
{
	string str1, str2, str3, str0;

	// Don't add unnecessary spaces or tabs to the following str
	str1="INSERT INTO Weather ( \
	DouglasSeaState, \
	WindSpeed, \
	WindDir, \
	WaveHeight, \
	WaveDir, \
	WavePeriod, \
	AirTemperature, \
	AirPressure, \
	fk_id ) \
	VALUES ( \
	'"+myWeather->sDouglasSeaState+"', \
	'"+myWeather->sWindSpeed+"', \
	'"+myWeather->sWindDir+"', \
	'"+myWeather->sWaveHeight+"', \
	'"+myWeather->sWaveDir+"', \
	'"+myWeather->sWavePeriod+"', \
	'"+myWeather->sAirTemperature+"', \
	'"+myWeather->sAirPressure+"', \'";

	str2 = strialpkid;
	str3 = "');";

	str0 = str1+str2+str3;
	
	strcpy (sSQLcommand, str0.c_str());	

	return true;
}