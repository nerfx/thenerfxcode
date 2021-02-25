#include<iostream>
#include<ctime>
using namespace std;

void print(double *arr1, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr1[i] << " ";
	}
	cout << "\n";
}

void merge(double *arr, int left, int right) {
	int N = right - left + 1;
	double *add_arr = new double[N];
	int middle = (right + left) / 2;
	int i = left, j = middle + 1;
	int k = 0; 

	
	while (i <= middle && j <= right) {
		if (arr[i] < arr[j]) {
			add_arr[k++] = arr[i++];
		}
		else {
			add_arr[k++] = arr[j++];
		}
	}
	while (i <= middle) {
		add_arr[k++] = arr[i++];
	}
	
	while (j <= right) {
		add_arr[k++] = arr[j++];
	}

	for (int i = 0; i < N; ++i) {
		arr[left + i] = add_arr[i];
	}
}

void merge_sort(double *A, int left, int right) {
	int middle;
	if (left < right) {
		if (right - left == 1) {
			if (A[right] < A[left]) {
				swap(A[left], A[right]);
			}
		}
		else {
			middle = (right + left) / 2;
			merge_sort(A, left, middle);
			merge_sort(A, middle + 1, right);
			merge(A, left, right);
		}
	}
}

int main() {
	srand(time(NULL));
	int n;
	cout << "Number of elements in the array: " << endl;
	cin >> n;
	double *a = new double[n];
	for (int i = 0; i < n; ++i) {
		a[i] = rand() / 100.1;
	}
	cout << "Source Array: " << endl;
	print(a, n);
	merge_sort(a, 0, n-1);
	cout << "Sorted array: " << endl;
	print(a, n);
	system("pause");
	return 0;
}