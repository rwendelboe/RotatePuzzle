#include <iostream>
#include "Game.h"
#include "Queue.h"

Game::Game(Board start)
{
	 initBoard =start;
	 goalBoard.makeBoard();
	 gameState = 1;
	 movesYouTook = "";

}
string Game::solve() // solve the game
{
	Board current = initBoard; //creat a board from initial board
	Queue<Board> q; //creat a q that holds Nodes
	Node<Board> firstNode(current); // creat a Node that holds the board
	q.Enqueue(firstNode); // add the node to the Q

	while (true){
		Node<Board> tempCurrent; //creating temp node to work with
		tempCurrent= q.Dqueue(); // remove the node
		
		for (int i = 0; i <= 11; i++){
			Node<Board> newBoard = tempCurrent; //copy the current board 
			stringstream ss;
			ss << "\nState " << gameState << " From State " << tempCurrent.state << newBoard.stuff.move(i);//make a move
			if (newBoard.stuff == goalBoard) // check if the board is eqauls to the winning board
			{
				ss << endl << newBoard.stuff.toString(); 
				return movesYouTook + ss.str();
			}
			movesYouTook += ss.str(); 
			movesYouTook += "\n" + newBoard.stuff.toString();// add to the string so it knows the moves
			newBoard.state = gameState;
			q.Enqueue(newBoard); //add it to the Q
			gameState++; // increment gameState
		}
	}
}