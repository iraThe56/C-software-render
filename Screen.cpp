//
// Created by Ira Evetts on 1/3/26.
//

#include "Screen.h"
#ifndef PARTICLE_H
#define PARTICLE_H
#include <SDL_render.h>
#include <array>

class Particle {
private:
    float x, y;           // center position
    float velocityX, velocityY;
    float radius;         // Changed from int to float
    std::array<int, 4> color_and_alpha;

public:
    Particle(float startX, float startY, float startRadius);
    void addAcceleration(float accelX, float accelY);
    void apply_velocity(float deltaTime);
    void draw_particle(SDL_Renderer* renderer);
    void set_position(float x, float y);

    // Getters so you can read the values
    float getX() const;          // Fixed function names
    float getY() const;          // Fixed function names
    float getRadius() const;
};

#endif //PARTICLE_H