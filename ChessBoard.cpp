#include "ChessBoard.hpp"

using namespace std;

ChessBoard::ChessBoard()
{
		current_turn = white;
		setup();
		cout << "A new chess game is started!" << endl;
}

ChessBoard::~ChessBoard()
{
		delete_board();
}

void ChessBoard::setup()
{
		//king placement
		board["E1"] = new King(white);
		board["E8"] = new King(black);

		//queen placement
		board["D1"] = new Queen(white);
		board["D8"] = new Queen(black);

		//castle placement
		board["A1"] = new Castle(white);
		board["H1"] = new Castle(white);
		board["A8"] = new Castle(black);
		board["H8"] = new Castle(black);

		//knight placement
		board["B1"] = new Knight(white);
		board["G1"] = new Knight(white);
		board["B8"] = new Knight(black);
		board["G8"] = new Knight(black);

		//bishop placement
		board["C1"] = new Bishop(white);
		board["F1"] = new Bishop(white);
		board["C8"] = new Bishop(black);
		board["F8"] = new Bishop(black);

		//white pawn placement
		for (char i = 'A'; i <= 'H'; i++)
		{
			string square;
			square += i;
			square += '2';
			board[square] = new Pawn(white);
		}

		//black pawn placement
		for (char i = 'A'; i <= 'H'; i++)
		{
			string square;
			square += i;
			square += '7';
			board[square] = new Pawn(black);
		}
}

void ChessBoard::resetBoard()
{
		delete_board();

		current_turn = white;
		setup();
		cout << "A new chess game is started!" << endl;

}

void ChessBoard::delete_board()
{
		map<string,Piece*>::iterator square;
		for (square = board.begin();square!=board.end();)
		{
			map<string,Piece*>::iterator square_to_delete;
			delete square->second;
			square_to_delete = square++;
			board.erase(square_to_delete);
		}
}

void ChessBoard::submitMove(string source_square, string destination_square)
{
		//check that source_square has piece
		if (!is_piece(source_square))
		{
			cout << "There is no piece at position " << source_square << "!" << endl;
			return;
		}

		// initialise useful variable
		Piece* piece_ptr = get_piece(source_square);
		string colour_str = piece_ptr->colour_str();
		string piece_str = piece_ptr->piece_type_str();

		//check if moving piece is colour of turn flag
		if (piece_ptr->piece_colour != current_turn)
		{
			cout << "It is not " << colour_str << "'s turn to move!" << endl;
			return;
		}

		//check that source_square != dest_square
		if (source_square==destination_square)
		{
			cout << "Cannot move a piece to a square it's already on!" << endl;
			return;
		}

		//get list of piece's valid moves, check if any == dest_square
		set<string> valid_move_list;
		piece_ptr->valid_moves(this, source_square, valid_move_list);

		if (valid_move_list.find(destination_square) == valid_move_list.end())
		{
			cout << colour_str << "'s " << piece_str << " cannot move to ";
			cout << destination_square << "!" << endl << endl;
			return;
		}

		// mark taken piece for death to Delete later
		bool fatality = false;
		Piece* marked_for_death;
		string dead_colour_str;
		string dead_piece_str;
		if (is_piece(destination_square))
		{
			fatality = true;
			marked_for_death = get_piece(destination_square);
			dead_colour_str = marked_for_death->colour_str();
			dead_piece_str = marked_for_death->piece_type_str();
		}

		//update board
		board[destination_square] = board[source_square];
		map<string,Piece*>::iterator previous_position = board.find(source_square);
		board.erase(previous_position);

		//check if own king in check now
		string king_square = get_king_square(current_turn);
		if (is_in_check(king_square))
		{
			cout << colour_str << "'s " << piece_str << " cannot move to ";
			cout << destination_square;
			cout<< ": cannot put/leave self in check!" << endl;

			//roll back board changes to previous state
			board[source_square] = piece_ptr;
			if (fatality)
				board[destination_square] = marked_for_death;

			return;
		}

		//delete piece marked for death
		if (fatality)
			delete marked_for_death;

		//print success message
		cout << colour_str << "'s " << piece_str << " moves from ";
		cout << source_square << " to " << destination_square;
		if (fatality)
			cout << " taking " << dead_colour_str << "'s " << dead_piece_str;
		cout << endl;

		//check if opponent in checkmate
		//check if opponent in check
		string opponent_king_square = get_king_square(opponent_colour());
		if (is_in_check(opponent_king_square))
		{
			cout << opponent_colour_str() << " is in check";
			cout << endl;
		}

		/*change first_turn flag to false*/
		piece_ptr->first_turn = false;

		//change turn flag to opponent
		if (current_turn == white)
			current_turn = black;
		else
			current_turn = white;

		//check for stalemate
		//print_board(); cout << endl << "--------------------------------------" << endl << endl;
}

// returns a pointer to a piece at given position
Piece* ChessBoard::get_piece(string square)
{
		map<string,Piece*>::iterator it = board.find(square);
		if (it == board.end())
			return NULL;
		else
			return it->second;
}

//checks if a square contains a piece
bool ChessBoard::is_piece(string square)
{
		if (board.find(square) == board.end())
			return false;
		else
			return true;
}

//checks if given square is on the board
bool ChessBoard::is_on_board(string square)
{
		if (square.length() < 2)
			return false;

		char file = square[0];
		char rank = square[1];

		if (file < 'A' || file > 'H')
			return false;
		else if (rank < '1' || rank > '8')
			return false;
		else
			return true;

}

string ChessBoard::change_square(string square, int file, int rank)
{
		char starting_file = square[0];
		char starting_rank = square[1];
		char new_file = starting_file + file;
		char new_rank = starting_rank + rank;

		string new_square;
		new_square+=new_file;
		new_square+=new_rank;
		return new_square;
}

string ChessBoard::get_king_square(colour player)
{
	map<string,Piece*>::iterator it;
	for (it = board.begin(); it!=board.end(); ++it)
	{
		Piece* the_king = it->second;
		if (the_king->type == king && the_king->piece_colour == player)
		{
			return it->first;
		}
	}
	return "";
}

bool ChessBoard::is_in_check(string checked_square)
{
	Piece* checked_piece = (board.find(checked_square))->second;

	map<string,Piece*>::iterator it;
	for (it=board.begin(); it !=board.end(); ++it)
	{
		Piece* piece_ptr = it->second;
		string piece_square = it->first;
		if (piece_ptr->piece_colour != checked_piece->piece_colour)
		{
			set<string> valid_move_list;
			piece_ptr->valid_moves(this, piece_square, valid_move_list);

			if (valid_move_list.find(checked_square) != valid_move_list.end())
				return true;
		}
	}
	return false;
}

colour ChessBoard::opponent_colour()
{
		if (current_turn == white)
			return black;
		else
			return white;
}

string ChessBoard::opponent_colour_str()
{
		if (current_turn == white)
			return "Black";
		else
			return "White";
}

void ChessBoard::print_board()
{
		for (char rank = '8'; rank >= '1'; rank--)
		{
			for (char file = 'A'; file <= 'H'; file++)
			{
				string square;
				square += file;
				square += rank;

				if (is_piece(square))
				{
					Piece* the_piece = get_piece(square);
					cout.width(4);
					cout << *the_piece;
				}
				else
				{
					cout.width(4);
					cout << "\u25A1";
				}
			}

			cout << endl;
		}
}




