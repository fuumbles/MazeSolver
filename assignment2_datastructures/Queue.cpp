#include "Queue.h"

using namespace std;

Queue::Queue() : _first(NULL), _last(NULL), _count(0) {}
Queue::~Queue()
{
	while( _first != NULL )
        {
            Serve();
        }
}

int Queue::FrontX()
{
	if (isEmpty())
		throw new DequeEmptyException();

	return _first->_dataX;
}
int Queue::BackX()
{
	if (isEmpty())
		throw new DequeEmptyException();

	return _last->_dataX;
}
int Queue::FrontY()
{
	if (isEmpty())
		throw new DequeEmptyException();

	return _first->_dataY;
}
int Queue::BackY()
{
	if (isEmpty())
		throw new DequeEmptyException();

	return _last->_dataY;
}

//should've used a fucking stack
//deques are aids
bool Queue::isEmpty()
{
	return _count == 0 ? true : false;
}
void Queue::InsertFront(int X, int Y)
{
	// Create a new node
	QueueNode* tmp = new QueueNode();
	tmp->SetXData(X);
	tmp->setYData(Y);
	tmp->_next = NULL;
	tmp->_prev = NULL;

	if (isEmpty()) {
		// Add the first element
		_first = _last = tmp;
	}
	else {
		// Prepend to the list and fix links
		tmp->_next = _first;
		_first->_prev = tmp;
		_first = tmp;
	}

	_count++;
}
void Queue::RemoveFront()
{
	if (isEmpty()) {
		throw new DequeEmptyException();
	}

	////  Data in the front node
	//int ret = front->data;

	// Delete the front node and fix the links
	QueueNode* tmp = _first;
	if (_first->_next != NULL)
	{
		_first = _first->_next;
		_first->_prev = NULL;
	}
	else
	{
		_first = NULL;
	}
	_count--;
	delete tmp;

}

void Queue::InsertRear(int X, int Y)
{
	// Create a new node
	QueueNode* tmp = new QueueNode();
	tmp->SetXData(X);
	tmp->setYData(Y);
	tmp->_next = NULL;
	tmp->_prev = NULL;

	if (isEmpty()) {
		// Add the first element
		_first = _last = tmp;
	}
	else {
		// Append to the list and fix links
		_last->_next = tmp;
		tmp->_prev = _last;
		_last = tmp;
	}

	_count++;
}
void Queue::RemoveRear()
{
	if (isEmpty()) {
		throw new DequeEmptyException();
	}

	//  Data in the rear node
	/*int retY = _last->_dataY;
	int retX = _last->_dataX;*/
	// Delete the front node and fix the links
	QueueNode* tmp = _last;
	if (_last->_prev != NULL)
	{
		_last = _last->_prev;
		_last->_next = NULL;
	}
	else
	{
		_last = NULL;
	}
	_count--;
	delete tmp;

}

//size of queue
int Queue::QueueCount()
{
	return _count;
}

//unused
//void Queue::Add(int X, int Y)
//{
//	QueueNode* node = new QueueNode();
//	node->SetXData(X);
//	node->setYData(Y);
//
//	if( _first == NULL )
//        {
//            _first = node;
//        }
//        else
//        {
//            _last->SetNext( node );
//        }
//        
//        _last = node;
//}

//int Queue::Peek()
//{
//    return _first->getData();
//}

void Queue::Serve()
{
	QueueNode* node = _first;
	_first = _first->getNext();
	delete node;
}


ostream& operator<<( ostream& output, Queue& queue )
{
    QueueNode* node = queue._first;
    
    while( node != NULL )
    {
        cout << node->GetXData() << ",";
		cout << node->GetYData() << endl;
        
        node = node->getNext();
    }
    
    return output;
}