#include <iostream>
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
	for (int c = 0; c < COLOR_COUNT; ++c)
	{
		for (int p = 0; p < KIND_COUNT; ++p)
		{
			//checks the piece currently stored by the variable created by the second loop (p) and creates a piece accordingly
			switch (p)
			{
			case A_PAWN:
			case B_PAWN:
			case C_PAWN:
			case D_PAWN:
			case E_PAWN:
			case F_PAWN:
			case G_PAWN:
			case H_PAWN:
				_pieces[c][p] = new Pawn((Kind) p, (Color) c);
				break;
			case Q_ROOK:
			case K_ROOK:
				_pieces[c][p] = new Rook((Kind) p, (Color) c);
				break;
			case Q_KNIGHT:
			case K_KNIGHT:
				_pieces[c][p] = new Knight((Kind) p, (Color) c);
				break;
			case Q_BISHOP:
			case K_BISHOP:
				_pieces[c][p] = new Bishop((Kind) p, (Color) c);
				break;
			case QUEEN:
				_pieces[c][p] = new Queen((Kind) p, (Color) c);
				break;
			case KING:
				_pieces[c][p] = new King((Kind) p, (Color) c);
				break;
			}
		}
	}
}

State::~State()
{

	delete _board;
	delete _spriteFactory;

	for (int c = 0; c < COLOR_COUNT; ++c)
	{
		for (int p = 0; p < KIND_COUNT; ++p)
		{
			delete _pieces[c][p];
		}
	}
}

bool
State::turnCheck()
{
	if (this->currentTurn != this->_pickedPiece->getColor())
	{
		if (this->currentTurn == WHITE)
		{
			this->currentTurn = BLACK;
		}
		else
		{
			this->currentTurn = WHITE;
		}
		return true;
	}
	return false;
}

void State::startMove(Square square)
{
	Piece* piece = _board->getPiece(square);
	if (piece)
	{
		_pickedPiece = piece;
	}
}

void State::endMove(Square square)
{
	if (_pickedPiece)
	{
		
		if (_pickedPiece->canMove(_board, square))
		{
			if (this->turnCheck())
			{
				this->_board->setPiece(square, _pickedPiece);
				this->_spriteFactory->updatePosition(_pickedPiece, square);
				this->_pickedPiece->setHasMoved();

				for (int c = 0; c < COLOR_COUNT; c++)
				{
					for (int p = 0; p < KIND_COUNT; p++)
					{
						this->_spriteFactory->updatePosition(_pieces[(Color)c][(Kind)p], _pieces[(Color)c][(Kind)p]->getSquare());
					}
				}
			}
		}
	}
    _pickedPiece = 0;
}

void State::squareClicked(sf::Vector2i point)
{
	std::cout << _hitbox.getSquareAtPoint(point) << std::endl;
	this->startMove(_hitbox.getSquareAtPoint(point));
}

void State::squareReleased(sf::Vector2i point)
{
	std::cout << _hitbox.getSquareAtPoint(point) << " e" << std::endl;
	this->endMove(_hitbox.getSquareAtPoint(point));
}




//resets the pieces to their original positions
void
State::reset()
{
	_board->setPiece(A1, _pieces[WHITE][Q_ROOK]);
	_board->setPiece(B1, _pieces[WHITE][Q_KNIGHT]);
	_board->setPiece(C1, _pieces[WHITE][Q_BISHOP]);
	_board->setPiece(D1, _pieces[WHITE][QUEEN]);
	_board->setPiece(E1, _pieces[WHITE][KING]);
	_board->setPiece(F1, _pieces[WHITE][K_BISHOP]);
	_board->setPiece(G1, _pieces[WHITE][K_KNIGHT]);
	_board->setPiece(H1, _pieces[WHITE][K_ROOK]);
	_board->setPiece(A2, _pieces[WHITE][A_PAWN]);
	_board->setPiece(B2, _pieces[WHITE][B_PAWN]);
	_board->setPiece(C2, _pieces[WHITE][C_PAWN]);
	_board->setPiece(D2, _pieces[WHITE][D_PAWN]);
	_board->setPiece(E2, _pieces[WHITE][E_PAWN]);
	_board->setPiece(F2, _pieces[WHITE][F_PAWN]);
	_board->setPiece(G2, _pieces[WHITE][G_PAWN]);
	_board->setPiece(H2, _pieces[WHITE][H_PAWN]);

	_board->setPiece(A8, _pieces[BLACK][Q_ROOK]);
	_board->setPiece(B8, _pieces[BLACK][Q_KNIGHT]);
	_board->setPiece(C8, _pieces[BLACK][Q_BISHOP]);
	_board->setPiece(D8, _pieces[BLACK][QUEEN]);
	_board->setPiece(E8, _pieces[BLACK][KING]);
	_board->setPiece(F8, _pieces[BLACK][K_BISHOP]);
	_board->setPiece(G8, _pieces[BLACK][K_KNIGHT]);
	_board->setPiece(H8, _pieces[BLACK][K_ROOK]);
	_board->setPiece(A7, _pieces[BLACK][A_PAWN]);
	_board->setPiece(B7, _pieces[BLACK][B_PAWN]);
	_board->setPiece(C7, _pieces[BLACK][C_PAWN]);
	_board->setPiece(D7, _pieces[BLACK][D_PAWN]);
	_board->setPiece(E7, _pieces[BLACK][E_PAWN]);
	_board->setPiece(F7, _pieces[BLACK][F_PAWN]);
	_board->setPiece(G7, _pieces[BLACK][G_PAWN]);
	_board->setPiece(H7, _pieces[BLACK][H_PAWN]);

	for (int c = 0; c < COLOR_COUNT; c++)
	{
		for (int p = 0; p < KIND_COUNT; p++)
		{
			_spriteFactory->updatePosition(_pieces[(Color)c][(Kind)p], _pieces[(Color)c][(Kind)p]->getSquare());
		}
	}
}

const sf::Sprite&
State::getSprite(Color color, Kind kind) const
{
	return _spriteFactory->getSprite(_pieces[color][kind]);
}
