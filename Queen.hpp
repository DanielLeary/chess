#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.hpp"

using namespace std;


class Queen: public Piece
{
	public:
		Queen(colour the_colour);
		~Queen(){}

		void valid_moves(ChessBoard *cb, string square, set<string>& valid_list);

	protected:
};






#endif
