// GoGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "cGameBoard.h"
#include "cPlayer.h"
#include "cGameplay.h"


using namespace std;


void PrintGame(cGameBoard);
char ConvertPostitionStatusToChar(ColourStatus);
cCoordinates AskTurnPosition(cPlayer);



int main()
{
	cGameBoard* game = new cGameBoard;
	cGameplay Gameplay;
	
	cPlayer Player1 = { White,0 };
	cPlayer Player2 = { Black,0 };

	Gameplay.MakeMove(Player1, cCoordinates{ 10,10 }, game);
	Gameplay.MakeMove(Player2, cCoordinates{ 11,10 }, game);
	Gameplay.MakeMove(Player2, cCoordinates{ 10,9 }, game);
	Gameplay.MakeMove(Player2, cCoordinates{ 10,11 }, game);
	PrintGame(*game);
	while (1) {
		
		
		while(1) {
			cCoordinates Move;
			Move = AskTurnPosition(Player1);
			if (Gameplay.bIsValidMove(Move, Player1, game->GetPlayfield())) {
				break;
			}
			else {
				cout << "Move Invalid\n\n";
			}
		}

		Gameplay.MakeMove(Player1, AskTurnPosition(Player1), game);
		PrintGame(*game);

		while (1) {
			cCoordinates Move;
			Move = AskTurnPosition(Player2);
			if (Gameplay.bIsValidMove(Move, Player2, game->GetPlayfield())) {
				break;
			}
			else {
				cout << "Move Invalid\n\n";
			}
		}

		Gameplay.MakeMove(Player2, AskTurnPosition(Player2), game);
		PrintGame(*game);
	}
	

}


void PrintGame(cGameBoard game) {
	//x axis numbering
	cout << "    ";
	for (int i = 0; i < 19; i++) {

		if (i + 1 < 10) {
			cout << i + 1 << " ";
		}
		else {
			cout << i - 9 << " ";
		}
	}
	cout << endl;

	for (int y = 0; y < 19; y++) {
		
		//y axis numbering
		if (y + 1 < 10) {
			cout << "  " << y + 1 << " ";
		}
		else {
			cout << " " << y + 1 << " ";
		}

		//print game board line
		for (int x = 0; x < 19; x++) {

			cCoordinates* Coordinates = new cCoordinates{ x,y };
			cout << ConvertPostitionStatusToChar(game.GetPositionStatus(*Coordinates))<<" ";
			delete Coordinates;
		}
		cout << endl;
	}
	
}

char ConvertPostitionStatusToChar(ColourStatus ps) {
	switch (ps) {
	case Blank: 
	{
		return'#';
	}
	case White:
	{
		return 'w';
	}
	case Black:
	{
		return 'b';
	}
	default:
	{
		cout << "Error in ConvertPositionToChar";
		return NULL;
	}
	}
}

cCoordinates AskTurnPosition(cPlayer Player)
{
	if (Player.PlayerColour == Black) {
		cout << "Black";
	} 
	
	if (Player.PlayerColour == White) {
		cout << "White";
	}

	cout << "s turn\n";

	cCoordinates Coordinates;
	cout << "Enter x coordinate\n";
	cin >> Coordinates.x;
	(Coordinates.x) -= 1;

	cout << "Enter y coordinate\n";
	cin >> Coordinates.y;
	(Coordinates.y) -= 1;
	return Coordinates;
}


