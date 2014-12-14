
#include "Pawn.hpp"
#include "ChessBoard.hpp"

using namespace std;

Pawn::Pawn(colour the_colour): Piece(pawn,the_colour)
{}

void Pawn::valid_moves(ChessBoard *cb, string square, set<string>& valid_list)
{
	string two_forward;
	string forward;
	string take_left;
	string take_right;

	if (piece_colour == white)
	{
		two_forward = cb->change_square(square,0,2);
		forward = cb->change_square(square, 0, 1);
		take_left = cb->change_square(square, -1, 1);
		take_right = cb->change_square(square, 1, 1);
	}
	else if (piece_colour == black)
	{
		two_forward = cb->change_square(square,0,-2);
		forward = cb->change_square(square, 0, -1);
		take_left = cb->change_square(square, -1, -1);
		take_right = cb->change_square(square, 1, -1);
	}

	if (is_valid_move(cb, two_forward) && first_turn && !is_opponent_piece(cb,two_forward))
		valid_list.insert(two_forward);

	if (is_valid_move(cb, forward) && !is_opponent_piece(cb,forward))
		valid_list.insert(forward);

	if (is_valid_move(cb, take_left) && is_opponent_piece(cb, take_left))
		valid_list.insert(take_left);

	if (is_valid_move(cb, take_right) && is_opponent_piece(cb, take_right))
		valid_list.insert(take_right);
}



