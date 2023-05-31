#include "./app/app.hpp"
#include <iostream>
using namespace std;

int main() {
    App app;
    app.Init();

    while(app.getRun()){
        app.Events();
        app.Update();
        app.Render();
    }

}

