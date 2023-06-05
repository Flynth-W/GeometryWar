#include "beginGame.hpp"

void BeginGame::Init(){


    this->rectangle=StartButton();
    this->stage=Stages::beginGame;
};
void BeginGame::Update(){
    if( Event::getIfStateKey(keys, GLFW_KEY_ENTER,ButtonState::Released ) ){
        this->stage=Stages::one;
    }
    bool clik=false;
    if( Event::getIfStateKey(mouseKeys, GLFW_MOUSE_BUTTON_LEFT,ButtonState::Pressed ) ){
       clik=true; 
    }
    if( clik && rectangle.pointIn(mouse->x, mouse->y)  ){
        this->stage=Stages::one;
    }
};
void BeginGame::Render(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f, 0.0f, 0.0f,1.0f);
    this->rectangle.Render();
};

void BeginGame::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void BeginGame::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void BeginGame::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void BeginGame::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};

Stages BeginGame::getStage(){
    return this->stage ;
}
