#include "QueueNode.h"

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

struct DequeEmptyException
{
public:
	DequeEmptyException()
	{
		cout << "Deque empty." << endl;
	}
};
class Queue
{
private:
	QueueNode* _first;
	QueueNode* _last;
	int _count;
public:
	Queue();
	virtual ~Queue();
	bool isEmpty();

	//unused
	//void Add(int X, int Y);

	void InsertFront(int X, int Y);
	void RemoveFront();

	void InsertRear(int X, int Y);
	void RemoveRear();

	int BackX();
	int BackY();

	int FrontX();
	int FrontY();


	int QueueCount();

	//int Peek() {} no use in solver

	void Serve();

	friend ostream& operator<<( ostream& output, Queue& queue );
};
#endif