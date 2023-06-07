#pragma once

#include "../bullet/bullet.hpp"

class SysBullet{
    public:
        int numBullets; 
        unordered_map<int,Bullet *> bullets;
        unordered_map<Bullet *, int> keyBullets;
        CollisionsHandler *handleCollision;
        double *deltaTime;
        bool limitBall=false;
    public:
        void Init();
        void Update();
        void Render();

        void AddBullet(glm::vec3 position, float angle);
        void setDeltaTime(double *deltaTime);
        void setCollisionHandler(CollisionsHandler *handleCollision);
};
