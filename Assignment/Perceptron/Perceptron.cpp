#include "Perceptron.h"
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

Perceptron::Perceptron():
    X{{0,0,1},{0,1,1},{1,0,1},{1,1,1}}
{
    w1 = getRandom();
    w2 = getRandom();

    theta = getRandom();
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

void Perceptron::initialise(int Y[4])
{
    this->Y[0] = Y[0];
    this->Y[1] = Y[1];
    this->Y[2] = Y[2];
    this->Y[3] = Y[3];
}

void Perceptron::train()
{
    bool updated;
    int epochs = 0;
    cout << "Weights initialised: " <<"w1: "<< w1 <<","<<"w2: "
         << w2<<","<<"theta: "<< theta<<endl;
    do
    {
        float prev_w1 = w1;
        float prev_w2 = w2;
        float prev_theta = theta;

        for(int i=0; i < 4; i++)
        {
            float y = w1*X[i][0] + w2*X[i][1] + theta*X[i][2];

            if(Y[i] == 0 && y > 0)
            {
                w1=w1-X[i][0];
                w2=w2-X[i][1];
                theta = theta-X[i][2];
                updated = true;
            }

            if(Y[i] == 1 && y <= 0)
            {
                w1=w1+X[i][0];
                w2=w2+X[i][1];
                theta = theta+X[i][2];
                updated = true;
            }
        }

        epochs++;

        if( prev_w1 == w1 &&
            prev_w2 == w2 &&
            prev_theta == theta )
        {
            break;
        }
    }
    while(1);

    cout << "Updated Weights: " <<"w1: "<< w1 <<","<<"w2: "
         << w2<<","<<"theta: "<< theta<<endl;
    cout << "Epochs: " << epochs <<endl;
}

int Perceptron::threshold(float y)
{
    return (y>0)?1:0;
}

void Perceptron::display()
{
	for(int i = 0; i < 4; i++)
	{
        float y = w1*X[i][0] + w2*X[i][1] + theta*X[i][2];
		int output = threshold(y);
        cout << "(" << X[i][0] <<","
             <<X[i][1]<<") --> ("<<output<<")\n";
	}
    cout << "--------------------"<<endl;
}
