#include "Vector3D_task1.h"

Vector3D::Vector3D(double param) {
    x = param; y = param; z = param;
    state = OK;
}

Vector3D::Vector3D(double* pointer) {
    if (pointer = nullptr) {
        state = BAD_INIT;
        x = 0; y = 0; z = 0;
    }
    else {
        x = pointer[0]; 
        y = pointer[1];
        z = pointer[2];
        state = OK;
    }
}

Vector3D& Vector3D::operator++() {
    x += 1.0; y += 1.0; z += 1.0;
    return *this;
}

bool Vector3D::operator!() const {
    if (x == 0 || y == 0 || z == 0) {
        return false;
    }
    else
        return true;
}

Vector3D& operator--(Vector3D& s) {
    s --= 1.0;
    return s;
}

//bool Vector3D::operator~() const {
//    if ()
//} 
//