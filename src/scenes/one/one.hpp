#pragma once
#include "../stage.hpp"
#include "../../utils/classes/nave/nave.hpp"
#include "../../utils/classes/square/square.hpp"
#include "../../utils/classes/sysSquares/sysSquares.hpp"
#include "../../utils/classes/bullet/bullet.hpp"
#include "../../utils/classes/song/song.hpp"

class OneStage:public Stage{
    private:
        double *deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
        Stages stage;
        Nave nave;
        //Square square;
        SysSquare sysSquare;
        CollisionsHandler handleCollision;
        Song *song;
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
