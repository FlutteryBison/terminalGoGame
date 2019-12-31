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

	//Check validity


	//place piece
	GameBoard->PlaceStone(Player.PlayerColour, MoveCoordinates);

	
	

	
	//check adjacent pieces and add to group
	bool bIsInGroup = false;
	cPoint AdjacentPoint;

	///TODO refactor
	if (MoveCoordinates.x + 1 < 19) {
		AdjacentPoint = GameBoard->GetPoint(MoveCoordinates, 1, 0);
		if (AdjacentPoint.Status != Blank) {

			if (AdjacentPoint.Status == Player.PlayerColour) {
				std::cout << "1Friendly piece at (" << MoveCoordinates.x + 1 << "," << MoveCoordinates.y << ")\n";
				GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x + 1 ,MoveCoordinates.y });
				bIsInGroup = true;
			}

			else { ///if adjecent enemy piece

				if (bIsCaptured(GameBoard, AdjacentPoint.Group)) {
					//update score
					Player.score + (GameBoard->GetGroup(AdjacentPoint.Group).PointsInGroup.size());
					//remove pieces
					GameBoard->RemoveStones(GameBoard->GetGroup(AdjacentPoint.Group));
					GameBoard->EraseGroup(GameBoard->GetGroup(AdjacentPoint.Group));

				}
			}

		}
	}


	if (MoveCoordinates.y + 1 < 19) {
		AdjacentPoint = GameBoard->GetPoint(MoveCoordinates, 0, 1);
		if (AdjacentPoint.Status != Blank) {
			if (AdjacentPoint.Status == Player.PlayerColour) {
				std::cout << "2Friendly piece at (" << MoveCoordinates.x << "," << MoveCoordinates.y + 1 << ")\n";
				if (bIsInGroup) {
					GameBoard->ConnectGroups(MoveCoordinates, cCoordinates{ MoveCoordinates.x,MoveCoordinates.y + 1 });
				}

				else {
					GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x ,MoveCoordinates.y + 1 });
					bIsInGroup = true;
				}
			}

			else {
				if (bIsCaptured(GameBoard, AdjacentPoint.Group)) {
					//update score
					Player.score + (GameBoard->GetGroup(AdjacentPoint.Group).PointsInGroup.size());
					//remove pieces
					GameBoard->RemoveStones(GameBoard->GetGroup(AdjacentPoint.Group));
					GameBoard->EraseGroup(GameBoard->GetGroup(AdjacentPoint.Group));
				}
			}
		}
	}



	if (MoveCoordinates.x - 1 >= 0) {
		AdjacentPoint = GameBoard->GetPoint(MoveCoordinates, -1, 0);
		if (AdjacentPoint.Status != Blank) {
			if (AdjacentPoint.Status == Player.PlayerColour) {
				std::cout << "3Friendly piece at (" << MoveCoordinates.x - 1 << "," << MoveCoordinates.y << ")\n";
				if (bIsInGroup) {
					GameBoard->ConnectGroups(MoveCoordinates, cCoordinates{ MoveCoordinates.x - 1,MoveCoordinates.y });
				}

				else {
					GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x - 1 ,MoveCoordinates.y });
					bIsInGroup = true;
				}
			}

			else {
				if (bIsCaptured(GameBoard, AdjacentPoint.Group)) {
					//update score
					Player.score + (GameBoard->GetGroup(AdjacentPoint.Group).PointsInGroup.size());
					//remove pieces
					GameBoard->RemoveStones(GameBoard->GetGroup(AdjacentPoint.Group));
					GameBoard->EraseGroup(GameBoard->GetGroup(AdjacentPoint.Group));
				}
			}
		}
	}


	if (MoveCoordinates.y - 1 >= 0) {
		AdjacentPoint = GameBoard->GetPoint(MoveCoordinates, 0, -1);
		if (AdjacentPoint.Status != Blank) {
			if (AdjacentPoint.Status == Player.PlayerColour) {
				std::cout << "4Friendly piece at (" << MoveCoordinates.x << "," << MoveCoordinates.y - 1 << ")\n";
				if (bIsInGroup) {
					GameBoard->ConnectGroups(MoveCoordinates, cCoordinates{ MoveCoordinates.x,MoveCoordinates.y - 1 });
				}

				else {
					GameBoard->AddToExistingGroup(MoveCoordinates, cCoordinates{ MoveCoordinates.x ,MoveCoordinates.y - 1 });
					bIsInGroup = true;
				}
			}

			else {
				if (bIsCaptured(GameBoard, AdjacentPoint.Group)) {
					//update score
					Player.score + (GameBoard->GetGroup(AdjacentPoint.Group).PointsInGroup.size());
					//remove pieces
					GameBoard->RemoveStones(GameBoard->GetGroup(AdjacentPoint.Group));
					GameBoard->EraseGroup(GameBoard->GetGroup(AdjacentPoint.Group));
				}
			}
		}

	}


	//if not in group make new group
	if (!bIsInGroup) {
		GameBoard->AddToNewGroup(MoveCoordinates);
	}

}

bool cGameplay::bIsValidMove(cCoordinates, cPlayer)
{
	return false;
}



///TODO impliment edge checking
bool cGameplay::bIsCaptured(cGameBoard* GameBoard, cGroup Group )
{
	std::cout << "bIsCaptured Coordinates in Group :\n";
	GameBoard->PrintGroup(Group);
	for (int i = 0; i < Group.PointsInGroup.size(); i++) {
		cCoordinates CurrentPointCoordinates = Group.PointsInGroup.at(i);

		
		if (GameBoard->GetPoint(CurrentPointCoordinates, 1, 0).Status == Blank) {
			return false;
		}


		if (GameBoard->GetPoint(CurrentPointCoordinates, 0, 1).Status == Blank) {
			return false;
		}

		if (GameBoard->GetPoint(CurrentPointCoordinates, -1, 0).Status == Blank) {
			return false;
		}


		if (GameBoard->GetPoint(CurrentPointCoordinates, 0, -1).Status == Blank) {
			return false;
		}

	}

	return true;
}

bool cGameplay::bIsCaptured(cGameBoard *GameBoard, int GroupNumber)
{
	return bIsCaptured(GameBoard, GameBoard->GetGroup(GroupNumber));
}

bool cGameplay::bIsOnBoard(cCoordinates Coordinates)
{
	if (Coordinates.x < 19 && Coordinates.x >= 0 && Coordinates.y < 19 && Coordinates.y >= 0) {
		return true;
	}

	else {
		return false;
	}
}
