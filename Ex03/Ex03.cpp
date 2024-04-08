#include "MyFunctions_Ex03.h"

int main(int argc, char* argv[]) {
	if (argc != 5) {
		cout << "MYCOPYFILE -s path_of_source_file -d path_of_destination" << endl;
		return 1;
	}

	copyFile(argv[2], argv[4]);

	return 0;
}