#include "stdafx.h"
#include "Hash.h"

//constants
const entry_val ONE = 1;
const entry_val TWO = 2;

// Function Name: continueInput()
// Purpose:	  check that input from user is valid
// Parameters: none
// Returns:	  int
// Pre-conditions: none	
// Post-conditions: none
int continueInput()
{
	int input;
	std::cin >> input;
	while (std::cin.fail() || input > TWO || input < ONE)//if failed, not number
	{
		std::cin.clear();
		std::cin.ignore();
		cout << "\nError... Incorrect input!" << "\nLoad new file? 1 = Yes 2 = No : ";
		std::cin >> input;
	}
	return input;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Hash hash;
	ifstream iFile;
	entry_val data;
	int continue_in;
	bool isOpen = false;
	bool isContinue = true;
	std::cout << "Grant Sowards" << "\nCS 2420" << "\nProject 5 Hashing" << endl;
	
	while (isContinue)
	{
		std::cout << "\nEnter file name (include extension), e.g. numbers.txt: " << endl;
		while (!isOpen)
		{
			string cinName;
			cin >> cinName;
			string fileName = cinName;
			iFile.open(fileName);
			if (iFile.is_open())
			{
				isOpen = true;
				std::cout << "\nOpening File..." << endl;
			}
			else
			{
				cin.clear();
				std::cout << "Could not open file!" << "\n\nTry Again: ";
			}

		}
		cout << "\n------------------Insertion Updates-------------";
		while (!iFile.eof()) //read in file
		{
			iFile >> data;
			hash.insert(data);
		}
		cout << "\n-------------------Traverse Array---------------";
		hash.traverseHash();
		iFile.close();
		hash.clear();//clear hash table
		cout << "\n\nItems Cleared...";
		cout << "\nLoad a new file? 1 = Yes 2 = No: ";
		continue_in = continueInput();//check for continuation
		if (continue_in == ONE)
		{
			isContinue = true;
			isOpen = false;
		}
		else if (continue_in == TWO)
		{
			isContinue = false;
		}

	}
	cout << "\nExiting...";

	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
	return 0;
}

