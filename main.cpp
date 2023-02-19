#include <iostream>
#include "src/modeling/predictive_modeling/PredictiveNeuralNetwork.cpp"

using namespace std;

int main() {
    PredictiveNeuralNetwork<int> network = PredictiveNeuralNetwork<int>(1, 1, 1, 1, 1.0, 0.7);
    cout << network.getRawDataType() << endl;
    network.insertTrainingData(R"(C:\Users\zlhartma\Downloads\kidney_data.csv)");
//    for(const string& s : network.getDataCopy()) {
//        cout << "NL: " << s << endl;
//    }
    cout << network.getDataCopy().size() << endl;
    network.train();
    return 0;
}
