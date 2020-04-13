#include <iostream>

class Engine
{

public:
    void Start() 
    { 
        std::cout<<"Engine Start"<<std::endl;
    }

};

class Headlights
{

public:
    void TurnOn() 
    { 
        std::cout<<"Trun On headlight"<<std::endl;
    }

};

//  That's your facade.
class Car
{

private:
    Engine engine;
    Headlights headlights;

public:
    void TurnIgnitionKeyOn()
    {
        headlights.TurnOn();
        engine.Start();
    }

};

int main(int argc, char *argv[])
{
    //  Consuming facade.
    Car car;
    car.TurnIgnitionKeyOn();

    return 0;
}