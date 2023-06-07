#include "bullet.hpp"

void Bullet::Init(glm::vec3 position, float angle){
    Shader shadera("./shader/square.vs" ,"./shader/square.fs");
    square.setShader(shadera);
    float vertex[] = {
        // positions          // normals           
        -0.003f, -0.003f, 0.0f,  1.0f,  1.0f, 0.0f,  
         0.003f, -0.003f, 0.0f,  1.0f,  1.0f, 0.0f,  
         0.003f,  0.003f, 0.0f,  1.0f,  1.0f, 0.0f,  
         
         0.003f,  0.003f, 0.0f,  1.0f,  1.0f, 0.0f,  
        -0.003f,  0.003f, 0.0f,  1.0f,  1.0f, 0.0f,  
        -0.003f, -0.003f, 0.0f,  1.0f,  1.0f, 0.0f,  
    };
    square.setVetices(vertex,sizeof(vertex));
    this->radius=0.003;
    square.setPosition(position);
    square.rotate(angle);
    square.move(0.0,0.05);
    square.Init();
    this->position=square.position;
    this->run=true;
    this->type=TypeObjet::Bullet;
}
void Bullet::Update(){
    if( run ){
        double speed = *deltaTime * 0.4;
        square.move(0.0,speed);
    }
}
void Bullet::Render(){
    if (run){
        square.Render();
    }
}
void Bullet::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Bullet::setRadius(unsigned int radius){
    this->radius=radius;
}

glm::vec3 Bullet::getPosition(){
    glm::vec3 ps =this->square.getPosition();
    return ps;
}
double Bullet::getRadio(){
    return this->radius;
}
bool Bullet::getRun(){
    return this->run;
}
void Bullet::colision(Iobjet_colicion *a){
    std::cout << "bullet" << std::endl;
}
