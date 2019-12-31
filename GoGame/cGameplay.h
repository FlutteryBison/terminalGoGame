#pragma once
#include "cPlayer.h"
#include "cCoordinates.h"
#include "cGameBoard.h"


class cGameplay
{
public:
	cGameplay();
	~cGameplay();

	//friend class cGameBoard;

	void MakeMove(cPlayer, cCoordinates, cGameBoard*);
	bool bIsValidMove(cCoordinates, cPlayer); ///TODO impliment bIsValidMove

private:
	bool bIsCaptured(cGameBoard*, cGroup);
	bool bIsCaptured(cGameBoard*, int);
	bool bIsOnBoard(cCoordinates);


};