#include <iostream>
#include "src/modeling/predictive_modeling/PredictiveNeuralNetwork.cpp"

using namespace std;

int main() {
    PredictiveNeuralNetwork<int> network = PredictiveNeuralNetwork<int>(1, 1, 1, 1, 1.0);
    cout << network.getRawDataType() << endl;
    return 0;
}
