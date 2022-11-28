#pragma once
#include <iostream>
#include <math.h>
#include<complex>
using namespace std;

enum STATE {
    OK, BAD_INIT, BAD_DIV
};

//typedef complex<double> ComplexDouble; //for complex values etc

class Vector3D
{
private:
	int state = 0;
	double x = 0, y = 0, z = 0;
public:
	Vector3D() {}
	Vector3D(double param) {}
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
        cout << "\n Current state of vector: " << state << endl;
    }
    Vector3D& operator++();
    Vector3D& operator++(int);
    friend Vector3D& operator--(Vector3D&);
    bool operator!() const;
    bool operator~() const;
};