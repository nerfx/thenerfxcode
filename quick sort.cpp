#include<iostream>
#include<ctime>
using namespace std;

void print(double *A, int N) {
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void quick_sort(double *arr, int left, int right) {
	int f = left, l = right;
	int mid = (left + right) / 2;

	double middle = arr[mid]; 
	while(f<l) {
		while (arr[f] < middle) {
			f++;
		}
		while (arr[l] > middle) {
			l--;
		}
		if (f <= l) {
			swap(arr[f++], arr[l--]); 
		}
	} 
	if (left < l) {
		quick_sort(arr, left, l);
	}
	if (f < right) {
		quick_sort(arr, f, right);
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
	print(a, n);
	quick_sort(a, 0, n - 1);
	cout << "Sorted array: " << endl;
	print(a, n);
	system("pause");
	return 0;
}
