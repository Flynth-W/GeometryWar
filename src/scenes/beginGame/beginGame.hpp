#pragma once
#include "../stage.hpp"
#include "../../utils/classes/Draw/rectangle/rectangle.hpp"
#include "../../factory/objets/objets.hpp"
class BeginGame:public Stage{
    private:
        double *deltaTime;
        RectangleDraw rectangle;
    public:
        void Init()   override;
        void Update() override;
        void Render() override;
        void setDeltaTime(double *deltaTime) override;
        
};
