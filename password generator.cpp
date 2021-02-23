#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

void password_gen(int sym) { 

	int size1 = rand() % sym;
	int size2 = sym - size1;
	int size3 = rand() % size2;
	int size4 = sym - size1 - size3;

	char *arr = new char[sym];

	for (int i = 0; i < size4; i++) {    
		arr[i] = ('a' + (rand() % 26));
	}
	for (int i = size4; i < size4 + size3; i++) {
		arr[i] = ('0' + (rand() % 10));
	}
	for (int i = size4 + size3; i < sym; i++) {
		arr[i] = ('A' + (rand() % 26));
	}

	random_shuffle(&arr[0], &arr[sym - 1]);

	for (int i = 0; i < sym; i++) {
		cout << arr[i];
	}
	cout << endl;
}

void size_of_pass(int N) {
	srand(time(NULL));

	int count;

	for (int i = 0; i < N; i++) {
		count = 8 + rand() % 9;
		password_gen(count);
	}
}

int main() {
	int n;
	cout << "Number of generated passwords: ";
	cin >> n;
	size_of_pass(n);
	system("pause");
	return 0;
}
