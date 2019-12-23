#include "pch.h"
#include "cGameBoard.h"



cGameBoard::cGameBoard()
{
	//set all positions blank
	for (int i = 0; i < 19; i++) {
		for (int c = 0; c < 19; c++) {
			Playfield[i].insert(std::pair<int, PositionStatus>(c, Blank));
		}
	}
}


cGameBoard::~cGameBoard()
{
}

PositionStatus cGameBoard::GetPositionStatus(int x, int y)
{
	return (Playfield[y]).at(x);
}

void cGameBoard::PlacePiece(PositionStatus PlayerColour, int x, int y)
{
	(Playfield[y]).at(x) = PlayerColour;
}
