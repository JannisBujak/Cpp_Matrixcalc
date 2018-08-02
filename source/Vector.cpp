//
// Created by JannisB98 on 22.07.2018.
//

#include "Vector.h"
#include "Matrix.h"
#include <sstream> //stringstream
#include <iomanip>//setprecision


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

Vector* Vector::orthogonalVector(Vector* otherVector) {
	if(size != otherVector->getSize() != 3){
		return nullptr;
	}
	string myName = "cross_product_" + this->name + "x" + otherVector->getName();
	Vector* v = new Vector(myName, size);

	std::vector<double> vVector;

	for(int i = 0; i < size; i++){
		vVector.push_back((this->row[(i + 1) % size] * otherVector->row[(i + 2) % size]) - (this->row[(i + 2) % size] * otherVector->row[(i + 1) % size]));
	}
	v->setRow(vVector);
	return v;
}

double Vector::calcScalar(Vector* v) {
	if(size != v->getSize()){
		return 0;
	}
	double sum = 0;
	for(int i = 0; i < this->size; i++){
		sum += (this->row[i] * v->row[i]);
	}
	return  sum;
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

		stringstream stringstr;
		stringstr << fixed << setprecision(2) << d;
		vectorString += stringstr.str();
		//vectorString += to_string(d);
		vectorString += '\n';
	}
	return vectorString;
}
