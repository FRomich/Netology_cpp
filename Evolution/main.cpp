#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <windows.h>


namespace 
{
	bool** readInitFile(const std::string& pathInitFile, int& rows, int& cols, int& aliveCells)
	{
		std::ifstream file(pathInitFile);

		if (!file)
			return nullptr;

		file >> rows >> cols;

		bool** gameBoard = new bool* [rows];

		for (int i = 0; i < rows; i++)
		{
			gameBoard[i] = new bool[cols] {false};
		}

		int col;
		int row;

		while (file >> col >> row)
		{
			if (row >= 0 && row < rows &&
				col >= 0 && col < cols &&
				!gameBoard[row][col])
			{
				gameBoard[row][col] = true;
				aliveCells++;
			}

		}

		return gameBoard;
	}

	void gameBoardDelete(bool**&  gameBoard, int rows)
	{
		if (!gameBoard)
			return;

		for (int i = 0; i < rows; i++)
		{
			delete[] gameBoard[i];
		}

		delete[] gameBoard;

		gameBoard = nullptr;
	}

	void gameBoardDrawing(bool** gameBoard, int rows, int cols, int generation, int aliveCells)
	{
		if (!gameBoard)
			return;

		std::string allBoardString;

		std::system("cls");

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (gameBoard[i][j])
				{
					allBoardString += "*";
				}
				else
				{
					allBoardString += "-";
				}
				
			}
			allBoardString += '\n';
		}

		std::cout << allBoardString;

		std::cout << "Generation: " << generation << ". Alive cells: " << aliveCells;
	}

	int countNeighbors(bool** gameBoard, int rows, int cols, int x, int y)
	{
		int count = 0;

		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
					continue;

				int newX = x + i;
				int newY = y + j;

				if (newX >= 0 && newX < rows &&
					newY >= 0 && newY < cols)
				{
					if (gameBoard[newX][newY])
						count++;
				}
			}
		}

		return count;
	}

	bool nextGeneration(bool** gameBoard, bool** newBoard, int rows, int cols, int& aliveCells)
	{
		bool changed = false;
		aliveCells = 0;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int neighbors = countNeighbors(gameBoard, rows, cols, i, j);

				bool newState;

				if (gameBoard[i][j])
				{
					newState = (neighbors == 2 || neighbors == 3);
				}
				else
				{
					newState = (neighbors == 3);
				}

				newBoard[i][j] = newState;

				if (newState)
					aliveCells++;

				if (newState != gameBoard[i][j])
					changed = true;
			}
		}

		return changed;
	}

	void swapBoard(bool**& gameBoard, bool**&  newBoard)
	{
		bool** tmp = gameBoard;
		gameBoard = newBoard;
		newBoard = tmp;
	}

}


int main(int argc, char** argv)
{
	std::string pathInitFile{ "initEvolution.txt" };

	if (argc < 2)
	{
		std::cout << "Used the default file.\n";
		std::cout << "To use an external file, pass it as a parameter. \n";
	}
	else pathInitFile = argv[1];

	if (!std::filesystem::exists(pathInitFile))
	{
		std::cout << "Init file not found: " << pathInitFile << "\n";
		return 1;
	}

	int rows = 0;
	int cols = 0; 
	int generation = 0;
	int aliveCells = 0;

	bool** gameBoard = readInitFile(pathInitFile, rows, cols, aliveCells);

	if (!gameBoard)
	{
		std::cout << "Failed to read file: " << pathInitFile << '\n';
		return 1;
	}

	bool** newBoard = new bool* [rows];

	for (int i = 0; i < rows; i++)
	{
		newBoard[i] = new bool[cols] {false};
	}

	if (aliveCells < 1)
	{
		std::cout << "in init file not alive cells" << pathInitFile << "\n";
		gameBoardDelete(gameBoard, rows);
		gameBoardDelete(newBoard, rows);
		return 1;
	}

	while (true)
	{
		gameBoardDrawing(gameBoard, rows, cols, generation, aliveCells);

		bool changed = nextGeneration(gameBoard, newBoard, rows, cols, aliveCells);

		if (!changed)
		{
			std::cout << "\nThe world has stagnated. Game over\n";
			break;
		}

		swapBoard(gameBoard, newBoard);

		generation++;

		if (aliveCells < 1)
		{
			std::cout << "\nAll cells are dead. Game over\n";
			break;
		}

		Sleep(500);
	}

	gameBoardDelete(gameBoard, rows);
	gameBoardDelete(newBoard, rows);

	return 0;
}