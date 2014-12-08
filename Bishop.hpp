#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.hpp"

using namespace std;


class Bishop: public Piece
{
	public:
		Bishop(colour the_colour);
		~Bishop(){}

		void valid_moves(ChessBoard *cb, string square, set<string>& valid_list);

	protected:
};






#endif
