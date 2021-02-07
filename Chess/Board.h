#pragma once
class Piece;

class Board
{
public:
	//A8 = 0!
	enum Square
    {
        NONE = -1,
        A8, A7, A6, A5, A4, A3, A2, A1,
        B8, B7, B6, B5, B4, B3, B2, B1,
        C8, C7, C6, C5, C4, C3, C2, C1,
        D8, D7, D6, D5, D4, D3, D2, D1,
        E8, E7, E6, E5, E4, E3, E2, E1,
        F8, F7, F6, F5, F4, F3, F2, F1,
        G8, G7, G6, G5, G4, G3, G2, G1,
        H8, H7, H6, H5, H4, H3, H2, H1
    };
	
	static int getFileIndex(Square square);
	static int getRankIndex(Square square); 
	static Square getSquareByIndices(int fileIndex, int rankIndex);

	Board();
	virtual ~Board();

	void setPiece(Square square, Piece* piece);
	Piece* getPiece(Square square) const;
	bool hasPiece(Square square) const;

private:
	const static int DIMENSION = 64;

	Piece* _squares[DIMENSION];
};

