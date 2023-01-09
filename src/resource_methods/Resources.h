//
// Created by zlhartma on 1/4/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_RESOURCES_H
#define NEURAL_NETWORK_VISUALIZER_RESOURCES_H

#include <fstream>
#include <vector>

using namespace std;

class Resources {
public:
    static double sigmoid(double val);
    static vector<string> getCSVAsStringVector(fstream ifread, const string& fileName);
};


#endif //NEURAL_NETWORK_VISUALIZER_RESOURCES_H
