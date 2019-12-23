#pragma once
#include <map>
#include "enumPositionStatus.h"
#include "cCoordinates.h"



class cGameBoard
{
public:
	cGameBoard();
	~cGameBoard();

	ColourStatus GetPositionStatus(cCoordinates);

	void PlacePiece(ColourStatus, cCoordinates);

private:
	//map for each row. each row contains 19 places
	std::map <int, ColourStatus> Playfield[19];

};

