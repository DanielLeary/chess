
#include "Knight.hpp"
#include "ChessBoard.hpp"

using namespace std;

Knight::Knight(colour the_colour): Piece(knight,the_colour)
{}

void Knight::valid_moves(ChessBoard *cb, string square, set<string>& valid_list)
{
	string moves[8];
	moves[0] = cb->change_square(square, -1, 2);
	moves[1] = cb->change_square(square, -2, 1);
	moves[2] = cb->change_square(square, -2, -1);
	moves[3] = cb->change_square(square, -1, -2);
	moves[4] = cb->change_square(square, 1, -2);
	moves[5] = cb->change_square(square, 2, -1);
	moves[6] = cb->change_square(square, 2, 1);
	moves[7] = cb->change_square(square, 1, 2);

	for (int i=0; i<8; i++)
		if (is_valid_move(cb, moves[i]))
			valid_list.insert(moves[i]);
}

