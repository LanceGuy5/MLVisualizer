//
// Created by zlhartma on 1/7/2023.
//

#include "Model.h"

Model::Model(int inputNodes,
             int hiddenLayers,
             int outputNodes,
             int epochs,
             double learningRate) {
    _inputNodes = inputNodes;
    _hiddenLayers = hiddenLayers;
    _outputNodes = outputNodes;
    _epochs = epochs;
    _learningRate = learningRate;
}

void Model::save() {

}
