#pragma once
#include "../Draw/bullet/bullet.hpp"
#include "../collision.hpp"

class Bullet:public Iobjet_colicion{
    private:
        double * deltaTime;
        DrawBullet square;
        double radius;
        bool run=false;
    public:
        void Init(glm::vec3 position , float angle);
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
        void setRadius(unsigned int radius);
        bool getRun();
        
        glm::vec3 getPosition() override;
        double getRadio() override;
        void colision(Iobjet_colicion *a) override;
};
