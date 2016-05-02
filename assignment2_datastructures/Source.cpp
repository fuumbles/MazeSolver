#include "Queue.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <regex>

using namespace std;

Queue Q;

//why am I here?
int random(int low, int high) {
	return rand() % (high - low + 1) + low;
}

void PrintMaze(char** MazeP, int MazeHeight, int MazeWidth)
{
	for (int h = 0; h < MazeHeight; h++)
	{
		for (int w = 0; w < MazeWidth; w++)
		{
			cout << MazeP[h][w];
		}
		cout << endl;
	}

}

void SolveMaze(char** MazeArr, int ExitX, int ExitY, int MazeHeight, int MazeWidth)
{
	int currX = 1;
	int currY = 0;
	char** Visited = new char*[MazeHeight];
	for (int i = 0; i < MazeHeight; i++)
	{
 		Visited[i] = new char[MazeWidth];
	}
	while (currY != MazeArr[ExitX][ExitY] || currX != MazeArr[ExitX][ExitY])
	{		
		if (currY == MazeArr[ExitX][ExitY] && currX == MazeArr[ExitX][ExitY])
			break;
		/*for (int h = 0; h < MazeHeight; h++)
		{
			for (int w = 0; w < MazeWidth; w++)
			{
				cout << MazeArr[h][w];
			}
			cout << endl;
		}*/
		
		//cout << currX << "-" << currY << endl;//testing
		

		// Check North
		if (MazeArr[currX - 1][currY] == ' ' && Visited[currX - 1][currY] != 'X')
		{
			currX--;
			Visited[currX][currY] = 'X';
			MazeArr[currX][currY] = '#';
			Q.InsertRear(currX, currY);
			//continue;
		}
		// Check South
		else if (MazeArr[currX + 1][currY] == ' ' && Visited[currX + 1][currY] != 'X')
		{
			currX++;
			Visited[currX][currY] = 'X';
			MazeArr[currX][currY] = '#';
			Q.InsertRear(currX, currY);
			//continue;
		}
		// Check East
		else if (MazeArr[currX][currY + 1] == ' ' && Visited[currX][currY + 1] != 'X')
		{
			currY++;
			Visited[currX][currY] = 'X';
			MazeArr[currX][currY] = '#';
			Q.InsertRear(currX, currY);
			//continue;
		}
		// Check West
		else if (MazeArr[currX][currY - 1] == ' ' && Visited[currX][currY - 1] != 'X')
		{
			currY--;
			Visited[currX][currY] = 'X';
			MazeArr[currX][currY] = '#';
			Q.InsertRear(currX, currY);
			//continue;
		}		
		//Dead End
		else {
			if (currX != ExitX || currY != ExitY)
			{
				// pop current node
				MazeArr[currX][currY] = ' ';
				Visited[currX][currY] = 'X';
				Q.RemoveRear();
				// pop node are backtracking to as we will be pushing it again on the loop's next iteration
				currX = Q.BackX();
				currY = Q.BackY();
			}

			else
			{
				break;
			}
		}
		
	}
	PrintMaze(MazeArr, MazeHeight, MazeWidth);

	
	_getch();

}
//getting dimensions of each maze as needed
int GetWidth(string MazeName)
{
	ifstream WidthStream;
	string currLine;
	int mWidth;
	try
	{
		WidthStream.open(MazeName);
		while(!WidthStream.eof())
		{
			getline(WidthStream, currLine);
			mWidth = currLine.length();
			return mWidth;
		}
	}
	catch(ifstream::failure e)
	{
		cerr << "Exception opening/reading/closing file. \n";
	}
	catch(...)
	{
		cerr << "Error with program. \n";
	}
}

int GetHeight(string MazeName)
{
	ifstream HeightStream;
	string currLine;
	int mHeight = 0;
	try
	{
		HeightStream.open(MazeName);
				
		while(!HeightStream.eof())
		{
			getline(HeightStream, currLine);
			mHeight++;
		}
		return mHeight;	
						
	}
	catch(ifstream::failure e)
	{
		cerr << "Exception opening/reading/closing file. \n";
	}
	catch(...)
	{
		cerr << "Error with program. \n";
	}	

}

//allocation of space
char** ExpandArray(int MazeW, int MazeH)
{	
	char** MazeArrayEx = new char*[MazeH];
	for(int i = 0; i < MazeH; i++)
	{
		MazeArrayEx[i] = new char[MazeW];
	}

	return MazeArrayEx;
	
}

//loads the maze requested & fills the 2d array
char** MazeFill(string MazeName, int MazeHeight, int MazeWidth)
{
	ifstream MazeStream;
	string currLine;
	int line = 0;
	char** Maze;
	
	Maze = ExpandArray(MazeWidth, MazeHeight);	

	try
	{
		MazeStream.open(MazeName);
		while(!MazeStream.eof())
		{
			for(int h = 0; h < MazeHeight; h++)
			{
				getline(MazeStream, currLine);
				for(int w = 0; w < MazeWidth; w++)
				{
					Maze[h][w] = currLine[w];
				}
			}
		}
		return Maze;
	}
	catch(ifstream::failure e)
	{
		cerr << "Exception opening/reading/closing file. \n";
	}
	catch(...)
	{
		cerr << "Error with program. \n";
	}
}

void MainMenu()
{
	bool UserSelection = true;
	string MazeSelection;

	string MazeName1 = "maze.txt";
	string MazeName2 = "maze2.txt";
	string MazeName3 = "maze3.txt";
	string MazeName4 = "maze4.txt";
	string MazeName5 = "mazex.txt";

	int MazeHeight = 0;
	int MazeWidth = 0;


	

	int MazeExitX;
	int MazeExitY;

	do
	{
		cout << "Please select a maze from 1 - 5, \n";
		cout << "or press Q/q to exit. \n";
		getline(cin, MazeSelection);

		if(MazeSelection == "1")
		{
			cout << "Selected maze 1." << endl;
			char** MazeArray;
			MazeHeight = GetHeight(MazeName1);
			MazeWidth = GetWidth(MazeName1);
			MazeArray = MazeFill(MazeName1, MazeHeight, MazeWidth);
			
			MazeExitY = MazeWidth - 1;
			MazeExitX = MazeHeight - 2;

			for(int h = 0; h < MazeHeight; h++)
			{
				for(int w = 0; w < MazeWidth; w++)
				{
					cout << MazeArray[h][w];
				}				
				cout << endl;
			}
			SolveMaze(MazeArray, MazeExitX, MazeExitY, MazeHeight, MazeWidth);
			//cout << MazeExitY << "," << MazeExitX << endl;
		}
		else if(MazeSelection == "2")
		{
			cout << "Selected maze 2." << endl;
			char** MazeArray;
			MazeHeight = GetHeight(MazeName2);
			MazeWidth = GetWidth(MazeName2);
			MazeArray = MazeFill(MazeName2, MazeHeight, MazeWidth);
			
			MazeExitY = MazeWidth - 1;
			MazeExitX = MazeHeight - 2;

			for(int h = 0; h < MazeHeight; h++)
			{
				for(int w = 0; w < MazeWidth; w++)
				{
					cout << MazeArray[h][w];
				}
				cout << endl;
			}
			SolveMaze(MazeArray, MazeExitX, MazeExitY, MazeHeight, MazeWidth);
			//cout << MazeExitY << "," << MazeExitX << endl;
		}
		else if(MazeSelection == "3")
		{
			cout << "Selected maze 3." << endl;
			char** MazeArray;
			MazeHeight = GetHeight(MazeName3);
			MazeWidth = GetWidth(MazeName3);
			MazeArray = MazeFill(MazeName3, MazeHeight, MazeWidth);

			MazeExitY = MazeWidth-1;
			MazeExitX = MazeHeight - 2;

			for(int h = 0; h < MazeHeight; h++)
			{
				for(int w = 0; w < MazeWidth; w++)
				{
					cout << MazeArray[h][w];
				}
				cout << endl;
			}

			/*cout << MazeExitX << ":X-Y:" << MazeExitY << " Maze Loc: " << MazeArray[24][49] << endl;
			cout << MazeExitX << ":X-Y:" << MazeExitY << " Maze Loc: " << MazeArray[24][50] << endl;
			cout << MazeExitX << ":X-Y:" << MazeExitY << " Maze Loc: " << MazeArray[23][49] << endl;
			cout << MazeExitX << ":X-Y:" << MazeExitY << " Maze Loc: " << MazeArray[23][50] << endl;*/
			SolveMaze(MazeArray, MazeExitX, MazeExitY, MazeHeight, MazeWidth);
			//cout << MazeExitY << "," << MazeExitX << endl;
		}
		else if(MazeSelection == "4")
		{
			cout << "Selected maze 4." << endl;
			char** MazeArray;
			MazeHeight = GetHeight(MazeName4);
			MazeWidth = GetWidth(MazeName4);
			MazeArray = MazeFill(MazeName4, MazeHeight, MazeWidth);

			MazeExitY = MazeWidth - 1;
			MazeExitX = MazeHeight - 2;

			for(int h = 0; h < MazeHeight; h++)
			{
				for(int w = 0; w < MazeWidth; w++)
				{
					cout << MazeArray[h][w];
				}
				cout << endl;
			}
			SolveMaze(MazeArray, MazeExitX, MazeExitY, MazeHeight, MazeWidth);
			//cout << MazeExitY << "," << MazeExitX << endl;
		}
		else if(MazeSelection == "5")
		{
			cout << "Selected maze 5." << endl;
			char** MazeArray;
			MazeHeight = GetHeight(MazeName5);
			MazeWidth = GetWidth(MazeName5);
			MazeArray = MazeFill(MazeName5, MazeHeight, MazeWidth);

			MazeExitY = MazeWidth - 1;
			MazeExitX = MazeHeight - 2;

			for(int h = 0; h < MazeHeight; h++)
			{
				for(int w = 0; w < MazeWidth; w++)
				{
					cout << MazeArray[h][w];
				}
				cout << endl;
			}
			SolveMaze(MazeArray, MazeExitX, MazeExitY, MazeHeight, MazeWidth);
			//cout << MazeExitY << "," << MazeExitX << endl;
		}
		else if(MazeSelection == "Q" || MazeSelection == "q")
		{
			UserSelection = false;
		}
		else 
		{
			cout << "Something was wrong with your input. \n";
			cout << "Please try again. \n";
		}
		MazeSelection.clear();
		

	}
	while(UserSelection);
	cout << "Thanks for playing!";
}


void main()
{
	MainMenu();
	
	_getch();
}