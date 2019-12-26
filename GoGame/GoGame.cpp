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
void TakeTurn(cPlayer); //not currently used
cCoordinates AskTurnPosition(cPlayer);



int main()
{
	cGameBoard* game = new cGameBoard;
	cGameplay Gameplay;
	PrintGame(*game);
	cPlayer Player1 = { White,0 };
	cPlayer Player2 = { Black,0 };


	while (1) {
		Gameplay.MakeMove(Player1,AskTurnPosition(Player1),game);
		PrintGame(*game);
		//Gameplay.MakeMove(Player2, AskTurnPosition(Player2), game);
		//PrintGame(*game);
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

void TakeTurn(cPlayer) 
{
	
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


