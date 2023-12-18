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

    // ��������� ������������ �������� � �����
    void addItem();

    // ����������� ������������ �������� � ������
    void editItem();

    // ������� ������������ �������� �� ������
    void removeItem();

private:
    Vehicle** vehicles;
    int vehicleCount;
    int capacity;

    // ����������� ������ ������� ������������ �������
    void expandCapacity();

    // ������� ������, ���������� ��� ������������ ��������
    void clearGarage();

    // �������� ���������� � ������ �� ������������
    Car* getCarFromUser() const;

    // �������� ���������� � ��������� �� ������������
    Motorcycle* getMotorcycleFromUser() const;

    // �������� ���������� �� �������� �� ������������
    Bus* getBusFromUser() const;

    // �������� ���������� � ������������ �������� �� ������������
    Vehicle* getVehicleFromUser() const;
};
