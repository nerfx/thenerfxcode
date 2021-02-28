#include<iostream>
using namespace std;

void factorization(int num) {
	int d = 2;
	while (num > 1) {
		while (num%d == 0) {
			num /= d;
			cout << d << endl;
		}
		if (d == 2) {
			d += 1;
		}
		else {
			d += 2;
		}
	}
}

void rec_factorization(int n, int div = 2) {
	if (n == 1) return;
	if (n%div == 0) {
		cout << div << endl;
		rec_factorization(n / div, div);
	}
	else {
		if (div == 2) {
			div += 1;
			rec_factorization(n, div);
		}
		else {
			div += 2;
			rec_factorization(n, div);
		}
	}
}

int main() {
	cout << "The number: " << endl;
	int n;
	cin >> n;
	cout << "Prime factors: " << endl;
	factorization(n);
	cout << "Prime factors (recursively): " << endl;
	rec_factorization(n);
	system("pause");
	return 0;
}