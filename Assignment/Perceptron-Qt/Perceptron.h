#ifndef __PERCEPTRON_
#define __PERCEPTRON_

class Perceptron
{
    float w1,w2,theta;
	
    int X[4][3];
    int Y[4];
	
	public:
        Perceptron();
		
		int random(int min, int max);
		float getRandom();
        void initialise(int Y[4]);
		void train();
		int threshold(float y);
		void display();
};

#endif
