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

	Matrix* B = new Matrix("MatrixB");
	//B->print();
	writeM(B);

	Vector* V = new Vector("V");
	Vector* V2 = new Vector("V2");

	/*
	B->gaussAlgorithm(0, false);
	B->print();



	Matrix* solution = B->multiplyWith(A);
	if(solution != nullptr) {
		writeM(solution);
		solution->calculateDeterminant();
		writeM(solution);
	}


	Vector* orthogonalVxV2 = V->orthogonalVector(V2);
	if(orthogonalVxV2 != nullptr) {

		orthogonalVxV2->print();

		cout << V->calcScalar(orthogonalVxV2) << endl;
		cout << V2->calcScalar(orthogonalVxV2) << endl;

		writeV(orthogonalVxV2);
	}
	*/

	A->solveAndPrintSystem(false, V);
	//system("pause");

	writeM(A);
	writeM(B);
}