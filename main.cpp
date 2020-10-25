#include "linkedList.h"
#include "functions.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>


/*
Eric Alvarez
Linked list implementation
TODO - Add Google Test unit testing
     - Apply parralel programming concepts
*/

int main()
{
	//std::cout << "no seg fault" << std::endl; // --------------------------
	player players[100];
	int pCount = 0, listLen = 30;
	linkedList list;

	//initialize files for read/write
	std::fstream cmds, pfs;
	cmds.open("commands.csv"); // file containing commands
	if (!cmds) std::cout << "Error opening file" << std::endl;
	pfs.open("profiles.csv"); // file containing past profiles
	if (!pfs) std::cout << "Error opening file" << std::endl;
	
	//read in command description pairs from csv file
	std::string cmd, des;
	while (true)
	{
		std::getline(cmds, cmd, ',');
		std::getline(cmds, des);
		list.push(new node<std::string, std::string>(cmd, des)); // add newly allocated node to list
		list.incLength(); //increment list size
		if (cmds.eof()) break;
	}

	srand(time(NULL)); // initialize random seed

	int check = 0, opt;
	player* foundPlayer;
	//main loop
	while (check == 0)
	{
		opt = display(); //reads in menu choice from user
		switch (opt)
		{
		case 1:
			//print rules
			std::cout << "The objective of the game is to match Linux commands to appropriate descriptions of those commands. If a command\nis matched, then you earn 1 point. If the command is not matched, then you lose a point.\nNegative point totals are possible.\nYou may choose the ammount of questions you would like to answer.\n";
			break;
		case 2:
			initPlayerForGame(&players[pCount]);
			playGame(&list, &players[pCount]);
			std::cout << "Current player history:" << std::endl;
			pCount++;
			for (int i = 0; i < pCount; i++)
				std::cout << "Name: " << players[i].getName() << std::endl << "Score: " << players[i].getPoints() << std::endl << std::endl;
			break;
		case 3:
			foundPlayer = findPlayerForgame(players, pCount);
			if (foundPlayer) playGame(&list, foundPlayer);
			else std::cout << "Player not found..." << std::endl;
			break;
		case 4:
			list.addCom();
			list.incLength();
			break;
		case 5:
			list.removeCom();
			list.decLength();
			break;
		case 6:
			check = 1;
			break;
		}
	}

	//write data to files
	list.writeCmdsToFile();

	//close files
	cmds.close();
	pfs.close();

	return 0;
}