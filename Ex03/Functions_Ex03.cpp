#include "MyFunctions_Ex03.h"

string findFileName(const string path) {
    int len = path.length();
    int found = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (path[i] == '/' || path[i] == '\\') {
			found = i;
			break;
		}
    }
	return path.substr(found + 1);
}

void copyFile(const string& source, const string& destination) {
    ifstream sourceFile(source, ios::binary);
    if (!sourceFile) {
        cout << "Error opening source file." << endl;
        return;
    }

    string destFilePath = destination + "/" + findFileName(source);
    ofstream destinationFile(destFilePath, ios::binary);
    if (!destinationFile) {
        cout << "Error opening destination file." << endl;
        return;
    }

    char buffer[4096];
    while (sourceFile.read(buffer, sizeof(buffer))) {
        destinationFile.write(buffer, sizeof(buffer));
    }

    sourceFile.close();
    destinationFile.close();
    cout << "Copied file " << source << " to " << destFilePath;
}