#include "State.h"
#include "Board.h"

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

State::State()
	: _board(new Board())
{
	//initVariables();
	//for loop that iterates across all types of colors then pieces until it reaches a stopper, 'COLOR_COUNT' and 'KIND_COUND' respectively
	for (int c = 0; c < Piece::COLOR_COUNT; ++c)
	{
		for (int p = 0; p < Piece::KIND_COUNT; ++p)
		{
			//checks the piece currently stored by the variable created by the second loop (p) and creates a piece accordingly
			switch (p)
			{
			case Piece::A_PAWN:
			case Piece::B_PAWN:
			case Piece::C_PAWN:
			case Piece::D_PAWN:
			case Piece::E_PAWN:
			case Piece::F_PAWN:
			case Piece::G_PAWN:
			case Piece::H_PAWN:
				_pieces[c][p] = new Pawn((Piece::Kind) p, (Piece::Color) c);
				break;
			case Piece::Q_ROOK:
			case Piece::K_ROOK:
				_pieces[c][p] = new Rook((Piece::Kind) p, (Piece::Color) c);
				break;
			case Piece::Q_KNIGHT:
			case Piece::K_KNIGHT:
				_pieces[c][p] = new Knight((Piece::Kind) p, (Piece::Color) c);
				break;
			case Piece::Q_BISHOP:
			case Piece::K_BISHOP:
				_pieces[c][p] = new Bishop((Piece::Kind) p, (Piece::Color) c);
				break;
			case Piece::QUEEN:
				_pieces[c][p] = new Queen((Piece::Kind) p, (Piece::Color) c);
				break;
			case Piece::KING:
				_pieces[c][p] = new King((Piece::Kind) p, (Piece::Color) c);
				break;
			}
		}
	}
}

State::~State()
{
	delete _board;

	for (int c = 0; c < Piece::COLOR_COUNT; ++c)
	{
		for (int p = 0; p < Piece::KIND_COUNT; ++p)
		{
			delete _pieces[c][p];
		}
	}
}

void State::startMove(char file, int rank)
{

}

void State::endMove(char file, int rank)
{

}



//resets the pieces to their original positions
void
State::reset()
{
	_board->setPiece('a', 0, _pieces[Piece::WHITE][Piece::Q_ROOK]);
	_board->setPiece('b', 0, _pieces[Piece::WHITE][Piece::Q_KNIGHT]);
	_board->setPiece('c', 0, _pieces[Piece::WHITE][Piece::Q_BISHOP]);
	_board->setPiece('d', 0, _pieces[Piece::WHITE][Piece::QUEEN]);
	_board->setPiece('e', 0, _pieces[Piece::WHITE][Piece::KING]);
	_board->setPiece('f', 0, _pieces[Piece::WHITE][Piece::K_BISHOP]);
	_board->setPiece('g', 0, _pieces[Piece::WHITE][Piece::K_KNIGHT]);
	_board->setPiece('h', 0, _pieces[Piece::WHITE][Piece::K_ROOK]);

	_board->setPiece('a', 7, _pieces[Piece::BLACK][Piece::Q_ROOK]);
	_board->setPiece('b', 7, _pieces[Piece::BLACK][Piece::Q_KNIGHT]);
	_board->setPiece('c', 7, _pieces[Piece::BLACK][Piece::Q_BISHOP]);
	_board->setPiece('d', 7, _pieces[Piece::BLACK][Piece::QUEEN]);
	_board->setPiece('e', 7, _pieces[Piece::BLACK][Piece::KING]);
	_board->setPiece('f', 7, _pieces[Piece::BLACK][Piece::K_BISHOP]);
	_board->setPiece('g', 7, _pieces[Piece::BLACK][Piece::K_KNIGHT]);
	_board->setPiece('h', 7, _pieces[Piece::BLACK][Piece::K_ROOK]);
}

sf::Sprite State::getSprite(int c, int p)
{
	return _pieces[(Piece::Color) c][(Piece::Kind) p]->getSprite();
}
