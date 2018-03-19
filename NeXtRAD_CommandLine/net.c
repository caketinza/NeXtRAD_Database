#include "SaveToTrial.h"
#include "SaveToPulse.h"
#include "SaveToNodes.h"
#include "SaveToWeather.h"
#include "SaveToTarget.h"
#include "SimpleIni.h"

MYSQL *conn, mysql;

bool InitStructs(Trial *myTrial, Pulse *myPulse, Nodes *myNodes, Weather *myWeather, Target *myTarget)
{
	if (!InitTrial(myTrial))
	{
		cout << "ERROR: Could not initialise trial variables!" << endl;
		return 1;
	}

	if (!InitPulse(myPulse))
	{
		cout << "ERROR: Could not initialise pulse variables!" << endl;
		return false;
	}

	if (!InitNodes(myNodes))
	{
		cout << "ERROR: Could not initialise node variables!" << endl;
		return false;
	}

	if (!InitWeather(myWeather))
	{
		cout << "ERROR: Could not initialise weather variables!" << endl;
		return false;
	}

	if (!InitTarget(myTarget))
	{
		cout << "ERROR: Could not initialise target variables!" << endl;
		return false;
	}


	return true;
}


bool ReadFile(string sfilename, Trial *myTrial, Pulse *myPulse, Nodes *myNodes, Weather *myWeather, Target *myTarget)
{
	if (!AllocTrial(myTrial, sfilename))
	{
		cout << "ERROR: Could not allocate trial variables!" << endl;
		return false;
	}

	if (!AllocPulse(myPulse))
	{
		cout << "ERROR: Could not allocate pulse variables!" << endl;
		return false;
	}

	if (!AllocNodes(myNodes))
	{
		cout << "ERROR: Could not allocate Nodes variables!" << endl;
		return false;
	}

	if (!AllocWeather(myWeather))
	{
		cout << "ERROR: Could not allocate Weather variables!" << endl;
		return false;
	}

	if (!AllocTarget(myTarget))
	{
		cout<<"ERROR: Could not allocate Target variables!"<<endl;
		return false;
	}


	return true;
}


bool SaveToDatabase(Trial *myTrial, Pulse *myPulse, Nodes *myNodes, Weather *myWeather, Target *myTarget, string sfilename)
{
	// const char *server="localhost";
   	// const char *user="root";
   	// const char *password="bubsy3726";
   	// const char *database="nextrad";

	// MYSQL *conn, mysql;


   	// mysql_init(&mysql);
   	// conn=mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
   	// if(conn==NULL)
   	// {
    // 	cout<<mysql_error(&mysql)<<endl;
    // 	return false;
   	// }

	// Connect();
	
	MYSQL_RES *res;
	MYSQL_ROW row;
	char sSQLcommand[3000];
	sSQLcommand[0] = '\0';
	int query_state;

	char strialpkid[3000];
	strialpkid[0] = '\0';

	char ch;

	if (!LoadTrialStr(sSQLcommand, myTrial))
   	{
      	cout<<"ERROR: Could not load trial str!"<<endl;
      	return false;
   	}
   	query_state = mysql_query(conn, sSQLcommand);
   	if (query_state != 0)
   	{
		cout<<mysql_error(conn)<<endl;
		cout << "The contents of this file have been loaded before. Do you still wish to continue? y/n" << endl;
		cin >> ch;
		if (ch != 'y')
		{
			return false;
		}
   	}

	if (!GetTrialPkIdStr(sSQLcommand, sfilename))
   	{
      	cout<<"ERROR: Could not get string for pk_id from trial table in database!"<<endl;
      	return false;
   	}
   	query_state=mysql_query(conn, sSQLcommand); 

   	if (query_state!=0)
   	{
      	cout<<mysql_error(conn)<<endl<<endl;
      	return false;
   	}

   	res=mysql_store_result(conn);

   	while ((row=mysql_fetch_row(res))!=NULL)
   	{
		sprintf( strialpkid, "%s", row[0]);
   	}

	if (!LoadPulseStr(sSQLcommand, myPulse, strialpkid))
   	{
      	cout<<"ERROR: Could not load Pulse str!"<<endl;
      	return false;
   	}

   	query_state = mysql_query(conn, sSQLcommand);
   	if (query_state != 0)
   	{
      	cout<<mysql_error(conn)<<endl<<endl;
      	return false;
   	}

	if (!LoadNodesStr(sSQLcommand, myNodes, strialpkid))
	{
      	cout<<"ERROR: Could not load Nodes str!"<<endl;
      	return false;
	}

	query_state = mysql_query(conn, sSQLcommand);
	if (query_state != 0)
	{
    	cout << mysql_error(conn) << endl;
		return false;
	}

	if (!LoadWeatherStr(sSQLcommand, myWeather, strialpkid))
   	{
      	cout<<"ERROR: Could not save data to Weather table in database!"<<endl;
      	return false;
   	}

   	query_state=mysql_query(conn, sSQLcommand);
   	if (query_state!=0)
   	{
      	cout<<mysql_error(conn)<<endl<<endl;
      	return false;
   	}

	if (!LoadTargetStr(sSQLcommand, myTarget, strialpkid))
   	{
      	cout<<"ERROR: Could not save data to Target table in database!"<<endl;
      	return false;
   	}

   	query_state=mysql_query(conn, sSQLcommand);
   	if (query_state!=0)
   	{
      	cout<<mysql_error(conn)<<endl<<endl;
      	return false;
   	}
 
	// Close connection to database
	mysql_close(conn);

	return true;
}

bool Connect()
{
	const char *server="localhost";
   	const char *user="root";
   	const char *password="bubsy3726";
   	const char *database="nextrad";

	char ch;

   	mysql_init(&mysql);
   	conn=mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
   	if(conn==NULL)
   	{
    	cout<<mysql_error(&mysql)<<endl;
    	return false;
   	}
	return true;
}

// string moop(string sqlcommand)
// {
// 	cout<< sqlcommand <<endl;
// 	return "maaaaa";
// }

string DbAction(string sqlcommand)
{
	cout << "um"<<endl;
	MYSQL_RES *result;
	MYSQL_ROW row;
	char sSQLcommand[3000];
	sSQLcommand[0] = '\0';
	int query_state;
	string blah = "";

	strcpy (sSQLcommand, sqlcommand.c_str());

	query_state=mysql_query(conn, sSQLcommand); 

   	if (query_state!=0)
   	{
      	cout<<mysql_error(conn)<<endl<<endl;
      	//return false;
   	}

   	result=mysql_store_result(conn);

	//int i=0;
	//row = mysql_fetch_row(result);
   	while ((row=mysql_fetch_row(result))!=NULL)
   	{
		for (int i=0;i<4;i++){
			blah = blah + " " + row[i];
		}
		blah = blah + "\n";
		//blah = row[i];
		// sprintf( blah, "%s", row[0]);
//i++;
   	}
	//cout << blah <<endl;
	// cout << row[1] <<endl;
	// cout << row[2] <<endl;
	// cout << row[3] <<endl;
	// row = mysql_fetch_row(result);
	// 	cout << row[0] <<endl;
	// cout << row[1] <<endl;
	// cout << row[2] <<endl;
	// cout << row[3] <<endl;
	return blah;
}


int main()
{
	Trial myTrial;
	Pulse myPulse;
	Nodes myNodes;
	Weather myWeather;
	Target myTarget;

	// // Ask user for next filename to load
	// char query[50];
	// cout << "Enter next filename to load: " << endl;
	// cin >> query;

	//char filename[50];
	// strcpy(filename,query);

	// check file format - to be added back later, when filename finalised
	/*char firstchar = filename[0];
	if (firstchar != 'e')
	{
		printf("\nFilename is in wrong format!\n\n");
		return(1);
	}*/



	string sfilename/* = filename*/;	

	if (InitStructs(&myTrial, &myPulse, &myNodes, &myWeather, &myTarget))
	{
    	cout<<"Initialised structs." << endl;
	}
	else
	{
      	cout << "Could not initialise structs!"<< endl;
      	return 1;
   	}

	if (ReadFile(sfilename, &myTrial, &myPulse, &myNodes, &myWeather, &myTarget))
   	{
      	cout << "Successfully read file: " << sfilename << endl;
	}
	else
   	{
      	cout<<"Could not read file: " << sfilename << " !"<<endl;
      	return 1;
   	}

	Connect();

	cout << DbAction(meep)<<endl;

	//cout <<  << endl;

	//cout << "Name: " << sfilename << endl;
	if (SaveToDatabase(&myTrial, &myPulse, &myNodes, &myWeather, &myTarget, sfilename))
	{
      	cout << "Saved data to database."<< endl;
	}
	else
   	{
      	cout << "Could not save data to database!"<< endl;
      	return 1;
   	}
	
	cout << endl << "Completed program!" << endl << endl;

	return 0;
}
