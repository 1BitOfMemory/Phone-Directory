#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "EntryManip.h"

class BST
{
private:
	struct node
	{
		int id;
		std::string name, number, desc;
		node* left, *right;
	};
	node *root;

public:
	BST()
	{
		root = NULL;
	}

	//Insert x into treebased on id
	void insert(int id, std::string name, std::string number, std::string desc, node*& r)
	{
		if (r == NULL)
		{
			r = new node;
			r->id = id;
			r->name = name;
			r->number = number;
			r->desc = desc;
			r->left = r->right = NULL;
		}
		else
		{
			if (id < r->id)
				insert(id, name, number, desc, r->left);
			if (id > r->id)
				insert(id, name, number, desc, r->right);
		}
	}

	//Search for person based on name
	void searchName(node* r, std::string x)
	{
		
		if (r == NULL) { Log("R is NULL"); std::cout << "This item is not found"; return; }
		else if (r->name == x) { std::cout << x << " has a number of: " << r->number << std::endl; return; }

		else
		{
			Log("R is not NULL");
			if (x < r->name)
				searchName(r->right, x);
			if (x > r->name)
				searchName(r->left, x);
		}
	}

	//Search for person based on name
	void searchId(node* r, int x)
	{
		if (r == NULL) { std::cout << "This item is not found"; return; }
		else if (r->id == x) { std::cout << x << " has a number of: $" << r->number << std::endl; return; }

		else
		{
			if (x < r->id)
				searchId(r->left, x);
			if (x > r->id)
				searchId(r->right, x);
		}
	}

	//Display BST using  inorder traversal: (LC)(P)(RC)
	void displayInorder(node* r)
	{
		if (r != NULL)
		{
			displayInorder(r->left);//(LC)
			std::cout << r->name << "........." << r->number << "\n";//(P)
			displayInorder(r->right);//(RC)
		}
	}

	void insert(int n, std::string x, std::string y, std::string z) { insert(n, x, y, z, root); }
	void searchName(std::string x) { searchName(root, x); }
	void displayInorder() { displayInorder(root); }

}; //End of BST 

  /***************************************************************************************************\
 /  This function searches the binary search tree. It allows the user to search for a specific name	   \
 \ 	and also allows the user to display the full directory in the console.							   /
  \***************************************************************************************************/
void search()
{
	Entry contact;
	BST Name;
	std::string name, number, desc;
	int id, resp;
	char ans = 'y';

	//Load phonebook into BST
	std::fstream list;
	list.open("Phonebook.raf", std::ios::in | std::ios::out | std::ios::binary);
	list.read((char *)&contact, sizeof(contact));
	while (true)
	{
		Name.insert(contact.id, contact.name, contact.number, contact.description);
		list.read((char *)&contact, sizeof(contact));
		if (list.fail()) break;
	}	

	//Display options
		std::cout << "------Phone Directory------" << std::endl;
		std::cout << "1: Search name\n2: Display the full directory\n";

	while (ans == 'y' || ans == 'Y')
	{
		std::cout << "Make a selection: ";
		std::cin >> resp;

		switch (resp)
		{
		case 1:
			//Search for phone number by name
			std::cout << "Enter a name to search for: ";
			std::cin >> name;
			Name.searchName(name);
			break;

		case 2:
			//Dislay the BST
			std::cout << "\nFull Directory\n";
			Name.displayInorder();
			std::cout << std::endl;
			break;
		}

		std::cout << "\nContinue(y/n)? " << std::endl;
		std::cin >> ans;
	}
	exit(0);
}