#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "EntryManip.h"
#include "Log.h";

	/***************************************************************************************************\
   /  This function will get the contact info import.txt. The information is stored in Phonebook.raf.    \
  /   A random Id will  be assigned to the name which will be saved in Phonebook.raf. All descriptions    \
  \   will set set to "NA".																				  /
   \  																									 /
    \***************************************************************************************************/
void massImport()
{
	srand(0);

	Entry newEntry;
	std::ofstream addContacts;
	std::ifstream imp;
	newEntry.description = "NA";
	
	imp.open("import.txt");
	addContacts.open("Phonebook.raf", std::ios::app | std::ios::binary);

	if (!imp)
	{
		std::cout << "Error: import.txt not found\n";
		system("pause");
		exit(0);
	}

	while (!imp.eof())
	{
		newEntry.id = rand();
		imp >> newEntry.name;
		imp >> newEntry.number;

		addContacts.seekp(std::ios::end); //Point to end of file
		addContacts.write((char*)&newEntry, sizeof(newEntry)); //Write to end of raf file
		
		if (imp.fail()) break;
	}

	imp.close();
	addContacts.close();
}