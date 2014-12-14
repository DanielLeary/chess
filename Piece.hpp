#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

enum colour {black, white};
enum piece_type {king, queen, castle, bishop, knight, pawn};

class ChessBoard;
class Piece {
	public:
		//constructor and destructor
		Piece(piece_type type_of_piece, colour the_colour);
		virtual ~Piece(){}

		colour piece_colour;
		piece_type type;
		bool first_turn;

		//return string representation of piece type or colour
		string piece_type_str();
		string colour_str();

		//adds list of valid move squares to call-by-reference valid_list
		virtual void valid_moves(ChessBoard *cb, string square, set<string>& valid_list)=0;

		friend ostream& operator<<(ostream& os, Piece& the_piece);

	protected:
        /*Recursively steps along board in a direction using coordinate arguments,
		checking move validity. Updates call-by-ref set with list of valid squares*/
		void step_recursive(ChessBoard *cb, string square, int h, int v, set<string>& list);

        // checks if a square is valid for any piece to move to
		bool is_valid_move(ChessBoard *cb, string square);

		//checks if piece at square is an opponent's piece
		bool is_opponent_piece(ChessBoard *cb, string square);

};







#endif
