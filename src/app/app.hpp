#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../scenes/orchestrator.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class App{
    public:
        GLFWwindow *window;
        double deltaTime;
        Orchestrator orchestrator;
    private:
        unsigned int height, width;
        const char *title = "Asteroid"; 
    public:
        App();
        ~App();
        void Init();
        void Events();
        void Update();
        void Render();
        
        bool getRun();
};
