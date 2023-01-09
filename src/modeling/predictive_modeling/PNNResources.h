//
// Created by zlhartma on 1/4/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_PNNRESOURCES_H
#define NEURAL_NETWORK_VISUALIZER_PNNRESOURCES_H

#include <fstream>
using namespace std;

namespace PENNResources {
    class PNNResources {
    public:
        static double sigmoid(double val);
        static vector<string> getCSVAsStringVector(fstream ifread, const string& fileName);
    };
}


#endif //NEURAL_NETWORK_VISUALIZER_PNNRESOURCES_H
