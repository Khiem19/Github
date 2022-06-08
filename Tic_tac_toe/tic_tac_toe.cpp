#include <iostream>
#include <vector>
#include <cmath>


struct move {
    int r, c, score;
};

std::vector<std::vector<char>> Create_grid(int size) {
	std::vector<std::vector<char>> grid;
	for (int i = 0; i < size; i++) {
		grid.push_back(std::vector<char>());
		for (int j = 0; j < size; j++) {
			grid[i].push_back(' ');
		}
	}
	return grid;
}

int check_win(std::vector<char> arr, int wincond){
    int counterO,counterX =  0;
	for (int j = 0; j < arr.size(); j++) {
		if (arr[j] == 'O')
		{
			if (counterX != 0)
			{
				counterX = 0;
			}					
			counterO++;
		}
		if (arr[j] == 'X')
		{
			if (counterO != 0)
			{
				counterO = 0;
			}
			
			counterX++;
		}

		if (counterO == wincond)
		{
			return 1;	
		}
		else if(counterX == wincond)
		{

			return -1;
			
		}
	
	}
	return 0;
}

int win(std::vector<std::vector<char>> grid, int wincond ) {
    
    int s = grid.size();
	int win_O = 0;
	int win_X = 0;
    
    for ( int i=0;i<s-wincond+1;i++){
        std::vector<char> tmp[4];  
        for ( int j = 0; j< s-i; j++){
            tmp[0].push_back(grid[i+j][j]);
            tmp[1].push_back(grid[j][i+j]);
            tmp[2].push_back(grid[s-i-1-j][j]);
            tmp[3].push_back(grid[s-j-1][i+j]);
        }
        for (auto elm:tmp){
            if ( check_win(elm,wincond) == 1){
                win_O++;
            }
            else if ( check_win(elm,wincond) == -1){
                win_X++;
            }
        }
				
    }
    
    for ( int i=0;i<s;i++){
        
        std::vector<char> loc;
        for ( int j=0;j<s;j++){
            loc.push_back(grid[i][j]);
        }
        
        
        if ( check_win(grid[i],wincond) == 1 || check_win(loc,wincond) == 1 ){
            win_O++;
        }
        else if (  check_win(grid[i],wincond) == -1 || check_win(loc,wincond) == -1 ){
            win_X++;
        }
    }
        
        
	if (win_X > 0){
	    return -1;
	}			
	else if(win_O > 0){
	    return 1;
	}
	else {
	    return 0;
	}
    
}

void print(std::vector<std::vector<char>> grid) {
	std::cout << '\n';
	for (int i = 0; i < grid.size(); i++) {
		if (i) {
			for (int i = 0; i < grid.size(); i++)
			{
				std::cout << "-----";
			}
			std::cout << "\n";	
		}
		for (int j = 0; j < grid.size(); j++) {
			if (j) {
				std::cout << "|";
			}
			std::cout << ' ';
			if (grid[i][j] == ' ') {
                    std::cout << grid.size() * i + j + 1;
                } else {
                    std::cout << grid[i][j];
                }
			std::cout << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int tie(std::vector<std::vector<char>> grid,int wincond){
	if(win(grid,wincond)){
		return -1;
	}
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid.size(); j++)
		{
			if (grid[i][j] != ' ')
			{
				return -1;
			}
			
		}	
	}
	return 0;	
}

std::vector<std::vector<char>> player_move(std::vector<std::vector<char>> grid,char p_marker) {
	std::cout << "Enter the empty cell:"; 
	int cell;
	std::cin >> cell;
	int last_cell = pow(grid.size(),2);
	int i = (cell -1)/grid.size(), j = (cell-1)%grid.size();
	if(cell >= 1 && cell <= last_cell) {
		grid[i][j] = p_marker;
	}
	else{
		std:: cout << "\n Please enter the correct cell !!! \n";
	}

	return grid;
}

move minimax(bool maximizing_player,std::vector<std::vector<char>> grid,int wincond){
	move best_move;
	int game_state = win(grid,wincond);
	int tie_state = tie(grid,wincond);
        if (game_state != 0) {
            if (maximizing_player) {
                best_move.score = -1;
            } else {
                best_move.score = 1;
            }
            return best_move;
        } else if (tie_state == 0) {
            best_move.score = 0;
            return best_move;
        }
        
        best_move.score = maximizing_player ? -2 : 2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == ' ') {
                    grid[i][j] = maximizing_player ? 'X' : 'O';
                    move board_state = minimax(!maximizing_player,grid,wincond);
                    if (maximizing_player) {
                        if (board_state.score > best_move.score) {
                            best_move.score = board_state.score;
                            best_move.r = i;
                            best_move.c = j;
                        }
                    } else {
                        if (board_state.score < best_move.score) {
                            best_move.score = board_state.score;
                            best_move.r = i;
                            best_move.c = j;
                        }
                    }
                    grid[i][j] = ' ';
                }
            }
        }
    return best_move;

}

std::vector<std::vector<char>> computer_move(std::vector<std::vector<char>> grid, char marker, int wincond) {
    move best_move = minimax(true,grid,wincond);
    grid[best_move.r][best_move.c] = marker;
	return grid;
}

void play(std::vector<std::vector<char>> grid, int wincond){
	char player,computer;
	while (true){
		std::cout <<" Which sybol go first (X or O)?";
		std::cin >> player;
		if(player == 'X' || player == 'O'){
			break;
		}
	}
	computer = player =='X' ? 'O' : 'X';
	if (player == 'O')
	{	
		std:: cout <<1;
		grid = computer_move(grid,computer,wincond);
		std:: cout <<2;
	}
	print(grid);
	while(!win(grid,wincond)){
		grid = player_move(grid,player);
		print(grid);
		int game_state = win(grid,wincond);
		int tie_state = tie(grid,wincond);
		if (game_state == -1)
		{
			std::cout << "Player X win" << std::endl;
		}
		if (game_state == 1){
			std::cout << "Player O win" << std::endl;
		}
		if(tie_state == 0){
			std::cout << "Game is tied" << std::endl;
		}
		std::cout << "Computer is making a move..\n";
		grid = computer_move(grid,computer,wincond);
		print(grid);
	}
}


int main()
{
 
        
    std::vector<std::vector<char>> grid; /*={{'X','X','4','O','O','O'},
                                           {'2','X','4','5','6','7'},
                                           {'8','9','5','4','5','6'},
                                           {'1','1','3','5','4','6'},
                                           {'1','2','6','4','5','6'},
                                           {'1','2','3','4','5','6'}};*/
    
    // cout<<check_win(grid[0],4)<<endl;
    // std::cout<<win(grid,3)<<endl;
	grid = Create_grid(4);
	play(grid,3);
    return 0;
}
