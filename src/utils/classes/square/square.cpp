#include "square.hpp"

void Square::Init(double x,double y){
    Shader shadera("./shader/square.vs" ,"./shader/square.fs");
    square.setShader(shadera);
    float vertex[] = {
        // positions          // normals           
        -0.02f, -0.02f, 0.0f,  1.0f,  1.0f, 1.0f,  
         0.02f, -0.02f, 0.0f,  1.0f,  1.0f, 1.0f,  
         0.02f,  0.02f, 0.0f,  1.0f,  1.0f, 1.0f,  
         
         0.02f,  0.02f, 0.0f,  1.0f,  1.0f, 1.0f,  
        -0.02f,  0.02f, 0.0f,  1.0f,  1.0f, 1.0f,  
        -0.02f, -0.02f, 0.0f,  1.0f,  1.0f, 0.0f,  
    };
    square.setVetices(vertex,sizeof(vertex));
    this->radius=0.02;
    this->position= new glm::vec3(x,y,0.0);
    square.setPosition(position);
    this->run=true;
    if(x > 1){
        this->direction[0]=-1;
    }else{
        this->direction[0]=1;
    }
    if(y > 1){
        this->direction[1]=-1;
    }else{
        this->direction[1]=1;
    }
}
void Square::Update(){
    double speed = *deltaTime * 0.2;
    double x  = this->direction[0] * speed; 
    double y  = this->direction[1] * speed; 
    square.move(x,y);

    if( this->position->x  > 0.9  && this->direction[0] == 1){
        this->direction[0] = -1;
    };
    if(  this->position->x  < -0.9  && this->direction[0] == -1){
        this->direction[0] = 1;
    };
    if( this->position->y  > 0.9  && this->direction[1] == 1){
        this->direction[1] = -1;
    };
    if(  this->position->y  < -0.9  && this->direction[1] == -1){
        this->direction[1] = 1;
    };

}
void Square::Render(){
    square.Render();
}
void Square::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Square::setRadius(unsigned int radius){
    this->radius=radius;
}

glm::vec3 Square::getPosition(){
    return *this->position;
}
double Square::getRadio(){
    return this->radius;
}
bool Square::getRun(){
    return this->run;
}
void Square::colision(Iobjet_colicion *a){
    if( a->type == TypeObjet::Bullet){
        this->run=false;
    }
}
