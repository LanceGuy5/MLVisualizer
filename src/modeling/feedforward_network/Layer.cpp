//
// Created by zlhartma on 3/9/2023.
//

#include "Layer.h"
#include <random>
#include <iostream>

using namespace std;

Layer::Layer(int neurons, int inputsPerNeuron) {
    //Populating weights for the vector into random values
    this->weights = vector<vector<double>>();
    for(int i = 0; i < inputsPerNeuron; i++){
        this->weights.emplace_back();
        for(int j = 0; j < neurons; j++){
            this->weights.at(i).push_back(2 * unif(re) - 1);
        }
    }
}

void Layer::displayWeights() {
    for(const vector<double>& v : this->weights){
        for(const double& d : v){
            cout << d << ", ";
        }
        cout << endl;
    }
}

double Layer::dot(Layer l2) {
    return 0;
}




