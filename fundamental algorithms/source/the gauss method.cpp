#include<iostream>
using namespace std;

void print(double **a, int M, int N) { 
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

double * gauss(double **arr, int N) {
	double var;

	for (int i = 0; i < N; ++i) {
		if (arr[i][i] == 0) {
			int ind;
			for (int k = 0; k < N; ++k) {
				if (arr[k][i] != 0) {
					ind = k; break;
				}
			}
			for (int j = 0; j < N + 1; ++j) {
				var = arr[i][j];
				arr[i][j] = arr[ind][j];
				arr[ind][j] = var;
			}
		}
	}
	int N1 = N + 1;

	double **add_matrix = new double*[N];
	for (int i = 0; i < N; ++i) {
		add_matrix[i] = new double[N1];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N1; ++j) {
			add_matrix[i][j] = arr[i][j];
		}
	}

	double value = 0;
	for (int k = 0; k < N; ++k) {
		for (int j = 0; j < N1; ++j) {
			add_matrix[k][j] = add_matrix[k][j] / arr[k][k];
		}
		for (int i = k + 1; i < N; ++i) {
			value = add_matrix[i][k] / add_matrix[k][k];
			for (int j = 0; j < N1; ++j)
				add_matrix[i][j] = add_matrix[i][j] - value*add_matrix[k][j];
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N1; ++j) {
				arr[i][j] = add_matrix[i][j];
			}
		}
	}

	double value1 = 0;
	for (int k = N - 1; k >= 0; k--) {
		for (int j = N; j >= 0; j--) {
			add_matrix[k][j] = add_matrix[k][j] / arr[k][k];
		}
		for (int i = k - 1; i >= 0; i--) {
			value1 = add_matrix[i][k] / add_matrix[k][k];
			for (int j = N; j >= 0; j--) {
				add_matrix[i][j] = add_matrix[i][j] - value1*add_matrix[k][j];
			}
		}
	}

	double *roots = new double[N];
	for (int i = 0; i < N; ++i) {
		roots[i] = add_matrix[i][N];
	}
	return roots;
}

int main() {
	int n;
	cout << "Enter the number of rows/columns: ";
	cin >> n;
	double **matr = new double *[n];
	for (int i = 0; i < n; ++i) {
		matr[i] = new double[n + 1];
	}
	cout << "Enter the extended matrix: " << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			cin >> matr[i][j];
		}
	}
	cout << "System introduced: " << endl;
	print(matr, n, n + 1);
	double *root = gauss(matr, n);
	cout << "The roots of the system : " << endl;
	for (int i = 0; i < n; ++i) {
		cout << root[i] << endl;
	}
	return 0;
}