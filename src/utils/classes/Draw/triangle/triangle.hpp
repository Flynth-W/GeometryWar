#pragma once

#include "../../shader.hpp"


class Triangle{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        glm::vec3 translate;
        float angle;
        unsigned int size;
    public:
        Triangle();
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setShader(Shader shader);

        void move(double x , double y);
        void rotate(float angle);
};
