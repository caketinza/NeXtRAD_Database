#ifndef SAVETOTARGET
#define SAVETOTARGET

#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>   

using namespace std;

struct Target
{
 	string sTgtLocationLat;
	string sTgtLocationLon;
	string sTgtLocationHt;
};

bool InitTarget(Target *myTarget);
bool AllocTarget(Target *myTarget);
bool LoadTargetStr(char *sSQLcommand, Target *myTarget, char *strialpkid);

#endif
