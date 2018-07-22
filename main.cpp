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

    A->gaussAlgorithm();
    A->print();

    //system("pause");

    delete(A);
    delete(B);
    return 0;
}