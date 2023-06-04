#pragma once

#include "../../shader.hpp"


class RectangleDraw{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 *model;
        unsigned int size;
    public:
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setPosition(glm::mat4 *model);
        void setShader(Shader shader);
        void setSize(int size);
        bool pointIn(int x , int y);
};
