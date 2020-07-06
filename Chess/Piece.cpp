#include "Piece.h"
#include <iostream>



Piece::Piece()
{
}


Piece::~Piece()
{
}


Piece::Piece(char name, char player)
{
	this->name = name;
	this->player = player;
}

char Piece::getName()
{
	return name;
}

char Piece::getPlayer()
{
	return player;
}

void Piece::setName(char name)
{
	this->name = name;
}

void Piece::setPlayer(char player)
{
	this->player = player;
}
