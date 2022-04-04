#include "Perceptron.h"
#include <iostream>
#include <string.h>

using namespace std;

Perceptron::Perceptron()
{

}

int Perceptron::random(int min, int max)
{
	static bool first = true;

	if(first)
	{
		srand(time(NULL));
		first = false;
	}
	return min+rand()%((max+1)-min); 
}

float Perceptron::getRandom()
{
	return random(-100,100)/100.0;
}

void Perceptron::initialise()
{
	int row = 4;
	int col = 2;

	X = new int*[row];
	for(int i = 0;i < row;i++) 
	{
    	X[i] = new int[col];
	}

	Y = new int[row];	

	int temp_x[4][2] = {{0,0},{0,1},{1,0},{1,1}};
	int temp_y[4] = {0,0,0,1};

	memcpy(X,temp_x,sizeof(int)*row*col);
	memcpy(Y,temp_y,sizeof(int)*row);
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
	for(int i = 0; i < 4; i++)
	{
		float y = w1*X[i][0] + w2*X[i][1] + theta;
		int output = threshold(y);
		cout << "(" << X[i][0] <<"," <<X[i][1]<<") --> ("<<output<<")\n";
	}
}
