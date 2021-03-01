#include<iostream>
#include<cmath>
using namespace std;

int euclid(int num1, int num2) {
	int d = 0;
	while (num2 != 0) { 
		d = num2;
		num2 =num1 % d;
		num1 = d;
	}
	return d;
}

int euclid_rec(int n1, int n2) {
	int d;
	if (n2 == 0) {
		return n1;
	}
	else {
		d = n2;
		n2 = n1%d;
		euclid_rec(d, n2);
	}
}

int main() {
	int a, b;
	bool t = true;
	while(t) {
		cout << "Numbers: " << endl;
		cin >> a >> b;
		if (a != 0 && b != 0) {
			cout << "greatest common divisor: " << endl;
			cout << euclid(abs(a), abs(b)) << endl;
			cout << "greatest common divisor (recursively): " << endl;
			cout << euclid_rec(abs(a), abs(b)) << endl;
			t = false;
			
		}
		else {
			cout << "Error" << endl;
			t = true;
		}
	}
	system("pause");
	return 0;
}