#include<iostream>
using namespace std;
void del_element(double **arr, int m, int &n, int index) {
	for (int i = 0; i < m; ++i) {
		for (int j = index; j < n; ++j) {
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
		double p = 0;
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
						arr2[i][j] = arr[i + 1][j];
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

double ** kramer(double **arr1, double **arr2, int n) {
	double **roots = new double*[n];
	for (int i = 0; i < n; ++i) {
		roots[i] = new double[1];
	}
	double **arr3 = new double*[n];
	for (int i = 0; i < n; ++i) {
		arr3[i] = new double[1];
	}
	double det1 = det(arr1, n);
	if (det1 == 0) {
		cout << "Main determinant = 0" << endl;
		return arr1;
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
		return roots;
	}
}

void print1(double **a, int M, int N) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}


double scalar_mult(double *vec1, double *vec2, int size) {
	double s = 0; 
	for (int i = 0; i < size; ++i) {
		s += vec1[i] * vec2[i];
	}
	return s;
}


double * mult(double *arr, int N, double k) {
	for (int i = 0; i < N; ++i) {
		arr[i] = k*arr[i];
	}
	return arr;
}

void projection (double **matr, double *vec, int M1, int N1) {
	double *arr1 = new double[N1];
	double *arr2 = new double[N1];
	double **alpha = new double*[M1];
	for (int i = 0; i < M1; ++i) {
		alpha[i] = new double[M1];
	}

	double **coef = new double*[M1];
	for (int k = 0; k < M1; ++k) {
		coef[k] = new double[1];
	}
	for (int i = 0; i < M1; ++i) {
		for (int j = 0; j < N1; ++j) {
			arr1[j] = matr[i][j];
		}
		coef[i][0] = scalar_mult(arr1, vec, N1);
		for (int k = 0; k < M1; ++k) {
			for (int l = 0; l < N1; ++l) {
				arr2[l] = matr[k][l];
			}
			alpha[i][k] = scalar_mult(arr1, arr2, N1);
		}
	}
	double **root = kramer(alpha, coef, M1);
	double *proj = new double[N1]; 
	for (int i = 0; i < N1; ++i) {
		proj[i] = 0;
	}
	double *arr3 = new double[N1];
	for (int i = 0; i < M1; ++i) {
		for (int k = 0; k < N1; ++k) {
			arr3[k] = matr[i][k];
		}
		for (int j = 0; j < N1; ++j) {
			proj[j] = proj[j] + arr3[j] * root[i][0];
		}
	}
	cout << "The projection of the vector: ";
	for (int i = 0; i < N1; ++i) {
		cout << proj[i] << " ";
	}
	cout << "\n";
}

int main() {
	int m; 
	int n; 
	cout << "Enter the number of linear shell vectors: ";
	cin >> m;
	cout << "Enter the dimension of the vectors: ";
	cin >> n;
	double **arr = new double*[m];
	for (int i = 0; i < m; ++i) {
		arr[i] = new double[n];
	}
	for (int i = 0; i < m; ++i) {
		cout << "Enter "<<i+1<<" shell vector: ";
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	cout << "Enter the vector whose projection you want to find: ";
	double *a = new double[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	projection(arr, a, m, n);
	system("pause");
	return 0;
}