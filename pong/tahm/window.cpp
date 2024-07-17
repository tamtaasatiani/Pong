#include "seek.h"

void Tahm::Window::create(const char* title, int width, int height)
{
    this->title = title;
    this->width = width;
    this->height = height;

}

void Tahm::Window::init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << ("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    SDLwindow = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, //x and y
        width, height, 
        flags);

    if (!SDLwindow)
    {
        std::cout << ("Failed to open %d x %d window: %s\n", width, height, SDL_GetError());
        exit(1);
    }
}
