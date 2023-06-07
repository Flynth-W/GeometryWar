#pragma once

#include "../Draw/triangle/triangle.hpp"
#include "../../../event/events.hpp"
#include "../collision.hpp"
#include "../sysBullets/sysBullet.hpp"

class Nave:public Iobjet_colicion{
    private:
        Triangle triangle;
        double radio;
        double * deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
        bool run=false;
        SysBullet bullets;
        float angle;
        CollisionsHandler *handleCollision;
    public:
        void Init();
        void Update();
        void Render();
        void setCollisionHandler(CollisionsHandler *handleCollision);
        void setDeltaTime(double *deltaTime);
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) ;
        bool getRun() override;

        glm::vec3 getPosition() override;
        double getRadio() override;
        void colision(Iobjet_colicion *a) override;
};
