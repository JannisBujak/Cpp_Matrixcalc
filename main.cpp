#include <iostream>
#include "fstream"
#include <vector>
#include "source/Matrix.h"
using namespace std;


void write(string s){
    ofstream writer;
    writer.open("../Text/MatrixSolution.txt");
    writer << s;
    writer.close();
}

int main() {

    Matrix* A = new Matrix("MatrixA");
    //A->print();

    Matrix* B = new Matrix("MatrixB");
    //B->print();
    B->print();
    B->gaussAlgorithm(0);
    B->print();
    printf("%5.1f\n", B->calculateDeterminant());

    //system("pause");

    delete(A);
    delete(B);
    return 0;
}