//
// Created by zlhartma on 1/6/2023.
//

#include <vector>
#include <typeinfo>
#include <iostream>
#include <sstream>

#include "PredictiveNeuralNetwork.h"
#include "../../resource_methods/Resources.h"

// The template element is the
template <typename T>
PredictiveNeuralNetwork<T>::PredictiveNeuralNetwork(int inputNodes,
        int hiddenLayers, int outputNodes, int epochs, double learningRate, double allowedError):
    Model(inputNodes, hiddenLayers, outputNodes, epochs, learningRate, allowedError) {

}

template <typename T> PredictiveNeuralNetwork<T>::~PredictiveNeuralNetwork() {
    //SAVE FILE?
}

//PUBLIC

template <typename T>
void PredictiveNeuralNetwork<T>::load(){

}

template <typename T>
void PredictiveNeuralNetwork<T>::insertData(const std::string& pathName) {
    this->dataVector = Resources::getCSVAsStringVector(fstream(), pathName);
}

template <typename T>
std::vector<std::string> PredictiveNeuralNetwork<T>::getDataCopy() {
    return dataVector;
}

template <typename T>
string PredictiveNeuralNetwork<T>::getRawDataType(){
    return typeid(T).name();
}

template <typename T>
void PredictiveNeuralNetwork<T>::train(){
    cout << "Training. . ." << endl;
    vector<vector<string>> componentVector = getDataAsTypeComponents(',');
}

//PRIVATE

template <typename T>
vector<string>* PredictiveNeuralNetwork<T>::getData() {
    return &dataVector;
}

template <typename T>
vector<vector<string>> PredictiveNeuralNetwork<T>::getDataAsTypeComponents(char delimiter) {
    vector<vector<string>> ret;
    for(const string& temp : dataVector) {
        vector<string> lineVec;
        std::stringstream ss(temp);
        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            lineVec.push_back(substr);
        }
        ret.push_back(lineVec);
        lineVec.clear();
    }
    return ret;
}
