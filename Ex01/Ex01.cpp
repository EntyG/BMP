#include "MyFunctions_Ex01.h"

int main() {
    while (true) {
        cout << "Menu:\n";
        cout << "1. Save array to binary file\n";
        cout << "2. Load array from binary file and find median\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            saveArr();
            break;
        case 2: {
            loadArr();
            break;
        }
        case 3:
            cout << "Exiting program.";
            return 0;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
        system("pause");
        system("cls");
    }

    return 0;
}