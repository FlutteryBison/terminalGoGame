#pragma once
#include <map>

enum PositionStatus : char { Black = 'b', White = 'w', Blank = '#' };

class cGameBoard
{
public:
	cGameBoard();
	~cGameBoard();

	PositionStatus GetPositionStatus(int x, int y);

	void PlacePiece(PositionStatus, int x, int y);

private:
	//map for each row. each row contains 19 places
	std::map <int, PositionStatus> Playfield[19];

};

