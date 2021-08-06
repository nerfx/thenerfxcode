#include<iostream>
#include<ctime>
#include<string>
using namespace std;

void output(double **matr, int M, int N) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << matr[i][j] << "\t";
		}
		cout << "\n";
	}
}

void check_the_result(double **matrix1, double **matrix2, int row_1, int row_2, int col_1, int col_2) {

	double **mult_matrix = new double *[row_1];
	for (int i = 0; i < row_1; ++i) {
		mult_matrix[i] = new double[col_2];
	}
	
	if (col_1 == row_2) {
		double sum_of_elem = 0;
		for (int i = 0; i < row_1; ++i) {
			for (int j = 0; j < col_2; ++j) {
				for (int k = 0; k < col_1; ++k) {
					sum_of_elem += matrix1[i][k] * matrix2[k][j];
				}
				mult_matrix[i][j] = sum_of_elem;
				sum_of_elem = 0;
			}
		}
		output(mult_matrix, row_1, col_2);
	}
	else {
		cout << "Multiplication is not possible" << endl;
	}
}

void delete_of_col(double **M, int row_for_del, int &col_for_del, int ind) {
	for (int i = 0; i < row_for_del; ++i){
		for (int j = ind; j < col_for_del - 1; ++j) {
			M[i][j] = M[i][j + 1];
		}
	}
	col_for_del--;
}

double determinant(double **matrix, int row_for_det, int col_for_det) {
	if (row_for_det == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		double sum = 0;
		double mult_of_minor = 1;
		int new_num = row_for_det - 1;
		double **new_matrix = new double *[new_num];
		for (int i = 0; i < new_num; ++i) {
			new_matrix[i] = new double[col_for_det];
		}
		for (int k = 0; k < col_for_det; ++k) {
			for (int i = 0; i < new_num; ++i) {
				for (int j = 0; j < col_for_det; ++j) {
					if (k != j) {
						new_matrix[i][j] = matrix[i + 1][j];
					}
				}
			}
			delete_of_col(new_matrix, new_num, col_for_det, k);
			sum = sum + mult_of_minor * matrix[0][k] * determinant(new_matrix, new_num, col_for_det);
			col_for_det++;
			mult_of_minor = -mult_of_minor;
		}
		return sum;
	}
}

double delete_of_row_col(double **M1, int row_for_del1, int col_for_del1, int ind1, int ind2) {

	double **re_assign = new double *[row_for_del1];
	for (int i = 0; i < row_for_del1; ++i) {
		re_assign[i] = new double[col_for_del1];
	}
	for (int i = 0; i < row_for_del1; ++i) {
		for (int j = 0; j < col_for_del1; ++j) {
			re_assign[i][j] = M1[i][j];
		}
	}

	for (int i = 0; i < row_for_del1; ++i) {
		for (int j = ind1; j < col_for_del1 - 1; ++j) {
			re_assign[i][j] = re_assign[i][j + 1];
		}
	}
	col_for_del1--;
	for (int i = 0; i < col_for_del1; ++i) {
		for (int j = ind2; j < row_for_del1 - 1; ++j) {
			re_assign[j][i] = re_assign[j + 1][i];
		}
	}
	row_for_del1--;
	return determinant(re_assign, row_for_del1, col_for_del1);
}

double **transpose(double **input_matr, int in_row, int in_col) {
	double **t_matr = new double *[in_col];
	for (int i = 0; i < in_col; ++i) {
		t_matr[i] = new double[in_row];
	}
	for (int i = 0; i < in_col; ++i) {
		for (int j = 0; j < in_row; ++j) {
			t_matr[i][j] = input_matr[j][i];
		}
	}
	return t_matr;
}

double **reverse_matrix(double **matrix, int row, int col) {
	double det = determinant(matrix, row, col);
	if (det == 0) {
		cout << "The the determinant is null" << endl;
		return matrix;
	}
	else {
		double index = 0;
		double **add_matrix = new double *[row];
		for (int i = 0; i < row; ++i) {
			add_matrix[i] = new double[col];
		}
		if (row == 2) {
			double **t_matrix = new double*[row];
			for (int i = 0; i < row; ++i) {
				t_matrix[i] = new double[col];
			}
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					t_matrix[i][j] = matrix[i][j];
				}
			}
			swap(t_matrix[0][0], t_matrix[1][1]);
			t_matrix[0][1] *= (-1);
			t_matrix[1][0] *= (-1);
			for (int i = 0; i < col; ++i) {
				for (int j = 0; j < row; ++j) {
					t_matrix[i][j] /= det;
				}
			}
			return t_matrix;
		}
		else {
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) 
				{
					if ((i + j + 2) % 2 == 0) {
						index = 1;
					}
					else {
						index = -1;
					}
					add_matrix[i][j] = index * delete_of_row_col(matrix, row, col, j, i);
				}
			}
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					add_matrix[i][j] /= det;
				}
			}
			double **final_matrix = transpose(add_matrix, row, col);

			return final_matrix;
		}
	}
}

int main() {
	srand(time(NULL));
	int row;
	int col;
	cout << "Input number of rows of matrix: " << endl;
	cin >> row;
	cout << "Input number of cols of matrix: " << endl;
	cin >> col;
	double **arr = new double *[row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new double[col];
	}
	
	string mess;
	bool index = true;
	double **rev_matr;
	cout << "Input a random matrix?(Yes/No)" << endl;
	cin >> mess;
	if (mess == "Yes") {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				arr[i][j] = rand() / 100.1;
			}
		}
		output(arr, row, col);
		rev_matr = reverse_matrix(arr, row, col);
		cout << "The reverse matrix: " << endl;
		output(rev_matr, col, row);
		cout << "Check: " << endl;
		check_the_result(arr, rev_matr, row, row, col, col);

	}
	else if (mess == "No") {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				cin >> arr[i][j];
			}
		}
		output(arr, row, col);
		rev_matr = reverse_matrix(arr, row, col);
		cout << "The reverse matrix: " << endl;
		output(rev_matr, col, row);
		cout << "Check: " << endl;
		check_the_result(arr, rev_matr, row, row, col, col);
	}
	else {
		cout << "Press any key" << endl;
		index = false;
	}
	system("pause");
	return 0;
}