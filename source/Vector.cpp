//
// Created by JannisB98 on 22.07.2018.
//

#include "Vector.h"
#include "Matrix.h"

Vector::Vector(string name) {

	this->name = name;
	vector<string> columns = Matrix::textToVectorList(name);
	for(string row : columns)
	{
		//vector<double > line = stringToIntVector(row);
		//this->allRows.push_back(line);
	}
	calcSize();
	//ySize = allRows.size();
	//xSize = getXSize();
	//fillRows();
}

void Vector::calcSize() {
	size = row.size();
}
