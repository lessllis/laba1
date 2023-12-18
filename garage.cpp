#include "garage.h"

void Garage::addVehicle(Vehicle* vehicle)
{
    if (vehicleCount >= capacity) {
        // Увеличиваем размер массива
        expandCapacity();
    }
    vehicles[vehicleCount++] = vehicle;
}

void Garage::displayAllVehicles() const
{
    std::cout << std::endl;
    for (int i = 0; i < vehicleCount; ++i) {
        std::cout << "[" << i + 1 << "]" << std::endl;
        std::cout << "------------------\n";
        vehicles[i]->displayInfo();
        std::cout << "------------------";
        std::cout << std::endl;
    }
}

void Garage::writeToFile(std::string& path)
{
    std::ofstream out(path);
    if (!out.is_open()) {
        std::cout << "Invalid path to file";
        return;
    }
    for (int i = 0; i < vehicleCount; ++i) {
        out << vehicles[i]->getInfo();
        out << std::endl;
    }
    out.close();
}

void Garage::readFromFile(std::string& path)
{
    std::ifstream in(path);
    if (!in.is_open()) {
        std::cout << "Invalid path to file";
        return;
    }
    std::string str;
    std::string type;
    std::stringstream ss;
    while (in >> str) {
        if (str == "Motorcycle") {
            std::string brand;
            std::string model;
            float engine_capacity;
            double engine_power;
            std::string terrain;
            in >> brand >> model >> engine_capacity >> engine_power >> terrain;
            Vehicle* mot = new Motorcycle(brand, model, engine_capacity, engine_power, terrain);
            addVehicle(mot);
        }
        if (str == "Car") {
            std::string brand;
            std::string model;
            std::string color;
            std::string transmission;
            float engine_capacity;
            in >> brand >> model >> color >> transmission >> engine_capacity;
            Vehicle* car = new Car(brand, model, color, transmission, engine_capacity);
            addVehicle(car);
        }
        if (str == "Bus") {
            std::string brand;
            std::string model;
            int seating_capacity;
            int total_capacity;
            std::string final_destination;
            in >> brand >> model >> seating_capacity >> total_capacity >> final_destination;
            Vehicle* bus = new Bus(brand, model, seating_capacity, total_capacity, final_destination);
            addVehicle(bus);
        }
    }
}

void Garage::addItem()
{
    std::cout << "Select the type of vehicle to add:\n";
    std::cout << "1. Car\n";
    std::cout << "2. Motorcycle\n";
    std::cout << "3. Bus\n";
    int choice;
    std::cout << "Input index: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        addVehicle(getCarFromUser());
        break;
    case 2:
        addVehicle(getMotorcycleFromUser());
        break;
    case 3:
        addVehicle(getBusFromUser());
        break;
    default:
        std::cout << "Invalid choice. No vehicle added.\n";
        break;
    }
}

void Garage::editItem()
{
    if (vehicleCount == 0) {
        std::cout << "No vehicles in the garage to edit.\n";
        return;
    }

    displayAllVehicles();
    int index;
    std::cout << "Input index: ";
    std::cin >> index;
    index--;


    if (index < 0 || index >= vehicleCount) {
        std::cout << "Invalid index. No vehicle edited.\n";
        return;
    }

    // Удаление старого транспортного средства
    delete vehicles[index];

    // Заменяем транспортное средство новым
    vehicles[index] = getVehicleFromUser();
}

void Garage::removeItem()
{
    if (vehicleCount == 0) {
        std::cout << "No vehicles in the garage to remove.\n";
        return;
    }

    displayAllVehicles();
    int index;
    std::cout << "Input index:";
    std::cin >> index;
    index--;

    if (index < 0 || index >= vehicleCount) {
        std::cout << "Invalid index. No vehicle removed.\n";
        return;
    }

    // Удаление транспортного средства
    delete vehicles[index];

    // Сдвигаем оставшиеся элементы в массиве
    for (int i = index; i < vehicleCount - 1; ++i) {
        vehicles[i] = vehicles[i + 1];
    }

    // Уменьшаем количество транспортных средств
    --vehicleCount;

    std::cout << "Vehicle removed from the garage.\n";
}

void Garage::expandCapacity()
{
    int newCapacity = capacity * 2 + 1;  // Удвоение размера плюс один, чтобы избежать бесконечного цикла
    Vehicle** newVehicles = new Vehicle * [newCapacity];

    // Копирование данных из старого массива в новый
    for (int i = 0; i < capacity; ++i) {
        newVehicles[i] = vehicles[i];
    }

    // Удаление старого массива
    delete[] vehicles;

    // Переключение на новый массив и установка новой емкости
    vehicles = newVehicles;
    capacity = newCapacity;
}

void Garage::clearGarage()
{
    for (int i = 0; i < vehicleCount; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

Car* Garage::getCarFromUser() const
{
    std::string brand, model, color, transmission_type;
    float engien_capacity;
    std::cout << "Enter car brand: ";
    std::cin >> brand;
    std::cout << "Enter car model: ";
    std::cin >> model;
    std::cout << "Enter car color: ";
    std::cin >> color;
    std::cout << "Enter transmission type: ";
    std::cin >> transmission_type;
    std::cout << "Engine capacity: ";
    std::cin >> engien_capacity;
    return new Car(brand, model, color, transmission_type, engien_capacity);
}

Motorcycle* Garage::getMotorcycleFromUser() const
{
    std::string brand, model, terrain;
    double enginePower;
    float engine_capacity;
    std::cout << "Enter motorcycle brand: ";
    std::cin >> brand;
    std::cout << "Enter motorcycle model: ";
    std::cin >> model;
    std::cout << "Enter engine power: ";
    std::cin >> enginePower;
    std::cout << "Enter terrain type: ";
    std::cin >> terrain;
    std::cout << "Enter engine capacity: ";
    std::cin >> engine_capacity;
    return new Motorcycle(brand, model, engine_capacity, enginePower, terrain);
}

Bus* Garage::getBusFromUser() const
{
    std::string brand, model, finalDestination;
    int seatingCapacity, totalCapacity;
    std::cout << "Enter bus brand: ";
    std::cin >> brand;
    std::cout << "Enter bus model: ";
    std::cin >> model;
    std::cout << "Enter seating capacity: ";
    std::cin >> seatingCapacity;
    std::cout << "Enter total capacity: ";
    std::cin >> totalCapacity;
    std::cout << "Enter final destination: ";
    std::cin >> finalDestination;
    return new Bus(brand, model, seatingCapacity, totalCapacity, finalDestination);
}

Vehicle* Garage::getVehicleFromUser() const
{
    std::cout << "Select the type of vehicle to add:\n";
    std::cout << "1. Car\n";
    std::cout << "2. Motorcycle\n";
    std::cout << "3. Bus\n";
    int choice;
    std::cout << "Input vehicle: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        return getCarFromUser();
    case 2:
        return getMotorcycleFromUser();
    case 3:
        return getBusFromUser();
    default:
        std::cout << "Invalid choice. No vehicle added.\n";
        return nullptr;
    }
}



