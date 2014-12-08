
#include "Queen.hpp"

using namespace std;

Queen::Queen(colour the_colour): Piece(queen,the_colour)
{}

void Queen::valid_moves(ChessBoard *cb, string square, set<string>& valid_list)
{
		//diagonal
		step_recursive(cb, square, 1, 1, valid_list);
		step_recursive(cb, square, -1, -1, valid_list);
		step_recursive(cb, square, 1, -1, valid_list);
		step_recursive(cb, square, -1, 1, valid_list);

		//along
		step_recursive(cb, square, 0, 1, valid_list);
		step_recursive(cb, square, 0, -1, valid_list);
		step_recursive(cb, square, 1, 0, valid_list);
		step_recursive(cb, square, -1, 0, valid_list);
}

