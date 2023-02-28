#include <iostream>
#include "src/modeling/predictive_modeling/PredictiveNeuralNetwork.cpp"
#include "src/modeling/predictive_modeling/PredictiveNeuralNetwork.h"

using namespace std;

int main() {
    PredictiveNeuralNetwork<int> network = PredictiveNeuralNetwork<int>(1, 1, 1, 1, 1.0, 0.7, ERR_FUNC::LOGCOSH);
//    cout << network.getRawDataType() << endl;
    network.insertTrainingData(R"(C:\Users\zlhartma\Downloads\train.csv)", true);
//    for(const string& s : network.getDataCopy()) {
//        cout << "NL: " << s << endl;
//    }
//    cout << network.getDataCopy().size() << endl;
    network.train(4);
    return 0;
}
