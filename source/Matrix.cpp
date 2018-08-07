//

#include "Matrix.h"
#include "Vector.h"
#include "fstream"
#include "cmath"
#include <utility>
#include <vector>
#include <sstream> //stringstream
#include <iomanip>//setprecision
#include <cmath>

using namespace std;


Matrix::Matrix(string name)
{

    this->name = name;
    vector<string> columns = this->textToVectorList(name);

    for(string row : columns)
    {
        vector<double > line = stringToIntVector(row);

        this->allRows.push_back(line);
    }
    calcSize();
    ySize = allRows.size();
    xSize = getXSize();
    fillRows();
}

//
// Created by Jannis on 20.07.2018.
vector<string> Matrix::textToVectorList(string filename) {
    {
        string file = "../Text/" + filename + ".txt";
        //Most important values
        ifstream reader;    reader.open(file);  vector<string> text;    string line;
        if(reader.is_open())
        {
            while(reader.good())
            {
                getline(reader, line);
                if(line.empty())
                    break;
                text.push_back(line);
            }
            reader.close();
        }else{
            cout << "Unable to open file " + file << endl;
        }
        return text;
    }
}

vector<double> Matrix::stringToIntVector(string s) {
    vector<double > v;

    string numberOfMultipleNums;
    char* pEnd;
    for (char i : s) {
        if(i == ' ')
        {
            if(!numberOfMultipleNums.empty())
            {
                double d = strtod(numberOfMultipleNums.c_str(), &pEnd);
                v.push_back(d);
                numberOfMultipleNums = "";
            }
        }else
            numberOfMultipleNums += i;
    }
    if(!numberOfMultipleNums.empty()){
        v.push_back(atof(numberOfMultipleNums.c_str()));
    }
    return v;
}

void Matrix::calcSize() {
    ySize = allRows.size();
    int maxXSize = 0;
    for(vector<double > v : allRows){
        if(v.size() > maxXSize)
            maxXSize = v.size();
    }
    this->xSize =  maxXSize;
}

void Matrix::fillRows() {
    for(int y = 0; y < ySize; y++){
        for(int s = allRows[y].size(); s < xSize; s++){
            allRows[y].push_back(0);
        }
    }
}

void Matrix::print()
{
    this->calcSize();
    cout << name << " (" << xSize << "x" << ySize << "):" << endl;
    for(int y = 0; y < ySize; y++){
        for(int x = 0; x < xSize; x++){
            double valueHere = this->allRows[y][x];
            printf("%3.1f ", valueHere);
            int stringLength = to_string(valueHere).length();
	        for(int i = stringLength; i < 10; i++){
		        cout << ' ';
	        }
            //for(int i =((string)to_string(valueHere)).length(); i < 4; i++)              cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::print(Vector *v) {
	this->calcSize();
	cout << name << " (" << xSize << "x" << ySize << "):" << endl;
	for(int y = 0; y < ySize; y++){
		for(int x = 0; x < xSize; x++){
			double valueHere = this->allRows[y][x];
			printf("%3.1f ", valueHere);
			int stringLength = to_string(valueHere).length();
			for(int i = stringLength; i < 10; i++){
				cout << ' ';
			}
		}
		cout << '|';    for(int i = 0; i < 5; i++)  cout << ' ';

		double valueHere = v->getRow()[y];
		printf("%3.1f ", valueHere);
		int stringLength = to_string(valueHere).length();
		for(int i = stringLength; i < 10; i++){
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

string Matrix::toString() {
    string text;
    for(int y = 0; y < ySize; y++){
        for(int x = 0; x < xSize; x++){
        	double valueHere = this->allRows[y][x];
        	stringstream stringstr;
	        stringstr << fixed << setprecision(2) << valueHere;
            text += stringstr.str();

            int stringLength = stringstr.str().length();
            for(int i = stringLength; i < 10; i++){
            	text += ' ';
            }
        }
        text += '\n';
    }
    return text;
}

Matrix::Matrix(string name, int xSize, int ySize) {
    this->xSize = xSize;
    this->ySize = ySize;

    this->name = std::move(name);
    allRows.resize(((unsigned int)(ySize)));
    for (vector<double> row : allRows) {
        std::vector<double > v;
        v.resize((unsigned int)xSize);
        row = v;
    }
}

Matrix * Matrix::multiplyWith(Matrix* M) {
    print();
    cout << "multiplied with: \n" << endl;
    M->print();
    if(xSize != M->ySize){
        cout << "Forbidden, the size of the Matrices does not fit!" << endl;
        return nullptr;
    }
    Matrix* multiplicated = new Matrix(this->name + "_x_" + M->name, getYSize(), M->getXSize());
    for(int y = 0; y < multiplicated->getYSize(); y++){
        for(int x = 0; x < multiplicated->getXSize(); x++) {
            int value = 0;
            for(int i = 0; i < xSize; i++){
                value += allRows[y][i] * M->allRows[i][x];
            }
            multiplicated->setValue(y, x, value);
        }
    }
    multiplicated->print();
    return multiplicated;
}


Matrix *Matrix::copy() {
	Matrix* mCopy = new Matrix(name + "_copy", xSize, ySize);
	for(int y = 0; y < ySize; y++){
		for(int x = 0; x < xSize; x++) {
			mCopy->addValueToRow(y, allRows[y][x]);
		}
	}
	return  mCopy;
}

const string &Matrix::getName() const {
	return name;
}

int Matrix::getXSize() {
    return xSize;
}

int Matrix::getYSize() const {  return ySize;   }

void Matrix::setValue(int y, int x, double value)
{
    (allRows.at(y)).at(x) = value;
}

void Matrix::gaussAlgorithm(int row, bool shallTrack)
{
    if(!triangularForm){
	    name = name + "Triangular";
	    triangularForm = true;
    }
	if(row == ySize || inDiagonalForm()){
		cleanUp(min(xSize, ySize) - 1, shallTrack);
		return;
	}
	if(shallTrack && allRows[row][row] != 0)
		print();
	for(int y = row + 1; y < ySize; y++){

    	if(allRows[row][row] == 0)
    		continue;
        double multiplicator = allRows[y][row] / allRows[row][row];
        allRows.at(y).at(row) = 0;
        for(int x = row + 1; x < xSize; x++){
            allRows.at(y).at(x) = allRows[y][x] - multiplicator * allRows[row][x];
        }
    }

    gaussAlgorithm(row + 1, shallTrack);

}

void  Matrix::gaussAlgorithm(int row, bool shallTrack, Vector* v)
{
	if(!triangularForm){
		if(v->getSize() != this->ySize)
			return;
		name = name + "Triangular";
		triangularForm = true;
	}

	if(row == ySize || inDiagonalForm()){
		//break
		cleanUp(min(xSize, ySize) - 1, shallTrack, v);
		return;
	}
	if(shallTrack && allRows[row][row] != 0)
		print(v);
	for(int y = row + 1; y < ySize; y++){

		if(allRows[row][row] == 0)
			continue;
		double multiplicator = allRows[y][row] / allRows[row][row];
		allRows.at(y).at(row) = 0;
		for(int x = row + 1; x < xSize; x++){
			allRows.at(y).at(x) = allRows[y][x] - multiplicator * allRows[row][x];
		}
		v->setRowAtPosition(y, v->getRow()[y] - multiplicator * (v->getRow())[row]);
	}

	gaussAlgorithm(row + 1, shallTrack, v); //recursion
	return;
}

void Matrix::cleanUp(int row, bool shallTrack) {
    if(shallTrack)  print();
    if(row == 0)    return;

    for(int y = row - 1; y >= 0; y--)
    {
        double multiplicator = allRows[y][row] / allRows[row][row];
        for(int x = 0; x < xSize; x++){
            if(x == row)
            	allRows.at(y).at(x) = 0;
            else
            	allRows.at(y).at(x) = allRows[y][x] - multiplicator * allRows[row][x];
        }
    }
    cleanUp(row - 1, shallTrack);
}

void Matrix::cleanUp(int row, bool shallTrack, Vector* v) {
	if(shallTrack)  print(v);
	if(row == 0)    return;

	for(int y = row - 1; y >= 0; y--)
	{
		double multiplicator = allRows[y][row] / allRows[row][row];
		for(int x = 0; x < xSize; x++){
			if(x == row)
				allRows.at(y).at(x) = 0;
			else
				allRows.at(y).at(x) = allRows[y][x] - multiplicator * allRows[row][x];
		}
		v->setRowAtPosition(y, v->getRow()[y] - multiplicator * (v->getRow())[row]);
	}
	cleanUp(row - 1, shallTrack, v);
}

double Matrix::calculateDeterminant() {
    if(xSize != ySize){
        cout << "Determinant has to be n x n - Matrix!" << endl;
        return -1;
    }
    if(!inDiagonalForm())
        gaussAlgorithm(0, false);
    double determinant = 1;
    for(int i = 0; i < xSize; i++){
        determinant *= allRows[i][i];
    }
    return determinant;
}

bool Matrix::inDiagonalForm() {
    for(int y = 0; y < ySize; y++){
        for(int x = 0; x < y; x++) {
            if(allRows[y][x] != 0)
                return false;
        }
    }
    return true;
}

void Matrix::addValueToRow(int row, double value){
	allRows[row].push_back(value);
}

void Matrix::solveAndPrintSystem(bool shallTrack, Vector *v) {
	if(getYSize() != v->getSize())
		return;
	Matrix* mCopy = copy();
	Vector* vCopy = v->copy();
	mCopy->gaussAlgorithm(0, shallTrack, vCopy);
	if(!shallTrack)
		mCopy->print(vCopy);
}

Matrix::~Matrix() = default;

