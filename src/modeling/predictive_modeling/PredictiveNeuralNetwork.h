//
// Created by zlhartma on 1/6/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
#define NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H

#include <vector>
#include "../Model.h"

template <typename T> class PredictiveNeuralNetwork : public Model{
public:
    PredictiveNeuralNetwork(int inputNodes,
                            int hiddenLayers,
                            int outputNodes,
                            int epochs,
                            double learningRate,
                            double allowedError);
//    ~PredictiveNeuralNetwork(); //TODO DEFINE CONSTRUCTOR
    void load() override;
    void insertData(const std::string& pathName);
    std::vector<std::string> getDataCopy();
    std::string getRawDataType();
    void train() override;
private:
    std::vector<std::string> dataVector{};
    std::vector<std::string>* getData();
    std::vector<std::vector<std::string>> getDataAsTypeComponents(char delimiter);
};

#endif //NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
