#pragma once
#include "../Draw/square/square.hpp"
#include "../collision.hpp"

class Square:public Iobjet_colicion{
    private:
        double * deltaTime;
        DrawSquare square;
        double radius;
    public:
        void Init();
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
        void setRadius(unsigned int radius);
        
        glm::vec3 getPosition() override;
        double getRadio() override;
};
