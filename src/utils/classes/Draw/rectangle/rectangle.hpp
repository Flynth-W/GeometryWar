#pragma once

#include "../../shader.hpp"


class RectangleDraw{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 *model;
    public:
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setPosition(glm::mat4 *model);
        void setShader(Shader shader);
};
