//
// Created by Jannis on 20.07.2018.
//

#ifndef TESTS_MATRIX_H
#define TESTS_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix {

private:

    string name;
    int xSize;
    int ySize;
    void calcSize();
    std::vector < std::vector < double > > allRows;

    vector<string> textToVectorList(string filename);
    std::vector< double > stringToIntVector(string s);
    void fillRows();

public:
	bool triangularForm;
    explicit Matrix(string name);
    ~Matrix();
    explicit Matrix(string name, int xSize, int ySize);

	void gaussAlgorithm(int row);
	double calculateDeterminant();
    void setValue(int y, int x, int value);
    const string &getName() const;

    int getXSize();
    int getYSize() const;

	bool inDiagonalForm();

    void print();
    string toString();
    Matrix * multiplyWith(Matrix *M);

};


#endif //TESTS_MATRIX_H
