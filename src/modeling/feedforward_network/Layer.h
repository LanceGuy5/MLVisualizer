//
// Created by zlhartma on 3/9/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_LAYER_H
#define NEURAL_NETWORK_VISUALIZER_LAYER_H


#include <vector>
#include <random>

/**
 * The whole purpose of the layer class is to store one type of information -> a list of random numbers
 * which represent weights for each individual layer. They are properly formatted using an algorithm
 * in the constructor in Layer.cpp which assigns them each their own double[][] of the proper size
 * to ensure that they can be dotted properly (when using multiple layers, very important).
 */
class Layer {
public:
    Layer(int neurons, int inputsPerNeuron);
    void displayWeights();
    double dot(Layer l2);
private:
    int neurons{};
    int inputsPerNeuron{};
    std::vector<std::vector<double>> weights{};
    std::uniform_real_distribution<double> unif{0, 0.01};
    std::default_random_engine re{43};
};


#endif //NEURAL_NETWORK_VISUALIZER_LAYER_H
