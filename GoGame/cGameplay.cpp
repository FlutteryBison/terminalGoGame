#include "pch.h"
#include "cGameplay.h"
#include <iostream> //temp for make move


cGameplay::cGameplay()
{
}


cGameplay::~cGameplay()
{
}

void cGameplay::MakeMove(cPlayer Player, cCoordinates MoveCoordinates, cGameBoard* GameBoard)
{
	
	//check placement validity

	//place piece
	GameBoard->PlacePiece(Player.PlayerColour, MoveCoordinates);

	//check group
		//check edge
	if (MoveCoordinates.x == 0 ||
		MoveCoordinates.y == 0 ||
		MoveCoordinates.x == 18 ||
		MoveCoordinates.y == 18) 
	{

	}
		//check adjacent pieces and add to group
	bool bIsInGroup = false;

	///TODO refactor
	bool bTempif = (GameBoard->GetPoint(MoveCoordinates, 1, 0).Status == Player.PlayerColour);
	int tempplayercolour = (GameBoard->GetPoint(MoveCoordinates, 1, 0).Status);
	if (GameBoard->GetPoint(MoveCoordinates, 1, 0).Status == Player.PlayerColour) {
		std::cout << "1Friendly piece at (" << MoveCoordinates.x + 1 << "," << MoveCoordinates.y << ")\n";
		GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x + 1 ,MoveCoordinates.y });
		bIsInGroup = true;
	}
	if (GameBoard->GetPoint(MoveCoordinates, 0, 1).Status == Player.PlayerColour) {
		std::cout << "2Friendly piece at (" << MoveCoordinates.x << "," << MoveCoordinates.y + 1 << ")\n";
		if (bIsInGroup) {
			GameBoard->ConnectGroups(MoveCoordinates, cCoordinates{ MoveCoordinates.x,MoveCoordinates.y + 1 });
		}

		else {
			GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x ,MoveCoordinates.y + 1 });
			bIsInGroup = true;
		}
	}
	if (GameBoard->GetPoint(MoveCoordinates, -1, 0).Status == Player.PlayerColour) {
		std::cout << "3Friendly piece at (" << MoveCoordinates.x - 1 << "," << MoveCoordinates.y << ")\n";
		if (bIsInGroup) {

		}

		else {
			GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x - 1 ,MoveCoordinates.y });
			bIsInGroup = true;
		}
	}
	if (GameBoard->GetPoint(MoveCoordinates, 0, -1).Status == Player.PlayerColour) {
		std::cout << "4Friendly piece at (" << MoveCoordinates.x << "," << MoveCoordinates.y - 1 << ")\n";
		if (bIsInGroup) {

		}

		else {
			GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x ,MoveCoordinates.y - 1 });
			bIsInGroup = true;
		}
	}

	//if not in group make new group
	if (!bIsInGroup) {
		GameBoard->AddToNewGroup(MoveCoordinates);
	}

	
		//combine groups if applicable
		//set group on playfield
	
	//check for capture

	//remove captured pieces and update player score
}
