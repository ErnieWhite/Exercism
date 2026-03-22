#include "triangle.h"

bool is_triangle(triangle_t sides) {
    
    // All sides must have a length > 0
    if (sides.a == 0 || sides.b == 0 || sides.c == 0) {
        return false;
    }

    // The sum of the lengths of any two sides must be greater than
    // or equal to the length of the third side.
    if (sides.a + sides.b < sides.c || 
        sides.b + sides.c < sides.a ||
        sides.c + sides.a < sides.b) {
        return false;
    }

    return true;
}

bool is_equilateral(triangle_t sides) {
    if (!is_triangle(sides)) {
        return false;
    }
    if (sides.a == sides.b && sides.b == sides.c) {
        return true;
    } else { 
        return false;
    }
}

bool is_isosceles(triangle_t sides) {
    if (!is_triangle(sides)) {
        return false;
    }

    if (sides.a == sides.b ||
        sides.a == sides.c ||
        sides.b == sides.c) {
        return true;
    } else {
        return false;
    }
}

bool is_scalene(triangle_t sides) {
    if (!is_triangle(sides)) {
        return false;
    }

    if (sides.a != sides.b &&
        sides.a != sides.c &&
        sides.b != sides.c) {
        return true;
    } else {
        return false;   
    }
}
