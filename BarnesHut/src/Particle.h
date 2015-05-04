#pragma once

#include "Body.h"
#include "ofGraphics.h"

class Particle : public Body {
public:
    ofVec2f force, velocity;
    float radius;
    Particle(float _x, float _y, float _mass,
             float _xv = 0, float _yv = 0, float radius = 1) :
    Body(_x, _y, _mass),
    velocity(_xv, _yv),
    radius(radius) {
    }
    void updatePosition(float dt, float friction = 1) {
        velocity += dt * force / mass;
        velocity *= friction;
        *this += dt * velocity;
    }
    void zeroForce() {
        force.set(0, 0);
    }
    void draw() {
        //ofRect(x, y, mass, mass);
        ofDrawCircle(x, y, mass);
    }
};
