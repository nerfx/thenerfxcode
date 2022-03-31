#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

template<typename T>
vector<T> input(vector<T> arr, T len) {
	int val;

	for (int i = 0; i < len; ++i) {
		cin >> val;

		arr.push_back(val);
	}

	return arr;
}

vector<int>::iterator upperBound(vector<int>::iterator first, vector<int>::iterator last, int val) {
	vector<int>::iterator it;

	iterator_traits<vector<int>::iterator>::difference_type step, count;
	count = distance(first, last);

	while (count > 0) {
		it = first;
		step = count / 2;

		advance(it, step);

		if (val >= *it) {
			first = ++it;
			count -= (step + 1);
		}
		else {
			count = step;
		}
	}

	return first;
}

vector<int>::iterator lowerBound(vector<int>::iterator left, vector<int>::iterator right, int key) {
	vector<int>::iterator iter;

	iterator_traits<vector<int>::iterator>::difference_type count, step;
	count = distance(left, right);

	while (count > 0) {
		iter = left;
		step = count / 2;

		advance(iter, step);

		if (key > *iter) {
			left = ++iter;
			count -= (step + 1);
		}
		else {
			count = step;
		}
	}

	return left;
}

vector<int>::iterator equal(vector<int>::iterator begin, vector<int>::iterator end, int elem) {
	vector<int>::iterator mid;

	bool count = true;

	while (begin <= end && count) {
		mid = begin + (end - begin) / 2;

		if (elem == *mid) {
			count = false;
		}
		else if (elem < *mid) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}

	return mid;
}


int main() {
	int size; 

	int key1;
	int key2;
	int key3;

	vector<int> nums;

	cout << "Input size of the array: ";
	cin >> size;

	cout << "Input the array: ";

	nums = input(nums, size);

	cout << "Input the key for upper_bound: ";
	cin >> key1;
	cout << "Input the key for lower_bound: ";
	cin >> key2;
	cout << "Input the key to search of: ";
	cin >> key3;

	vector<int>::iterator iterUp = upperBound(nums.begin(), nums.end(), key1);
	vector<int>::iterator iterLow = lowerBound(nums.begin(), nums.end(), key2);
	vector<int>::iterator iterEq = equal(nums.begin(), nums.end(), key3);
	
	cout << "upper_bound: ";
	cout << iterUp - nums.begin() + 1 << '\n';

	cout << "lower_bound: ";
	cout << iterLow - nums.begin() << '\n';

	cout << "index of the found key: ";
	cout << iterEq - nums.begin() + 1 << '\n';

	system("pause");
	return 0;
}