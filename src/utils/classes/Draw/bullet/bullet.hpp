#pragma once

#include "../../shader.hpp"


class DrawBullet{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        glm::vec3 translate=glm::vec3(0.0);
        glm::vec3 initialPosition;
        float angle=0.0f;
    public:
        glm::vec3 *position;
    public:
        void Init();
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setShader(Shader shader);
        void setPosition(glm::vec3  position);
        glm::vec3 getPosition();
        
        void move(double x , double y);
        void rotate(float angle);
};
