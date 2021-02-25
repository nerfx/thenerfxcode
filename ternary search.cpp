#include<iostream>
#include<cmath>
using namespace std;

double func(double x) {
	return 9*x*x-x*x*x;
}

double ternary_search(double f(double), double left, double right, double eps) {	
	double a, b;
	while (right - left >= eps) {
	
		a = left + (right - left) / 3;
		b = left + 2 * (right - left) / 3;
		if (f(a) > f(b)) {
			right = b;
		}
		else {
			left = a;
		}
	}
	return (right + left) / 2;
}

double recursive_ternary(double f(double), double l, double r, double eps) {
	double a, b;
	if (r - l<eps) {
		return (l + r) / 2;
	}
	a = (2 * l + r) / 3;
	b = (2 * r + l) / 3;
	if (f(a) > f(b)) {
		return recursive_ternary(f, l, b, eps);
	}
	else {
		return recursive_ternary(f, a, r, eps);
	}
}

int main() {
	double r, l;
	cout << "Thr left border of the segment: " << endl;
	cin >> l;
	cout << "The right border of the segment: " << endl;
	cin >> r;
	double eps;
	cout << "Accuracy: " << endl;
	cin >> eps;
	cout << "Maximum point on the segment: " << endl;
	cout << ternary_search(func, l, r, eps) << endl;
	cout << "Recursively: " << endl;
	cout << recursive_ternary(func, l, r, eps) << endl;
	system("pause");
	return 0;
}