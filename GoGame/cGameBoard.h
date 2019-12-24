#pragma once
#include <map>
#include "enumPositionStatus.h"
#include "cCoordinates.h"
#include <vector>

struct cPoint{
	ColourStatus Status;
	int Group;
};



class cGameBoard
{
public:
	cGameBoard();
	~cGameBoard();

	ColourStatus GetPositionStatus(cCoordinates);
	std::vector<std::vector<cPoint>> GetPlayfield();

	void PlacePiece(ColourStatus, cCoordinates);
	int AddToNewGroup(cCoordinates);//returns group number
	void AddToExistingGroup(cCoordinates, int GroupNumber);

private:
	//map for each row. each row contains 19 places
	//std::map <int, ColourStatus> Playfield[19];
	std::vector<std::vector<cPoint>> Playfield;
	std::vector<cCoordinates> Group;
	std::vector<std::vector<cCoordinates>> Groups;

};

