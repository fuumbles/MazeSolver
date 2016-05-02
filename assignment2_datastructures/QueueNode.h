#include <fstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <regex>

using namespace std;

#ifndef QUEUENODE_H
#define QUEUENODE_H

class QueueNode
{
private:
    

public:
	int _dataX;
	int _dataY;

    QueueNode* _next;
	QueueNode* _prev;

	QueueNode() ;
	QueueNode(int dataX, int dataY, QueueNode* next);
	virtual ~QueueNode();

	int GetXData(); 
	int GetYData();

	void SetXData(int dataX);
	void setYData(int dataY);

	QueueNode* getNext();
	void SetNext(QueueNode* next);
};

#endif