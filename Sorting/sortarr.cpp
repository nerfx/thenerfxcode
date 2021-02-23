#include<iostream>
#include<ctime>
#include<fstream>
#include<cmath>
using namespace std;


int knuth(int n) {
	int num = int(log(n) / log(2)) - 1;
	int hk = 1;
	for (int i = 2; i <= num; ++i) {
		hk = hk * 2 + 1;

	}
	return hk;
}

class sortarr{
private:
	double *arr;
	int num;
public:
	sortarr(int n) {
		num = n;
		arr = new double[num];
	}
	sortarr() {
		int n;
		ifstream in("input.txt");
		in >> n;
		num = n;
		arr = new double[num];
		for (int i = 0; i < num; ++i) {
			in >> arr[i];
		}
	}
	void random() {
		srand(time(NULL));
		for (int i = 0; i < num; ++i) {
			arr[i] = rand() / 100.1;
		}
	}

	friend ostream& operator << (ostream &out, sortarr &m) {
		for (int i = 0; i < m.num; ++i) {
			out << m.arr[i] << " ";
		}
		cout << endl;
		return out;
	}

	int bubble_sort(sortarr s) {
		int k1 = 0, k2 = 0, k3 = 0;
		for (int i = 0; i < s.num - 1; ++i) {
			k3 += 1;
			bool ind = false;
			for (int j = 0; j < s.num - i - 1; ++j) {
				k1 += 1;
				if (s.arr[j]>s.arr[j + 1]) {
					double temp;
					temp = s.arr[j + 1];
					s.arr[j + 1] = s.arr[j];
					s.arr[j] = temp;
					ind = true;
					k2 += 1;

				}
			}
			if (ind == false) {
				break;
			}
		}
		return k1 + k2 + k3;
	}

	int select_sort(sortarr s) {
		int loc;
		double min;
		int k1 = 0, k2 = 0;
		for (int i = 0; i < s.num - 1; ++i) {
			min = s.arr[i];
			loc = i;
			for (int j = i + 1; j < s.num; ++j){
				k1 += 1;
				if (min>s.arr[j]) {
					min = s.arr[j];
					loc = j;
				}
			}
			double temp = s.arr[i];
			s.arr[i] = s.arr[loc];
			s.arr[loc] = temp;
			k2 += 1;
		}
		return k2 + k1;
	}

	int insert_sort(sortarr s3) {
		double temp = 0;
		int key = 0;
		int k1 = 0, k2 = 0, k3 = 0;
		for (int i = 0; i < s3.num - 1; ++i) {
			key = i + 1;
			temp = s3.arr[key];
			k1 += 1;
			for (int j = i + 1; j>0 && temp < s3.arr[j - 1]; --j) {
				s3.arr[j] = s3.arr[j - 1];
				key = j - 1;
				k2 += 1;
			}
			s3.arr[key] = temp;
			k3 += 1;
		}
		return k1 + k2 + k3;
	}
	int shell_sort(sortarr s) { 
		int i, j, k;
		double var;
		int k1 = 0, k2 = 0, k3 = 0;
		for (k = s.num / 2; k > 0; k /= 2) {
			for (i = k; i < s.num; ++i) {
				var = s.arr[i];
				k1 += 1;
				for (j = i; j >= k; j -= k) {
					k2 += 1;
					if (var < s.arr[j - k]) {
						s.arr[j] = s.arr[j - k];
						k3 += 1;
					}
					else {
						break;
					}
				}
				s.arr[j] = var;
			}
		}
		return k1 + k2 + k3;
	}

	int shell_knuth(sortarr s) {
		int i, j, k;
		double var;
		int k1 = 0, k2 = 0, k3 = 0;
		for (k = knuth(s.num); k >= 1; k = (k - 1) / 2) {
			for (i = k; i < s.num; ++i) {
				var = s.arr[i];
				k1 += 1;
				for (j = i; j >= k; j -= k) {
					k2 += 1;
					if (var < s.arr[j - k]) {
						s.arr[j] = s.arr[j - k];
						k3 += 1;
					}
					else {
						break;
					}
				}
				s.arr[j] = var;
			}
		}
		return k1 + k2 + k3;
	}
};

int main() {
	ofstream out("file14.xls");
	out << "Elem" << "\t" << "compl1" << "\t" << "compl2" << "\t" << "compl3" << "\t" << "compl4" << "\t" << "compl" << endl;
	for (int i = 10; i <= 1000; ++i) {
		sortarr s1(i), s2(i), s3(i), s4(i), s5(i);
		s1.random();
		s2.random();
		s3.random();
		s4.random();
		s5.random();
		out << i << "\t" << s1.bubble_sort(s1) << "\t" << s2.select_sort(s2) << "\t" << s3.insert_sort(s3);
		out<< "\t" << s4.shell_sort(s4) << "\t" << s5.shell_knuth(s5) << endl;
	}
	system("pause");
	return 0;
}