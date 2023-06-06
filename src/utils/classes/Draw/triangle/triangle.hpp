#pragma once

#include "../../shader.hpp"


class Triangle{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        float *angle;
        unsigned int size;
        glm::vec3 *translate;
    public:
        Triangle();
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setShader(Shader shader);
        void setPosition(glm::vec3 * position);
        void setAngle(float *angle);

        void move(double x , double y);
        void rotate(float angle);
};
