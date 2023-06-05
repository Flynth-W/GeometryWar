#pragma once

#include "../Draw/triangle/triangle.hpp"
#include "../../../event/events.hpp"
#include "../collision.hpp"

class Nave:public Iobjet_colicion{
    private:
        Triangle triangle;
        double radio;
        double * deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
    public:
        void Init();
        void Update();
        void setDeltaTime(double *deltaTime);
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) ;
        void Render();

        glm::vec3 getPosition() override;
        double getRadio() override;
};
