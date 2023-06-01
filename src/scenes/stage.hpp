#pragma once
#include <GL/glew.h>

enum class Stages{
    beginGame,
    one,
};

class Stage{
    public:
        virtual void Init(){};
        virtual void Update(){};
        virtual void Render(){};
        virtual Stages getStage(){return Stages::beginGame;};
        virtual void setDeltaTime(double *deltaTime){};
};
