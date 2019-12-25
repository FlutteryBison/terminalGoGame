#pragma once
#include <map>
#include "enumPositionStatus.h"
#include "cCoordinates.h"
#include <vector>
#include <iostream> //for debbug PrintGroup


//TODO initialise status to blank. change cGameBoard consturctor
struct cPoint{
	ColourStatus Status;
	int Group = -1;
};



class cGameBoard
{
public:
	cGameBoard();
	~cGameBoard();

	ColourStatus GetPositionStatus(cCoordinates) const;
	std::vector<std::vector<cPoint>> GetPlayfield() const;

	void PlacePiece(ColourStatus, cCoordinates);
	int AddToNewGroup(cCoordinates);//returns group number
	void AddToExistingGroup(cCoordinates, int GroupNumber);


	//DEBUG FUNCTIONS
	void PrintGroup(int);

private:
	//map for each row. each row contains 19 places
	//std::map <int, ColourStatus> Playfield[19];
	std::vector<std::vector<cPoint>> Playfield; //TODO Change from vector of vectors to vector of class group.group contains coordinates vector and group number
	std::vector<std::vector<cCoordinates>> Groups;


	//private functions
	void UpdatePlayFieldPointsGroups(std::vector<cCoordinates>, int);

};

