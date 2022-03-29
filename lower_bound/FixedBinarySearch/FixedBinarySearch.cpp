#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> input(vector<int> arr, int length) {
	int value;

	for (int i = 0; i < length; ++i) {
		cin >> value;

		arr.push_back(value);
	}

	return arr;
}

void output(vector<int> arr) {
	int length = arr.size();

	for (int i = 0; i < length; ++i) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int fixedBinarySearch(vector<int> forSearch, int num) {
	int left = 0;
	int right = forSearch.size() - 1;
	int mid;

	bool index = true;
	int upperIndex;

	while (index) {
		mid = (left + right) / 2;

		if (right - left == 1) {
			if (num < forSearch[left]) {
				upperIndex = left;
				index = false;
			}
			else if(num > forSearch[left]) {
				upperIndex = right;
				index = false;
			}
		}
		else if (num > forSearch[mid]) {
			left = mid;
		}
		else {
			right = mid;
		}
		
	}
	
	return upperIndex + 1;
}

int binarySearch(vector<int> nums, int key) {
	int left = 0;
	int right = nums.size() - 1;
	int index = -1;

	int mid;
	bool t = true;

	while (t && left <= right) {
		mid = (left + right) / 2;

		if (key == nums[mid]) {
			t = false;
			index = mid;
		}
		else if (key < nums[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	if (index == -1) {
		return index;
	}
	else {
		int newIndex;

		int k = index - 1;
		bool get = true;
		
		if (k < 0) {
			return k + 2;
		}
		else {
			while (get) {
				if (k < 0) {
					get = false;
					newIndex = k + 1;
				}
				else if(nums[k] != key) {
					get = false;
					newIndex = k + 1;
				} 
				else {
					--k;
				}
			}
		}

		return newIndex + 1;
	}
}

int main() {
	int lenOfNum;
	int lenOfCheck;

	vector<int> numbers;
	vector<int> check;

	cin >> lenOfNum;
	numbers = input(numbers, lenOfNum);

	cin >> lenOfCheck;
	check = input(check, lenOfCheck);

	for (int i = 0; i < lenOfCheck; ++i) {
		int t = binarySearch(numbers, check[i]);

		if (t != -1) {
			cout << "Yes " << t << '\n';
		}
		else {
			cout << "No " << fixedBinarySearch(numbers, check[i]) << '\n';
		}
	}

	system("pause");
	return 0;
}