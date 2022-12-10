#include "Vector3d.h"
#include "ComplexMatrix.h"
#include <math.h>

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

Vector3D& Vector3D::operator-=(const Vector3D& vec) {
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


/*------------------------------VectorLong----------------------------------*/


long VectorLong::badIndexRef = 0;
VectorLong::VectorLong(int n) {
	if (n <= 0)    n = 1;  // default num =2;
	num = n;
	vector = new long[n];
	for (int i = 0; i < n; i++) {
		vector[i] = 0.0;
	}
}
VectorLong::VectorLong(int n, float b) : VectorLong(n) {
	for (int i = 0; i < num; i++) {
		vector[i] = b;
	}
}
VectorLong::VectorLong(const VectorLong& s) {
	num = s.num;
	vector = new long[num];
	state = 1;
	for (int i = 0; i < num; i++)   vector[i] = s.vector[i];
}
VectorLong& VectorLong::operator=(const VectorLong& s) {
	if (this == &s) return *this;
	if (num != s.num)
	{
		if (vector) delete[] vector;
		num = s.num;
		vector = new long[num];
		state = 1;
	}
	for (int i = 0; i < num; i++)   vector[i] = s.vector[i];
	return *this;
}
VectorLong& VectorLong::operator=(VectorLong&& s) noexcept
{
	if (this == &s) return *this;
	num = s.num; state = s.state;
	if (this->vector != nullptr) delete[] vector;
	vector = s.vector;
	s.num = 0; s.vector = nullptr; s.state = -1;
	return *this;
}
void VectorLong::Init(int n) {
	if (num != n) {
		if (vector != nullptr) delete[] vector;
		num = n;
		vector = new long[n];
	}
	for (int i = 0; i < num; i++)
		vector[i] = 0;
}
void VectorLong::Init(int n, float b) {
	if (num != n) {
		if (vector != nullptr) delete[] vector;
		num = n;
		vector = new long[n];
	}
	for (int i = 0; i < num; i++)
		vector[i] = b;
}

istream& operator>>(istream& is, VectorLong& s) {
	for (int i = 0; i < s.num; i++) {
		is >> s.vector[i];
	}
	return is;
};
ostream& operator<<(ostream& os, VectorLong& s) {
	for (int i = 0; i < s.num; i++)
		os << s.vector[i] << '\t';
	os << endl;
	return os;
}
long& VectorLong::operator[](int index) {
	if (index >= 0 && index < num) return vector[index];
	cout << " Error : operator[] - index out of range \n";
	return badIndexRef;
}

VectorLong& VectorLong::operator-=(const VectorLong& b) {
	int i;
	if (num == b.num)
		for (i = 0; i < num; i++)
			vector[i] -= b.vector[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation -= \n";
		if (num < b.num) {
			long* tmp;
			tmp = new long[b.num];
			for (i = 0; i < num; i++) tmp[i] = vector[i] - b.vector[i];
			for (; i < b.num; i++) tmp[i] = -b.vector[i];
			num = b.num;
			if (vector != nullptr) delete[] vector;
			vector = tmp;
		}
		else
			for (i = 0; i < b.num; i++)
				vector[i] -= b.vector[i];
	}
	return *this;
}
VectorLong& VectorLong::operator-=(int vec) {
	if (num > 0) {
		for (int i = 0; i < num; i++)
			vector[i] -= vec;
	}
	return *this;
}
VectorLong& VectorLong::operator-=(float vec) {
	if (num > 0) {
		for (int i = 0; i < num; i++)
			vector[i] -= vec;
	}
	return *this;
}

VectorLong& VectorLong::operator--(int) {
	for (int i = 0; i < num; i++)
		vector[i] -= 1;
	return *this;
}
VectorLong VectorLong::operator-(const VectorLong& b) {
	VectorLong tmp(*this);
	tmp -= b;
	return tmp;
}
VectorLong VectorLong::operator-(int b) {
	VectorLong tmp(*this);
	for (int i = 0; i < num; i++)
		tmp[i] += b;
	return tmp;
}
VectorLong VectorLong::operator-(float b) {
	VectorLong tmp(*this);
	for (int i = 0; i < num; i++)
		tmp[i] += b;
	return tmp;
}
VectorLong& VectorLong::operator++(int) {
	for (int i = 0; i < num; i++)
		vector[i] += 1;
	return *this;
}
VectorLong& VectorLong::operator+=(const VectorLong& b) {
	int i;
	if (num == b.num) for (i = 0; i < num; i++)
		vector[i] += b.vector[i];
	else {
		cout << " Vectors of different sizes are used in operation += !!!\n";
		if (num < b.num) {
			long* tmp;
			tmp = new long[b.num];
			for (i = 0; i < num; i++) tmp[i] = vector[i] + b.vector[i];
			for (; i < b.num; i++) tmp[i] = b.vector[i];
			num = b.num;
			if (vector != nullptr) delete[] vector;
			vector = tmp;
		}
		else for (i = 0; i < b.num; i++)
			vector[i] += b.vector[i];
	}
	return *this;
}
VectorLong& VectorLong::operator+=(const int& b) {
	if (num > 0) {
		for (int i = 0; i < num; i++)
			vector[i] += b;
	}
	return *this;
}
VectorLong& VectorLong::operator+=(const float& b)
{
	if (num > 0) {
		for (int i = 0; i < num; i++)
			vector[i] += b;
	}
	return *this;
}
VectorLong VectorLong::operator+(const VectorLong& b)
{
	VectorLong tmp(*this);
	tmp += b;
	return tmp;
}
VectorLong VectorLong::operator+(const int& b) {
	VectorLong tmp(*this);
	tmp += b;
	return tmp;
}
VectorLong VectorLong::operator+(const float& b) {
	VectorLong tmp(*this);
	for (int i = 0; i < num; i++)
		tmp[i] += b;
	return tmp;
}

VectorLong& VectorLong::operator*=(const  VectorLong& b) {
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++)
		vector[i] *= b.vector[i];
	return *this;
}

VectorLong& VectorLong::operator*=(const int& b) {
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < num; i++)
		vector[i] *= b;
	return *this;
	return tmp;
}
VectorLong& VectorLong::operator*=(const float& b) {
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	for (int i = 0; i < num; i++) vector[i] *= b;
	return *this;
	return tmp;
}

VectorLong VectorLong::operator*(const  VectorLong& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++)
		vector[i] *= b.vector[i];
	return *this;
}
VectorLong VectorLong::operator*(const int& b) {
	VectorLong rez(*this);
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez *= b;
	return rez;
	return tmp;
}
VectorLong VectorLong::operator*(const float& b) {
	VectorLong rez(*this);
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez *= b;
	return rez;
	return tmp;
}
VectorLong& VectorLong::operator/=(const  VectorLong& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++)
		vector[i] /= b.vector[i];
	return *this;
}
VectorLong& VectorLong::operator/=(const int& b) {
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	else for (int i = 0; i < num; i++)
		vector[i] /= b;
	return *this;
	return tmp;
}
VectorLong& VectorLong::operator/=(const float& b) {
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return *this;
	}
	else for (int i = 0; i < num; i++)
		vector[i] /= b;
	return *this;
	return tmp;
}


VectorLong& VectorLong::operator/(const  VectorLong& b)
{
	if (num != b.num) { std::cout << " Error : vectors of different sizes are used in operation %= \n"; return *this; }
	for (int i = 0; i < num; i++)
		vector[i] /= b.vector[i];
	return *this;
}
VectorLong VectorLong::operator/(const int& b) {
	VectorLong rez(*this);
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez /= b;
	return rez;
	return tmp;
}
VectorLong VectorLong::operator/(const float& b) {
	VectorLong rez(*this);
	VectorLong tmp;
	if (b == 0) {
		tmp.state = BAD_DIV;
		cout << "Eror BAD_DIV" << endl;
		return rez;
	}
	rez /= b;
	return rez;
	return tmp;
}

bool VectorLong::operator>(const VectorLong& s) {
	for (int i = 0; i < num; i++) {
		if (vector[i] > s.vector[i])
			return true;
	}
	return false;
}
bool VectorLong::operator>=(const VectorLong& s) {
	for (int i = 0; i < num; i++) {
		if (vector[i] >= s.vector[i])
			return true;
	}
	return false;
}
bool VectorLong::operator<(const VectorLong& s) {
	for (int i = 0; i < num; i++) {
		if (vector[i] < s.vector[i])
			return true;
	}
	return false;
}
bool VectorLong::operator<=(const VectorLong& s) {
	for (int i = 0; i < num; i++) {
		if (vector[i] <= s.vector[i])
			return true;
	}
	return false;
}

void VectorLong::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << vector[i] << "   ";
		}
	}
}
