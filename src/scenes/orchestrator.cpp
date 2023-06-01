#include "orchestrator.hpp"

void Orchestrator::Init(){
    typeStage = Stages::beginGame;
    stage = new BeginGame();
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
