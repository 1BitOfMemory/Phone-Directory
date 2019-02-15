#include <iostream>
#include <fstream>
#include "EntryManip.h"
#include "Search.h"
#include "DisplayDirectory.h"
#include "Log.h"
#include "MassImport.h"

int main()
{
	int selection;

	while (true)
	{
		system("cls");
		std::cout << "--------Phone Directory---------\nMake a selection: \n1: Add new entry\n2: Display entire directory\n"
			"3: Search for number\n4. Mass import\n";
		std::cin >> selection;

		switch (selection)
		{
		case 1:
			addEntry();
			Log("New Entry Added");
			break;
		case 2:
			displayDirectory("Phonebook.raf");
			break;
		case 3:
			search();
			break;
		case 4:
			massImport();
			std::cout << "Import was successful!\n";
			Log("Successful import");
			break;
		}
		system("pause");
	}
	return 0;
}