#ifndef GAME_H 
#define GAME_H
#include "Queue.h"
#include "Board.h"

class Game
{
	private:
		Queue<Node<Board>> q;
		Board initBoard;
		Board goalBoard;
		int gameState;
		string movesYouTook;

	public:
		Game(Board initBoard);
		string solve();

};
#endif