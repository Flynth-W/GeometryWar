#pragma once

#include "../collision.hpp"
#include "../square/square.hpp"
#include <queue>

using namespace std;

class SysSquare{
    public:
        int numSquares; 
        unordered_map<int,Square *> squares;
        unordered_map<Square *, int> keySquares;
        CollisionsHandler *handleCollision;
        double *deltaTime;
        queue<int> deleteSquares;
        float createTime;
    public:
        void Init();
        void Update();
        void Render();

        void AddSquare();
        void removeSquare();
        void setDeltaTime(double *deltaTime);
        void setCollisionHandler(CollisionsHandler *handleCollision);
};
