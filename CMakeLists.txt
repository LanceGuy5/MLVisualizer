cmake_minimum_required(VERSION 3.24)
project(Neural_Network_Visualizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Neural_Network_Visualizer main.cpp src/modeling/predictive_modeling/PredictiveNeuralNetwork.cpp src/modeling/predictive_modeling/PredictiveNeuralNetwork.h src/modeling/predictive_modeling/PredictiveNeuralNetwork.h src/modeling/Model.cpp src/modeling/Model.h src/modeling/Model.h src/resource_methods/Constants.h src/resource_methods/Resources.cpp src/resource_methods/Resources.h src/resource_methods/Resources.h)
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
