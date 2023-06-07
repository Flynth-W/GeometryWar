#include "sysBullet.hpp"



void SysBullet::Init(){
    this->numBullets=0;
}
void SysBullet::AddBullet(glm::vec3 position, float angle){
    bullets[numBullets]= new Bullet();
        //bullet.setDeltaTime(deltaTime);
        //bullet.Init( *this->position , this->angle );
        //handleCollision->add(&bullet);
    bullets[numBullets]->setDeltaTime(deltaTime); 
    bullets[numBullets]->Init(position,angle); 

    keyBullets[bullets[numBullets]]=numBullets;

    handleCollision->add(bullets[numBullets]);
    numBullets++;
}
void SysBullet::Update(){

  for ( auto item : this->bullets ){
    if( item.second->getRun() ){
      item.second->Update();
    }
    else{
      int numObj= keyBullets[item.second];
      keyBullets.erase(item.second);
      //hndlCls->del(mapAstrs[numObj]);
      //mapAstrs[numObj]->stt=SttObjClsn::None;
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
