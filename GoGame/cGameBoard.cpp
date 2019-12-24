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

ColourStatus cGameBoard::GetPositionStatus(cCoordinates Coordinates)
{
	return (Playfield[Coordinates.x][Coordinates.y]).Status;
}

std::vector<std::vector<cPoint>> cGameBoard::GetPlayfield()
{
	return Playfield;
}


void cGameBoard::PlacePiece(ColourStatus PlayerColour, cCoordinates Coordinates)
{
	Playfield[Coordinates.x][Coordinates.y].Status = PlayerColour;
}
