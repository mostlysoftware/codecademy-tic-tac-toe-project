#include <iostream>
#include <vector>

int player_turn = 1;
char player_mark = 'X';

std::vector<std::vector<char>> grid{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};

void print_intro() {

	std::cout << "Tic Tac Toe\n";
	std::cout << "P1 = X,  P2 = O\n\n";

}

void print_grid() {
	for (int x = 0; x < 3; x++) {//row
		std::cout << "     |     |\n";
		for (int y = 0; y < 3; y++) {//column
			std::cout << "  ";
			std::cout << grid[x][y];
			std::cout << "  ";
			if (y < 2) {
				std::cout << "|";
			}
		}//end_column
		std::cout << "\n     |     |\n";
		if (x < 2) {
			std::cout << "_____|_____|_____\n";
		}
	}//end_row
	std::cout << "\n";

}

void get_entry() {

	char player_entry;
	bool valid_entry = false;

	std::cout << "Player ";
	std::cout << player_turn;
	std::cout << ", enter your move: ";

	while (!valid_entry) {
		std::cin >> player_entry;

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (player_entry == grid[x][y]) {
					grid[x][y] = player_mark;
					valid_entry = true;
				}
			}
		}
		if (!valid_entry) {
			std::cout << "Invalid move! Try again: ";
		}
	}

}

bool check_win() {
	if ((grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) || //row1
		(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) || //row2
		(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) || //row3
		(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) || //col1
		(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) || //col2
		(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) || //col3
		(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || //diag1
		(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])) { //diag2
		return true;
	}
	else {
		return false;
	}
}

bool check_draw() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (grid[x][y] != 'X' && grid[x][y] != 'O') {
				return false;
			}
		}
	}
	return true;
}

void change_players() {
	if (player_turn == 1) {
		player_turn = 2;
		player_mark = 'O';
	}
	else {
		player_turn = 1;
		player_mark = 'X';
	}
}

void print_end(bool check_win,bool check_draw) {
	std::cout << "Game over! ";
	if (check_win) {
		std::cout << "Player ";
		std::cout << player_turn;
		std::cout << " wins!\n\n";
	}
	else if (check_draw) {
		std::cout << "The game was a draw!\n\n";
	}
}