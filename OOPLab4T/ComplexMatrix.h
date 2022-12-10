#pragma once
#include "Vector3D.h"
#include <iostream>
using namespace std;

class matrixLong {
private:
	VectorLong* longArray;
	int n = 0, m = 0;
	int state = 0;
	static int num_matrix;
public:
	matrixLong() { longArray = nullptr; n = m = state = 0; }
	matrixLong(int size);
	matrixLong(int n, int m, double a); //
	matrixLong(int m, int n);
	matrixLong(const matrixLong* s);
	matrixLong& operator=(matrixLong& s);
	VectorLong& operator[](int index) {
		if (index >= 0 && index < n) return longArray[index];
		cout << " Error: operator[] - index index out of range \n";
		return longArray[0];
	}
	friend istream& operator>>(istream& is, matrixLong& s);
	friend ostream& operator<<(ostream& os, matrixLong& s);
	matrixLong& operator++(int);
	matrixLong& operator--(int);

	void outputMatrix();
	int getState() {
		return state;
	}

	matrixLong operator+(matrixLong v);
	matrixLong operator+(float value);
	matrixLong operator-(matrixLong v);
	matrixLong operator-(float value);

	matrixLong operator/(float value);
	matrixLong operator*(float value);

	matrixLong operator+=(matrixLong v);
	matrixLong operator+=(float value);
	matrixLong operator-=(matrixLong v);
	matrixLong operator-=(float value);

	matrixLong operator*(const matrixLong& b);;
	matrixLong operator*=(float value);
	matrixLong operator/=(float value);

	bool operator>(const matrixLong& s);
	bool operator>=(const matrixLong& s);
	bool operator<(const matrixLong& s);
	bool operator<=(const matrixLong& s);

};