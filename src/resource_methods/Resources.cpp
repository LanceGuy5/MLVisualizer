//
// Created by zlhartma on 1/4/2023.
//

#include <sstream>
#include <utility>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

#include "Resources.h"

using namespace std;

//MATH

const double EulerConstant = exp(1.0);

double Resources::sigmoid(double val){
    return 1 / (1 + pow(EulerConstant, val));
}

double Resources::sigmoidDerivative(double val) {
    return sigmoid(val) * (1 - sigmoid(val));
}

double Resources::tanhActivation(double val) {
    return ::tanh(val); //(exp(val) - exp(-val)) / (exp(val) + exp(-val))
}

double Resources::dotProduct(std::vector<double> one, std::vector<double> two) {
    if(one.size() == two.size()){
        double ret = 0;
        for(int i = 0; i < one.size(); i++){
            ret += (one.at(i) * two.at(i));
        }
        return ret;
    }else{
        return -1;
    }
}

double Resources::reluActivation(double val, double beta) {
    return std::max(val, beta * val);
}

double Resources::singleOutputForwardPass(std::vector<double> one, std::vector<double> two,
                                          double (*activation)(double)) {
    return activation(dotProduct(std::move(one), std::move(two)));
}

/*
 *  Based on the following:
 *  https://builtin.com/sites/www.builtin.com/files/styles/ckeditor_optimize/public/inline-images/13_common-loss-functions_0.png
 *  TODO figure out the summation part of ^
 */
double Resources::logCoshLoss(double real, double pred) {
    return ::log(::cosh(pred - real));
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
