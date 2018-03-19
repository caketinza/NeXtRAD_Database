#include "SaveToTrial.h"
#include "SimpleIni.h"


bool InitTrial(Trial *myTrial)
{
 	myTrial->sArchiveName = "0";
 	myTrial->sTrialDate = "1000-01-01";
	myTrial->sStartTime = "00:00:00";
	return true;
}


bool AllocTrial(Trial *myTrial, string sfilename)
{
	std::ifstream check("NeXtRAD.ini");

	if (!check.good())
	{
		printf("Please check header file location and try again.\n");
	 	exit(EXIT_FAILURE);
	}	

	CSimpleIniA ini;
	ini.LoadFile("NeXtRAD.ini");

	string year = ini.GetValue("Timing", "YEAR");
	string month = ini.GetValue("Timing", "MONTH");
	string day = ini.GetValue("Timing", "DAY");
	string hour = ini.GetValue("Timing", "HOUR");
	string min = ini.GetValue("Timing", "MINUTE");
	string sec = ini.GetValue("Timing", "SECOND");

	// while working with NeXtRAD.ini - to change when working with Darryn's renamed file
	myTrial->sArchiveName = year + "-" + month + "-" + day + "_" + hour + ":" + min + ":" + sec;
	
	myTrial->sTrialDate = year + "-" + month + "-" + day;
	myTrial->sStartTime = hour + ":" + min + ":" + sec;
	
	//sfilename = year + "-" + month + "-" + day + "_" + hour + ":" + min + ":" + sec;
	//cout << sfilename << endl;
	return true;
}


bool LoadTrialStr(char *sSQLcommand, Trial *myTrial)
{
	string str;

	// Don't add unnecessary spaces or tabs to the following str
	str="INSERT INTO Trial ( \
	ArchiveName, \
	TrialDate, \
	StartTime) \
	VALUES ( \
	'"+myTrial->sArchiveName+"', \
	'"+myTrial->sTrialDate+"', \
	'"+myTrial->sStartTime+"');";

	strcpy (sSQLcommand, str.c_str());	

	return true;
}


bool GetTrialPkIdStr(char *sSQLcommand, string sfilename)
{
	string name = "Select pk_id from Trial";/*where uk_name = '" + sfilename + "'";*/
	strcpy (sSQLcommand, name.c_str());
	return true;
}