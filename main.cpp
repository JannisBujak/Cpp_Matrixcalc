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
	A->gaussAlgorithm(0, true);
	writeM(A);


	Matrix* B = new Matrix("MatrixB");
	//B->print();
	writeM(B);

	//B->gaussAlgorithm(0, true);
	//B->print();

	//Matrix* solution = B->multiplyWith(A);
	//writeM(solution);
	//solution->calculateDeterminant();
	//writeM(solution);


	Vector* V = new Vector("V");
	Vector* V2 = new Vector("V2");

	Vector* orthogonalVxV2 = V->orthogonalVector(V2);
	if(orthogonalVxV2 == nullptr) {

		orthogonalVxV2->print();

		cout << V->calcScalar(orthogonalVxV2) << endl;
		cout << V2->calcScalar(orthogonalVxV2) << endl;

		writeV(orthogonalVxV2);
	}

	//system("pause");

	writeM(A);
	writeM(B);
}