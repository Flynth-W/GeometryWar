#include "beginGame.hpp"

void BeginGame::Init(){};
void BeginGame::Update(){};
void BeginGame::Render(){
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
};

void BeginGame::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
