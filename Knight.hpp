#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.hpp"

using namespace std;


class Knight: public Piece
{
	public:
		Knight(colour the_colour);
		~Knight(){}

		void valid_moves(ChessBoard *cb, string square, set<string>& valid_list);

	protected:
};






#endif
