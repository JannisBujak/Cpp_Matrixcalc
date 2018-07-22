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

    Matrix * C = A->multiplyWith(B);

    if(C != nullptr)
        write(C->toString());
    system("pause");
    delete(A);
    delete(B);
    delete(C);
    return 0;
}