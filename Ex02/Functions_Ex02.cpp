#include "MyFunctions_Ex02.h"

void saveDateArr() {
	cout << "Enter the number of dates you want to save: ";
	int n;
	cin >> n;
	Date* dateArr = new Date[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the day of date " << i + 1 << ": ";
		cin >> dateArr[i].day;
		cout << "Enter the month of date " << i + 1 << ": ";
		cin >> dateArr[i].month;
		cout << "Enter the year of date " << i + 1 << ": ";
		cin >> dateArr[i].year;
	}
	cout << "Enter the destination file name: ";
	string fileName;
	cin >> fileName;
	ofstream fout(fileName, ios::binary);
	if (fout.fail()) {
		cout << "Error opening file!" << endl;
		delete[] dateArr;
		return;
	}
	fout.write(reinterpret_cast<char*>(&n), sizeof(n));
	fout.write(reinterpret_cast<char*>(dateArr), n * sizeof(Date));
	fout.close();
	cout << "Saved successfully to " << fileName << "!";
	delete[] dateArr;
}

int changeDateToInt(Date date) {
	return date.year * 10000 + date.month * 100 + date.day;
}

void findNewestDate(Date* dateArr, const int& n) {
	int newestDate = changeDateToInt(dateArr[0]);
	for (int i = 1; i < n; i++) {
		int temp = changeDateToInt(dateArr[i]);
		if (temp > newestDate) {
			newestDate = temp;
		}
	}
	cout << "The newest date is: " << newestDate % 100 << "/" << (newestDate % 10000) / 100 << "/" << newestDate / 10000 << endl;
}

void loadDateArr() {
	cout << "Enter the source file name: ";
	string fileName;
	cin >> fileName;
	ifstream fin(fileName, ios::binary);
	if (fin.fail()) {
		cout << "Error opening file!" << endl;
		return;
	}
	int n;
	fin.read(reinterpret_cast<char*>(&n), sizeof(n));
	Date* dateArr = new Date[n];
	fin.read(reinterpret_cast<char*>(dateArr), n * sizeof(Date));
	fin.close();
	findNewestDate(dateArr, n);
	delete[] dateArr;
}