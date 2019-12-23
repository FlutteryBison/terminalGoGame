// GoGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "cGameBoard.h"

using namespace std;


void PrintGame(cGameBoard);
char ConvertPostitionStatusToChar(PositionStatus);

int main()
{
	cGameBoard game;
	PrintGame(game);
	cout << endl;
	game.PlacePiece(Black, 0, 2);
	PrintGame(game);

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
			cout << ConvertPostitionStatusToChar(game.GetPositionStatus(x, y))<<" ";
		}
		cout << endl;
	}
	
}

char ConvertPostitionStatusToChar(PositionStatus ps) {
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


