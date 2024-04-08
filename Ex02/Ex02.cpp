#include "MyFunctions_Ex02.h"

int main() {
    while (true) {
        cout << "Menu:\n";
        cout << "1. Save array of dates to binary file\n";
        cout << "2. Load array of dates from binary file and find the newest date\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            saveDateArr();
            break;
        case 2: {
            loadDateArr();
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