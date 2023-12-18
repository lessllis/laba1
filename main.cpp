#include "garage.h"

int main() {
    Garage garage;

    while (true) {
        system("cls");
        std::cout << "\nGarage Menu:\n";
        std::cout << "1. Add Vehicle\n";
        std::cout << "2. Display All Vehicles\n";
        std::cout << "3. Edit Vehicle\n";
        std::cout << "4. Remove Vehicle\n";
        std::cout << "5. Write to file\n";
        std::cout << "6. Read from file\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::string path = "out.txt";

        switch (choice) {
        case 1:
            system("cls");
            garage.addItem();
            system("pause");
            break;
        case 2:
            system("cls");
            garage.displayAllVehicles();
            system("pause");
            break;
        case 3:
            system("cls");
            garage.editItem();
            system("pause");
            break;
        case 4:
            system("cls");
            garage.removeItem();
            system("pause");
            break;
        case 5:
            system("cls");
            garage.writeToFile(path);
            system("pause");
            break;
        case 6:
            system("cls");
            garage.readFromFile(path);
            system("pause");
            break;
        case 7:
            system("cls");
            std::cout << "Exiting the program.\n";
            system("pause");
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    }

    return 0;
}