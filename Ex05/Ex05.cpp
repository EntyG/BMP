#include "MyFunctions_Ex05.h"

int main(int argc, char* argv[]) {
	if (argc != 5) {
		cout << "MYMERGEFILE -s path_of_part01 -d path_of_destination" << endl;
		return 1;
	}

	int n = 0;
	string* source;
	findSource(argv[2], source, n);
	mergeFile(n, source, argv[4]);

	return 0;
}