#include "triangle.hpp"
#include <iostream>

Triangle::Triangle(){
    this->model = glm::mat4(1.0);

//    this->model=glm::translate(model, glm::vec3(4.0f, 80.0f, 0.0f));
}
void Triangle::Render(){
    this->shader->use();
    this->model = glm::mat4(1.0);
    this->model = glm::translate(this->model,translate );
    this->model = glm::rotate(this->model, this->angle, glm::vec3(0.0f, 0.0f, 1.0f));
    
    this->shader->setMat4("model", this->model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Triangle::setShader(Shader shader){
    this->shader=new Shader(shader);
}

void Triangle::setVetices(float *vertex, unsigned int vertexSize){
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

void Triangle::move(double x, double y){
    this->translate= this->translate + glm::vec3(x,y,0.0f);
}
void Triangle::rotate(float angle){
    this->angle += angle;
}
