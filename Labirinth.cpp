/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>

using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j]=values[i][j];
}


void Labirinth::initializeVisited(int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int a = 0; a < 10; a++)
			visited[i][a] = false;
	visited[y][x] = true;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
			cout << labirinth[i][a] << " ";

		cout << endl;
	}
}
bool Labirinth::searchWall(int x, int y){
	if(labirinth[x][y] == 0){
			return false;
		}
	else
		return true;
}

bool Labirinth::findChoices(int x, int y){
	if(searchWall(x,y+1) && !visited[x][y+1] && searchWall(x,y-1) && !visited[x][y-1]){

		return true;
	}
	if(searchWall(x,y+1) && !visited[x][y+1] && searchWall(x-1,y) && !visited[x-1][y]){

			return true;
		}
	if(searchWall(x,y+1) && !visited[x][y+1] && searchWall(x+1,y) && !visited[x+1][y]){

			return true;
		}
	if(searchWall(x,y-1) && !visited[x][y-1] && searchWall(x-1,y) && !visited[x-1][y]){

			return true;
		}
	if(searchWall(x,y-1) && !visited[x][y-1] && searchWall(x+1,y) && !visited[x+1][y]){

			return true;
		}
	if(searchWall(x-1,y) && !visited[x-1][y] && searchWall(x+1,y) && !visited[x+1][y]){

			return true;
		}
	return false;
}
bool Labirinth::findVictory(int x, int y){
	if(labirinth[x][y-1] == 2){
		return true;
	}
	if(labirinth[x][y+1] == 2){
			return true;
		}
	if(labirinth[x+1][y] == 2){
				return true;
			}
	if(labirinth[x-1][y] == 2){
				return true;
			}
	return false;
}


bool Labirinth::findGoal(int x, int y)
{
	int tempx;
	int tempy;
	tempx =x;
	tempy = y;
	visited[x][y] = true;
	if(findChoices(x,y)){
		choicesx.push_back(x);
		choicesy.push_back(y);
	}

	if(findVictory(x,y)){
		cout << 6 << endl << endl;
		return true;
	}
	else if(searchWall(x,y+1) && !visited[x][y+1]){
		cout << 0 << endl;
		return findGoal(x,y+1);

	}
	else if(searchWall(x,y-1) && !visited[x][y-1]){
		cout << 1 << endl;
		return findGoal(x,y-1);

	}
	else if(searchWall(x-1,y) && !visited[x-1][y]){
		cout << 2 << endl;
			return findGoal(x-1,y);

		}
	else if(searchWall(x+1,y) && !visited[x+1][y]){
		cout << 3 << endl;
			return findGoal(x+1,y);

		}
	else if(!choicesx.empty()){
		cout << 4 << endl;
		tempx = choicesx.back();
		tempy = choicesy.back();
		choicesx.pop_back();
		choicesy.pop_back();
		cout << 5 << endl;
		return findGoal(tempx,tempy);
	}


	return false;
}



