#include <iostream>
#include "ttt_functions.hpp"

bool game_over = false;

int main()
{
	print_intro();
	print_grid();

	while (!game_over) {

		get_entry();
		print_grid();

		if (check_win() || check_draw()) {
			game_over = true;
		}
		else {
			change_players();
		}
	}

	print_end(check_win(), check_draw());

}