#include "sysSquares.hpp"

double RandomData(){
    int num =rand() % 1000;
    double increase=0.01;
    cout << num % 2 <<endl;
    double result =(num * 0.001) + increase; 
    if( (num %2 ) == 1   ){
       result *=-1; 
    }
    return result;
}
void SysSquare::AddSquare(){
    //int x,y;
    //RandomData(&x,&y);
    double x = RandomData();
    double y = RandomData();
    squares[numSquares]= new Square();
    squares[numSquares]->setDeltaTime(deltaTime); 
    squares[numSquares]->Init(x,y); 
    
    keySquares[squares[numSquares]]=numSquares;

    //hndlCls->add(mapAstrs[numAstrs]);
    handleCollision->add(squares[numSquares]);
    numSquares++;
}

void SysSquare::Init(){
    this->AddSquare();
    srand((unsigned)time(NULL));
    this->createTime=0;
}
void SysSquare::Update(){
    
    this->createTime+=*deltaTime;
    if(this->createTime > 2){
      this->createTime-=2;
      this->AddSquare();
    }

    for ( auto item : this->squares ){
        if( item.second->getRun() ){
          item.second->Update();
        }
        else{
          int numObj= keySquares[item.second];
          keySquares.erase(item.second);
          deleteSquares.push(numObj);
        }
    };
    removeSquare();
}
void SysSquare::removeSquare(){
  while(deleteSquares.size()!=0){
    int _num=deleteSquares.front();
    squares.erase(_num);
    deleteSquares.pop();
  }
};
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
