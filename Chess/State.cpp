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


	//for loop that iterates across all types of colors then pieces until it reaches a stopper, 'COLOR_COUNT' and 'KIND_COUNT' respectively
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
			case A_X_QUEEN:
			case B_X_QUEEN:
			case C_X_QUEEN:
			case D_X_QUEEN:
			case E_X_QUEEN:
			case F_X_QUEEN:
			case G_X_QUEEN:
			case H_X_QUEEN:
				_pieces[c][p] = new Queen((Kind)p, (Color)c);
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
	if (this->currentTurn == this->_pickedPiece->getColor())
	{
		return true;
	}
	return false;
}

void
State::swapTurn()
{
	if (this->currentTurn == WHITE)
	{
		this->currentTurn = BLACK;
	}
	else
	{
		this->currentTurn = WHITE;
	}
}

void State::startMove(Square square)
{
	Piece* piece = _board->getPiece(square);
	if (piece)
	{
		_pickedPiece = piece;
	}

	startSquare = square;
}

void State::endMove(Square square)
{
	if (_pickedPiece)
	{
		if (this->turnCheck())
		{
			if (_pickedPiece->canMove(_board, square))
			{
				this->_board->setPiece(square, _pickedPiece); //move piece
				this->_board->commit(); //save board state
				if (this->kingInCheck() == false) //if your king is not it check
				{
					this->_pickedPiece->setHasMoved(); //set that the piece has moved
					this->promotionCheck(_pickedPiece);
					this->swapTurn(); //swap the turn color
				}
				else //if your king is in check
				{
					_board->setState(LAST); //revert the board state to before the piece was moved
					_pickedPiece->setSquare(startSquare); //sets the moved piece's square to where it was before to prevent overlap
				}
			}
		}
	}
	for (int c = 0; c < COLOR_COUNT; c++)
	{
		for (int p = 0; p < KIND_COUNT; p++)
		{
			_spriteFactory->updatePosition(_pieces[(Color)c][(Kind)p], _pieces[(Color)c][(Kind)p]->getSquare());
		}
	}
	for (int i = 0; i <= 63; i++)
	{
		if (_board->getPiece(Square(i)))
		{
			_spriteFactory->updatePosition(_board->getPiece(Square(i)), Square(i));
		}
	}

    _pickedPiece = 0;
}

void State::squareClicked(sf::Vector2i point)
{
	this->startMove(_hitbox.getSquareAtPoint(point));
}

void State::squareReleased(sf::Vector2i point)
{
	if (point.x >= 0 &&
		point.x <= 1080 &&
		point.y >= 0 &&
		point.y <= 1080)
	{
		this->endMove(_hitbox.getSquareAtPoint(point));
	}
}

void State::pieceToMousePos(sf::Vector2i mouse)
{
	if (_pickedPiece) {
		_spriteFactory->getSprite(_pickedPiece).setPosition(sf::Vector2f(mouse.x - 68, mouse.y - 68));
	}
}

void State::goToMove()
{
	std::cout << "open menu\n";
}

bool State::kingInCheck()
{
	if (this->currentTurn == WHITE)
	{
		for (int p = 0; p < KIND_COUNT; p++)
		{
			if (_pieces[BLACK][Kind(p)]->canMove(_board, _pieces[WHITE][KING]->getSquare()))
			{
				return true;
			}
		}
	}
	else
	{
		for (int p = 0; p < KIND_COUNT; p++)
		{
			if (_pieces[WHITE][Kind(p)]->canMove(_board, _pieces[BLACK][KING]->getSquare()))
			{
				return true;
			}
		}
	}
	return false;
}

void State::promotionCheck(Piece* piece)
{
	if (piece->isPawn())
	{
		switch (piece->getSquare())
		{
		case A8:				
			_board->setPiece(A8, _pieces[WHITE][A_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][A_X_QUEEN], A8);
			this->_board->commit();
			break;
		case B8:				
			_board->setPiece(B8, _pieces[WHITE][B_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][B_X_QUEEN], B8);
			this->_board->commit();
			break;
		case C8:				
			_board->setPiece(C8, _pieces[WHITE][C_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][C_X_QUEEN], C8);
			this->_board->commit();
			break;
		case D8:				
			_board->setPiece(D8, _pieces[WHITE][D_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][D_X_QUEEN], D8);
			this->_board->commit();
			break;
		case E8:				
			_board->setPiece(E8, _pieces[WHITE][E_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][E_X_QUEEN], E8);
			this->_board->commit();
			break;
		case F8:				
			_board->setPiece(F8, _pieces[WHITE][F_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][F_X_QUEEN], F8);
			this->_board->commit();
			break;
		case G8:				
			_board->setPiece(G8, _pieces[WHITE][G_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][G_X_QUEEN], G8);
			this->_board->commit();
			break;
		case H8:				
			_board->setPiece(H8, _pieces[WHITE][H_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[WHITE][H_X_QUEEN], H8);
			this->_board->commit();
			break;
		case A1:				
			_board->setPiece(A1, _pieces[BLACK][A_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][A_X_QUEEN], A1);
			this->_board->commit();
			break;
		case B1:				
			_board->setPiece(B1, _pieces[BLACK][B_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][B_X_QUEEN], B1);
			this->_board->commit();
			break;
		case C1:				
			_board->setPiece(C1, _pieces[BLACK][C_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][C_X_QUEEN], C1);
			this->_board->commit();
			break;
		case D1:				
			_board->setPiece(D1, _pieces[BLACK][D_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][D_X_QUEEN], D1);
			this->_board->commit();
			break;
		case E1:				
			_board->setPiece(E1, _pieces[BLACK][E_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][E_X_QUEEN], E1);
			this->_board->commit();
			break;
		case F1:				
			_board->setPiece(F1, _pieces[BLACK][F_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][F_X_QUEEN], F1);
			this->_board->commit();
			break;
		case G1:				
			_board->setPiece(G1, _pieces[BLACK][G_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][G_X_QUEEN], G1);
			this->_board->commit();
			break;
		case H1:				
			_board->setPiece(H1, _pieces[BLACK][H_X_QUEEN]);
			_spriteFactory->updatePosition(_pieces[BLACK][H_X_QUEEN], H1);
			this->_board->commit();
			break;
		default: 				
			break;
		}
	}
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

	_board->setPiece(NONE, _pieces[WHITE][A_X_QUEEN]);

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

	_board->setPiece(NONE, _pieces[BLACK][A_X_QUEEN]);

	_board->commit();
	/*
	for (int c = 0; c < COLOR_COUNT; c++)
	{
		for (int p = 0; p < KIND_COUNT; p++)
		{
			_spriteFactory->updatePosition(_pieces[(Color)c][(Kind)p], _pieces[(Color)c][(Kind)p]->getSquare());
		}
	}
	*/
	for (int i = 0; i <= 63; i++)
	{
		if (_board->getPiece(Square(i)))
		{
			_spriteFactory->updatePosition(_board->getPiece(Square(i)), Square(i));
		}
	}
}

const sf::Sprite&
State::getSprite(Color color, Kind kind) const
{
	return _spriteFactory->getSprite(_pieces[color][kind]);
}
