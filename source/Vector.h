//
// Created by JannisB98 on 22.07.2018.
//

#ifndef MATRIXCALC_VECTOR_H
#define MATRIXCALC_VECTOR_H

#include <iostream>
#include <vector>
using namespace std;

class Vector {
    
private:
	string name;

	std::vector<double> row;
	int size;

public:
	vector<string> textToVectorList(string filename);

	Vector(string name, int size);
	Vector(string name);
	Vector* copy();

	Vector* orthogonalVector(Vector* otherVector);
	void print();
	string toString();

	double calcScalar(Vector* v);



	void calcSize();

	void setRow(const vector<double> &row);
	void setRowAtPosition(int position, double value);
	void addValueToRow(double value);

	const vector<double> &getRow() const;

	const string &getName() const;
	int getSize() const;
};




#endif //MATRIXCALC_VECTOR_H
