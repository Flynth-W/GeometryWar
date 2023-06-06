#pragma once

#include "../collision.hpp"
#include "../square/square.hpp"

using namespace std;

class SysSquare{
    public:
        int numSquares; 
        unordered_map<int,Square *> squares;
        unordered_map<Square *, int> keySquares;
        CollisionsHandler *handleCollision;
        double *deltaTime;
    public:
        void Init();
        void Update();
        void Render();

        void AddSquare();
        void setDeltaTime(double *deltaTime);
        void setCollisionHandler(CollisionsHandler *handleCollision);
};
