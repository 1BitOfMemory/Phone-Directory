#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "EntryManip.h"
#include "Log.h"

   /***************************************************************************************************\
  /  This function will display every contact in the Phonebook.raf file in the console.			        \				  
  \  																								    /
   \***************************************************************************************************/
void displayDirectory(std::string input)
{
	Entry contact;
	std::fstream directory;
	directory.open(input, std::ios::beg | std::ios::in | std::ios::out | std::ios::binary);
	directory.read((char *)&contact, sizeof(contact));

	while (true)
	{
		std::cout << contact.id << "\t" << contact.name << "\t" << contact.number << "\t" << contact.description << std::endl;
		directory.read((char *)&contact, sizeof(contact));

		if (directory.fail()) break;
	}
	directory.close();
	system("pause");
	exit(0);
}
