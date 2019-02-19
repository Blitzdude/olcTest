#include <iostream>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.hpp"

/*
    INSTALLATION
    g++: sudo apt install g++
    GL/gl.h: sudo apt install mesa-common-dev
    libpng: sudo apt install libpng-dev 
*/
// Override base class with your custom functionality
class Example : public olc::PixelGameEngine
{
public:
    Example()
    {
        sAppName = "Example";
    }
public:
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override
    {
        // called once per frame, draws random coloured pixels
        for (int x = 0; x < ScreenWidth(); x++)
            for (int y = 0; y < ScreenHeight(); y++)
                Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));
        return true;
    }
};
int main()
{
    Example demo;
    if (demo.Construct(256, 240, 4, 4))
        demo.Start();
    return 0;
}