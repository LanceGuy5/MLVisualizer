//
// Created by zlhartma on 2/16/2023.
//

#ifndef NEURAL_NETWORK_VISUALIZER_RENDERER_H
#define NEURAL_NETWORK_VISUALIZER_RENDERER_H

#include <thread>

class Renderer {
public:
    explicit Renderer(const char* name);
    ~Renderer();
    bool* getRunning();
    void setRunning(const bool* running);
private:
    void runWindow(const char* name);
};


#endif //NEURAL_NETWORK_VISUALIZER_RENDERER_H
