#ifndef __PERCEPTRON_
#define __PERCEPTRON_

class Perceptron
{
	float w1,w2,theta;
	
	int **X;
	int *Y;
	
	public:
		Perceptron();
		
		int random(int min, int max);
		float getRandom();
		void initialise();
		void train();
		int threshold(float y);
		void display();
};

#endif