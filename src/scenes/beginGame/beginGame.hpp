#pragma once
#include "../stage.hpp"
#include "../../utils/classes/Draw/rectangle/rectangle.hpp"
#include "../../factory/objets/objets.hpp"

class BeginGame:public Stage{
    private:
        double *deltaTime;
        RectangleDraw rectangle;
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
        Stages stage;
    public:
        void Init()   override;
        void Update() override;
        void Render() override;
        void setDeltaTime(double *deltaTime) override;
        void setMouse(Mouse *mouse) override;
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) override;
        void setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys) override;
        Stages getStage()override;
        
};
