#include <iostream>
#include "Perceptron.h"

using namespace std;

int main()
{
    Perceptron AND_Gate;
	
    int AND_output[4] = {0,0,0,1};

    cout << "AND GATE"<<endl;
    cout << "********"<<endl;

    AND_Gate.initialise(AND_output);
    AND_Gate.train();
    AND_Gate.display();

    Perceptron OR_Gate;

    int OR_output[4] = {0,1,1,1};

    cout << "OR GATE" <<endl;
    cout << "********" << endl;

    OR_Gate.initialise(OR_output);
    OR_Gate.train();
    OR_Gate.display();

    Perceptron NAND_Gate;

    int NAND_output[4] = {1,1,1,0};

    cout << "NAND GATE"<<endl;
    cout << "********"<<endl;

    NAND_Gate.initialise(NAND_output);
    NAND_Gate.train();
    NAND_Gate.display();

    Perceptron NOR_Gate;

    int NOR_output[4] = {1,0,0,0};

    cout << "NOR GATE"<<endl;
    cout << "********"<<endl;

    NOR_Gate.initialise(NOR_output);
    NOR_Gate.train();
    NOR_Gate.display();

    Perceptron XOR_Gate;

    int XOR_output[4] = {0,1,1,0};

    cout << "XOR GATE"<<endl;
    cout << "********"<<endl;

    XOR_Gate.initialise(XOR_output);
    XOR_Gate.train();
    XOR_Gate.display();


	return 0;
}
