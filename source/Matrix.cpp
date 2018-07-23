//

#include "Matrix.h"
#include "fstream"
#include <vector>
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
                if(line == "")
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
    string::size_type sz;
    double ints = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int numberAtIndex = ((s[i] - '0'));
            if(ints == -1){
                ints = 0;
            }
            ints = (ints * 10) + numberAtIndex;
        }
        else
            {
            v.push_back(ints);
            ints = - 1;
            continue;
        }
    }
    if(ints != -1)
        v.push_back(ints);
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
            //cout << valueHere;
            printf("%3.1f ", valueHere);
            //for(int i =((string)to_string(valueHere)).length(); i < 4; i++)              cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string Matrix::toString() {
    string text = "";
    for(int y = 0; y < ySize; y++){
        for(int x = 0; x < xSize; x++){
            string value = to_string(this->allRows[y][x]);
            text +=  value;
            for(int i = value.length(); i < 4; i++){
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

    this->name = name;
    allRows.resize(((unsigned int)(ySize)));
    for(int i = 0; i < allRows.size(); i++){
        std::vector<double > v;
        v.resize((unsigned int)xSize);
        allRows[i] = v;
    }
}

Matrix * Matrix::multiplyWith(Matrix *M) {
    print();
    cout << "multiplied with: \n" << endl;
    M->print();
    if(xSize != M->ySize){
        cout << "Forbidden, the size of the Matrices does not fit!" << endl;
        return nullptr;
    }
    Matrix* multiplicated = new Matrix(this->name + " * " + M->name, getYSize(), M->getXSize());
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

const string &Matrix::getName() const { return name;    }

int Matrix::getXSize() {
    return xSize;
}

int Matrix::getYSize() const {  return ySize;   }

void Matrix::setValue(int y, int x, int value)
{
    (allRows.at(y)).at(x) = value;
}

void Matrix::gaussAlgorithm(int row) {
    if(row == ySize || inDiagonalForm() == -1) return;
    for(int y = row + 1; y < ySize; y++){

        double multiplicator = allRows[y][row] / allRows[row][row];
        allRows.at(y).at(row) = 0;
        cout << multiplicator << endl;
        for(int x = row + 1; x < xSize; x++){
            allRows.at(y).at(x) = allRows[y][x] - multiplicator * allRows[row][x];
        }
    }

    gaussAlgorithm(row + 1);

}

double Matrix::calculateDeterminant() {
    if(xSize != ySize){
        cout << "Determinant has to be n x n - Matrix!" << endl;
        return -1;
    }
    if(!inDiagonalForm())
        gaussAlgorithm(0);
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

Matrix::~Matrix() = default;

