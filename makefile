all: ChessMain

ChessMain: ChessMain.o ChessBoard.o Piece.o King.o Queen.o Castle.o Bishop.o Knight.o Pawn.o
	g++ -g ChessMain.o ChessBoard.o Piece.o King.o Queen.o Castle.o Bishop.o Knight.o Pawn.o -o ChessMain

ChessMain.o: ChessMain.cpp
	g++ -g -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp
	g++ -g -c ChessBoard.cpp

Piece.o: Piece.cpp
	g++ -g -c Piece.cpp

King.o: King.cpp
	g++ -g -c King.cpp

Queen.o: Queen.cpp
	g++ -g -c Queen.cpp

Castle.o: Castle.cpp
	g++ -g -c Castle.cpp

Bishop.o: Bishop.cpp
	g++ -g -c Bishop.cpp

Knight.o: Knight.cpp
	g++ -g -c Knight.cpp

Pawn.o: Pawn.cpp
	g++ -g -c Pawn.cpp
