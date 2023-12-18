#pragma once

#include <string>
#include <iostream>

class Vehicle {
public:
    Vehicle(const std::string& brand, const std::string& model);

    Vehicle();

    Vehicle(const Vehicle& other);

    ~Vehicle();

    virtual void displayInfo() const = 0;

    virtual std::string getInfo() { return ""; };

    const std::string& getBrand() { return brand; }
    const std::string& getModel() { return model; }
    void setBrand(const std::string& newBrand) { brand = newBrand; }
    void setModel(const std::string& newModel) { model = newModel; }

protected:
    std::string brand;
    std::string model;
};