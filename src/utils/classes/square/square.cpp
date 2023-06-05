#include "square.hpp"

void Square::Init(){
    Shader shadera("./shader/square.vs" ,"./shader/square.fs");
    square.setShader(shadera);
    float vertex[] = {
        // positions          // normals           
        -0.03f, -0.03f, 0.0f,  1.0f,  1.0f, 1.0f,  
         0.03f, -0.03f, 0.0f,  1.0f,  1.0f, 1.0f,  
         0.03f,  0.03f, 0.0f,  1.0f,  1.0f, 1.0f,  
         
         0.03f,  0.03f, 0.0f,  1.0f,  1.0f, 1.0f,  
        -0.03f,  0.03f, 0.0f,  1.0f,  1.0f, 1.0f,  
        -0.03f, -0.03f, 0.0f,  1.0f,  1.0f, 0.0f,  
    };
    square.setVetices(vertex,sizeof(vertex));
    this->radius=0.03;
    this->position=glm::vec3(0.0);
    square.setPosition(&position);
}
void Square::Update(){
    double speed = *deltaTime * 0.2;
    //square.move(speed,speed);
}
void Square::Render(){
    square.Render();
}
void Square::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Square::setRadius(unsigned int radius){
    this->radius=radius;
}

glm::vec3 Square::getPosition(){
    return this->position;
}
double Square::getRadio(){
    return this->radius;
}
