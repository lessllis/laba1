#pragma once
#pragma once

#include "bus.h"
#include "car.h"
#include "motorcycle.h"

#include <fstream>
#include <sstream>

class Garage {
public:
    Garage() : vehicles(nullptr), vehicleCount(0), capacity(0) {}

    ~Garage() {
        clearGarage();
    }

    void addVehicle(Vehicle* vehicle);

    void displayAllVehicles() const;

    void writeToFile(std::string& path);

    void readFromFile(std::string& path);

    // Добавляет транспортное средство в гараж
    void addItem();

    // Редактирует транспортное средство в гараже
    void editItem();

    // Удаляет транспортное средство из гаража
    void removeItem();

private:
    Vehicle** vehicles;
    int vehicleCount;
    int capacity;

    // Увеличивает размер массива транспортных средств
    void expandCapacity();

    // Очищает память, выделенную под транспортные средства
    void clearGarage();

    // Получает информацию о машине от пользователя
    Car* getCarFromUser() const;

    // Получает информацию о мотоцикле от пользователя
    Motorcycle* getMotorcycleFromUser() const;

    // Получает информацию об автобусе от пользователя
    Bus* getBusFromUser() const;

    // Получает информацию о транспортном средстве от пользователя
    Vehicle* getVehicleFromUser() const;
};
