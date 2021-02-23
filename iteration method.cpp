#include<iostream>
using namespace std;

class matrix {
private:
	int row;
	int col;
	double **arr;
public:
	matrix(int m = 3, int n = 3) { 
		row = m;
		col = n;
		arr = new double*[row];
		for (int i = 0; i < row; ++i) {
			arr[i] = new double[n];
		}
	}
	friend istream &operator >> (istream &in, matrix &y) { 
		for (int i = 0; i < y.row; ++i) {
			for (int j = 0; j < y.col; ++j) {
				in >> y.arr[i][j];
			}
		}
		return in;
	}
	friend ostream &operator << (ostream &out, matrix &y) {
		for (int i = 0; i < y.row; ++i) {
			for (int j = 0; j < y.col; ++j) {
				out << y.arr[i][j] << "\t";
			}
			cout << endl;
		}
		return out;
	}
	matrix operator + (matrix &y) { 
		for (int i = 0; i < y.row; ++i) {
			for (int j = 0; j < y.col; ++j) {
				n.arr[i][j] = arr[i][j] + y.arr[i][j];
			}
		}
		return n;
	}
	friend matrix operator * (matrix &y, matrix &y1); 

	void operator = (matrix &y) {
		for (int i = 0; i < y.row; ++i) {
			for (int j = 0; j < y.col; ++j) {
				arr[i][j] = y.arr[i][j];
			}
		}
	}
	matrix operator - (matrix &m) { 
		matrix add(m.row, m.col);
		for (int i = 0; i < m.row; ++i) {
			for (int j = 0; j < m.col; ++j) {
				add.arr[i][j] = arr[i][j] - m.arr[i][j];
			}
		}
		return add;
	}
	double func_norm(matrix &y) { 
		double norm = 0;
		for (int i = 0; i < y.row; ++i) {
			for (int j = 0; j < y.col; ++j) {
				norm = norm + y.arr[i][j] * y.arr[i][j];
			}
		}
		double norm1 = sqrt(norm);
		return norm1;
	}
	matrix class_iter(matrix m) { 
		double s;
		for (int i = 0; i < m.row; ++i) {
			s = m.arr[i][i];
			for (int j = 0; j < m.col; ++j) {
				m.arr[i][j] = m.arr[i][j] * (-1) / s;
				m.arr[i][i] = 0;
			}
		}
		return m;
	}

	matrix iter_betta(matrix m) { 
		double s = 0;
		for (int i = 0; i < m.row; ++i) {
			s = arr[i][i];
			for (int j = 0; j < m.col; ++j) {
				m.arr[i][j] = m.arr[i][j] / s;
			}
		}
		return m;
	}

	matrix iterations(matrix alpha, matrix betta, double eps) {
		matrix x0(3, 1), x1(3, 1), x2(3, 1);
		x0 = iter_betta(betta);
		cout << "The matrix is reduced to the iterative type: " << endl;
		cout << class_iter(alpha) << endl;
		x1 = x0;
		int i = 0;
		while (true) {
			x1 = alpha * x0 + betta;
			x2 = x1 - x0;
			if (func_norm(x2) < eps) break;
			x0 = x1;
			i++;
		}
		cout << "Number of iterations: ";
		cout << i << endl;
		return x1;
	}

	matrix checkpoint(matrix &m1, matrix &m2) {
		matrix m3(3, 1);
		m3 = m1*m2;
		return m3;
	}
};
matrix operator * (matrix &y, matrix &y1)
{
	matrix n(y.row, y1.col);
	double s;
	matrix r0(0, 0);
	if (y.col != y1.row) {
		cout << "Multiplication is not possible" << endl;
		return NULL;
	}
	for (int i = 0; i < y.row; ++i) {
		for (int j = 0; j < y1.col; ++j) {
			s = 0;
			for (int k = 0; k < y.col; ++k) {
				s = s + y.arr[i][k] * y1.arr[k][j];
			}
			n.arr[i][j] = s;

		}
	}
	return n;
}

int main() {
	matrix x1(3, 3), x2(3, 1), x(3, 3), x11(3, 1), x3(3, 1);
	cout << "Enter the coefficients for unknown values: " << endl;
	cin >> x1;
	cout << "Enter the free members column: " << endl;
	cin >> x2;
	cout << "Coefficients: " << endl;
	cout << x1;
	cout << "Column of free coefficients: " << endl;
	cout << x2;
	x = x1;
	x3 = x2;
	cout << "Enter the accuracy: " << endl;
	double eps;
	cin >> eps;
	x11 = x1.iterations(x1, x2, eps);
	cout << "Roots: " << endl;
	cout << x11 << endl;
	cout << "Checking the results obtained: " << endl;
	cout << x.checkpoint(x, x11) - x3 << endl;
	system("pause");
	return 0;
}