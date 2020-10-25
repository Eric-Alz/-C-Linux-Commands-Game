#include "player.h"

//constructors
player::player() // O(1)
{
	points = 0;
	name = "---";
}

player::player(std::string str) // O(1)
{
	points = 0;
	name = str;
}

//getters/setters
int player::getPoints() { return points; } // O(1)
void player::setName(std::string name1) { name = name1; } // O(1)
std::string player::getName() { return name; } // O(1)

//class functions
void player::addPoint() { points++; } // O(1)
void player::subPoint() { points--; } // O(1)