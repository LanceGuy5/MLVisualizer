#include <iostream>
#include "src/modeling/predictive_modeling/PredictiveNeuralNetwork.cpp"

using namespace std;

int main() {
    PredictiveNeuralNetwork<int> network = PredictiveNeuralNetwork<int>(1, 1, 1, 1, 1.0, 0.7);
    cout << network.getRawDataType() << endl;
    network.insertData(R"(C:\Users\zlhartma\Downloads\pennsylvania-history.csv)");
    cout << network.getDataCopy().size() << endl;
    return 0;
}
