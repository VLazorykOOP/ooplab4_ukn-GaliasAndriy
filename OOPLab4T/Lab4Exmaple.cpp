#include <iostream>
#include "Vector3D.h"
#include "Lab4Tasks.h"
#include "ComplexMatrix.h"

int vector3D() {
	cout << "\n";
	Vector3D a(5), res;
	double* p = nullptr, newP[] = { 2.5, 5.7, 10 };
	double newD[] = { 4, 8.5, 5,25 }, test[] = { 1, 2, 3 };
	Vector3D b(newP);
	Vector3D c(12.2);
	Vector3D d(newD);
	Vector3D multiplyVec(test);
	Vector3D divideVec(test);
	a.output();
	b.output();
	c.output();
	++c;
	c.output();
	--c;
	c.output();
	d.output();
	d += c;
	d.output();
	d -= a;
	d.output();
	d += 2.8;
	d.output();
	d -= 15.7;
	d.output();
	multiplyVec.output();
	res = multiplyVec * divideVec;
	res.output();
	multiplyVec = multiplyVec * 10.0;
	multiplyVec.output();
	multiplyVec = multiplyVec / 5.0;
	multiplyVec.output();
	if (multiplyVec > divideVec)
		cout << "multiplyVec greater than divideVec" << endl;
	else if (multiplyVec < divideVec)
		cout << "multiplyVec less than divideVec" << endl;
	else if (multiplyVec >= divideVec)
		cout << "multiplyVec bigger or equal to divideVec" << endl;
	else if (multiplyVec > divideVec)
		cout << "multiplyVec less or equal to divideVec" << endl;

	return 2;
}

int matrixVeryLong() {
	cout << "\n";
	matrixLong a(3);
	matrixLong b(3, 5);
	matrixLong c(3, 5, 3);
	matrixLong op(3, 5, 2), op2(3, 5, 10), op10(3, 5, 1);
	matrixLong copy(c);
	cout << "------------------------------Matrix with one parametr---------------------" << endl;
	a.outputMatrix();
	cout << "------------------------------Matrix with two parameters-------------------" << endl;
	b.outputMatrix();
	cout << "------------------------------Matrix with three parameters-----------------" << endl;
	c.outputMatrix();
	cout << "------------------------------Copying matrix-----------------" << endl;
	copy.outputMatrix();
	c++;
	cout << "------------------------------Prefix++  -----------------" << endl;
	c.outputMatrix();
	c--;
	cout << "------------------------------Prefix--  -----------------" << endl;
	c.outputMatrix();
	cout << "------------------------------Add two matrices-------------------" << endl;
	(c + op).outputMatrix();
	cout << "------------------------------Substract two matrices--------------" << endl;
	(op2 - op).outputMatrix();
	cout << "------------------------------Add scalar to matrix-------------------" << endl;
	(op2 + 10).outputMatrix();
	cout << "------------------------------Substract scalar to matrix-------------------" << endl;
	(op2 - 22).outputMatrix();
	cout << "------------------------------Mupltiply scalar to matrix-------------------" << endl;
	(op2 * (-2)).outputMatrix();
	cout << "------------------------------Divide scalar to matrix-------------------" << endl;
	(op2 / 4).outputMatrix();
	cout << "------------------------------Assign and add two matrices-------------------" << endl;
	(op2 += op10).outputMatrix();
	cout << "------------------------------Assign and substract two matrices-------------------" << endl;
	(op2 -= op10).outputMatrix();
	cout << "------------------------------Assign and multiply matrix on scalar-------------------" << endl;
	(op2 *= (float)2.6).outputMatrix();
	cout << "------------------------------Assign and Divide matrix on scalar-------------------" << endl;
	(op2 /= (float)1.5).outputMatrix();
	cout << "------------------------------Assign and Divide matrix on scalar-------------------" << endl;
	cout << "------------------------------Indexing operation-------------------" << endl;
	cout << op10[7] << endl;

	return 0;
}