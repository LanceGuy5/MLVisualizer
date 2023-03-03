cmake_minimum_required(VERSION 3.24)
project(Neural_Network_Visualizer)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory("src/rendering/imgui")

add_executable(Neural_Network_Visualizer main.cpp src/modeling/feedforward_network/PredictiveNeuralNetwork.cpp src/modeling/feedforward_network/PredictiveNeuralNetwork.h src/modeling/feedforward_network/PredictiveNeuralNetwork.h src/modeling/Model.cpp src/modeling/Model.h src/modeling/Model.h src/resource_methods/Constants.h src/resource_methods/Resources.cpp src/resource_methods/Resources.h src/resource_methods/Resources.h src/rendering/Renderer.cpp src/rendering/Renderer.h)
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
