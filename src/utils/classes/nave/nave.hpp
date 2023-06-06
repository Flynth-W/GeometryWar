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
        bool run;
    public:
        void Init();
        void Update();
        void Render();
        void setDeltaTime(double *deltaTime);
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) ;
        bool getRun();

        glm::vec3 getPosition() override;
        double getRadio() override;
        void colision(Iobjet_colicion *a) override;
};
