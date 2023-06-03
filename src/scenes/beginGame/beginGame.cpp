#include "beginGame.hpp"

void BeginGame::Init(){


    this->rectangle=StartButton();

};
void BeginGame::Update(){};
void BeginGame::Render(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f, 0.0f, 0.0f,1.0f);
    this->rectangle.Render();
};

void BeginGame::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
