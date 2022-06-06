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

	int win3(std::vector<std::vector<char>> grid,int s, int w, char marker) {
		wincond = w;
		size =s;
		int counterO,counterX =  0;

		//wincond in rows
		for (int i = 0; i < size-2; i++)
		{
			for (int j = 0; j < size-2; j++) {
				if (grid[i][j] == 'O')
				{
					if (counterX != 0)
					{
						counterX = 0;
					}					
					counterO++;
				}
				if (grid[i][j] == 'X')
				{
					if (counterO != 0)
					{
						counterO = 0;
					}
					
					counterX++;
				}

				if (counterO = wincond)
				{
					return 1;	
				}
				else if(counterX = wincond)
				{

					return -1;
					
				}
				else return 0;
			}
		}

		//wincond in column
		for (int j = 0; j < size-2; j++)
		{
			for (int i = 0; i < size-2; i++) {
				if (grid[i][j] == 'O')
				{
					if (counterX != 0)
					{
						counterX = 0;
					}					
					counterO++;
				}
				if (grid[i][j] == 'X')
				{
					if (counterO != 0)
					{
						counterO = 0;
					}
					
					counterX++;
				}

				if (counterO = wincond)
				{
					return 1;	
				}
				else if(counterX = wincond)
				{

					return -1;
					
				}
				else return 0;
			}
		}

		//wincond in diagonals 
		//first diagonol from top-left to bottom-right
		for (int i = 0; i < size -2; i++)
		{
			for (int j = 0; j < size -2; j++)
			{ 
				if(i == j)
				{
					if (grid[i][j] == 'O')
					{
						if (counterX != 0)
						{
							counterX = 0;
						}					
						counterO++;
					}
					if (grid[i][j] == 'X')
					{
						if (counterO != 0)
						{
							counterO = 0;
						}
						
						counterX++;
					}

					if (counterO = wincond)
					{
						return 1;	
					}
					else if(counterX = wincond)
					{

						return -1;
						
					}
					else return 0;
				}
			}
		}
		//Diagonal form top-right to bottem left
		for (int i = 0; i < size -2; i++)
		{
			for (int j = 0; j < size -2; j++)
			{ 
				if(i + j == size-1)
				{
					if (grid[i][j] == 'O')
					{
						if (counterX != 0)
						{
							counterX = 0;
						}					
						counterO++;
					}
					if (grid[i][j] == 'X')
					{
						if (counterO != 0)
						{
							counterO = 0;
						}
						
						counterX++;
					}

					if (counterO = wincond)
					{
						return 1;	
					}
					else if(counterX = wincond)
					{

						return -1;
						
					}
					else return 0;
				}
			}
		}
	}


	void play(int s) {
		size = s;
		int wincond = 3;
		Init(size);
		// grid= {{'O','X','O','O','O'}};
		// print3(size);
	
		// 	if (win3(grid,wincond,'O') == 10)
		// 	{
		// 		std::cout << "Player win !\n";
		// 	}
		// 	else
		// 	{
		// 		std:: cout << "Computer win !\n";
		// 	}
	



		// while (true) {
		// 	player_move3(size);
		// 	print3(size);
		// 	if (win3(size,wincond,'O'))
		// 	{
		// 		std::cout << "Player win !\n";
		// 		return;
		// 	}
		// 	else{
		// 		std::cout << "loser\n";
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
	game.play(5);
	
}