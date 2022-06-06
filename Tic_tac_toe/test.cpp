#include <iostream>
#include <algorithm>
#include <vector>

#define inf 3
#define minus_inf -3
#define P_marker 'X'
#define C_marker 'O'

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

	bool win3(int s, int w) {
		size = s;
		wincond = w;
		int counter1,counter2,counter3 =  0;
		//wincond in rows
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				if (grid[i][j] == P_marker)
				{
					counter1++;
				}
				if (grid[i][j+1] == C_marker)
				{
					counter1 = 0 ;
				}
				if (counter1 = wincond && grid[i][j] == grid[i][j+1])
				{
					return true;
				}
				else return false;
			}
		}
		// wincond in columns
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				if (grid[i][j] == P_marker)
				{
					counter2 ++;
				}
				if (grid[i+1][j] == C_marker)
				{
					counter2 = 0;
				}
				if (counter2 = wincond && grid[i][j] == P_marker && grid[i][j] == grid[i+1][j])
				{
					return true;
				}
				else return false;
			}
		}			
		// wincond in diagonals in 2 case(size%2=0 && szie%2 =1)
		
	}

	void player_move3(int s) {
		size = s;
		while (true) {
			int row, column;
			std::cout << "Enter an empty row : ";
			std::cin >> row;
			std::cout << "Enter an empty column : ";
			std::cin >>column;

			if (grid[row][column] = ' ')
			{	
				grid[row][column] = P_marker;
				break;
			}
		}
	}

	void play(int s) {
		size = s;
		Init(size);
		while (true) {
			player_move3(size);
			print3(size);
			if (win3(size,3))
			{
				std::cout << "Player win !\n";
				return;
			}
			
		}

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