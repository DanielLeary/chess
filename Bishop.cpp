
#include "Bishop.hpp"

using namespace std;

Bishop::Bishop(colour the_colour): Piece(bishop,the_colour)
{}

void Bishop::valid_moves(ChessBoard *cb, string square, set<string>& valid_list)
{
		step_recursive(cb, square, 1, 1, valid_list);
		step_recursive(cb, square, -1, -1, valid_list);
		step_recursive(cb, square, 1, -1, valid_list);
		step_recursive(cb, square, -1, 1, valid_list);
}


