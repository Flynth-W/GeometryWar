#pragma once
#include "../stage.hpp"

class BeginGame:public Stage{
    private:
        double *deltaTime;
    public:
        void Init()   override;
        void Update() override;
        void Render() override;
        void setDeltaTime(double *deltaTime) override;
};
