//
// Created by Ira Evetts on 1/3/26.
//

#include "Screen.h"


Screen::Screen(int screen_width, int screen_height) {
    m_screen_width = screen_width;
    m_screen_height = screen_height;
}
void Screen::setScreenSize(int width, int height) {
    m_screen_width = width;
    m_screen_height = height;
}

int *Screen::getPointerToScreenWidth() {
    return &m_screen_width;
};
int *Screen::getPointerToScreenHeight() {

    return  &m_screen_height;

};


