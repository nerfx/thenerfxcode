#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

vector<int> input(vector<int> A, int length) {
	int value;

	for (int i = 0; i < length; ++i) {
		cin >> value;
	
		A.push_back(value);
	}

	return A;
}

void output(vector<int> B) {
	int len = B.size();

	for (int i = 0; i < len; ++i) {
		cout << B.at(i) << " ";
	}

	cout << '\n';
}

template<class SearchContain, class T >
int binarySearch(SearchContain container, int left, int right, T key) {
	int mid = (left + right) / 2;

	if (key == container[mid]) {

		return mid;
	}
	else if (key < container[mid] && left <= right) {

		return binarySearch(container, left, mid - 1, key);
	}
	else if (key > container[mid] && left <= right) {

		return binarySearch(container, mid + 1, right, key);
	}
	else {

		return -1;
	}
}

int fixed(vector<int> nums, int key) {
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
				else if (nums[k] != key) {
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

vector<int>::iterator lowerBound(vector<int>::iterator first, vector<int>::iterator last, int key) {
	vector<int>::iterator it;

	iterator_traits<vector<int>::iterator>::difference_type count, step;
	count = distance(first, last);

	while (count > 0) {
		it = first;
		step = count / 2;

		advance(it, step);

		if (!(key < *it)) {
			first = ++it;

			count -= step + 1;
		}
		else {
			count = step;
		}
	}

	return first;
}

int main() {
	vector<int> nums;
	vector<int> que;

	int lenOfNums;
	int lenOfQue;
	
	cin >> lenOfNums;
	nums = input(nums, lenOfNums);

	cin >> lenOfQue;
	que = input(que, lenOfQue);
	
	int add;
	vector<int>::iterator iter;
	for (int i = 0; i < lenOfQue; ++i) {
		add = fixed(nums, que.at(i));

		if (add != -1) {
			cout << "Yes " << add << '\n';
		}
		else {
			iter = lowerBound(nums.begin(), nums.end(), que.at(i));

			cout << "No " << iter - nums.begin() + 1 << '\n';
		}
	}

	system("pause");
	return 0;
}
