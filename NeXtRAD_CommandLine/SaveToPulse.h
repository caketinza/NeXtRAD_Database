#ifndef SAVETOPULSE
#define SAVETOPULSE

#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>   

using namespace std;

struct Pulse
{
 	string sWaveform;
	string sNumOfPRIs;
	string sSamplesPerPRI;
 	string sDACDelay;
	string sADCDelay;
	string sPolOrder;
	string sPRI;
	string sPrePulse;
	string sLBandWaveformFreq;
	string sXBandWaveformFreq;
};

bool InitPulse(Pulse *myPulse);
bool AllocPulse(Pulse *myPulse);
bool LoadPulseStr(char *sSQLcommand, Pulse *myPulse, char *strialpkid);

#endif
