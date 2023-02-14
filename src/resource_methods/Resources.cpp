//
// Created by zlhartma on 1/4/2023.
//

#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

#include "Resources.h"

using namespace std;

//MATH

const double EulerConstant = std::exp(1.0);

double Resources::sigmoid(double val){
    return 1 / (1 + pow(EulerConstant, val));
}

double Resources::sigmoidDerivative(double val) {
    return sigmoid(val) * (1 - sigmoid(val));
}

//FILE MANAGEMENT

vector<string> Resources::getCSVAsStringVector(fstream ifread, const string& fileName) {
    vector<string> temp;
    ifread.open(fileName);
    string currLine;
    while(getline(ifread, currLine)){
        temp.push_back(currLine);
    }
    ifread.close();
    return temp;
}

//DATA MANIPULATION

set<string> Resources::tokenizeWords(string *arr) {
    set<string> ret;
    for(int i = 0; i < arr->length(); ++i){
//        if(ret.find(arr[i]) == ret.end()){
            ret.insert(arr[i]);
//        }
    }
    return ret;
}
