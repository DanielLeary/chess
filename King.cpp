#include "King.hpp"
#include "ChessBoard.hpp"

using namespace std;

King::King(colour the_colour): Piece(king,the_colour)
{}


void King::valid_moves(ChessBoard *cb, string square, set<string>& valid_list)
{

	string moves[8];
	moves[0] = cb->change_square(square, 0, 1);
	moves[1] = cb->change_square(square, 1, 1);
	moves[2] = cb->change_square(square, 1, 0);
	moves[3] = cb->change_square(square, 1, -1);
	moves[4] = cb->change_square(square, 0, -1);
	moves[5] = cb->change_square(square, -1, -1);
	moves[6] = cb->change_square(square, -1, 0);
	moves[7] = cb->change_square(square, -1, 1);

	for (int i=0; i<8; i++)
		if (is_valid_move(cb, moves[i]))
			valid_list.insert(moves[i]);
}

