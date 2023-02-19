//
// Created by zlhartma on 1/7/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_MODEL_H
#define NEURAL_NETWORK_VISUALIZER_MODEL_H

#include <cmath>

// Abstract class to establish general features about what defines a "Model"
// Allows for opening/saving models with ease
class Model {
public:
    Model(int _inputNodes,
          int _hiddenLayers,
          int _outputNodes,
          int _epochs,
          double _learningRate,
          double _allowedError);
    void save();
    virtual void load() = 0;
    virtual void train() = 0;
protected:
    int _inputNodes{};
    int _hiddenLayers{};
    int _outputNodes{};
    int _epochs{};
    double _bias{};
    double _learningRate{};
    double _allowedError{};
    int _hiddenNodesPerLayer = floor(_inputNodes * (2.0 / 3.0) + _outputNodes);
    int _hiddenLayerWeightNumber = _inputNodes * _hiddenNodesPerLayer;
    //TODO DETERMINE OTHER VARIABLES NEEDED
};

#endif //NEURAL_NETWORK_VISUALIZER_MODEL_H
