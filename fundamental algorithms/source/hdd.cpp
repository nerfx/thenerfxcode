#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include<ctime>
#include<list>
#include<iterator>
using namespace std;

class disk {
private:
	int size_of_disk = 360; 
	int *arr = new int[size_of_disk]; 
	int *arr1; 
	//int *arr2;
	string arr3[20]; 
	int size_of_arr3; 
	int ind1, ind2;
	int new_ind1, new_ind2; 
	int counter; 
	bool index; 

public:
	disk() {
		for (int i = 0; i < size_of_disk; ++i) {
			arr[i] = -1;
		}
		arr1 = new int[20];
		//arr2 = new int[20];
		ind1 = 0;
		ind2 = 0;
		index = true;
		counter = 0;
	}

	void input_file(int first, int last) {
		for (int i = first; i <= last; ++i) {
			arr[i] = rand() % 2;
		}
	}

	void add_file(int size_of_file, string name_of_file) {
		if (index) {
			ind2 = size_of_file + ind1 - 1; 
			input_file(ind1, ind2);
			arr1[counter] = ind1; 
			//arr2[counter] = ind2 - ind1;
			ind1 = ind2 + 1;
			size_of_arr3 += 1;
			arr3[counter] = name_of_file;
			counter += 1;
		}
		else {
			if (size_of_file <= arr1[new_ind2] - arr1[new_ind1]) {
				int var_ind1 = arr1[new_ind1];
				int var_ind2 = size_of_file + arr1[new_ind1] - 1;
				arr3[new_ind1] = name_of_file;
				input_file(var_ind1, var_ind2);
				index = true;
				size_of_arr3 += 1;
			}
			else {
				index = true;
				add_file(size_of_file, name_of_file);
			}
			
		}

	}

	void delete_of_file(string name_of_del) {
		for (int i = 0; i < size_of_arr3; ++i) {
			if (name_of_del == arr3[i]) {
				new_ind1 = i;
				new_ind2 = i + 1;
			}
		}
		for (int k = arr1[new_ind1]; k < arr1[new_ind2]; ++k) {
			arr[k] = -1;
		}
		index = false;
	}

	void memory_status() {
		for (int i = 0; i < size_of_disk; ++i) {
			cout << arr[i] << "\t";
		}
		cout << endl;
	}

	void list_memory_status() {
		list <int> list1;
		list <int> list2;
		for (int i = 0; i < size_of_disk; ++i) {
			if (arr[i] == 0 || arr[i] == 1) {
				list1.push_back(arr[i]);
			}
		}
		for (int i = 0; i < size_of_disk; ++i) {
			if (arr[i] == -1) {
				list2.push_back(arr[i]);
			}
		}
		copy(list1.begin(), list1.end(), ostream_iterator <int> (cout, " "));
		cout << endl;
		copy(list2.begin(), list2.end(), ostream_iterator <int>(cout, " "));
		cout << endl;
	}

	void counter_of_mameory() {
		int counter1 = 0, counter2 = 0;
		for (int i = 0; i < size_of_disk; ++i) {
			if (arr[i] == 0 || arr[i] == 1) {
				counter1 += 1;
			}
			else {
				counter2 += 1;
			}
		}
		cout << "-1: " << counter2 << endl;
		cout << "0 or 1: " << counter1 << endl;
	}
};

int main() {
	srand(time(NULL));
	disk s;
	bool ind = true;
	int index = 0;
	while (ind) {
		string mess;
		cin >> mess;
		if (mess == "Add") {
			string name, mess1;
			cout << "Input the name of file: " << endl;
			cin >> name;
			int size_of_file;
			cout << "Input size of file (from 18 to 32): " << endl;
			cin >> size_of_file;
			s.add_file(size_of_file, name);
			cout << "Show the memory status?" << endl;
			cin >> mess1;
			if (mess1 == "Yes") {
				s.memory_status();
				s.counter_of_mameory();
				s.list_memory_status();
			}
		}
		else if (mess == "Del") {
			string name_of_delete, mess2;
			cout << "Input name of file: " << endl;
			cin >> name_of_delete;
			s.delete_of_file(name_of_delete);
			cout << "Show the memory status?" << endl;
			cin >> mess2;
			if (mess2 == "Yes") {
				s.memory_status();
				s.counter_of_mameory();
				s.list_memory_status();
			}
		}
		else if (mess == "Stop") {
			ind = false;
		}
	}

	system("pause");
	return 0;
}