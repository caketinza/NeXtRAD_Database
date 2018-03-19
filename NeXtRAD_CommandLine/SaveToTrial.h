#ifndef SAVETOTRIAL
#define SAVETOTRIAL

#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>   

using namespace std;

struct Trial
{
 	string sArchiveName;
 	string sTrialDate;
	string sStartTime;
};

bool InitTrial(Trial *myTrial);
bool AllocTrial(Trial *myTrial, string sfilename);
bool LoadTrialStr(char *sSQLcommand, Trial *myTrial);
bool GetTrialPkIdStr(char *sSQLcommand, string sfilename);

#endif
