#include "player.h"
#include "linkedList.h"

int display();
void generateRandArr(int* arr, int minVal, int maxVal, int size);
bool isUnique(int* arr, int target, int size);
int loadPrevPlayer(player profiles[]);
void writePfsToFile(player pfs[], int pCount);
player* findPlayerForgame(player* players, int playerCount);
void initPlayerForGame(player* currPlayer);
void playGame(linkedList* list, player* currPlayer);