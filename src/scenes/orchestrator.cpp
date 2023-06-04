#include "orchestrator.hpp"

void Orchestrator::Init(){
    typeStage = Stages::beginGame;
    stage = new BeginGame();
    stage->setMouse(mouse);
    stage->setKeys(keys);
    stage->setMouseKeys(mouseKeys);
    stage->Init();

}

void Orchestrator::Update(){
    stage->Update();
}

void Orchestrator::Render(){
    stage->Render();
}

void Orchestrator::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
    stage->setDeltaTime(deltaTime);
}
void Orchestrator::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void Orchestrator::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void Orchestrator::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};
