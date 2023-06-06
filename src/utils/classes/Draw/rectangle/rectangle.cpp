#include "rectangle.hpp"
#include <iostream>

void RectangleDraw::Render(){
    this->shader->use();
    this->model = glm::mat4(1.0);
    this->shader->setMat4("model", model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void RectangleDraw::setShader(Shader shader){
    this->shader=new Shader(shader);
}

void RectangleDraw::setPosition(glm::mat4 *model){
    this->model=*model;
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
void RectangleDraw::setSize(int size){
    this->size=size;
}

bool RectangleDraw::pointIn(int x, int y){
    unsigned int positionx=500;
    unsigned int positiony=500;
    bool result = false;
    // in x
    int x1 =  positionx - size; 
    int x2 =  positiony + size; 
    if( x1 < x && x < x2  ){
         result =true ; 
    }
    // in y
    int y1 = positionx - size; 
    int y2 = positiony + size; 
    if( result &&( y1 < y && y < y2 )  ){
         result =true ; 
    }else{
        result = false ;
    }
    
    return result;
}
