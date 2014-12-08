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
		colour piece_colour;
		piece_type type;
		string piece_type_str();
		string colour_str();
		bool first_turn;

		//move constructor to protected once we have pure virtual function
		Piece(piece_type type_of_piece, colour the_colour);
		virtual ~Piece(){}

		//adds list of valid move squares to call-by-reference valid_list
		virtual void valid_moves(ChessBoard *cb, string square, set<string>& valid_list)=0;

		/*recursively steps through board using coordinate arguments,
		checking move validity. Updates call-by-reference set
		with valid squares*/
		void step_recursive(ChessBoard *cb, string square, int h, int v, set<string>& list);

		// checks if an individual square is valid for a piece
		bool is_valid_move(ChessBoard *cb, string square);

		//checks if piece at square is an opponent's piece
		bool is_opponent_piece(ChessBoard *cb, string square);

		friend ostream& operator<<(ostream& os, Piece& the_piece);

	protected:
};







#endif
