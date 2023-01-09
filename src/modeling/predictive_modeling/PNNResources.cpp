//
// Created by zlhartma on 1/4/2023.
//

#include <sstream>
#include <vector>

#include "PNNResources.h"

using namespace PENNResources;
using namespace std;

double PNNResources::sigmoid(double val){

}

vector<string> PNNResources::getCSVAsStringVector(fstream ifread, const string& fileName) {
    vector<string> temp;
    ifread.open(fileName);
    string currLine;
    while(getline(ifread, currLine)){
        temp.push_back(currLine);
    }
    ifread.close();
    return temp;
}

