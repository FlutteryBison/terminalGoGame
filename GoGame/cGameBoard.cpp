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
	return Playfield.at(Coordinates.y).at(Coordinates.x).Status;
}

std::vector<std::vector<cPoint>> cGameBoard::GetPlayfield() const 
{
	return Playfield;
}

cPoint cGameBoard::GetPoint(cCoordinates PointCoordinates) const
{
	return Playfield.at(PointCoordinates.y).at(PointCoordinates.x);
}
cPoint cGameBoard::GetPoint(cCoordinates RelativePoint, int X_Transform, int Y_Transform) const
{
	return (Playfield.at(RelativePoint.y + Y_Transform)).at(RelativePoint.x + X_Transform);
}


void cGameBoard::PlacePiece(ColourStatus PlayerColour, cCoordinates Coordinates)
{
	Playfield.at(Coordinates.y).at(Coordinates.x).Status = PlayerColour;
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

void cGameBoard::AddToExistingGroup(cCoordinates PlayedPoint, cCoordinates AdjacentPiece)
{
	int AdjecentPieceGroupNumber = (Playfield.at(AdjacentPiece.y)).at(AdjacentPiece.x).Group;
	(Playfield.at(PlayedPoint.y)).at(PlayedPoint.x).Group = AdjecentPieceGroupNumber;

	//search for index in groups, adds point to found group index
	Groups.at(SearchGroupIndexInGroups(AdjecentPieceGroupNumber)).PointsInGroup.push_back(PlayedPoint);
	PrintGroup(Groups.at(SearchGroupIndexInGroups(AdjecentPieceGroupNumber)));
}

void cGameBoard::ConnectGroups(cCoordinates Coordinates1, cCoordinates Coordinates2)
{
	int GroupNumber1 = GetPoint(Coordinates1).Group;
	int GroupNumber2 = GetPoint(Coordinates2).Group;
	int GroupIndex1 = SearchGroupIndexInGroups(GroupNumber1);
	int GroupIndex2 = SearchGroupIndexInGroups(GroupNumber2);
	
	Groups.at(GroupIndex1).PointsInGroup.insert(
		Groups.at(GroupIndex1).PointsInGroup.end(), ///where to start inserting
		Groups.at(GroupIndex2).PointsInGroup.begin(), ///where to start inserting from
		Groups.at(GroupIndex2).PointsInGroup.end()); ///where to finish inserting from

	Groups.erase(Groups.begin() + GroupIndex2);
	PrintGroup(Groups.at(GroupIndex1));
}



///Private Functions
void cGameBoard::UpdatePlayFieldPointsGroups(cGroup Group)
{
	for (int i = 0; i < Group.PointsInGroup.size(); i++) {
		(Playfield.at(Group.PointsInGroup.at(i).y)).at(Group.PointsInGroup.at(i).x).Group = Group.GroupNumber;
	}
}

int cGameBoard::SearchGroupIndexInGroups(int GroupNumber)
{
	for (int i = 0; i < Groups.size(); ++i) {
		if (Groups.at(i).GroupNumber == GroupNumber) {
			return i;
		}
	}
}



///DEBUG FUNCTION ONLY
void cGameBoard::PrintGroup(cGroup Group)
{
	std::cout << "points in group " << Group.GroupNumber << ":\n";
	for (int i = 0; i < Group.PointsInGroup.size(); i++) {
		std::cout << "(" << Group.PointsInGroup.at(i).x << "," << Group.PointsInGroup.at(i).y << ")\n";
	}
	std::cout << std::endl;
}