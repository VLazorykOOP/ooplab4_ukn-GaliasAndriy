
#pragma once
#include <iostream>
using namespace std;
#include<complex>

enum STATE {
    OK, BAD_INIT, BAD_DIV, BAD_MULTIPLY
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
    Vector3D& operator+=(const double& vec);
    Vector3D& operator+=(const float& vec);
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

class VectorLong {
private:
    long* vector;
    int num = 2;
    int state = 0;
    static long badIndexRef;
public:
    VectorLong() :VectorLong(1) {}
    VectorLong(int n);
    VectorLong(int n, float);
    VectorLong(const VectorLong& s);  // crot copy
    VectorLong& operator=(const VectorLong& s);
    VectorLong& operator=(VectorLong&& s) noexcept;
    void Init(int n);   //
    void Init(int n, float);   //
    ~VectorLong() {
        //	std::cout << " del vec";
        if (vector) delete[] vector;
    }
    friend istream& operator>>(istream& is, VectorLong& s);
    friend ostream& operator<<(ostream& os, VectorLong& s);

    long& operator[](int index);
    VectorLong& operator++(int);
    VectorLong& operator--(int);

    VectorLong& operator+=(const VectorLong& s);
    VectorLong& operator+=(const int& b);
    VectorLong& operator+=(const float& b);
    VectorLong  operator+(const VectorLong& b);
    VectorLong  operator+(const int& b);
    VectorLong  operator+(const float& b);

    VectorLong& operator-=(const VectorLong& s);
    VectorLong& operator-=(int b);
    VectorLong& operator-=(float b);
    VectorLong operator-(const VectorLong& b);
    VectorLong operator-(int b);
    VectorLong operator-(float b);

    VectorLong& operator*=(const VectorLong& b);
    VectorLong& operator*=(const int& b);
    VectorLong& operator*=(const float& b);

    VectorLong operator*(const VectorLong& b);
    VectorLong operator*(const int& b);
    VectorLong operator*(const float& b);

    VectorLong& operator/=(const VectorLong& b);
    VectorLong& operator/=(const int& b);
    VectorLong& operator/=(const float& b);

    VectorLong& operator/(const VectorLong& b);
    VectorLong operator/(const int& b);
    VectorLong operator/(const float& b);

    bool operator>(const VectorLong& s);
    bool operator>=(const VectorLong& s);
    bool operator<(const VectorLong& s);
    bool operator<=(const VectorLong& s);

    friend class matrixLong;

    void Output();
};