#include "objets.hpp"

RectangleDraw StartButton(){

    RectangleDraw rectangle;
    glm::mat4 model = glm::mat4(1.0f);
    rectangle.setPosition(&model);
    Shader shadera("./shader/square.vs" ,"./shader/square.fs");
    rectangle.setShader(shadera);
    float vertex[] = {
        // positions          // normals           
        -0.2f, -0.2f, 0.0f,  1.0f,  1.0f, 1.0f,  
         0.2f, -0.2f, 0.0f,  1.0f,  1.0f, 1.0f,  
         0.2f,  0.2f, 0.0f,  1.0f,  1.0f, 1.0f,  
         
         0.2f,  0.2f, 0.0f,  1.0f,  1.0f, 1.0f,  
        -0.2f,  0.2f, 0.0f,  1.0f,  1.0f, 1.0f,  
        -0.2f, -0.2f, 0.0f,  1.0f,  1.0f, 0.0f,  
    };
    rectangle.setVetices(vertex,sizeof(vertex));
    rectangle.setSize(100);
    return rectangle;
};
