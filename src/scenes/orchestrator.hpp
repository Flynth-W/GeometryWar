#pragma once
#include "beginGame/beginGame.hpp"

class Orchestrator{
    private:
        Stage *stage;
        Stages typeStage;
        double *deltaTime;
    public:
        void Init();
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
};
