#include "bullet.hpp"
#include <iostream>

void DrawBullet::Init(){
    this->translate=glm::vec3(0.0);
    this->angle=0.0f;
    this->model = glm::mat4(1.0);
    this->model = glm::translate(this->model,this->initialPosition );
    this->model = glm::rotate(this->model, this->angle, glm::vec3(0.0f, 0.0f, 1.0f));
    this->model = glm::translate(this->model,this->translate );
    
    this->position= new glm::vec3(this->model[3][0],this->model[3][1],0.0);
}
void DrawBullet::Render(){
    this->shader->use();
    this->model = glm::mat4(1.0);
    this->model = glm::translate(this->model,this->initialPosition );
    this->model = glm::rotate(this->model, this->angle, glm::vec3(0.0f, 0.0f, 1.0f));
    this->model = glm::translate(this->model,this->translate );
    
    *this->position=glm::vec3(this->model[3][0],this->model[3][1],0.0);

    this->shader->setMat4("model", model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void DrawBullet::setShader(Shader shader){
    this->shader=new Shader(shader);
}

void DrawBullet::setVetices(float *vertex, unsigned int vertexSize){
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
void DrawBullet::move(double x, double y){
    this->translate= this->translate + glm::vec3(x,y,0.0f);
}
glm::vec3 DrawBullet::getPosition(){
    return *this->position;
} 

void DrawBullet::setPosition(glm::vec3 position){
    this->initialPosition=position;

}
void DrawBullet::rotate(float angle){
    this->angle += angle;
}
