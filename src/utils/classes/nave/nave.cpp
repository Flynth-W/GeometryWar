#include "nave.hpp"

void Nave::Init(){
    this->type=TypeObjet::Nave;
    Shader shadera("./shader/square.vs" ,"./shader/square.fs");
    triangle.setShader(shadera);
    float vertex[] = {
        // positions          // normals           
        -0.04f, -0.04f, 0.0f,  0.0f,  0.4f, 0.7f,  
         0.04f, -0.04f, 0.0f,  0.0f,  0.4f, 0.7f,  
         0.0f,  0.04f, 0.0f,   0.0f,  0.2f, 0.5f,  
         
    };
    triangle.setVetices(vertex,sizeof(vertex));
    this->radio=0.04;
    this->position=new  glm::vec3(-0.8);
    triangle.setPosition(this->position);
    triangle.setAngle(&this->angle);
    this->run=true;
    Event::setKey(keys, GLFW_KEY_J);
    Event::setKey(keys, GLFW_KEY_L);
    Event::setKey(keys, GLFW_KEY_I);
   
    bullets.setDeltaTime(this->deltaTime);
    bullets.setCollisionHandler(this->handleCollision);
    bullets.Init();

}
void Nave::Update(){
    bullets.Update();
    float translationSpeed = 0.9;
    float rotationSpeed = 1.0;
    float limit= 1.0 - this->radio - 0.03;
    //std::cout << this->position.x <<"  " << this->position.y << std::endl;
    if(Event::getIfStateKey(keys,GLFW_KEY_W, ButtonState::Pressed , ButtonState::Repeat ) &&  limit > position->y){
        this->triangle.move(0.0f, float( translationSpeed * *deltaTime ) );
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_S, ButtonState::Pressed , ButtonState::Repeat )&& -limit < position->y){
        this->triangle.move(0.0f, float( - translationSpeed * *deltaTime ) );
    }

    if(Event::getIfStateKey(keys,GLFW_KEY_A, ButtonState::Pressed , ButtonState::Repeat ) && -limit < position->x){
        this->triangle.move(float( -translationSpeed * *deltaTime ) , 0.0f);
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_D, ButtonState::Pressed , ButtonState::Repeat ) && limit > position->x){
        this->triangle.move(float( translationSpeed * *deltaTime ) , 0.0f);
    }

    if(Event::getIfStateKey(keys,GLFW_KEY_J, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.rotate(float( rotationSpeed * *deltaTime ));
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_L, ButtonState::Pressed , ButtonState::Repeat )){
        this->triangle.rotate(float( -rotationSpeed * *deltaTime ));
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_I, ButtonState::Released )){
        //bullet.setDeltaTime(deltaTime);
        //bullet.Init( *this->position , this->angle );
        //handleCollision->add(&bullet);
        bullets.AddBullet(*this->position, this->angle);
    }
}
void Nave::Render(){
    triangle.Render();
    bullets.Render();
}
void Nave::setDeltaTime(double *deltaTime){
    this->deltaTime = deltaTime;
}
void Nave::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
bool Nave::getRun(){
    return this->run;
}

glm::vec3 Nave::getPosition(){
    return *this->position;
}
double Nave::getRadio(){
    return this->radio;
}
void Nave::colision(Iobjet_colicion *a){
    //std::cout << "nave" << std::endl;
    if(a->type == TypeObjet::Square){
        this->run=false;
    }
}

void Nave::setCollisionHandler(CollisionsHandler *handleCollision){
    this->handleCollision=handleCollision;
}
