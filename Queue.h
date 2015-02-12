#ifndef QUEUE_H
#define QUEUE_H
#include "Board.h"
#include <assert.h>

using namespace std;
template <class T>
struct Node{
			Node();
			Node(Node<T>& differentB);
			Node(Board game);
			T stuff;
			Node<T>* next;
			
			int state;
		};

template <class T>
class Queue {
	public:
		Queue();
		bool isempty();
		Node<T> Dqueue();
		void Enqueue(Node<T> data);

	private:
		
		Node<T>* front;
		Node<T>* rear;
		
};

template <class T> // defualt Node constructor
Node<T>::Node(){
	next = NULL;
}
template <class T> // copy constructor for the Node
Node<T>::Node(Node<T>& notb){
	next = NULL;
	stuff = notb.stuff;
	state = notb.state;
}
template <class T> // constructor for the Node
Node<T>::Node(Board game){
	next = NULL;
	stuff = game;
	state = 0;
}
template <class T> // defualt constructor for a Queue
Queue<T>::Queue(){
	front = NULL;
	rear = NULL;

}
template <class T> // check if the Queue is empty
bool Queue<T>::isempty(){
	if (front == NULL) return true;
	return false;
}
template <class T> // deleting from the Queue
Node<T> Queue<T>::Dqueue(){
	Node<T> empty ;
	if (isempty()){

		cout << "There is nothing to delete" << endl;
		
	}
	else {

		Node<T>* temp;
		temp = front;
		empty.stuff = temp->stuff;
		empty.state = temp->state;
		if (front == rear){
			front = NULL;
			rear = NULL;
		}
		else {
			
			front = front->next;
			
		}
		delete temp;	
	}

	return empty;
}
template <class T> // adding to the Queue
void Queue<T>::Enqueue(Node<T> data){
	Node<T>* newNode = new Node<T>(data);

	if (isempty()){
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}

}
#endif