#ifndef __PERCEPTRON_
#define __PERCEPTRON_

class Perceptron
{
	float w1,w2,theta;
	
	int X[4][2];
	int Y[4];
	
	public:
		Perceptron();
		
		void initialise();
		void train();
		int threshold(float y);
		void display();
};

#endif
