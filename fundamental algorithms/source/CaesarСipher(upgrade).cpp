#include<iostream>
using namespace std;

void encrypt(char *arr, int key) {
	char sym;

	for (int i = 0; arr[i] != '\0'; ++i) {
		sym = arr[i];
		if (sym >= 'a' && sym <= 'm'){ 					   
				sym = sym + key;
				if (sym > 'z') {
					sym = sym - 'z' + 'a' - 1;
				}
				arr[i] = sym;
		}
		else if (sym > 'm' && sym <= 'z') {
			sym = sym - key;
			if (sym < 'a') {
				sym = sym + 'z' - 'a' + 1;
			}
			arr[i] = sym;
		}
		if (sym >= 'A' && sym <= 'M') {
			sym = sym + key;
			if (sym > 'Z') {
				sym = sym - 'Z' + 'A' - 1;
			}
			arr[i] = sym;
		}
		else if (sym > 'M' && sym <= 'Z') {
			sym = sym - key;
			if (sym < 'A') {
				sym = sym + 'Z' - 'A' + 1;
			}
			arr[i] = sym;
		}
	}
}

int main() {
	const int n = 256;
	char arr[n];
	int key;
	printf("Enter a message: ");
	gets_s(arr);
	printf("Enter the key: ");
	scanf_s("%d", &key);
	encrypt(arr, key);
	printf("Encrypted message: %s", arr);
	printf("\n");
	system("pause");
	return 0;
}