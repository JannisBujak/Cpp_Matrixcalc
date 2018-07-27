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
    std::vector<int> row;
    int size;
    
    public:
    Vector(string name);

	void calcSize();
};




#endif //MATRIXCALC_VECTOR_H
