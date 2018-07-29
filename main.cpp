#include <iostream>
#include "fstream"
#include <vector>
#include "source/Matrix.h"
#include "source/Vector.h"
using namespace std;


void write(string s){
    ofstream writer;
    writer.open("../Text/MatrixSolution.txt");
    writer << s;
    writer.close();
}
void write(Matrix* m){
    ofstream writer;
    writer.open("../Text/" + m->getName() + ".txt");
    writer << m->toString();
    writer.close();
}

int main() {

    Matrix* A = new Matrix("MatrixA");
	//A->print();
	write(A);

	Matrix* B = new Matrix("MatrixB");
	//B->print();
	write(B);

	B->gaussAlgorithm(0);
	B->print();
	//Matrix* solution = B->multiplyWith(A);
	//write(solution);
	//solution->calculateDeterminant();
	//write(solution);


	Vector* V = new Vector("V");
	Vector* V2 = new Vector("V2");
	Vector* scalar = V->calcScalar(V2);

	scalar->print();

	//system("pause");

	write(A);
	write(B);
	delete(A);
    delete(B);
    return 0;
}