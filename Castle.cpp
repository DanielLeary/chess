
#include "Castle.hpp"

using namespace std;

Castle::Castle(colour the_colour): Piece(castle,the_colour)
{}

void Castle::valid_moves(ChessBoard *cb, string square, set<string>& valid_list)
{
		step_recursive(cb, square, 0, 1, valid_list);
		step_recursive(cb, square, 0, -1, valid_list);
		step_recursive(cb, square, 1, 0, valid_list);
		step_recursive(cb, square, -1, 0, valid_list);
}

