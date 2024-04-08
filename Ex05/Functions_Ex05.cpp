#include "MyFunctions_Ex05.h"

string findFileName(const string path) {
	int len = path.length();
	int start = 0;
	int end = path.length() - 1;
	for (int i = len - 1; i >= 0; i--) {
		if (path[i] == '/' || path[i] == '\\') {
			start = i + 1;
			break;
		}
	}
	for (int i = len - 1; i >= 0; i--) {
		if (path[i] == '.') {
			end = i - 1;
			break;
		}
	}
	return path.substr(start, end - start + 1);
}

void findSource(const string& path, string*& source, int& n) {
	//find all files with the name of fileName.partX
	string location = path.substr(0, path.find_last_of("/\\") + 1);
	string fileName = findFileName(path);
	while (true) {
		string filePath;
		if (n + 1 < 10) {
			filePath = location + fileName + ".part" + "0" + to_string(n + 1);
		}
		else {
			filePath = location + fileName + ".part" + to_string(n + 1);
		}
		ifstream file(filePath);
		if (!file) {
			break;
		}
		file.close();
		n++;
	}
	source = new string[n];
	for (int i = 0; i < n; i++) {
		if (i + 1 < 10) {
			source[i] = location + fileName + ".part" + "0" + to_string(i + 1);
		}
		else {
			source[i] = location + fileName + ".part" + to_string(i + 1);
		}
	}
}

void mergeFile(const int& n, string*& source, const string& destination) {
	for (int i = 0; i < n; i++) {
		ifstream sourceFile(source[i], ios::binary);
		if (!sourceFile) {
			cout << "Error opening source file." << endl;
			return;
		}

		string destFilePath = destination + "/" + findFileName(source[i]);
		ofstream destinationFile(destFilePath, ios::binary | ios::app);
		if (!destinationFile) {
			cout << "Error opening destination file." << endl;
			return;
		}
		
		destinationFile << sourceFile.rdbuf();

		sourceFile.close();
		destinationFile.close();
	}

	cout << "Merged " << n << " files into " << destination << " successfully.";

	delete[] source;
}