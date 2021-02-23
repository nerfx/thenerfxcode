#include<iostream>
using namespace std;

void print(double **arr, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void del_element(double **arr, int m, int &n, int index) {
	for (int i = 0; i < m; ++i) {
		for (int j = index; j < n; ++j) {
			arr[i][j] = arr[i][j + 1];
		}
	}
	n--;
}

double det(double **arr, int n) { //the computation of the determinant
	if (n == 2) {
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	}
	if (n > 2) {
		int p = 0;
		int l = 1;
		int m = n - 1;
		double **arr2 = new double*[m];
		for (int i = 0; i < m; ++i) {
			arr2[i] = new double[n];
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (k != j) {
						arr2[i][j] = arr[i+1][j];
					}
				}
			}
			del_element(arr2, m, n, k);
			p = p + det(arr2, n)*l*arr[0][k];
			n++;
			l = -l;
		}
		return p;
	}
}

void matrix(double **arr1, double **arr2, int n, int index) { 
	for (int i = 0; i < n; ++i) {
		arr1[i][index] = arr2[i][0];
	}
}

void kramer(double **arr1, double **arr2, int n) {
	double **roots = new double*[n];
	for (int i = 0; i < n; ++i) {
		roots[i] = new double[1];
	}
	double **arr3 = new double*[n];
	for (int i = 0; i < n; ++i) {
		arr3[i] = new double[1];
	}
	int det1 = det(arr1, n);
	if (det1 == 0) {
		cout << "Main determinant = 0" << endl;
	}
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				arr3[j][0] = arr1[j][i];
				arr1[j][i] = arr2[j][0];
			}
			roots[i][0] = det(arr1, n) / det1;
			matrix(arr1, arr3, n, i);
		}
		print(roots, n, 1);
	}
}

int main() {
	int n;
	cout << "Enter the number of rows/columns: ";
	cin >> n;
	double **arr = new double *[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new double[n];
	}
	cout << "Enter the matrix: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	cout << "Matrix: " << endl;
	print(arr, n, n);
	double **arr1 = new double *[n];
	for (int i = 0; i < n; ++i) {
		arr1[i] = new double [1];
	}
	cout << "Enter a column of free coefficients: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 1; ++j) {
			cin >> arr1[i][j];
		}
	}
	cout << "The roots of the system: " << endl;
	kramer(arr, arr1, n);
	system("pause");
	return 0;
}