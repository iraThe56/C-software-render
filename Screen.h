//
// Created by Ira Evetts on 1/3/26.
//

#ifndef SCREEN_H
#define SCREEN_H


// #include <SDL_render.h>
#include <array>


class Screen {
    private:
        int m_screen_width;
        int m_screen_height;
    public:
        Screen(int screen_width, int screen_height);
        void setScreenSize(int width, int height);

        int *getPointerToScreenWidth() ;
        int *getPointerToScreenHeight() ;


};

#endif //Screen_h