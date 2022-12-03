#include "Vector3D.h"

Vector3D& Vector3D::operator=(Vector3D&& s) noexcept {
    if (this == &s) return *this;
    x = s.x; y = s.y; z = s.z;
    state = s.state;
    return *this;
}

Vector3D::Vector3D(double* p) {
    if (p == nullptr) {
        state = BAD_INIT;
        x = 0; y = 0; z = 0;
    }
    else {
        x = p[0];
        y = p[1];
        z = p[2];
        state = OK;
    }
}

Vector3D& Vector3D::operator++() {
    x += 1.0; y += 1.0; z += 1.0;
    return *this;
}

Vector3D& Vector3D::operator--() {
    x -= 1.0; y -= 1.0; z -= 1.0;
    return *this;
}

bool Vector3D::operator!() const {
    if (x == 0 || y == 0 || z == 0) {
        return false;
    }
    else
        return true;
}

void Vector3D::output() {
    cout << "  " << count << " Vector: ";
    cout << "(" << x << "; " << y << "; " << z << ")" << "\n\n";
}

Vector3D::Vector3D(Vector3D& source) {
    x = source.x; y = source.y; z = source.z;
}
Vector3D::Vector3D(Vector3D&& source) {
    x = source.x; y = source.y; z = source.z;
}

istream& operator>>(istream& is, Vector3D& s) {
    is >> s.x; is >> s.y; is >> s.z;
    return is;
};
ostream& operator<<(ostream& os, Vector3D& s) {
    os << s.x << '\t';
    os << s.y << '\t';
    os << s.z << '\t';
    os << endl;
    return os;
}

Vector3D& Vector3D::operator-=(const Vector3D& vec){
    x -= vec.x; y -= vec.y; z -= vec.z;
    return *this;
}
Vector3D& Vector3D::operator-=(const double& vec) {
    x -= vec; y -= vec; z -= vec;
    return *this;
}
Vector3D& Vector3D::operator-=(const float& vec) {
    x -= vec; y -= vec; z -= vec;
    return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& vec) {
    x += vec.x; y += vec.y; z += vec.z;
    return *this;
}
Vector3D& Vector3D::operator+=(const double& vec) {
    x += vec; y += vec; z += vec;
    return *this;
}
Vector3D& Vector3D::operator+=(const float& vec) {
    x += vec; y += vec; z += vec;
    return *this;
}

Vector3D& Vector3D::operator+(const Vector3D& vec) {
    Vector3D tmp(*this);
    tmp += vec;
    return tmp;
}
Vector3D& Vector3D::operator+(const double& vec) {
    Vector3D tmp(*this);
    tmp += vec;
    return tmp;
}
Vector3D& Vector3D::operator+(const float& vec) {
    Vector3D tmp(*this);
    tmp += vec;
    return tmp;
}

Vector3D& Vector3D::operator-(const Vector3D& vec) {
    Vector3D tmp(*this);
    tmp -= vec;
    return tmp;
}
Vector3D& Vector3D::operator-(const double& vec) {
    Vector3D tmp(*this);
    tmp -= vec;
    return tmp;
}
Vector3D& Vector3D::operator-(const float& vec) {
    Vector3D tmp(*this);
    tmp -= vec;
    return tmp;
}

double Vector3D::operator*(Vector3D& s) {
    double res = 0;
    res = x * s.x + y * s.y + z * s.z;
    return res;
}
Vector3D Vector3D::operator*(float scalar) {
    Vector3D tmp;
    tmp.x = x * scalar;
    tmp.y = y * scalar;
    tmp.z = z * scalar;
    return tmp;
}
Vector3D Vector3D::operator*(double scalar) {
    Vector3D tmp;
    tmp.x = x * scalar;
    tmp.y = y * scalar;
    tmp.z = z * scalar;
    return tmp;
}

double Vector3D::operator/(Vector3D& s) {
    double res = 0;
    res = x / s.x + y / s.y + z / s.z;
    return res;
}
Vector3D Vector3D::operator/(float scalar) {
    Vector3D tmp;
    tmp.x = x / scalar;
    tmp.y = y / scalar;
    tmp.z = z / scalar;
    return tmp;
}
Vector3D Vector3D::operator/(double scalar) {
    Vector3D tmp;
    tmp.x = x / scalar;
    tmp.y = y / scalar;
    tmp.z = z / scalar;
    return tmp;
}

bool Vector3D::operator>(const Vector3D& s) {
    if (x > s.x) return true;
    else return false;
    if (y > s.y) return true;
    else return false;
    if (z > s.z) return true;
    else return false;
}
bool Vector3D::operator<(const Vector3D& s) {
    if (x < s.x) return true;
    else return false;
    if (y < s.y) return true;
    else return false;
    if (z < s.z) return true;
    else return false;
}
bool Vector3D::operator<=(const Vector3D& s) {
    if (x <= s.x) return true;
    else return false;
    if (y <= s.y) return true;
    else return false;
    if (z <= s.z) return true;
    else return false;
}
bool Vector3D::operator>=(const Vector3D& s) {
    if (x >= s.x) return true;
    else return false;
    if (y >= s.y) return true;
    else return false;
    if (z >= s.z) return true;
    else return false;
}



