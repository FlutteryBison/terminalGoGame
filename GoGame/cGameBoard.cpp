#include "pch.h"
#include "cGameBoard.h"


cGameBoard::cGameBoard()
{
	//set all positions blank
	std::vector<cPoint>* tempvector = new std::vector<cPoint>;
	cPoint* temppoint = new cPoint;

	for (int i = 0; i < 19; i++) {

		
		temppoint->Status = Blank;
		tempvector->push_back(*temppoint);
	}
	for (int i = 0; i < 19; i++) {
		Playfield.push_back(*tempvector);
	}
	delete temppoint;
	delete tempvector;
}


cGameBoard::~cGameBoard()
{
}

ColourStatus cGameBoard::GetPositionStatus(cCoordinates Coordinates) const 
{
	return (Playfield[Coordinates.x][Coordinates.y]).Status;
}

std::vector<std::vector<cPoint>> cGameBoard::GetPlayfield() const 
{
	return Playfield;
}


void cGameBoard::PlacePiece(ColourStatus PlayerColour, cCoordinates Coordinates)
{
	Playfield[Coordinates.x][Coordinates.y].Status = PlayerColour;
}

int cGameBoard::AddToNewGroup(cCoordinates PlayedPoint)
{
	Groups.resize(Groups.size() + 1);
	(Groups.back()).push_back(PlayedPoint);

	UpdatePlayFieldPointsGroups(Groups.back(), Groups.size() - 1);

	return Groups.size()-1;
}

void cGameBoard::UpdatePlayFieldPointsGroups(std::vector<cCoordinates> group, int GroupNumber)
{
	for (int i = 0; i < group.size(); i++) {
		(Playfield.at(group.at(i).y)).at(group.at(i).x).Group = GroupNumber;
	}
}
