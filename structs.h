#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>

// struct vs class, by default classes are private and by default structs are public
// use structs for Plain Old Data (POD) or just public variables

struct vec2 {
        float x, y;

        void add (const vec2& other);
};

#endif