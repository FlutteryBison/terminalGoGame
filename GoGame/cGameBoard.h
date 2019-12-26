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

///group number used to be group.size. if errors check this has been changed everywhere
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

	cPoint GetPoint(cCoordinates) const;
	cPoint GetPoint(cCoordinates RelativePoint, int X_Transform, int Y_Transform) const; ///TODO find better name for transform

	void PlacePiece(ColourStatus, cCoordinates);
	void AddToNewGroup(cCoordinates);
	void AddToExistingGroup(cCoordinates PlayedPoint , cCoordinates AdjecantPiece);
	void ConnectGroups(cCoordinates,cCoordinates); ///TODO improve parameters


	//DEBUG FUNCTIONS
	void PrintGroup(cGroup);

private:
	//vector of y with vector of inside. for cPoint at (x,y) playfield.at(y).at(x)
	std::vector<std::vector<cPoint>> Playfield;
	std::vector<cGroup> Groups;


	//private functions
	void UpdatePlayFieldPointsGroups(cGroup);
	int SearchGroupIndexInGroups(int GroupNumber);

};

