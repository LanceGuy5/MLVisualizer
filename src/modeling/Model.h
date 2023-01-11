//
// Created by zlhartma on 1/7/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_MODEL_H
#define NEURAL_NETWORK_VISUALIZER_MODEL_H

// Abstract class to establish general features about what defines a "Model"
// Allows for opening/saving models with ease
class Model {
public:
    Model(int _inputNodes,
          int _hiddenLayers,
          int _outputNodes,
          int _epochs,
          double _learningRate);
    void save();
    virtual void load() = 0;
protected:
    int _inputNodes{};
    int _hiddenLayers{};
    int _outputNodes{};
    int _epochs{};
    double _learningRate{};
    //TODO DETERMINE OTHER VARIABLES NEEDED
};

#endif //NEURAL_NETWORK_VISUALIZER_MODEL_H
