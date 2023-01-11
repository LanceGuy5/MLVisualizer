//
// Created by zlhartma on 1/6/2023.
//

#include <fstream>
#include <vector>
#include <typeinfo>

#include "PredictiveNeuralNetwork.h"
#include "../../resource_methods/Resources.h"

// The template element is the
template <typename T> PredictiveNeuralNetwork<T>::PredictiveNeuralNetwork(int inputNodes,
                                                 int hiddenLayers,
                                                 int outputNodes,
                                                 int epochs,
                                                 double learningRate):
                                                 Model(inputNodes,
                                                       hiddenLayers,
                                                       outputNodes,
                                                       epochs,
                                                       learningRate) {
}

//template <typename T> PredictiveNeuralNetwork<T>::~PredictiveNeuralNetwork() {
//    //Delete file!
//}

//PUBLIC

template <typename T> void PredictiveNeuralNetwork<T>::load(){

}

template <typename T> void PredictiveNeuralNetwork<T>::insertData(const std::string& pathName) {
    this->dataVector = Resources::getCSVAsStringVector(fstream(), pathName);
}

template <typename T> std::vector<std::string> PredictiveNeuralNetwork<T>::getDataCopy() {
    return dataVector;
}

template <typename T> string PredictiveNeuralNetwork<T>::getRawDataType(){
    return typeid(T).name();
}

//PRIVATE

template <typename T> vector<string>* PredictiveNeuralNetwork<T>::getData() {
    return &dataVector;
}

template <typename T> vector<vector<vector<T>>> PredictiveNeuralNetwork<T>::getDataAsTypeComponents(const string& delimiter) {
    vector<vector<vector<T>>> ret;
    for(const string& temp : dataVector) {
        size_t pos = 0;
        size_t loc = 0;
        string token;
        while((pos = temp.find(delimiter)) != string::npos){
            token = temp.substr(loc, pos);
            loc = pos;
        }
    }
}
