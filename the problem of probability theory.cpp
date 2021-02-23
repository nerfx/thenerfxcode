#include<iostream>
#include<ctime>
using namespace std;

void print(int *arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
	}
	cout << endl;
}

void max(double *arr, int n) {
	double max = arr[0];
	int index_max = 0;
	for (int i = 1; i < n; ++i) {
		if (max < arr[i]) {
			max = arr[i];
			index_max = i;
		}
	}
	cout << "Maximum probability: " << max<<"%" << " in the experiment ¹" << index_max + 1 << endl;
}

void probability(int *arr1, int *arr2, int n, double num, int exper) {
	double *arr_of_prob = new double[exper];
	for (int k = 0; k < exper; ++k) {
		for (int i = 0; i < n; ++i) { 
			arr1[i] = rand() % 2;
		}
		for (int i = 0; i < n; ++i) {
			arr2[i] = rand() % 2;
		}
		double count = 0;
		for (int i = 1; i <= num; ++i) {
			if (arr1[rand() % n] == arr2[rand() % n]) count += 1;
		}
		cout << "Exp ¹" << k + 1 << endl;
		cout << "The sequence of the player ¹1:";
		print(arr1, n);
		cout << "Thr sequence of the player ¹2: ";
		print(arr2, n);
		double prob = (count / num) * 100;
		cout << "Probability of winning = " << prob << "%" << endl;
		arr_of_prob[k] = prob;
	}
	max(arr_of_prob, exper);
}

int main() {
	srand(time(NULL));
	int n;
	cout << "Enter the number of sequence elements: ";
	cin >> n;
	int *arr1 = new int[n];
	int *arr2 = new int[n];
	cout << "Enter the number of games: ";
	double num;
	cin >> num;
	probability(arr1, arr2, n, num, 100);

	system("pause");
	return 0;
}