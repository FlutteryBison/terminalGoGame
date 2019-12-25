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

void cGameBoard::AddToNewGroup(cCoordinates PlayedPoint)
{
	
	Groups.resize(Groups.size() + 1); //create new group

	if (Groups.size() > 1) {
		Groups.back().GroupNumber = Groups.at(Groups.size() - 2).GroupNumber + 1;//group number is 1 bigger than the last groups number
	}
	else {
		Groups.back().GroupNumber = 0; // if no other groups (first piece) group number = 0
	}


	(Groups.back()).PointsInGroup.push_back(PlayedPoint); //add point to new group

	UpdatePlayFieldPointsGroups(Groups.back()); 

	PrintGroup(Groups.back()); //FOR DEBUG ONLY
}

void cGameBoard::AddToExistingGroup(cCoordinates PlayedPoint, cGroup &GroupToAddTo)
{
	GroupToAddTo.PointsInGroup.push_back(PlayedPoint);
}



void cGameBoard::UpdatePlayFieldPointsGroups(cGroup Group)
{
	for (int i = 0; i < Group.PointsInGroup.size(); i++) {
		(Playfield.at(Group.PointsInGroup.at(i).y)).at(Group.PointsInGroup.at(i).x).Group = Group.GroupNumber;
	}
}


void cGameBoard::PrintGroup(cGroup Group)
{
	std::cout << "points in group " << Group.GroupNumber << ":\n";
	for (int i = 0; i < Group.PointsInGroup.size(); i++) {
		std::cout << "(" << Group.PointsInGroup.at(i).x << "," << Group.PointsInGroup.at(i).y << ")\n";
	}
	std::cout << std::endl;
}