//
// Created by JannisB98 on 22.07.2018.
//

#include "Vector.h"
#include "Matrix.h"

Vector::Vector(string name) {

	this->name = name;
	vector<string> columns = Matrix::textToVectorList(name);
	for(string rowEntry : columns)
	{
		if(rowEntry == "")
			break;
		char* pEnd;
		double d = strtod(rowEntry.c_str(), &pEnd);
		row.push_back(d);
	}
	calcSize();
}

void Vector::calcSize() {
	size = row.size();
}

void Vector::print() {
	cout << "Vector: " << name << " (dim[" << size << "])" << endl;
	for(double d : row){
		cout << d << endl;
	}
}
