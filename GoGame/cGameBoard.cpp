#include "pch.h"
#include "cGameBoard.h"



cGameBoard::cGameBoard()
{
	//set all positions blank
	for (int i = 0; i < 19; i++) {
		for (int c = 0; c < 19; c++) {
			Playfield[i].insert(std::pair<int, ColourStatus>(c, Blank));
		}
	}
}


cGameBoard::~cGameBoard()
{
}

ColourStatus cGameBoard::GetPositionStatus(cCoordinates Coordinates)
{
	return (Playfield[Coordinates.y]).at(Coordinates.x);
}

void cGameBoard::PlacePiece(ColourStatus PlayerColour, cCoordinates Coordinates)
{
	(Playfield[Coordinates.y]).at(Coordinates.x) = PlayerColour;
}
