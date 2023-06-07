#pragma once
#include "../Draw/square/square.hpp"
#include "../collision.hpp"

class Square:public Iobjet_colicion{
    private:
        double * deltaTime;
        DrawSquare square;
        double radius;
        bool run=false;
        double direction[2];
    public:
        void Init(double x,double y);
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
        void setRadius(unsigned int radius);
        bool getRun() override;
        
        glm::vec3 getPosition() override;
        double getRadio() override;
        void colision(Iobjet_colicion *a) override;
};
