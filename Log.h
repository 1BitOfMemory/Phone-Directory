#ifndef Log_H
#define Log_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

	/*********************************************************************
	*To get current day and time, the code was taken from           	 *
	*https://www.geeksforgeeks.org/c-program-print-current-day-date-time/*
	*********************************************************************/

void Log(const char* toLog)
{
	time_t time;
	struct tm * ti;
	std::time(&time);
	ti = localtime(&time);
	
	std::fstream Log;
	Log.open("Log.txt", std::ios::app);
	Log << asctime(ti) << toLog << "\n*****************************\n";
	Log.close();
}

void Log(const std::string& toLog)
{
	time_t time;
	struct tm * ti;
	std::time(&time);
	ti = localtime(&time);

	std::fstream Log;
	Log.open("Log.txt", std::fstream::app);
	Log << asctime(ti) << toLog << "\n*****************************\n";
	Log.close();
}

void Log(const int toLog)
{
	time_t time;
	struct tm * ti;
	std::time(&time);
	ti = localtime(&time);

	std::fstream Log;
	Log.open("Log.txt", std::fstream::app);
	Log << "*****************************\n" << asctime(ti) << toLog << "\n";
	Log.close();
}

void Log(const std::string& toLog_string, const int toLog)
{
	time_t time;
	struct tm * ti;
	std::time(&time);
	ti = localtime(&time);

	std::fstream Log;
	Log.open("Log.txt", std::fstream::app);
	Log << asctime(ti) << toLog_string << toLog << "\n*****************************\n";
	Log.close();
}

//**************************WARNING******************************//
//Calling this functions will erase all contents of the log!!	//
void clearLog()												   //
{															  //
	std::fstream Log;										 //
	Log.open("Log.txt", std::ios::out);						//
	Log << "";											   //
}														  //
//*******************************************************//

#endif