#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class player
{
	public:
		//constructors
		player();
		player(std::string str);
		
		//member functions
		void addPoint(); // add point to player score (player.point)
		void subPoint(); // subtract point from player score (player.point)

		//setters/getters
		int getPoints();
		void setName(std::string name1);
		std::string getName();
	private:
		int points; //i.e. score
		std::string name; 
};

#endif