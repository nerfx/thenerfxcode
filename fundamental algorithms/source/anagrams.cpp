#include<iostream>
using namespace std;

void print(char *A, int N) {
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	cout << "\n";
}

void anagrams(char *arr, int left, int right, int n) {
	if (right == left) {
		print(arr, n);
	}
	else {
		int k = left; 
		while (k < n) {

			swap(arr[left], arr[k]);
			left += 1;
			anagrams(arr, left, right, n);
			left -= 1;
			swap(arr[left], arr[k]);
			++k;
		}
	}
}

int main() {
	int n;
	cout << "Enter the number of letters: " << endl;
	cin >> n;
	cout << "Enter the letters array: " << endl;
	char *a = new char[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << "Anagrams: " << endl;
	anagrams(a, 0, n - 1, n);
	system("pause");
	return 0;
}