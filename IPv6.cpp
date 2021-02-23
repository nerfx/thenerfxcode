#include<iostream>
#include<ctime>
using namespace std;

void print(char *arr, int n1) {
	for (int i = 0; i < n1; ++i) {
		cout << arr[i];
	}
	cout << endl;
}

void ipv6_gen(int N) {
	for (int k = 1; k <= N; ++k) {
		char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'a', 'b', 'c', 'd', 'e', 'f' };

		/*random formation of
		block lengths (from 1 to 4)*/
		int size1 = rand() % 4 + 1;
		int size2 = rand() % 4 + 1;
		int size3 = rand() % 4 + 1;
		int size4 = rand() % 4 + 1;
		int size5 = rand() % 4 + 1;
		int size6 = rand() % 4 + 1;
		int size7 = rand() % 4 + 1;
		int size8 = rand() % 4 + 1;

		//the size of the ip array, including colons after each block, except the last one
		int size = size1 + size2 + size3 + size4 + size5 + size6 + size7 + size8 + 7;
		char *ip = new char[size];

		/* calculation of indices of elements
		ip arrays with a colon in them */
		int index1 = size1;
		ip[size1] = ':';
		int index2 = index1 + size2 + 1;
		ip[index2] = ':';
		int index3 = index2 + size3 + 1;
		ip[index3] = ':';
		int index4 = index3 + size4 + 1;
		ip[index4] = ':';
		int index5 = index4 + size5 + 1;
		ip[index5] = ':';
		int index6 = index5 + size6 + 1;
		ip[index6] = ':';
		int index7 = index6 + size7 + 1;
		ip[index7] = ':';

		/* filling in the ip array, taking into account that if the block length is
		if it is greater than 1, then the first element of the block is not 0 */
		if (size1 > 1) {
			ip[index1-size1] = hex[rand() % 15 + 1];
			for (int i = 1; i < index1; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index1 - size1] = hex[rand() % 16];
		}

		if (size2>1) {
			ip[index2 - size2] = hex[rand() % 15 + 1];
			for (int i = index1 + 2; i < index2; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index2 - size2] = hex[rand() % 16];
		}

		if (size3 >1) {
			ip[index3 - size3] = hex[rand() % 15 + 1];
			for (int i = index2 + 2; i < index3; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index3 - size3] = hex[rand() % 16];
		}

		if (size4 >1) {
			ip[index4 - size4] = hex[rand() % 15 + 1];
			for (int i = index3 + 2; i < index4; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index4 - size4] = hex[rand() % 16];
		}

		if (size5 >1) {
			ip[index5 - size5] = hex[rand() % 15 + 1];
			for (int i = index4 + 2; i < index5; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index5 - size5] = hex[rand() % 16];
		}

		if (size6 >1) {
			ip[index6 - size6] = hex[rand() % 15 + 1];
			for (int i = index5 + 2; i < index6; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index6 - size6] = hex[rand() % 16];
		}

		if (size7 >1) {
			ip[index7 - size7] = hex[rand() % 15 + 1];
			for (int i = index6 + 2; i < index7; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[index7 - size7] = hex[rand() % 16];
		}

		if (size8 >1) {
			ip[size - size8] = hex[rand() % 15 + 1];
			for (int i = index7 + 2; i < size; ++i) {
				ip[i] = hex[rand() % 16];
			}
		}
		else {
			ip[size - size8] = hex[rand() % 16];
		}
		cout << "ip ¹" << k << ": ";
		print(ip, size);
		cout << "\n";
	}
}
int main() {
	srand(time(NULL));
	int n; 
	cout << "Enter the number of generated ip addresses: ";
	cin >> n;
	ipv6_gen(n);
	system("pause");
	return 0;
}