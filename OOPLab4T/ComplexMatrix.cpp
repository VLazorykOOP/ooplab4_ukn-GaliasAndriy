#include "ComplexMatrix.h"

matrixLong::matrixLong(int n1) {
	if (n < 0 || n > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		longArray = new VectorLong[n];
		for (int i = 0; i < n; i++) {
			longArray[i] = VectorLong(n);
		}
	}
}
matrixLong::matrixLong(int n1, int m1) {
	if (n < 0 || n > 1.e+100 || m1 < 0 || m1 > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		m = m1;
		longArray = new VectorLong[n];
		for (int i = 0; i < n; i++) {
			longArray[i] = VectorLong(m1);
		}
	}
}
matrixLong::matrixLong(int n1, int m1, double a) {
	if (n < 0 || n > 1.e+100 || m1 < 0 || m1 > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		m1 = m1;
		longArray = new VectorLong[n];
		for (int i = 0; i < n; i++) {
			longArray[i] = VectorLong(m1, a);
		}
	}
}

istream& operator>>(istream& is, matrixLong& s) {
	for (int i = 0; i < s.n; i++)
		is >> s.longArray[i];
	return is;
}
ostream& operator<<(ostream& os, matrixLong& s) {
	for (int i = 0; i < s.n; i++)
		os << s.longArray[i];  // << endl;
	return os;
}

matrixLong::matrixLong(const matrixLong* s) {
	n = s->n;
	longArray = new VectorLong[n];
	for (int i = 0; i < n; i++)
		longArray[i] = s->longArray[i];
	state = s->state;
}

matrixLong& matrixLong::operator=(matrixLong& s) {
	for (int i = 0; i < n; i++)
		longArray[i] = s.longArray[i];
	return *this;
}

matrixLong& matrixLong::operator++(int) {
	for (int i = 0; i < n; i++)
		longArray[i]++;
	return *this;
}
matrixLong& matrixLong::operator--(int) {
	for (int i = 0; i < n; i++)
		longArray[i]--;
	return *this;
}

void matrixLong::outputMatrix() {
	for (int i = 0; i < n; i++) {
		cout << "  ";
		longArray[i].Output();
		cout << "\n";
	}
}

matrixLong matrixLong::operator+(matrixLong v) {
	for (int i = 0; i < n; i++)
		longArray[i] += v.longArray[i];
	return *this;
}
matrixLong matrixLong::operator+(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] += value;
	return *this;
}

matrixLong matrixLong::operator-(matrixLong v) {
	for (int i = 0; i < n; i++)
		longArray[i] -= v.longArray[i];
	return *this;
}
matrixLong matrixLong::operator-(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] -= value;
	return *this;
}

matrixLong matrixLong::operator*(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] *= value;
	return *this;
}
matrixLong matrixLong::operator/(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] /= value;
	return *this;
}

matrixLong matrixLong::operator+=(matrixLong v) {
	for (int i = 0; i < n; i++)
		longArray[i] += v.longArray[i];
	return *this;
}
matrixLong matrixLong::operator+=(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] += value;
	return *this;
}
matrixLong matrixLong::operator-=(matrixLong v) {
	for (int i = 0; i < n; i++)
		longArray[i] -= v.longArray[i];
	return *this;
}
matrixLong matrixLong::operator-=(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] -= value;
	return *this;
}

matrixLong matrixLong::operator*=(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] *= value;
	return *this;
}
matrixLong matrixLong::operator/=(float value) {
	for (int i = 0; i < n; i++)
		longArray[i] /= value;
	return *this;
}

matrixLong matrixLong::operator*(const matrixLong& b) {
	if (n == b.m && m == b.m) {
		matrixLong ret(m, n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				ret[i][j] = 0;
				for (int k = 0; k < m; k++)
					ret[i][j] += longArray[i][k] * b.longArray[k][j];
			}
		return ret;
	}
	else {
		cout << "Error: matrices of different dimensions \n";
		cout << "The *  operation was not performed. \n";
		return *this;
	}
}
