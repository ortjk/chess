#pragma once
//everything comes back to the square class

class Piece;

class Square
{
public:
	Square(char file, int rank);
	virtual ~Square();

   	void setPiece(Piece* piece); 
   	Piece* getPiece() const;
	bool hasPiece() const;

	char getFile() const;
	int getRank() const;
private:
	const char _file;
	const int _rank;
	Piece* _piece;
};

