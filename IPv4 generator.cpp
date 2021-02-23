#include<iostream>
#include<ctime>
using namespace std;

void print(char *arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i];
	}
	cout << endl;
}

void ip_gen(int n) {
	for (int k = 1; k <= n; ++k) {
		int s1 = rand() % 3 + 1;
		int s2 = rand() % 3 + 1;
		int s3 = rand() % 3 + 1;
		int s4 = rand() % 3 + 1;
		int size = s1 + s2 + s3 + s4 + 3; 
		char *ip = new char[size];
		ip[s1] = '.';
		int ind1 = s1 + s2 + 1;
		ip[ind1] = '.';
		int ind2 = ind1 + s3 + 1;
		ip[ind2] = '.';
	
		if (s1 == 3) {
			ip[0] = rand() % 2 + '1';
			ip[1] = rand() % 5 + '0';
			ip[2] = rand() % 5 + '0';
		}
		else if (s1 == 2) {
			ip[0] = rand() % 9 + '1';
			ip[1] = rand() % 10 + '0';
		}
		else {
			ip[s1 - 1] = rand() % 10 + '0';
		}
		if (s2 == 3) {
			ip[s1 + 1] = rand() % 2 + '1';
			ip[s1 + 2] = rand() % 5 + '0';
			ip[s1 + 3] = rand() % 5 + '0';
		}
		else if (s2 == 2) {
			ip[s1 + 1] = rand() % 9 + '1';
			ip[s1 + 2] = rand() % 10 + '0';
		}
		else {
			ip[ind1 - 1] = rand() % 10 + '0';
		}
		if (s3 == 3) {
			ip[ind1 + 1] = rand() % 2 + '1';
			ip[ind1 + 2] = rand() % 5 + '0';
			ip[ind1 + 3] = rand() % 5 + '0';
		}
		else if (s3 == 2) {
			ip[ind1 + 1] = rand() % 9 + '1';
			ip[ind1 + 2] = rand() % 10 + '0';
		}
		else {
			ip[ind2 - 1] = rand() % 10 + '0';
		}
		if (s4 == 3) {
			ip[ind2 + 1] = rand() % 2 + '1';
			ip[ind2 + 2] = rand() % 5 + '0';
			ip[ind2 + 3] = rand() % 5 + '0';
		}
		else if (s4 == 2) {
			ip[ind2 + 1] = rand() % 9 + '1';
			ip[ind2 + 2] = rand() % 10 + '0';
		}
		else {
			ip[size - 1] = rand() % 10 + '0';
		}
		cout << "ip ¹" << k << ": ";
		print(ip, size);
	}
}


int main() {
	srand(time(NULL));
	int n;
	cout << "Enter the number of generated ip addresses: ";
	cin >> n;
	ip_gen(n);
	system("pause");
	return 0;
}