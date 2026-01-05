#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Screen.h"

int main() {
    // the main game loop
    bool init();
    bool loadMedia();
    void close();
    auto screen=Screen(1000,500);
    int* p_screen_width=screen.getPointerToScreenWidth();
    int* p_screen_hight=screen.getPointerToScreenHeight();
    static Uint32 lastTime = SDL_GetTicks();

    SDL_Window *window = SDL_CreateWindow("Window", 0, 0, *p_screen_width, *p_screen_hight, SDL_WINDOW_RESIZABLE);
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,( SDL_RENDERER_ACCELERATED,SDL_RENDERER_PRESENTVSYNC));
    // bool SDL_SetRenderVSync(SDL_Renderer *renderer, int vsync);

    if (window == nullptr) {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
    }
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_Surface *canvas = SDL_CreateRGBSurfaceWithFormat(0, *p_screen_width, *p_screen_hight, 32, SDL_PIXELFORMAT_RGBA8888);



    int mouse_x;
    int mouse_y;

    bool running = true;
    while (running) {
        Uint32 *buffer = (Uint32*) canvas->pixels;
        SDL_LockSurface(canvas);

        Uint32 mousestate = SDL_GetMouseState(&mouse_x, &mouse_y);
        for (int i = 0; i < *p_screen_width; i++) {
            for (int j = 0; j < *p_screen_hight; j++){
                int offset = j * *p_screen_width + i+mouse_x;
                unsigned char red_value = i ^ j;
                unsigned char green_value = j;
                Uint32 color = (red_value & 0xFF) << 24 | (green_value & 0xFF) << 16 | (0 & 0xFF) << 8 | ( 255 & 0xFF);

                buffer[offset] = color;
            }
        }
        SDL_UnlockSurface(canvas);


        SDL_BlitSurface(canvas, 0, window_surface, 0);
        SDL_UpdateWindowSurface(window);

        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - lastTime;

        if (deltaTime > 0) {
            float fps = 1000.0f / deltaTime;
            std::cout  << " FPS: " << fps <<currentTime<< std::endl;
        }
        lastTime = currentTime;




        SDL_Event e;
        bool quit = false;
        if (quit==false){
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT){
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN){
                    quit = true;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN){
                    quit = true;
                }
            }
            // bool running = !quit;
        }

    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    }









