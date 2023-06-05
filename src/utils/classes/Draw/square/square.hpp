#pragma once

#include "../../shader.hpp"


class DrawSquare{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        glm::vec3 *translate;
    public:
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setShader(Shader shader);
        void setPosition(glm::vec3 * position);
        
        void move(double x , double y);
};
