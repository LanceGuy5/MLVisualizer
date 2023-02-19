//
// Created by zlhartma on 1/6/2023.
//

#include <vector>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <list>
#include <random>

#include "PredictiveNeuralNetwork.h"
#include "../../resource_methods/Resources.h"

/*  FROM: https://cs231n.github.io/neural-networks-1/
 *
 *  Naming conventions. Notice that when we say N-layer neural network, we do not count the input layer.
 *  Therefore, a single-layer neural network describes a network with no hidden layers (input directly mapped to output).
 *  In that sense, you can sometimes hear people say that logistic regression or SVMs are simply a special case of
 *  single-layer Neural Networks. You may also hear these networks interchangeably referred to as “Artificial Neural
 *  Networks” (ANN) or “Multi-Layer Perceptrons” (MLP). Many people do not like the analogies between Neural Networks
 *  and real brains and prefer to refer to neurons as units.
 *
 *  Output layer. Unlike all layers in a Neural Network, the output layer neurons most commonly do not have an
 *  activation function (or you can think of them as having a linear identity activation function). This is because the
 *  last output layer is usually taken to represent the class scores (e.g. in classification), which are arbitrary
 *  real-valued numbers, or some kind of real-valued target (e.g. in regression).
 *
 *  Sizing neural networks. The two metrics that people commonly use to measure the size of neural networks are the
 *  number of neurons, or more commonly the number of parameters. Working with the two example networks in the above
 *  picture: https://cs231n.github.io/assets/nn1/neural_net2.jpeg
 *  The first network (left) has 4 + 2 = 6 neurons (not counting the inputs), [3 x 4] + [4 x 2] = 20 weights and
 *  4 + 2 = 6 biases, for a total of 26 learnable parameters.
 *  The second network (right) has 4 + 4 + 1 = 9 neurons, [3 x 4] + [4 x 4] + [4 x 1] = 12 + 16 + 4 = 32 weights and
 *  4 + 4 + 1 = 9 biases, for a total of 41 learnable parameters.
 *  To give you some context, modern Convolutional Networks contain on orders of 100 million parameters and are usually
 *  made up of approximately 10-20 layers (hence deep learning). However, as we will see the number of effective
 *  connections is significantly greater due to parameter sharing. More on this in the Convolutional Neural Networks
 *  module.
 */

template <typename T>
PredictiveNeuralNetwork<T>::PredictiveNeuralNetwork(int inputNodes,
        int hiddenLayers, int outputNodes, int epochs, double learningRate, double allowedError):
    Model(inputNodes, hiddenLayers, outputNodes, epochs, learningRate, allowedError) {
        this->_bias = unif(re);
}

template <typename T> PredictiveNeuralNetwork<T>::~PredictiveNeuralNetwork() {
    //TODO Deallocate _weights array
    //TODO Deallocate _bias
    //TODO Save file
}

//PUBLIC

template <typename T>
void PredictiveNeuralNetwork<T>::load(){

}

template <typename T>
void PredictiveNeuralNetwork<T>::insertTrainingData(const std::string& pathName) {
    this->trainDataVector = Resources::getCSVAsStringVector(fstream(), pathName);
}

template <typename T>
void PredictiveNeuralNetwork<T>::insertTestingData(const std::string& pathName) {
    this->testDataVector = Resources::getCSVAsStringVector(fstream(), pathName);
}

template <typename T>
vector<string> PredictiveNeuralNetwork<T>::getDataCopy() {
    return trainDataVector;
}

template <typename T>
string PredictiveNeuralNetwork<T>::getRawDataType(){
    return typeid(T).name();
}

/*
 *  LAYERS -> multiple layers work on each row, not overall
 *  Will work better with better-formatted data
 *  TODO use a map for the dicts -> <key, val> <row #, set<double>>
 *
 *  STEPS:
 *  1. Format data - might need to mess around with this a little bit
 *  2. Instantiate weights as an empty vector<vector> of random generated numbers (as a vector because dot product)
 *  3. Run through the training for _epochs number of epochs
 *  4. Make a prediction for the data
 */
template <typename T>
void PredictiveNeuralNetwork<T>::train(){
    vector<vector<string>> componentVector = getDataAsTypeComponents(',');
    //TODO ADD DATA PREPARATION HERE -> DICTS add to dicts (TRY CATCH?)
    //TODO change all instances (below this point) to the modified component vector
    this->_weights = vector<vector<double>>(); //Assumes all rows are same length
    for(int i = 0; i < _hiddenLayers + 1; i++){
        _weights.emplace_back();
        for(int j = 0; j < componentVector.at(0).size(); j++){
            _weights.at(i).push_back(unif(re));
        }
    }
    displayWeights();
    //TODO Mess with epochs?
    for(int i = 0; i < _epochs; i++){
        cout << "Epoch " << (i + 1) << ":" << endl;

        cout << "------------------------------------------" << endl;
    }
    isTrained = true;
}

/*
 * Here is how this is going to work:
 * 1. The network is trained, and the weights are preemptively determined by the training method
 * 2. The row number is used to find the row to exclude from the inputData
 * 3. The remaining input data is conditioned using preexisting dicts (stored above)
 * 4. The prediction is run using a single output forward pass
 * 5. The value of the SOFP is either returned (if a double) or conditioned based on dicts
 */
template<typename T>
auto PredictiveNeuralNetwork<T>::getRowPrediction(vector<double> inputData, int row) {
    //TODO GET ROW DATA TYPE
    double result = 0;
    for(int i = 0; i < _hiddenLayers; i++){

    }
}

template<typename T>
void PredictiveNeuralNetwork<T>::displayWeights() {
    for(const vector<double>& v : _weights){
        for(double d : v){
            cout << d << ", ";
        }
        cout << "" << endl;
    }
}

//PRIVATE

template <typename T>
vector<string>* PredictiveNeuralNetwork<T>::getData() {
    return &trainDataVector;
}

template <typename T>
vector<vector<string>> PredictiveNeuralNetwork<T>::getDataAsTypeComponents(char delimiter) {
    vector<vector<string>> ret;
    for(const string& temp : trainDataVector) {
        vector<string> lineVec;
        stringstream ss(temp);
        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            lineVec.push_back(substr);
        }
        ret.push_back(lineVec);
        lineVec.clear();
    }
    ret.erase(ret.begin());
    return ret;
}

template<typename T>
vector<string> PredictiveNeuralNetwork<T>::getDataRow(int rowNum) {
    vector<string> ret = vector<string>();
    for(vector<string> vec : getDataAsTypeComponents(',')){
        ret.push_back(vec.at(rowNum));
    }
    return ret;
}