//
// Created by zlhartma on 2/16/2023.
//

#include "Renderer.h"
//#include "imgui/imgui.cpp"
#include <iostream>

using namespace std;
bool isRunning = true;

Renderer::Renderer(const char* name) {
    runWindow(name);
}

Renderer::~Renderer() {

}

void Renderer::runWindow(const char* name) {
//    if(ImGui::Begin(name, getRunning(), ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove)){
//        ImGui::End();
//    }else{
//        cout << "FATAL ERROR - SCREEN RENDERING" << endl;
//    }
}

bool *Renderer::getRunning() {
    return &isRunning;
}

void Renderer::setRunning(const bool *running) {
    isRunning = running;
}
