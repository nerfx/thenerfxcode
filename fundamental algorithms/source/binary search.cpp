#include<iostream>
#include<math.h>
#include<ctime>
using namespace std;

void print(double *a, int N) {
	for (int i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int knuth_seq(int var) {
	int t = int(log(var) / log(2)) - 1;;
	int ht = 1;
	for (int i = 2; i <= t; ++i) {
		ht = 2 * ht + 1;
	}
	return ht;
}

void shell_knuth(double *arr1, int n) { 
	int key = 0;
	double value = 0;
	int j;
	for (int i = knuth_seq(n); i >= 1; i = (i - 1) / 2) {
		for (int k = i; k < n; ++k) {
			value = arr1[k];
			for (j = k; j >= i && value < arr1[j - i]; j = j - i) {
				arr1[j] = arr1[j - i];
			}
			arr1[j] = value;
		}
	}
}

int binary_search(double *arr, int num, double key) {
	int right = num - 1;
	int left = 0;
	int middle;
	bool ind = true;
	while (left <= right && ind) {
		middle = (right + left) / 2;
		if (arr[middle] == key) ind = false;

		else if (key < arr[middle]) {
			right = middle;
		}
		else {
			left = middle + 1;
		}
	}
	if (ind) {
		cout << "The element is not in the array" << endl;
		return NULL;
	}
	else {
		return middle;
	}

}

int main() {
	cout << "Number of elements in the array: " << endl;
	int n;
	cin >> n;
	double *arr = new double[n];
	cout << "Array: " << endl;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << "The element to be found: " << endl;
	double key;
	cin >> key;
	cout << "Sorted array: " << endl;
	shell_knuth(arr, n);
	print(arr, n);
	cout << "The index of the element: " << endl;
	cout << binary_search(arr, n, key) << endl;
	system("pause");
	return 0;
}
