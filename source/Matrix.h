//
// Created by Jannis on 20.07.2018.
//

#ifndef TESTS_MATRIX_H
#define TESTS_MATRIX_H

#include <iostream>
#include "Vector.h"
#include <vector>

using namespace std;

class Matrix {

private:

    string name;
    int xSize;
    int ySize;
    void calcSize();
    std::vector < std::vector < double > > allRows;

	std::vector< double > stringToIntVector(string s);
    void fillRows();

public:
	bool triangularForm;
    explicit Matrix(string name);
    ~Matrix();
    explicit Matrix(string name, int xSize, int ySize);
	Matrix* copy();

	void solveAndPrintSystem(bool shallTrack, Vector *v);
	void gaussAlgorithm(int row, bool shallTrack, Vector* v);
	void gaussAlgorithm(int row, bool shallTrack);

	void cleanUp(int row, bool shallTrack);
	void cleanUp(int row, bool shallTrack, Vector* v);
	double calculateDeterminant();
    void setValue(int y, int x, double value);
    void addValueToRow(int row, double value);
    const string &getName() const;

    int getXSize();
    int getYSize() const;

	bool inDiagonalForm();

    void print();
    void print(Vector* v);
    string toString();
    Matrix * multiplyWith(Matrix *M);

	static vector<string> textToVectorList(string filename);
};


#endif //TESTS_MATRIX_H
