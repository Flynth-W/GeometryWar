#pragma once

#include "../../shader.hpp"


class DrawBullet{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        glm::vec3 translate=glm::vec3(0.0);
        glm::vec3 position;
        float angle=0.0f;
    public:
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setShader(Shader shader);
        void setPosition(glm::vec3  position);
        
        void move(double x , double y);
        void rotate(float angle);
};
