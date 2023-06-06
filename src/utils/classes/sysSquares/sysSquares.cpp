#include "sysSquares.hpp"

void SysSquare::AddSquare(){
    //int x,y;
    //RandomData(&x,&y);
    squares[numSquares]= new Square();
    squares[numSquares]->setDeltaTime(deltaTime); 
    squares[numSquares]->Init(); 

    keySquares[squares[numSquares]]=numSquares;

    //hndlCls->add(mapAstrs[numAstrs]);
    handleCollision->add(squares[numSquares]);
    numSquares++;
}

void SysSquare::Init(){
    this->AddSquare();
}
void SysSquare::Update(){
  for ( auto item : this->squares ){
    if( item.second->getRun() ){
      item.second->Update();
    }
    else{
      int numObj= keySquares[item.second];
      keySquares.erase(item.second);
      //hndlCls->del(mapAstrs[numObj]);
      //mapAstrs[numObj]->stt=SttObjClsn::None;
      //colaDel.push(numObj);
    }
  };
}
void SysSquare::Render(){
  for ( auto &item : this->squares ){
    if( item.second->getRun()){
      item.second->Render();
    }
  };
}
void SysSquare::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void SysSquare::setCollisionHandler(CollisionsHandler *handleCollision){
    this->handleCollision=handleCollision;
}
