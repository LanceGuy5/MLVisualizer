//
// Created by zlhartma on 1/4/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_RESOURCES_H
#define NEURAL_NETWORK_VISUALIZER_RESOURCES_H

#include <fstream>
#include <vector>
#include <set>

using namespace std;

class Resources {
public:
    static double sigmoid(double val);
    static double sigmoidDerivative(double val);
    static double tanhActivation(double val);
    static double reluActivation(double val, double beta);
    static double dotProduct(std::vector<double> one, std::vector<double> two);
    static double singleOutputForwardPass(std::vector<double> one, std::vector<double> two, double (*activation)(double));
    static double logCoshLoss(double real, double pred);
    static vector<string> getCSVAsStringVector(fstream ifread, const string& fileName);
    static std::set<std::string> tokenizeWords(string arr[]);
};


#endif //NEURAL_NETWORK_VISUALIZER_RESOURCES_H
