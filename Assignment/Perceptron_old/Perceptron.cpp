#include "Perceptron.h"
#include <iostream>

using namespace std;

Perceptron::Perceptron():
	w1(1),
	w2(1),
	theta(-2.5),
	Y({0,0,0,1}),
	X({{0,0},{0,1},{1,0},{1,1}})
{
	train();
}

void Perceptron::initialise()
{
	
}

void Perceptron::train()
{
	for(int i=0; i < 4; i++)
	{
		float y = w1*X[i][0] + w2*X[i][1] + theta;
		
		if(Y[i] == 0 && y > 0)
		{
			w1=w1-X[i][0];
			w2=w2-X[i][1];
		}
		
		if(Y[i] == 1 && y <= 0)
		{
			w1=w1+X[i][0];
			w2=w2+X[i][1];
		}
	}
}

int Perceptron::threshold(float y)
{
	return (y>0)?1:0;
}

void Perceptron::display()
{
	cout << "AND Gate\n";
	cout << "********\n";
	
	for(int i = 0; i < 4; i++)
	{
		float y = w1*X[i][0] + w2*X[i][1] + theta;
		int output = threshold(y);
		cout << "(" << X[i][0] <<"," <<X[i][1]<<") --> ("<<output<<")\n";
	}
}
