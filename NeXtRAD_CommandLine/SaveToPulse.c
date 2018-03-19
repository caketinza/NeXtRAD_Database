#include "SaveToPulse.h"
#include "SimpleIni.h"

bool InitPulse(Pulse *myPulse)
{
 	myPulse->sWaveform = "0";
	myPulse->sNumOfPRIs = "0";
	myPulse->sSamplesPerPRI = "0";
 	myPulse->sDACDelay = "0";
	myPulse->sADCDelay = "0";
	myPulse->sPolOrder = "0";
	myPulse->sPRI = "0";
	myPulse->sPrePulse = "0";
	myPulse->sLBandWaveformFreq = "0";
	myPulse->sXBandWaveformFreq = "0";

	return true;
}


bool AllocPulse(Pulse *myPulse)
{
	std::ifstream check("NeXtRAD.ini");

	if (!check.good())
	{
		printf("Please check header file location and try again.\n");
	 	exit(EXIT_FAILURE);
	}	

	CSimpleIniA ini;
	ini.LoadFile("NeXtRAD.ini");

	// change to show actual waveform, not index
	myPulse->sWaveform = ini.GetValue("PulseParameters", "WAVEFORM_INDEX");
	myPulse->sNumOfPRIs = ini.GetValue("PulseParameters", "NUM_PRIS");
	myPulse->sSamplesPerPRI = ini.GetValue("PulseParameters", "SAMPLES_PER_PRI");
 	myPulse->sDACDelay = ini.GetValue("PulseParameters", "DAC_DELAY");
	myPulse->sADCDelay = ini.GetValue("PulseParameters", "ADC_DELAY");
	myPulse->sPolOrder = ini.GetValue("PulseParameters", "POL_ORDER");
	myPulse->sPRI = ini.GetValue("PulseParameters", "PRI");
	myPulse->sPrePulse = ini.GetValue("PulseParameters", "PRE_PULSE");
	myPulse->sLBandWaveformFreq = ini.GetValue("PulseParameters", "L_BAND_WAVEFORM_FREQ");
	myPulse->sXBandWaveformFreq = ini.GetValue("PulseParameters", "X_BAND_WAVEFORM_FREQ");
	
	return true;
}


bool LoadPulseStr(char *sSQLcommand, Pulse *myPulse, char *strialpkid)
{
	string str1, str2, str3, str0;

	// Don't add unnecessary spaces or tabs to the following str
	str1="INSERT INTO Pulse ( \
	Waveform, \
	NumOfPRIs, \
	SamplesPerPRI, \
	DACDelay, \
	ADCDelay, \
	PolOrder, \
	PRI, \
	PrePulse, \
	LBandWaveformFreq, \
	XBandWaveformFreq, \
	fk_id ) \
	VALUES ( \
	'"+myPulse->sWaveform+"', \
	'"+myPulse->sNumOfPRIs+"', \
	'"+myPulse->sSamplesPerPRI+"', \
 	'"+myPulse->sDACDelay+"', \
	'"+myPulse->sADCDelay+"', \
	'"+myPulse->sPolOrder+"', \
	'"+myPulse->sPRI+"', \
	'"+myPulse->sPrePulse+"', \
	'"+myPulse->sLBandWaveformFreq+"', \
	'"+myPulse->sXBandWaveformFreq+"', '";	

	str2 = strialpkid;
	str3 = "');";

	str0 = str1+str2+str3;
	
	strcpy (sSQLcommand, str0.c_str());	

	return true;
}

