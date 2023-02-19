//
// Created by zlhartma on 1/6/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
#define NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H

#include <vector>
#include <set>
#include "../Model.h"

template <typename T>
class PredictiveNeuralNetwork : public Model{
public:
    PredictiveNeuralNetwork(int inputNodes,
                            int hiddenLayers,
                            int outputNodes,
                            int epochs,
                            double learningRate,
                            double allowedError);
    ~PredictiveNeuralNetwork(); //TODO DEFINE DECONSTRUCTOR
    void load() override;
    void insertTrainingData(const std::string& pathName);
    void insertTestingData(const std::string& pathName);
    std::vector<std::string> getDataCopy();
    std::string getRawDataType();
    void train() override;
    auto getRowPrediction(std::vector<double> inputData, int row);
    void displayWeights();
private:
    std::vector<std::string> trainDataVector{};
    std::vector<std::string> testDataVector{};
    std::vector<std::string>* getData();
    std::vector<std::vector<std::string>> getDataAsTypeComponents(char delimiter);
    std::vector<std::string> getDataRow(int rowNum);
    std::list<std::set<int>> sets;
    std::vector<std::vector<double>> _weights;
    std::uniform_real_distribution<double> unif{0, 1};
    std::default_random_engine re{43};
    std::list<std::set<std::string>> dicts;
    bool isTrained{false};
};

#endif //NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
