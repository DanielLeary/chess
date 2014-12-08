#ifndef KING_H
#define KING_H

#include "Piece.hpp"

using namespace std;


class King: public Piece
{
	public:
		King(colour the_colour);
		~King(){}

		void valid_moves(ChessBoard *cb, string square, set<string>& valid_list);

	protected:
};






#endif
