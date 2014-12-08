#ifndef PAWN_H
#define PAWN_H

#include "Piece.hpp"

using namespace std;


class Pawn: public Piece
{
	public:
		Pawn(colour the_colour);
		~Pawn(){}

		void valid_moves(ChessBoard *cb, string square, set<string>& valid_list);

	protected:
};






#endif
