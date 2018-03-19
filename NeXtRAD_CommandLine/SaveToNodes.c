#include "SaveToNodes.h"
#include "SimpleIni.h"


bool InitNodes(Nodes *myNodes)
{
	myNodes->sNode0LocationLat = "0";
	myNodes->sNode0LocationLon = "0";
	myNodes->sNode0LocationHt = "0";
	myNodes->sNode1LocationLat = "0";
	myNodes->sNode1LocationLon = "0";
	myNodes->sNode1LocationHt = "0";
	myNodes->sNode2LocationLat = "0";
	myNodes->sNode2LocationLon = "0";
	myNodes->sNode2LocationHt = "0";
	myNodes->sDTGOfBearing = "0";
	myNodes->sBaselineBisector = "0";
	myNodes->sNode0Range = "0";
	myNodes->sNode0Bearing = "0";
	myNodes->sNode1Range = "0";
	myNodes->sNode1Bearing = "0";
	myNodes->sNode2Range = "0";
	myNodes->sNode2Bearing = "0";

	return true;
}


bool AllocNodes(Nodes *myNodes)
{
	std::ifstream check("NeXtRAD.ini");

	if (!check.good())
	{
		printf("Please check header file location and try again.\n");
	 	exit(EXIT_FAILURE);
	}	

	CSimpleIniA ini;
	ini.LoadFile("NeXtRAD.ini");

	myNodes->sNode0LocationLat = ini.GetValue("GeometrySettings", "NODE0_LOCATION_LAT");
	myNodes->sNode0LocationLon = ini.GetValue("GeometrySettings", "NODE0_LOCATION_LON");
	myNodes->sNode0LocationHt = ini.GetValue("GeometrySettings", "NODE0_LOCATION_HT");
	myNodes->sNode1LocationLat = ini.GetValue("GeometrySettings", "NODE1_LOCATION_LAT");
	myNodes->sNode1LocationLon = ini.GetValue("GeometrySettings", "NODE1_LOCATION_LON");
	myNodes->sNode1LocationHt = ini.GetValue("GeometrySettings", "NODE1_LOCATION_HT");
	myNodes->sNode2LocationLat = ini.GetValue("GeometrySettings", "NODE2_LOCATION_LAT");
	myNodes->sNode2LocationLon = ini.GetValue("GeometrySettings", "NODE2_LOCATION_LON");
	myNodes->sNode2LocationHt = ini.GetValue("GeometrySettings", "NODE2_LOCATION_HT");

	myNodes->sDTGOfBearing = ini.GetValue("Bearings", "DTG");
	myNodes->sBaselineBisector = ini.GetValue("Bearings", "BASELINE_BISECTOR");
	myNodes->sNode0Range = ini.GetValue("Bearings", "NODE0_RANGE");
	myNodes->sNode0Bearing = ini.GetValue("Bearings", "NODE0_BEARING");
	myNodes->sNode1Range = ini.GetValue("Bearings", "NODE1_RANGE");
	myNodes->sNode1Bearing = ini.GetValue("Bearings", "NODE1_BEARING");
	myNodes->sNode2Range = ini.GetValue("Bearings", "NODE2_RANGE");
	myNodes->sNode2Bearing = ini.GetValue("Bearings", "NODE2_BEARING");

	return true;
}


bool LoadNodesStr(char *sSQLcommand, Nodes *myNodes, char *strialpkid)
{
	string str1, str2, str3, str0;

	// Don't add unnecessary spaces or tabs to the following str
	str1="INSERT INTO Nodes ( \
	Node0LocationLat, \
	Node0LocationLon, \
	Node0LocationHt, \
	Node1LocationLat, \
	Node1LocationLon, \
	Node1LocationHt, \
	Node2LocationLat, \
	Node2LocationLon, \
	Node2LocationHt, \
	DTGOfBearing, \
	BaselineBisector, \
	Node0Range, \
	Node0Bearing, \
	Node1Range, \
	Node1Bearing, \
	Node2Range, \
	Node2Bearing, \
	fk_id ) \
	VALUES ( \
	'"+myNodes->sNode0LocationLat+"', \
	'"+myNodes->sNode0LocationLon+"', \
	'"+myNodes->sNode0LocationHt+"', \
	'"+myNodes->sNode1LocationLat+"', \
	'"+myNodes->sNode1LocationLon+"', \
	'"+myNodes->sNode1LocationHt+"', \
	'"+myNodes->sNode2LocationLat+"', \
	'"+myNodes->sNode2LocationLon+"', \
	'"+myNodes->sNode2LocationHt+"', \
	'"+myNodes->sDTGOfBearing+"', \
	'"+myNodes->sBaselineBisector+"', \
	'"+myNodes->sNode0Range+"', \
	'"+myNodes->sNode0Bearing+"', \
	'"+myNodes->sNode1Range+"', \
	'"+myNodes->sNode1Bearing+"', \
	'"+myNodes->sNode2Range+"', \
	'"+myNodes->sNode2Bearing+"', '";

	str2 = strialpkid;
	str3 = "');";

	str0 = str1+str2+str3;
	
	strcpy (sSQLcommand, str0.c_str());	

	return true;
}