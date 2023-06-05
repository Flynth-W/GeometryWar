#include "nave.hpp"

void Nave::Init(){
    Shader shadera("./shader/square.vs" ,"./shader/square.fs");
    triangle.setShader(shadera);
    float vertex[] = {
        // positions          // normals           
        -0.04f, -0.04f, 0.0f,  0.0f,  0.4f, 0.7f,  
         0.04f, -0.04f, 0.0f,  0.0f,  0.4f, 0.7f,  
         0.0f,  0.04f, 0.0f,   0.0f,  0.2f, 0.5f,  
         
    };
    triangle.setVetices(vertex,sizeof(vertex));
    this->radio=0.04;
    this->position= glm::vec3(-0.8);
    triangle.setPosition(&this->position);

    Event::setKey(keys, GLFW_KEY_J);
    Event::setKey(keys, GLFW_KEY_L);
    Event::setKey(keys, GLFW_KEY_I);
}
void Nave::Update(){
    float translationSpeed = 0.5;
    float rotationSpeed = 1.0;
    if(Event::getIfStateKey(keys,GLFW_KEY_W, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.move(0.0f, float( translationSpeed * *deltaTime ) );
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_S, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.move(0.0f, float( - translationSpeed * *deltaTime ) );
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_A, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.move(float( -translationSpeed * *deltaTime ) , 0.0f);
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_D, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.move(float( translationSpeed * *deltaTime ) , 0.0f);
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_J, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.rotate(float( rotationSpeed * *deltaTime ));
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_L, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.rotate(float( -rotationSpeed * *deltaTime ));
    }
}
void Nave::Render(){
    triangle.Render();
}
void Nave::setDeltaTime(double *deltaTime){
    this->deltaTime = deltaTime;
}
void Nave::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};

glm::vec3 Nave::getPosition(){
    return this->position;
}
double Nave::getRadio(){
    return this->radio;
}
