#include "QueueNode.h"

QueueNode::QueueNode(): _dataX(1), _dataY(0), _next(NULL) {}

QueueNode::~QueueNode() {}

QueueNode::QueueNode(int dataX, int dataY, QueueNode* next)  : _dataX(dataX), _dataY(dataY), _next(next)  {}

int QueueNode::GetYData()
{
	return _dataY;
}
int QueueNode::GetXData()
{ 
	return _dataX; 
}

void QueueNode::SetXData(int dataX) { _dataX = dataX; }

void QueueNode::setYData(int dataY) { _dataY = dataY; }

QueueNode* QueueNode::getNext() { return _next;}
void QueueNode::SetNext(QueueNode* next) {_next = next;}