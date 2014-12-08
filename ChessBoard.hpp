#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <map>
#include <set>
#include <string>
#include "Piece.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Castle.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Pawn.hpp"

using namespace std;

class ChessBoard {
	public:
		colour current_turn;
		map<string, Piece*> board;

		//initialisers and destructors
		ChessBoard();
		~ChessBoard();
		void setup();
		void resetBoard();
		void delete_board();

		// validates move submissions and carries them out
		void submitMove(string source_square, string destination_square);

		// returns pointer to piece at square
		Piece* get_piece(string square);

		// returns true if square has piece
		bool is_piece(string square);

		//returns true if square is on board
		bool is_on_board(string square);

		//adds coords to square and return new square
		string change_square(string square, int file, int rank);

		// checks if a players king is in check
		bool is_in_check(string checked_square);

		// get position of a players king
		string get_king_square(colour player);

		/*
		bool isInCheckMate(colour player);
		*/

		// returns opponent colour as enum type or string
		colour opponent_colour();
		string opponent_colour_str();

		// prints the board to the terminal
		void print_board();

	protected:
};







#endif