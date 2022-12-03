#pragma once
#include <iostream>
#include <math.h>
using namespace std;

enum STATE {
    OK, BAD_INIT, BAD_DIV
};

class Vector3D {
private:
    int state = OK;
    double x, y, z;
public:
    int count = 0;
    Vector3D() : x(0), y(0), z(0) { count++; }
    Vector3D(double param) {
        x = param; y = param; z = param;
        state = OK;
        count++;
    }
    Vector3D(const Vector3D& s) {   
        if (this == &s) return;
        x = s.x; y = s.y; z = s.z;
    }
    Vector3D& operator=(const Vector3D& s) {   
        if (this == &s) return *this;
        x = s.x; y = s.y; z = s.z;
        return *this;
    }
    Vector3D& operator=(Vector3D&& s) noexcept;
    Vector3D(double* pointer);
    ~Vector3D() {
        cout << " Current state of vector: " << state << endl;
    }
    friend istream& operator>>(istream& is, Vector3D& s);
    friend ostream& operator<<(ostream& os, Vector3D& s);

    Vector3D& operator++();
    Vector3D& operator--();
    bool operator!() const;
    void output();
    int getState() { return state; }
    Vector3D(Vector3D& source);
    Vector3D(Vector3D&& source);

    Vector3D& operator-=(const Vector3D& vec);
    Vector3D& operator-=(const double& vec);
    Vector3D& operator-=(const float& vec);
    Vector3D& operator-(const Vector3D& vec);
    Vector3D& operator-(const double& vec);
    Vector3D& operator-(const float& vec);
    Vector3D& operator+=(const Vector3D& vec);
    Vector3D& operator+=(const double & vec);
    Vector3D& operator+=(const float & vec);
    Vector3D& operator+(const Vector3D& vec);
    Vector3D& operator+(const double& vec);
    Vector3D& operator+(const float& vec);

    double operator*(Vector3D& s);
    Vector3D operator*(double sc);
    Vector3D operator*(float sc);

    double operator/(Vector3D& s);
    Vector3D operator/(double sc);
    Vector3D operator/(float sc);

    bool operator>(const Vector3D& s);
    bool operator>=(const Vector3D& s);
    bool operator<(const Vector3D& s);
    bool operator<=(const Vector3D& s);

};
