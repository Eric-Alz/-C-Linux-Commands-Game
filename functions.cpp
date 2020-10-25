#include "player.h"
#include "functions.h"
#include "linkedList.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <fstream>
#include <limits>

int display() // O(1)
{
	int opt;
	std::cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n";
	std::cin >> opt;
	// keep asking for user input while their input is invalid
	while (std::cin.fail() || opt < 1 || opt > 6) 
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid Input...\n";
		std::cin >> opt;
	}
	return opt;
}

void generateRandArr(int arr[], int minVal, int maxVal, int size) // O(n^2) could achieve O(n) using a hash table to store values already generated 
{
	if (size > abs(maxVal - minVal + 1)) // if range of possible values is less that the size of array
	{
		std::cout << "Cannot generate unique values when range of values is less than the size of array..." << std::endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = (rand() % (maxVal + 1)) + minVal; // maxVal + 1 to include max range value
		while (!isUnique(arr, arr[i], i)) // while the new value is not unique
		{
			arr[i] = (rand() % (maxVal + 1)) + minVal; // update with new value
			std::cout << std::endl;
		}
	}
}

bool isUnique(int* arr, int target, int size) // O(n) 
{
	if (size == 0) return true; // if target is only value in array it must be unique
	for (int i = size - 1; i >= 0; i--) // iterate through all previous indices of array
		if (arr[i] == target) return false; //if value at array index is equal to the target value then target is not unique
	return true;
}

int loadPrevPlayer(player profiles[]) // O(n)
{
	std::string target;
	std::cout << "Enter name of player to load: " << std::endl;
	getline(std::cin >> std::ws, target); //credit to stack overflow for this line

	// iterate through array to find target
	for (int i = 0; i < sizeof(*profiles)/sizeof(profiles[0]); i++)
		if (profiles[i].getName() == target) return i;
	
	// return invalid index if player is not found
	std::cout << "Player not found..." << std::endl;
	return -1;
}

void writePfsToFile(player pfs[], int pCount) // O(n)
{
	//open file
	std::ofstream file;
	file.open("profiles.csv");

	//write profiles to file
	for (int i = 0; i < pCount; i++)
	{
		file << pfs[i].getName() << "," << pfs[i].getPoints();
		if (i != pCount - 1) file << "\n";
	}
	file.close();
}

player* findPlayerForgame(player* players, int playerCount)
{
	std::string name;
	std::cout << "Enter name: " << std::endl;
	getline(std::cin >> std::ws, name);
	for (int i = 0; i < playerCount; i++)
	{
		std::cout << "Previous score: " << players[i].getPoints() << std::endl;
		if (players[i].getName() == name) return &players[i];
	}
	return nullptr;
}

void initPlayerForGame(player* currPlayer)
{
	std::string name;
	std::cout << "Enter name: " << std::endl;
	getline(std::cin >> std::ws, name);
	currPlayer->setName(name);
}

void playGame(linkedList* list, player* currPlayer)
{
	//play game
	//initialize variables
	std::string qChoices[3], name;
	int check = 0, correctAnsw, userAnsw, randDescIndices[3], randValues[3];

	// prompt for number of questions user wants to answer
	int numQ;
	std::cout << "Enter number of questions you would like to answer: " << std::endl;
	std::cin >> numQ; //assuming user enters an integer >= 0

	//ask the user amount of questions they requested
	while (numQ > 0)
	{
		std::string qCommand;

		generateRandArr(randDescIndices, 0, list->getLength(), 3);
		qCommand = list->getListComFromIndex(randDescIndices[0]); // qCommand will be the command displayed for the question

		//populate qChoices with the correct answer and two incorrect ones
		for (int i = 0; i < 3; i++)
		qChoices[i] = list->getListDescFromIndex(randDescIndices[i]);
			
		// populate rands with unique integers ranging from 0 to 1
		generateRandArr(randValues, 0, 2, 3);

		std::cout << "Command: " << qCommand << std::endl; // display command for question

		// printing answer choices for question
		for (int i = 0; i < 3; i++)
		{
			std::cout << i + 1 << ". " << qChoices[randValues[i]] << std::endl;
			if (qChoices[randValues[i]] == qChoices[0]) // if the current command description being printed is the same as the first answer in list...
				correctAnsw = i + 1; // store indext of answer location/option - 1, 2, 3
		}

		std::cin >> userAnsw; // read in user answer

		// check if answer is correct or not
		if (userAnsw == correctAnsw)
		{
			currPlayer->addPoint();
			std::cout << "Correct! You gain a point." << std::endl;
		}
		else
		{
			currPlayer->subPoint();
			std::cout << "Incorrect. You lose a point" << std::endl;
		}
		numQ--;
	}
	std::cout << "Your score: " << currPlayer->getPoints() << std::endl;
}