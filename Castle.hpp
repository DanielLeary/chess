#ifndef CASTLE_H
#define CASTLE_H

#include "Piece.hpp"

using namespace std;


class Castle: public Piece
{
	public:
		Castle(colour the_colour);
		~Castle(){}

		void valid_moves(ChessBoard *cd, string square, set<string>& valid_list);

	protected:
};






#endif
