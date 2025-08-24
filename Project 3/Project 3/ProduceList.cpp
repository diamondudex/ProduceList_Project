#include "ProduceList.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// populates itemList and creats populates the map with each time an item shows up on the list
void ProduceList::CreateLists(vector<string>& itemList, map<string, int>& produceList)
{
	ifstream File;
	string line;

	File.open("Project 3 Input File.txt");

	// if file is not open after opening it
	if (!File.is_open())
	{
		cout << "Error: File Could Not Be Opened, Shutting Program Down!!" << endl;
	}
	else
	{
		// while not eof, also gets the current line of the file
		while (getline(File, line))
		{
			itemList.push_back(line);
			produceList.emplace(line, 0);
		}

		cout << "Item list created." << endl;

	}

	File.close();

	// loops through newly created list and adds 1 to which key the itemlist string index corresponds to
	for (int i = 0; i < itemList.size(); ++i)
	{
		produceList[itemList.at(i)] += 1;
	}

	cout << "Total produce list created." << endl;


}
// the main loop of the program, where the program will keep asking the user for input until they exit the program by pressing 4
void ProduceList::InputLoop()
{
	CreateLists(itemList, produceList);
	
	
	string input;
	int inputNum = 0;

	PrintInputPrompt();
	cin >> input;

	while (inputNum != 4)
	{
		
		inputNum = stoi(input);

		switch(inputNum)
		{
			case 1:
			{
				SearchList(itemList, produceList);
				break;
			}

			case 2:
			{
				PrintMap(itemList, produceList);
				break;
			}

			case 3:
			{
				SpecialList(itemList, produceList);
				break;
			}

		}

		if (inputNum == 4)
		{
			SaveList();
			break;
		}

		PrintInputPrompt();
		cin >> input;
	}


}

void ProduceList::SearchList(vector<string>& itemList, map<string, int>& produceList)
{
	string input;
	
	cout << "Which item would you like to see the amount of?" << endl;
	cin >> input;

	if (produceList.count(input) == 1)
	{
		cout << produceList[input] << endl;
	}
	else
	{
		cout << "Error: could not find the item inputed by user." << endl;
	}
}

void ProduceList::PrintMap(vector<string>& itemList, map<string, int>& produceList)
{
	for (const auto& pair : produceList)
	{
		cout << pair.first << " " << pair.second << endl;
	}

	
}

void ProduceList::SpecialList(vector<string>& itemList, map<string, int>& produceList)
{
	// string that holds the special characters for each item representing the amount of items  
	string specialChars;

	for (const auto& pair : produceList)
	{
		for (int i = 0; i < pair.second; ++i)
		{
			specialChars += "$";
		}


		cout << pair.first << " " << specialChars << endl;

		specialChars.clear();
	}
	
}

void ProduceList::PrintInputPrompt()
{
	cout << endl;
	cout << "What option would you like to select? (1-4)" << endl;
	cout << "1. Search the list to find how many of a particular item there are?" << endl;
	cout << "2. Show the whole list of items and how many there are?" << endl;
	cout << "3. Show a special list of the items with special characters representing the amount?" << endl;
	cout << "4. Quit the Program?" << endl;
}

void ProduceList::SaveList()
{
	ofstream File("Frequency.dat");

	if (!File.is_open())
	{
		cout << "Error: File Could Not Be Opened" << endl;
	}
	else
	{
		string tempItem;
		int tempVal;

		cout << "Opened frequency.dat!!" << endl;
		for (const auto& pair : produceList)
		{
			tempItem = pair.first;
			tempVal = pair.second;

			File << tempItem << " " << tempVal << endl;
		}

		
	}

	File.close();
}
