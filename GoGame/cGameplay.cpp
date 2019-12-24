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
		//check adjacent pieces
	bool bIsInGroup = false;
	if (GameBoard->GetPlayfield().at(MoveCoordinates.x + 1).at(MoveCoordinates.y).Status == Player.PlayerColour) {
		std::cout << "Friendly piece at (" << MoveCoordinates.x + 1 << "," << MoveCoordinates.y << ")\n";
		GameBoard->GetPlayfield().at(MoveCoordinates.x).at(MoveCoordinates.y).Group = GameBoard->GetPlayfield().at(MoveCoordinates.x + 1).at(MoveCoordinates.y).Group;
		bIsInGroup = true;
	}
	if (GameBoard->GetPlayfield().at(MoveCoordinates.x).at(MoveCoordinates.y + 1).Status == Player.PlayerColour) {
		std::cout << "Friendly piece at (" << MoveCoordinates.x << "," << MoveCoordinates.y+1 << ")\n";
		bIsInGroup = true;
	}
	if (GameBoard->GetPlayfield().at(MoveCoordinates.x - 1).at(MoveCoordinates.y).Status == Player.PlayerColour) {
		std::cout << "Friendly piece at (" << MoveCoordinates.x - 1 << "," << MoveCoordinates.y << ")\n";
		bIsInGroup = true;
	}
	if (GameBoard->GetPlayfield().at(MoveCoordinates.x).at(MoveCoordinates.y - 1).Status == Player.PlayerColour) {
		std::cout << "Friendly piece at (" << MoveCoordinates.x << "," << MoveCoordinates.y-1 << ")\n";
		bIsInGroup = true;
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
