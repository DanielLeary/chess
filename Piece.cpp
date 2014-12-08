#include "Piece.hpp"
#include "ChessBoard.hpp"

using namespace std;

Piece::Piece(piece_type type_of_piece, colour the_colour)
{
		type = type_of_piece;
		piece_colour = the_colour;
		first_turn = true;
}

string Piece::piece_type_str()
{
		switch(type)
		{
			case king: return "King";
			case queen: return "Queen";
			case castle: return "Castle";
			case bishop: return "Bishop";
			case knight: return "Knight";
			case pawn: return "Pawn";
			default: return "";
		}
}

string Piece::colour_str()
{
		switch(piece_colour)
		{
			case white: return "White";
			case black: return "Black";
			default: return "";
		}
}


bool Piece::is_opponent_piece(ChessBoard *cb, string square)
{
		if (!(cb->is_on_board(square)))
			return false;
		if (!(cb->is_piece(square)))
			return false;

		Piece* the_piece = cb->get_piece(square);
		if (the_piece->piece_colour != piece_colour)
			return true;
		else
			return false;
}


void Piece::step_recursive(ChessBoard *cb, string square, int h, int v, set<string>& list)
{
		string new_square = cb->change_square(square,h,v);
		if (is_valid_move(cb, new_square))
		{
			list.insert(new_square);
			if (is_opponent_piece(cb, new_square))
				return;
			else
				step_recursive(cb,new_square,h,v,list);
		}
		else
			return;
}

bool Piece::is_valid_move(ChessBoard *cb, string square)
{
		if (!(cb->is_on_board(square)))
			return false;
		if (cb->is_piece(square))
		{
			if (is_opponent_piece(cb, square))
				return true;
			else
				return false;
		}
		else
			return true;
}

// overloader to print unicode chess pieces
ostream& operator<<(ostream& os, Piece& the_piece)
{
	if (the_piece.piece_colour == white)
	{
		switch (the_piece.type)
		{
			case king: return os << "\u2654";
			case queen: return os << "\u2655";
			case castle: return os << "\u2656";
			case bishop: return os << "\u2657";
			case knight: return os << "\u2658";
			case pawn: return os << "\u2659";
		}
	}
	if (the_piece.piece_colour == black)
	{
		switch (the_piece.type)
		{
			case king: return os << "\u265A";
			case queen: return os << "\u265B";
			case castle: return os << "\u265C";
			case bishop: return os << "\u265D";
			case knight: return os << "\u265E";
			case pawn: return os << "\u265F";
		}
	}
}

