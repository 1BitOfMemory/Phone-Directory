#pragma once

#include <string>
#include <ctime>
#include "Log.h"

std::fstream directory;

struct Entry
{
	int id;
	std::string name, number, description;
};

Entry toAdd[10];

  /***************************************************************************************************\
 /  This function will get the contact info from the user. The information is stored in Phonebook.raf. \
/   A random Id will  be assigned to the name which will be saved in Phonebook.raf. This is so that the \ 
\   contact information can be sorted by ID and searched by name.				    				    /
 \ 																									   /
  \***************************************************************************************************/
void addEntry()
{
	srand(time(0));
	Entry newEntry;
	std::fstream list, directory;

	//Get contact name, check for empty name
	std::cout << "Enter the name of the contact: ";
		std::cin >> newEntry.name;

		while (newEntry.name.length() == 0)
		{
			std::cout << "Invalid: Enter the name of the contact: ";
				std::cin >> newEntry.name;
		}

		newEntry.id = rand();

	//Get phone number in format of number, area-code+number, or digit+area-code+number
	std::cout << "Enter the phone number (No dashes, spaces, periods, etc): ";
		std::cin >> newEntry.number;

		while (newEntry.number.length() != 7 && newEntry.number.length() != 10 && newEntry.number.length() != 11 )
		{
			std::cout << "Invalid: Enter the phone number (No dashes, spaces, periods, etc): ";
				std::cin >> newEntry.number;
		}

		std::cout << "Enter a description (single word): ";
		std::cin >> newEntry.description;
		
		//Add new entry into Phonebook file
		directory.open("Phonebook.raf", std::ios::app | std::ios::binary);
	
	directory.seekp(std::ios::end); //Point to end of file
	directory.write((char*)&newEntry, sizeof(newEntry)); //Write to end of raf file
	directory.close();
}