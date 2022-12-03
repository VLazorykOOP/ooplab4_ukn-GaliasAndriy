#include <iostream>
#include "Vector3D.h"
#include "Lab4Tasks.h"

int vector3D() {
	cout << "\n";

	Vector3D a(5), res;
	double* p = nullptr, newP[] = { 2.5, 5.7, 10 };
	double newD[] = { 4, 8.5, 5,25 }, test[] = {1, 2, 3};
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
	res = multiplyVec* divideVec;
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
