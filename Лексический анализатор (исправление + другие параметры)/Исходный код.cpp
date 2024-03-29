#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void output(vector<T> A, int N) {
	for (int i = 0; i < N; ++i) {
		cout << A[i] << endl;
	}
}


vector<string> delete_tab(vector<string> B, int size) {
	for (int i = 0; i < size; ++i) {
		if (B[i][0] == '\t') {
			B[i].erase(0, 1);
		}
	}
	vector<string> add_arr;
	for (int i = 0; i < size; ++i) {
		add_arr.push_back(B[i]);
	}
	return add_arr;
}


vector<string> del_space(vector<string> C) {
	int size1 = C.size();
	for (int i = 0; i < size1; ++i) {
		if (C[i][0] == ' ') {
			C[i].erase(0, 1);
		}
	}

	return C;
}



vector<int> brack(vector<string> D, int num) {
	vector<int> brack_ind;
	int size2 = D[num].size();
	for (int k = 0; k < size2; ++k) {
		if (D[num][k] == '(' || D[num][k] == ')') {
			brack_ind.push_back(k);
		}
	}
	return brack_ind;
}

vector<int> search_of_comm(vector<string> complex_class, int ind1, int ind2, int ind_of_row) {
	vector<int> index_comm;
	int size_complex_class = complex_class.size();
	for (int i = ind1; i <= ind2; ++i) {
		if (complex_class[ind_of_row][i] == ',') {
			index_comm.push_back(i);
		}
	}

	return index_comm;
}

vector<int> analysis(vector<string> def_class, vector<int> brack_ind, int num_of_row) {
	bool var1 = true, var2 = true;
	int ind_of_comm;
	vector<int> index;
	int size3 = brack_ind.size();
	for (int i = 0; i < size3; i = i + 2) {

		ind_of_comm = def_class[num_of_row].find(',', brack_ind[i]);

		if (def_class[num_of_row][ind_of_comm - 1] == 'f' || def_class[num_of_row][ind_of_comm - 1] == 'F') {

			int pos1 = def_class[num_of_row].find('e', brack_ind[i]);

			if (pos1 == -1) {
				var1 = true;
			}
			else if (pos1 > ind_of_comm) {
				var1 = true;
			}
			else {
				var1 = false;
			}
		}
		else {
			var1 = false;
		}

		if (def_class[num_of_row][brack_ind[i + 1] - 1] == 'f' || def_class[num_of_row][brack_ind[i + 1] - 1] == 'F') {
			int pos3;
			pos3 = def_class[num_of_row].find('e', ind_of_comm);
			if (pos3 == -1) {
				var2 = true;
			}
			else if (pos3 > brack_ind[i + 1]) {
				var2 = true;
			}
			else {
				var2 = false;
			}
		}
		else {
			var2 = false;
		}

		if (var1 && var2) {
			index.push_back(i);
			index.push_back(i + 1);
		}
	}
	return index;
}

void function(vector<string> sym, vector<int> arr1, vector<int> arr2, int len) {
	int size4 = arr1.size();

	for (int i = 0; i < size4; ++i) {
		if (arr2[i] == 0) {
			sym[arr1[i]].erase(arr2[i], len);
		}
		else {
			sym[arr1[i]].erase(0, arr2[i]);
		}
	}

	vector<int> commas;
	del_space(sym);
	sym = del_space(sym);

	ofstream out("result.txt");
	vector<string> new_arr;
	vector<int> numbers;

	int size5 = arr1.size();
	for (int i = 0; i < size5; ++i) {
		vector<int> bc = brack(sym, arr1[i]);
		numbers = analysis(sym, bc, arr1[i]);

		bool ind = false;
		int n = numbers.size();
		if (n == 0) {
			continue;
		}
		else {
			for (int k = 0; k < bc[numbers[0]]; ++k) {
				if (sym[arr1[i]][k] == ',') {
					ind = true;
					break;
				}
			}

			if (!ind) {
				if (numbers.size() / 2 == 1) {
					for (int j = 0; j <= bc[numbers[1]]; ++j) {
						out << sym[arr1[i]][j];
					}
					out << endl;
				}
				else {
					int add = 1;

					for (int l = 0; l <= bc[numbers[add]]; ++l) {
						out << sym[arr1[i]][l];
					}
					out << endl;

					vector<int> comm1;

					for (int r = 3; r < n; r = r + 2) {
						int new_ind1;

						comm1 = search_of_comm(sym, bc[numbers[r] - 2] + 3, bc[numbers[r]], arr1[i]);

						int size_comm1 = comm1.size();
						if (size_comm1 == 1) {
							new_ind1 = bc[numbers[r] - 2] + 3;
						}
						else {
							new_ind1 = comm1[size_comm1 - 2] + 2;
						}
						for (int e = new_ind1; e <= bc[numbers[r]]; ++e) {
							out << sym[arr1[i]][e];
						}

						out << endl;
					}
				}
			}
			else {
				int new_ind2;
				vector<int> comm3;
				int size_comm3;

				for (int r = 1; r < n; r = r + 2) {

					comm3 = search_of_comm(sym, bc[numbers[r] - 2] + 3, bc[numbers[r]], arr1[i]);

					size_comm3 = comm3.size();

					if (size_comm3 == 1) {
						new_ind2 = bc[numbers[r] - 2] + 3;
					}
					else {
						new_ind2 = comm3[size_comm3 - 2] + 2;
					}
					for (int e = new_ind2; e <= bc[numbers[r]]; ++e) {
						out << sym[arr1[i]][e];
					}

					out << endl;
				}
			}
		}
	}
}

int main() {
	ifstream in("input.txt");

	string mes;

	vector <string> arr;

	while (!in.eof()) {
		getline(in, mes);
		arr.push_back(mes);
	}
	int arr_size = arr.size();
	output(arr, arr_size);

	vector<string> del = delete_tab(arr, arr_size);

	int del_size = del.size();
	output(del, del_size);

	string lex = "complex";
	vector<int> index;
	vector<int> pos;

	int val;
	int sym_of_del = lex.length();
	for (int i = 0; i < del_size; ++i) {
		val = del[i].find(lex, 0);
		if (val != -1) {
			index.push_back(i);
			pos.push_back(val);
		}
	}

	function(del, index, pos, sym_of_del);

	system("pause");
	return 0;
}
