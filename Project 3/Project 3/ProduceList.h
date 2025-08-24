#pragma once

#include <vector>
#include <string>
#include <map>

using namespace std;

class ProduceList
{
	public:
		void CreateLists(vector<string> &itemList, map<string, int> &produceList);
		void InputLoop();
		void SearchList(vector<string>& itemList, map<string, int>& produceList);
		void PrintMap(vector<string>& itemList, map<string, int>& produceList);
		void SpecialList(vector<string>& itemList, map<string, int>& produceList);
		void PrintInputPrompt();
		void SaveList();

	private:
		vector<string> itemList;
		map<string, int> produceList;
};

