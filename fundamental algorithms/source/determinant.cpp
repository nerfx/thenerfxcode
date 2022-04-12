#include<iostream>
#include<ctime>
using namespace std;

void print(double **arr, int m, int n) { 
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

void del_element(double **arr, int m, int &n, int index) { 
	for (int i = 0; i < m; ++i) {
		for (int j = index; j < n - 1; ++j) {
			arr[i][j] = arr[i][j + 1];
		}
	}
	n--;
}

double det(double **arr, int n) {
	if (n == 2) {
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	}
	if (n > 2) {
		int l = 1;
		double p = 0;
		int m = n - 1;
		double **arr2 = new double*[m];
		for (int i = 0; i < m; ++i) {
			arr2[i] = new double[n];
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (k != j) {
						arr2[i][j] = arr[i + 1][j];
					}
				}
			}
			del_element(arr2, m, n, k);
			p = p + arr[0][k] * det(arr2, n) * l;
			n++;
			l = -l;
		}
		return p;
	}
}

int main() {
	srand(time(NULL));
	int n;
	cout << "Enter the number of rows/columns: ";
	cin >> n;
	double **arr1 = new double *[n];
	for (int i = 0; i < n; ++i) {
		arr1[i] = new double[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr1[i][j] = rand() / 1000.1;
		}
	}
	cout << "Matrix: " << endl;
	print(arr1, n, n);
	cout << "det = ";
	cout << det(arr1, n) << endl;
	system("pause");
	return 0;
}