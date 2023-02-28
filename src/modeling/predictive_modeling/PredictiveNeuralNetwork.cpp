//
// Created by zlhartma on 1/6/2023.
//

#include <vector>
#include <typeinfo>
#include <iostream>
#include <sstream>
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
        int hiddenLayers, int outputNodes, int epochs, double learningRate, double allowedError, ERR_FUNC func):
    Model(inputNodes, hiddenLayers, outputNodes, epochs, learningRate, allowedError) {
        this->_bias = unif(re);
        this->_func = func;
}

template <typename T> PredictiveNeuralNetwork<T>::~PredictiveNeuralNetwork() {
    //TODO Save file
//    delete(this->_weights);
//    delete(this->_dicts);
//    delete(this->trainDataVector);
//    delete(this->_bias);
}

//PUBLIC

template <typename T>
void PredictiveNeuralNetwork<T>::load(){

}

template <typename T>
void PredictiveNeuralNetwork<T>::insertTrainingData(const std::string& pathName, bool hasTitleRow) {
    vector<string> imported = Resources::getCSVAsStringVector(fstream(), pathName);
    if(hasTitleRow && !imported.empty()){
        imported.erase(imported.cbegin());
    }
    this->trainDataVector = imported;
    this->_weights = vector<vector<double>>(); //Assumes all rows are same length
    for(int i = 0; i < _hiddenLayers + 1; i++){
        _weights.emplace_back();
        for(int j = 0; j < trainDataVector.at(0).size(); j++){
            _weights.at(i).push_back(unif(re));
        }
    }
//    displayWeights();
}

template <typename T>
void PredictiveNeuralNetwork<T>::insertTestingData(const std::string& pathName, bool hasTitleRow) {
    vector<string> imported = Resources::getCSVAsStringVector(fstream(), pathName);
    if(hasTitleRow && !imported.empty()){
        imported.erase(imported.cbegin());
    }
    this->trainDataVector = imported;
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
void PredictiveNeuralNetwork<T>::train(int rowNum){
    vector<vector<string>> componentVector = getDataAsTypeComponents(',');
    vector<vector<double>> modCompVector = processDataForTraining(componentVector);
    for(const vector<double>& vec : modCompVector){
        cout << "NL: ";
        for(double d : vec){
            cout << d << ", ";
        }
        cout << endl;
    }
    //TODO Mess with epochs?
//    for(int i = 0; i < _epochs; i++){
//        cout << "Epoch " << (i + 1) << ":" << endl;
//        double error; //This is the error of our prediction -> result of the error function f(x)
//        double pred = getRowPrediction(); Make sure to access modified data before getting the row prediction
//        switch(_func){ //Finding the error based on a function determined by the user
//            case LOGCOSH:
////                error = Resources::logCoshLoss();
//        }
        //First, repeat this process for each individual layer of the graph
//        for(const vector<double>& layer : _weights){
//            double real = 0.0;
////            for(int j = 0; j < layer.size(); j++){
////                if(j == rowNum){
////                    //set the real variable to the value of modified componentvector at j
////                }else{
////                    //add modified componentvector * weight to error at point
////                }
////            }
//        }
//        cout << "------------------------------------------" << endl;
//    }
//    _isTrained = true;
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
double PredictiveNeuralNetwork<T>::getRowPrediction(vector<double> inputData, int row) {
    double result = 0;
    //Assume that inputData hasn't gotten rid of the row we are searching yet (?)
    inputData.erase(inputData.cbegin() + row); //TODO CHECK!
    return result;
}

/**
 * A tool to display the weights of the model
 * @tparam T Unused
 */
template<typename T>
void PredictiveNeuralNetwork<T>::displayWeights() {
    for(const vector<double>& v : _weights){
        for(double d : v){
            cout << d << ", ";
        }
        cout << "" << endl;
    }
}

/**
 * A tool to display the dictionaries of tokenized words
 * @tparam T Unused
 */
template<typename T>
void PredictiveNeuralNetwork<T>::displayDicts(){
    for(auto & _dict : _dicts){
        cout << "ROW " << _dict.first << ": " << _dict.second.size();
        for(auto & map : _dict.second){
            cout << map.first << " -> " << map.second << endl;
        }
    }
}

//PRIVATE

/**
 * Method to tokenize any strings within data to use for training
 * @tparam T Unused for this method!
 * @param dataVector The original data vector -> each element represented as a string
 * @return A new vector of exclusively doubles representing the raw data
 */
template<typename T>
vector<vector<double>> PredictiveNeuralNetwork<T>::processDataForTraining(vector<vector<string>> &dataVector) {
    //Assumes the title row has already been eliminated
    this->_dicts = map<int, map<string, int>>();
    for(int i = 0; i < dataVector.at(0).size(); i++){
        if(!Resources::isNumber(dataVector.at(0).at(i))){
            //Assumes that every element of data is either a number or a string
            map<string, int> tempDict = map<string, int>();
            double index = 1;
            for(vector<string> curr : dataVector){
                if(tempDict.find(curr.at(i)) == tempDict.end()){
                    tempDict.insert({curr.at(i), index});
                    index++;
                }
            }
            _dicts.insert({i, tempDict});
        }
    }
//    displayDicts();
    //Dicts can now be used throughout the program due to the fact that it is a instance variable
    // Having had dicts established, apply these to a new data vector that I return
    vector<vector<double>> ret = vector<vector<double>>();
    for(int i = 0; i < dataVector.at(0).size(); i++){
        for(int j = 0; j < dataVector.size(); j++){
            if(dataVector.size() >= j) ret.emplace_back();
            if(_dicts.find(i) != _dicts.end()){
                try{
                    ret.at(j).push_back(_dicts.at(i)[dataVector.at(j).at(i)]);
                }catch(const std::out_of_range&){
                    cout << "Key \"" << _dicts.at(i).at(dataVector.at(j).at(i)) << "\" was not found." <<endl;
                }
            }else {
                ret.at(j).push_back((double) Resources::getDoubleFromString(dataVector.at(j).at(i)));
            }
        }
    }
    for(int i = 0; i < ret.size(); i++){
        if(ret.at(i).empty()){
            ret.erase(ret.cbegin() + i);
            i = 0;
        }
    }
    return ret;
}

/**
 * @tparam T Unused in this method.
 * @return A pointer for training data.
 */
template <typename T>
vector<string>* PredictiveNeuralNetwork<T>::getData() {
    return &trainDataVector;
}

/**
 * A method that divides the most raw data (directly read from csv) into individual strings
 * TODO Breaks if commas exist within the data
 * @tparam T Unused
 * @param delimiter The character used to delimit the data
 * @return A vector<vector<string>> representing rows and columns of string data
 */
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

/**
 * Gets a specific row from the raw data, formats it
 * @tparam T Unused
 * @param rowNum The number of the row being read
 * @return a vector of strings representing the row
 */
template<typename T>
vector<string> PredictiveNeuralNetwork<T>::getDataRow(int rowNum) {
    vector<string> ret = vector<string>();
    for(vector<string> vec : getDataAsTypeComponents(',')){
        ret.push_back(vec.at(rowNum));
    }
    return ret;
}