#include "SaveToTarget.h"
#include "SimpleIni.h"


bool InitTarget(Target *myTarget)
{
 	myTarget->sTgtLocationLat = "0";
	myTarget->sTgtLocationLon = "0";
	myTarget->sTgtLocationHt = "0";

	return true;
}



bool AllocTarget(Target *myTarget)
{
	std::ifstream check("NeXtRAD.ini");

	if (!check.good())
	{
		printf("Please check header file location and try again.\n");
	 	exit(EXIT_FAILURE);
	}	

	CSimpleIniA ini;
	ini.LoadFile("NeXtRAD.ini");

	myTarget->sTgtLocationLat = ini.GetValue("TargetSettings", "TGT_LOCATION_LAT");
	myTarget->sTgtLocationLon = ini.GetValue("TargetSettings", "TGT_LOCATION_LON");
	myTarget->sTgtLocationHt = ini.GetValue("TargetSettings", "TGT_LOCATION_HT");

	return true;
}




bool LoadTargetStr(char *sSQLcommand, Target *myTarget, char *strialpkid)
{
	string str1, str2, str3, str0;

// Don't add unnecessary spaces or tabs to the following str
	str1="INSERT INTO Target ( \
	TgtLocationLat, \
	TgtLocationLon, \
	TgtLocationHt, \
	fk_id ) \
	VALUES ( \
 	'"+myTarget->sTgtLocationLat+"', \
	'"+myTarget->sTgtLocationLon+"', \
	'"+myTarget->sTgtLocationHt+"', '";

	str2 = strialpkid;
	str3 = "');";

	str0 = str1+str2+str3;
	
	strcpy (sSQLcommand, str0.c_str());	

	return true;
}



