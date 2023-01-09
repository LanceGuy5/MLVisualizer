//
// Created by zlhartma on 1/6/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
#define NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H

#include "PNNResources.h"
#include "../Model.h"

class PredictiveNeuralNetwork : public Model{
public:
    PredictiveNeuralNetwork(int inputLayers);
    ~PredictiveNeuralNetwork();
    void load();
};

#endif //NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
