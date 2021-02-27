#include<iostream>
using namespace std;

void print(int *A, int N) {
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

bool narayana(int *arr, int n) {
	int j = n-2;
	while (j >= 0) {
		if (arr[j] < arr[j+1]) {
			break;
		}
		else {
			--j;
		}
	}

	if (j < 0) {
		return false;
	}

	int l = n-1;
	while (l >= 0) {
		if (arr[l]>arr[j]) {
			break;
		}
		else {
			--l;
		}
	}
	swap(arr[j], arr[l]);
	int left = j + 1, right = n - 1; 
	int h = (left + right) / 2; 
	int i = 0; 
	while (i + left <= h) {
		swap(arr[i + left], arr[right - i]);
		++i;
	}
	return true;
}

int main() {
	int n;
	cout << "Enter the number of elements in the array: " << endl;
	cin >> n;
	int *dig = new int[n];
	for (int i = 0; i < n; ++i) {
		dig[i] = i + 1;
	}
	cout << "Permutations: " << endl;
	int i = 1;
	cout << i << ": ";
	print(dig, n);
	++i;
	while (narayana(dig, n)) {
		cout << i << ": ";
		print(dig, n);
		++i;
	}
	system("pause");
	return 0;
}