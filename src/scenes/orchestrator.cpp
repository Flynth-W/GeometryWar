#include "orchestrator.hpp"

void Orchestrator::Init(){
    stage = new BeginGame();
    stage->setMouse(mouse);
    stage->setKeys(keys);
    stage->setMouseKeys(mouseKeys);
    stage->Init();
    typeStage = stage->getStage();

}

void Orchestrator::Update(){
    if(typeStage == stage->getStage() ){
        stage->Update();
        return;
    }
    typeStage = stage->getStage();
    this->changeStage();
    return;
}
void Orchestrator::changeStage(){
    switch (typeStage) {
        case Stages::beginGame:
            stage = new BeginGame();
            stage->setMouse(mouse);
            stage->setKeys(keys);
            stage->setMouseKeys(mouseKeys);
            stage->Init();
          break;
        case Stages::one:
            stage = new OneStage();
            stage->setMouse(mouse);
            stage->setKeys(keys);
            stage->setMouseKeys(mouseKeys);
            stage->Init();
          break;
    }
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
