#include "app.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
App::App(){
    this->height=1000;
    this->width=1000;
};

void App::Init(){
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(height, width, title, NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glewInit();
    orchestrator.Init();
}

void App::Events(){
    glfwPollEvents();  
};

void App::Update(){
    orchestrator.Update();
}

void App::Render(){
    orchestrator.Render();
    glfwSwapBuffers(window);
};

void App::setKeys(std::unordered_map<int, ButtonKey> *_keys){
  keys=_keys;
}
void App::setMouse(Mouse *_mouse){
  mouse =_mouse;
}
void App::setMouseKeys(std::unordered_map<int, ButtonKey> *_mousekeys){
  mouseKeys=_mousekeys;
}
bool App::getRun(){
  return (!glfwWindowShouldClose(window) ) ;
}
App::~App(){};
