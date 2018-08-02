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
void writeM(Matrix* m){
    ofstream writer;
    writer.open("../Text/" + m->getName() + ".txt");
    writer << m->toString();
    writer.close();
}


void writeV(Vector* v){
    ofstream writer;
    writer.open("../Text/" + v->getName() + ".txt");
    writer << v->toString();
    writer.close();
}

int main() {

    Matrix* A = new Matrix("MatrixA");
	//A->print();
	writeM(A);
	A->gaussAlgorithm(0);
	writeM(A);


	Matrix* B = new Matrix("MatrixB");
	//B->print();
	writeM(B);

	B->gaussAlgorithm(0);
	B->print();
	//Matrix* solution = B->multiplyWith(A);
	//writeM(solution);
	//solution->calculateDeterminant();
	//writeM(solution);


	Vector* V = new Vector("V");
	Vector* V2 = new Vector("V2");
	Vector* scalar = V->calcScalar(V2);

	writeV(scalar);

	if(scalar != nullptr)
		scalar->print();
	else
		cout << "is null";

	//system("pause");

	writeM(A);
	writeM(B);
	delete(A);
    delete(B);
    return 0;
}