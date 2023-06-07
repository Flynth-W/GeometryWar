#include "sysBullet.hpp"



void SysBullet::Init(){
    this->numBullets=0;
}
void SysBullet::AddBullet(glm::vec3 position, float angle){
    if(this->limitBall){
        bullets[numBullets]->Init(position,angle); 
    }else{
        bullets[numBullets]= new Bullet();
        bullets[numBullets]->setDeltaTime(deltaTime); 
        bullets[numBullets]->Init(position,angle); 
        keyBullets[bullets[numBullets]]=numBullets;
        handleCollision->add(bullets[numBullets]);
    }
    numBullets++;
    
    if(numBullets==10){
        numBullets=0;
        this->limitBall=true;
    }
}
void SysBullet::Update(){

  for ( auto item : this->bullets ){
    if( item.second->getRun() ){
      item.second->Update();
    }
    else{
      //int numObj= keyBullets[item.second];
      //keyBullets.erase(item.second);
      //cout << "DLETE bullet" << endl;
      //hndlCls->del(mapAstrs[numObj]);
      //handleCollision->del(bullets[numObj]);
      //bullets[numObj];
      //colaDel.push(numObj);
    }
  };
}
void SysBullet::Render(){
  for ( auto &item : this->bullets ){
    if( item.second->getRun()){
      item.second->Render();
    }
  };
}


void SysBullet::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void SysBullet::setCollisionHandler(CollisionsHandler *handleCollision){
    this->handleCollision=handleCollision;
}
