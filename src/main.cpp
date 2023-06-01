#include "./app/app.hpp"
#include <iostream>
#include <chrono>
using namespace std;

int main() {
    App app;
    app.Init();
    
    auto lastTime = std::chrono::system_clock::now();
    while(app.getRun()){
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> deltaTime = current - lastTime;
        app.deltaTime = deltaTime.count() ;  
        app.Events();
        app.Update();
        app.Render();

        lastTime = current;
    }

}

