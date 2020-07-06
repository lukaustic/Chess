#pragma once
#include<string>

using namespace std;

class Piece
{
public:
	Piece();
	~Piece();

	char name;
	char player;

	Piece(char, char);
	char getName();
	char getPlayer();
	void setName(char name);
	void setPlayer(char player);
};

