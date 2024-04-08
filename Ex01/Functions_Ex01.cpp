#include "MyFunctions_Ex01.h"

void saveArr() {
	cout << "Enter the number of elements: ";
	int n;
	cin >> n;
	int* arr = new int[n];
	cout << "Enter " << n << " elements: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Enter file name: ";
	string fileName;
	cin >> fileName;
	ofstream fout(fileName, ios::out | ios::binary);
	if (!fout) {
		cout << "Cannot open file!" << endl;
		delete[] arr;
		return;
	}
	fout.write(reinterpret_cast<char*>(&n), sizeof(n));
	fout.write(reinterpret_cast<char*>(arr), n * sizeof(int));
	fout.close();
	cout << "Saved successfully to " << fileName << "!" << endl;
	delete[] arr;
}

void median(int* arr, const int& n) {
	int* sortedArr = new int[n];
	for (int i = 0; i < n; i++) {
		sortedArr[i] = arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sortedArr[i] > sortedArr[j]) {
				int temp = sortedArr[i];
				sortedArr[i] = sortedArr[j];
				sortedArr[j] = temp;
			}
		}
	}
	if (n % 2 == 0) {
		cout << "Median: " << (sortedArr[n / 2 - 1] + sortedArr[n / 2]) / 2.0 << endl;
	}
	else {
		cout << "Median: " << sortedArr[n / 2] << endl;
	}
}

void loadArr() {
	cout << "Enter file name: ";
	string fileName;
	cin >> fileName;
	ifstream fin(fileName, ios::in | ios::binary);
	if (!fin) {
		cout << "Cannot open file!" << endl;
		return;
	}
	int n;
	fin.read(reinterpret_cast<char*>(&n), sizeof(n));
	int* arr = new int[n];
	fin.read(reinterpret_cast<char*>(arr), n * sizeof(int));
	fin.close();
	median(arr, n);
	delete[] arr;
}