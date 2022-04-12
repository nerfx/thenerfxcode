#include<iostream>
using namespace std;

void print(double *A, int N) {
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

int knuth_seq(int num) {
	int t = int(log(num) / log(2)) - 1;
	int ht = 1;
	for (int i = 2; i <= t; ++i) {
		ht = 2 * ht + 1;
	}
	return ht;
}


void shell_sort(double *arr, int n) {
	int j;
	double var;
	for (int step = knuth_seq(n); step >= 1; step = (step - 1) / 2) {
		for (int i = step; i < n; ++i) {
			var = arr[i];
			for (j = i; j >= step && var < arr[j - step]; j = j-step) {
				arr[j] = arr[j - step];
			}
			arr[j] = var;
		}
	}
}

int binary_search(double *arr1, int left, int right, double key) {
	int middle = (left + right) / 2;
	if (key == arr1[middle]) return middle;
	else if (arr1[middle] > key) {
		if (left < right) {
			return binary_search(arr1, left, middle, key);
		}
		else {
			cout << "The element is not in the array" << endl;
			return right;
		}
	}
	else {
		if (left < right) {
			return binary_search(arr1, middle + 1, right, key);
		}
		else {
			cout << "The element is not in the array" << endl;
			return right;
		}
	}
}

int main() {
	int n; 
	cout << "Number of elements in the array: " << endl;
	cin >> n;
	cout << "Array: " << endl;
	double *a = new double[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	print(a, n);
	cout << "Sorted array: " << endl;
	shell_sort(a, n);
	print(a, n);
	double elem;
	cout << "Enter the desired item: " << endl;
	cin >> elem;
	cout << "The number of the desired element: " << endl;
	cout << binary_search(a, 0, n - 1, elem) << endl;
	system("pause");
	return 0;
}