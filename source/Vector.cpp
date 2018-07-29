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

Vector* Vector::calcScalar(Vector* v) {
	if(size != v->getSize()){
		return nullptr;
	}
	string name = this->name + "x" + v->name + "_scalar";
	Vector* scalar = new Vector(name, size);

	std::vector<double> vector1;

	for(int i = 0; i < this->size; i++){
		vector1.push_back(this->row[i] * v->row[i]);
	}
	scalar->setRow(vector1);
	return  scalar;
}

Vector::Vector(string name, int size) {
	this->name = name;
	this->size = size;
}

int Vector::getSize() const {
	return size;
}

void Vector::setRow(const vector<double> &row) {
	this->row = row;
}

const string &Vector::getName() const {
	return name;
}

string Vector::toString() {
	string vectorString;
	for(double d : row){
		vectorString += to_string(d);
		vectorString += "\n";
	}
	return vectorString;
}
