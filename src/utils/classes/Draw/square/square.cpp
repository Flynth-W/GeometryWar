#include "square.hpp"
#include <iostream>

void DrawSquare::Render(){
    this->shader->use();
    this->model = glm::mat4(1.0);
    this->model = glm::translate(this->model,*translate );
    this->shader->setMat4("model", model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void DrawSquare::setShader(Shader shader){
    this->shader=new Shader(shader);
}

void DrawSquare::setVetices(float *vertex, unsigned int vertexSize){
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
void DrawSquare::move(double x, double y){
    *this->translate= *this->translate + glm::vec3(x,y,0.0f);
}

void DrawSquare::setPosition(glm::vec3 *position){
    this->translate=position;
}
