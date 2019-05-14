//cheese is marked with a number 5
#include "pch.h"
#include <iostream>
#include <array>
#include <list>
#include <vector>

using namespace std;

const int rowSize = 4;
const int columnSize = 5;

const int maze[rowSize][columnSize] = {
	{1, 0, 1, 1, 0},
	{1, 1, 0, 0, 1},
	{1, 1, 1, 0, 0},
	{0, 0, 1, 5, 1} 
};

pair<int, int> findCheese(int **mazePtr)
{
	for(int rCount = 0; rCount < rowSize; rCount++)
		for (int cCount = 0; cCount < columnSize; cCount++)
		{
			if (mazePtr[rCount][cCount] == 5)
				return { rCount,cCount };
		}

	return{ -1,-1 };
}

void allValidMovements( int **mazePtr, const vector<pair<int,int>> &totalMoves, list<pair<int,int>> &validMoves, int &X, int &Y)
{
	if (X + totalMoves[0].first >= 0 && mazePtr[X + totalMoves[0].first][Y] == 1)
		validMoves.push_back({ X + totalMoves[0].first, Y + totalMoves[0].second });

	if (X + totalMoves[1].first <= rowSize && mazePtr[X + totalMoves[1].first][Y] == 1)
		validMoves.push_back({ X + totalMoves[1].first, Y + totalMoves[1].second });

	if (Y + totalMoves[2].second >= 0 && mazePtr[X][Y + totalMoves[2].second] == 1)
		validMoves.push_back({ X + totalMoves[2].first, Y + totalMoves[2].second });

	if (Y + totalMoves[3].second <= columnSize && mazePtr[X][Y + totalMoves[3].second] == 1)
		validMoves.push_back({ X + totalMoves[3].first, Y + totalMoves[3].second });	
}

int main()
{
	int X = 1, Y = 1;
	pair<int, int> cheeseLocation = {0, 0};
	const vector<pair<int, int>> totalMoves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	list<pair<int, int>> validMoves;
	
	list<pair<int,int>> visited;
	//intialize to starting position
	visited.push_back({ 0, 0 });
	pair<int, int> nextMove = {};

	int **mazePtr = new int *[rowSize];

	for (int count = 0; count < rowSize; count++)
	{
		mazePtr[count] = new int [columnSize];
		for (int colCount = 0; colCount < columnSize; colCount++)
			mazePtr[count][colCount] = maze[count][colCount];
	}
	
	//find cheese location first
	cheeseLocation = findCheese(mazePtr);
	
	
	allValidMovements(mazePtr, totalMoves, validMoves, X, Y);	
		




	for (int count = 0; count < rowSize; count++)
	{
		delete[] mazePtr[count];
	}

	delete[] mazePtr;
}


