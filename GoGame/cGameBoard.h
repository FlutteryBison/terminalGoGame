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

///roup number used to be group.size. if errors check this has been changed everywhere
struct cGroup {
	int GroupNumber;
	std::vector<cCoordinates> PointsInGroup;
	int Liberties;
};



class cGameBoard
{
public:
	cGameBoard();
	~cGameBoard();

	ColourStatus GetPositionStatus(cCoordinates) const;
	std::vector<std::vector<cPoint>> GetPlayfield() const;

	void PlacePiece(ColourStatus, cCoordinates);
	void AddToNewGroup(cCoordinates);
	void AddToExistingGroup(cCoordinates, cGroup &GroupToAddTo);


	//DEBUG FUNCTIONS
	void PrintGroup(cGroup);

private:
	//map for each row. each row contains 19 places
	//std::map <int, ColourStatus> Playfield[19];
	std::vector<std::vector<cPoint>> Playfield; //TODO Change from vector of vectors to vector of class group.group contains coordinates vector and group number
	std::vector<cGroup> Groups;


	//private functions
	void UpdatePlayFieldPointsGroups(cGroup);

};

