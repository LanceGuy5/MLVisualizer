//
// Created by zlhartma on 1/6/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
#define NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H

#include <vector>
#include <set>
#include <map>
#include "../Model.h"

enum ERR_FUNC{
    LOGCOSH
};

template <typename T>
class PredictiveNeuralNetwork : public Model{
public:
    PredictiveNeuralNetwork(int inputNodes,
                            int hiddenLayers,
                            int outputNodes,
                            int epochs,
                            double learningRate,
                            double allowedError,
                            ERR_FUNC func);
    ~PredictiveNeuralNetwork(); //TODO DEFINE DECONSTRUCTOR
    void load() override;
    void insertTrainingData(const std::string& pathName, bool hasTitleRow);
    void insertTestingData(const std::string& pathName, bool hasTitleRow);
    std::vector<std::string> getDataCopy();
    std::string getRawDataType();
    void train(int rowNum) override;
    double getRowPrediction(std::vector<double> inputData, int ignoredColumn [], int numIgnored);
    void displayWeights();
    void displayDicts();
private:
    std::vector<std::string> trainDataVector;
    std::vector<std::string> testDataVector{};
    std::vector<std::string>* getData();
    std::vector<std::vector<std::string>> getDataAsTypeComponents(char delimiter);
    std::vector<std::string> getDataRow(int rowNum);
    std::vector<std::vector<double>> processDataForTraining(std::vector<std::vector<std::string>>& dataVector);
//    std::list<std::set<int>> _sets;
    std::vector<std::vector<double>> _weights;
    std::uniform_real_distribution<double> unif{0, 0.01};
    std::default_random_engine re{43};
    std::map<int, std::map<std::string, int>> _dicts;
    bool _isTrained{false};
    ERR_FUNC _func{};
};

#endif //NEURAL_NETWORK_VISUALIZER_PREDICTIVENEURALNETWORK_H
