#include "State.h"
#include "SpriteFactory.h"

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

State::State()
	: _board(new Board()), _spriteFactory(new SpriteFactory()), _pickedPiece(0)
{
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
	delete _spriteFactory;

	for (int c = 0; c < Piece::COLOR_COUNT; ++c)
	{
		for (int p = 0; p < Piece::KIND_COUNT; ++p)
		{
			delete _pieces[c][p];
		}
	}
}

void State::startMove(Board::Square square)
{
	Piece* piece = _board->getPiece(square);
	if (piece)
	{
		_pickedPiece = piece;
	}
}

void State::endMove(Board::Square square)
{
	if (_pickedPiece)
	{
		if (_pickedPiece->canMove(_board, square))
		{
			_board->setPiece(square, _pickedPiece);
		}
	}
    _pickedPiece = 0;
}


//resets the pieces to their original positions
void
State::reset()
{
	_board->setPiece(Board::A1, _pieces[Piece::WHITE][Piece::Q_ROOK]);
	_board->setPiece(Board::B1, _pieces[Piece::WHITE][Piece::Q_KNIGHT]);
	_board->setPiece(Board::C1, _pieces[Piece::WHITE][Piece::Q_BISHOP]);
	_board->setPiece(Board::D1, _pieces[Piece::WHITE][Piece::QUEEN]);
	_board->setPiece(Board::E1, _pieces[Piece::WHITE][Piece::KING]);
	_board->setPiece(Board::F1, _pieces[Piece::WHITE][Piece::K_BISHOP]);
	_board->setPiece(Board::G1, _pieces[Piece::WHITE][Piece::K_KNIGHT]);
	_board->setPiece(Board::H1, _pieces[Piece::WHITE][Piece::K_ROOK]);
	_board->setPiece(Board::A2, _pieces[Piece::WHITE][Piece::A_PAWN]);
	_board->setPiece(Board::B2, _pieces[Piece::WHITE][Piece::B_PAWN]);
	_board->setPiece(Board::C2, _pieces[Piece::WHITE][Piece::C_PAWN]);
	_board->setPiece(Board::D2, _pieces[Piece::WHITE][Piece::D_PAWN]);
	_board->setPiece(Board::E2, _pieces[Piece::WHITE][Piece::E_PAWN]);
	_board->setPiece(Board::F2, _pieces[Piece::WHITE][Piece::F_PAWN]);
	_board->setPiece(Board::G2, _pieces[Piece::WHITE][Piece::G_PAWN]);
	_board->setPiece(Board::H2, _pieces[Piece::WHITE][Piece::H_PAWN]);

	_board->setPiece(Board::A8, _pieces[Piece::BLACK][Piece::Q_ROOK]);
	_board->setPiece(Board::B8, _pieces[Piece::BLACK][Piece::Q_KNIGHT]);
	_board->setPiece(Board::C8, _pieces[Piece::BLACK][Piece::Q_BISHOP]);
	_board->setPiece(Board::D8, _pieces[Piece::BLACK][Piece::QUEEN]);
	_board->setPiece(Board::E8, _pieces[Piece::BLACK][Piece::KING]);
	_board->setPiece(Board::F8, _pieces[Piece::BLACK][Piece::K_BISHOP]);
	_board->setPiece(Board::G8, _pieces[Piece::BLACK][Piece::K_KNIGHT]);
	_board->setPiece(Board::H8, _pieces[Piece::BLACK][Piece::K_ROOK]);
	_board->setPiece(Board::A7, _pieces[Piece::BLACK][Piece::A_PAWN]);
	_board->setPiece(Board::B7, _pieces[Piece::BLACK][Piece::B_PAWN]);
	_board->setPiece(Board::C7, _pieces[Piece::BLACK][Piece::C_PAWN]);
	_board->setPiece(Board::D7, _pieces[Piece::BLACK][Piece::D_PAWN]);
	_board->setPiece(Board::E7, _pieces[Piece::BLACK][Piece::E_PAWN]);
	_board->setPiece(Board::F7, _pieces[Piece::BLACK][Piece::F_PAWN]);
	_board->setPiece(Board::G7, _pieces[Piece::BLACK][Piece::G_PAWN]);
	_board->setPiece(Board::H7, _pieces[Piece::BLACK][Piece::H_PAWN]);

	//_sprite.setPosition(sf::Vector2f(10.f + (10 * numFile), 10.f + (10 * numRank)));
}

const sf::Sprite&
State::getSprite(Piece::Color color, Piece::Kind kind) const
{
	return _spriteFactory->getSprite(_pieces[color][kind]);
}
