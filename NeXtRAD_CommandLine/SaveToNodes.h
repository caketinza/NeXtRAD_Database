#ifndef SAVETONODES
#define SAVETONODES

#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>   

using namespace std;

struct Nodes
{
	string sNode0LocationLat;
	string sNode0LocationLon;
	string sNode0LocationHt;
	string sNode1LocationLat;
	string sNode1LocationLon;
	string sNode1LocationHt;
	string sNode2LocationLat;
	string sNode2LocationLon;
	string sNode2LocationHt;
	string sDTGOfBearing;
	string sBaselineBisector;
	string sNode0Range;
	string sNode0Bearing;
	string sNode1Range;
	string sNode1Bearing;
	string sNode2Range;
	string sNode2Bearing;
};

bool InitNodes(Nodes *myNodes);
bool AllocNodes(Nodes *myNodes);
bool LoadNodesStr(char *sSQLcommand, Nodes *myNodes, char *strialpkid);

#endif
