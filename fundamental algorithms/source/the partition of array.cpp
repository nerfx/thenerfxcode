#include<iostream>
#include<ctime>
using namespace std;

void print(double *A, int ind1, int ind2) {
	for (int i = ind1; i <= ind2; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void partition(double *arr, int left, int right) {
	int f = left, l = right;
	int mid = (left + right) / 2;
	if (f < l) {
		f = mid + 1;
		l = mid;
		if (left < l) {
			print(arr, left, l);
			partition(arr, left, l);
		}
		if (f < right) {
			print(arr, f, right);
			partition(arr, f, right);
		}
	}
	else {
		return;
	}
}

int main() {
	srand(time(NULL));
	int n;
	cout << "Number of elements in the array: " << endl;
	cin >> n;
	double *a = new double[n];
	for (int i = 0; i < n; ++i) {
		a[i] = rand() / 1000.1;
	}
	cout << "Array: " << endl;
	print(a, 0, n-1);
	cout << "The partition of array: " << endl;
	partition(a, 0, n - 1);
	system("pause");
	return 0;
}
