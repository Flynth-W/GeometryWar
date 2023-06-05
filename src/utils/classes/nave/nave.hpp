#pragma once

#include "../Draw/triangle/triangle.hpp"
#include "../../../event/events.hpp"

class Nave{
    private:
        int position[2];
        Triangle triangle;
        double * deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
    public:
        void Init();
        void Update();
        void setDeltaTime(double *deltaTime);
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) ;
        void Render();
};
