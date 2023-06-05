#include "one.hpp"

void OneStage::Init(){
    this->stage=Stages::one;
    nave.setKeys(keys);
    nave.setDeltaTime(deltaTime);
    nave.Init();
};
void OneStage::Update(){
    nave.Update();
};
void OneStage::Render(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.03f, 0.05f,1.0f);
    nave.Render();
};

void OneStage::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void OneStage::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void OneStage::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void OneStage::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};

Stages OneStage::getStage(){
    return this->stage ;
}
