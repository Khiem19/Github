#include <iostream>
#include <algorithm>
#include <vector>

#define inf 3
#define minus_inf -3


struct move {
	int r, c, score;
};


struct TicTacToe3 {
	char player, computer;
	int size, wincond;
	std::vector<std::vector<char>> grid;

	void Init(int s) {
		size = s;
		for (int i = 0; i < s; i++) {
			grid.push_back(std::vector<char>());
			for (int j = 0; j < s; j++) {
				grid[i].push_back(' ');
			}
		}
	}

	int win3(int s, int w, char marker) {
		size = s;
		wincond = w;
		int counterO,counterX =  0;
		//wincond in rows
		for (int i = 0; i < size-1; i++) {
			if (grid[0][i] == 'O')
			{
				counterO++;
			}
			if (grid[0][i] == 'X')
			{
				counterX++;
			}
			if (grid[0][i] == 'O' && grid[0][i+1] == 'X')
			{
				counterO,counterX = 0;
			}
			if (counterO = wincond)
			{
				if (grid[i] == grid[i+1])
				{
					return 10;
				}	
			}
			else if(counterX = wincond)
			{
				if (grid[i] == grid[i+1])
				{
					return -10;
				}
				
			}
			else return 1;
		}
	}	

	void player_move3(int s)
	{
		size = s;
		while (true) {
			int row, column;
			std::cout << "Enter an empty row : ";
			std::cin >> row;
			std::cout << "Enter an empty column : ";
			std::cin >>column;

			if (grid[row][column] = ' ')
			{	
				grid[row][column] = 'O';
				break;
			}
		}
	}

	void play(int s) {
		size = s;
		int wincond = 3;
		Init(size);
		grid= {{'O','O','O'}};
		print3(size);
	
			if (win3(size,wincond,'O') == 10)
			{
				std::cout << "Player win !\n";
				return;
			}
			else
			{
				std:: cout << "Computer win !\n";
			}
	
		// while (true) {
		// 	player_move3(size);
		// 	print3(size);
		// 	if (win3(size,wincond))
		// 	{
		// 		std::cout << "Player win !\n";
		// 		return;
		// 	}
			
		// }

	}
	void print3(int s) {
		size = s;
		std::cout << '\n';
		for (int i = 0; i < s; i++) {
			if (i) {
				for (int i = 0; i < s; i++)
				{
					std::cout << "----";
				}
				std::cout << "\n";	
			}
			for (int j = 0; j < s; j++) {
				if (j) {
					std::cout << "|";
				}
				std::cout << ' ';
				std::cout << grid[i][j];
				std::cout << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
};


int main() {
	TicTacToe3 game;
	game.play(3);
	
}