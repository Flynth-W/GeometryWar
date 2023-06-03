#include "rectangle.hpp"
#include <iostream>

void RectangleDraw::Render(){
    this->shader->use();
    this->shader->setMat4("model", *model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void RectangleDraw::setShader(Shader shader){
    this->shader=new Shader(shader);
}

void RectangleDraw::setPosition(glm::mat4 *model){
    this->model=model;
}

void RectangleDraw::setVetices(float *vertex, unsigned int vertexSize){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
