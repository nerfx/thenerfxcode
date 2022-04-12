#include<iostream>
using namespace std;

int binary_size(int num) { 
	int add = 0;
	int q = 0;
	while (num / 2 > 0) {
		num = num / 2;
		q += 1;
	}
	return q + 1;
}

int decimal_size(int num) {
	int add = 0; 
	int q = 0; 
	while (num / 10 > 0) {
		num = num / 10;
		q += 1;
	}
	return q + 1;
}


int decimal(int bin_num, int n) {
	
	int *arr = new int[n];
	int div = pow(10, n-1);
	int col;
	for (int i = 0; i < n; ++i) {
		col = (bin_num / div) % 10;
		arr[i] =col;
		div = div / 10;
	}
	unsigned long long int s = 0;
	for (int i = 0; i < n; ++i) {
		s += arr[i] * pow(2, n - i - 1);
	}
	return s;
}


int * binary(int dec_num, int n) {
	int *arr = new int[n];
	int rem = 0;
	for(int i =0; i<n-1 && dec_num/2 >0; ++i) {
		rem = dec_num % 2;
		arr[n-i-1] = rem;
		dec_num = dec_num / 2;
	}
	arr[0] = dec_num;
	return arr;
} 

int main() {
	cout << "Enter a number in decimal notation: ";
	int dec_num;
	cin >> dec_num;
	int dig = binary_size(dec_num);
	cout << "Decimal -> Binary: ";
	int *num = binary(dec_num, dig);
	for (int i = 0; i < dig; ++i) {
		cout << num[i];
	}
	cout << endl;
	unsigned long long bin;
	cout << "Enter a number in binary notation: ";
	cin >> bin;
	int dig1 = decimal_size(bin);
	cout << "Binary -> Decimal: ";
	cout << decimal(bin, dig1)<< endl;
	system("pause");
	return 0;
}