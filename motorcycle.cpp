#include "motorcycle.h"

Motorcycle::Motorcycle(const std::string& brand, const std::string& model, float engine_capacity, double engine_power, const std::string& terrain)
    : Vehicle(brand, model), engine_capacity(engine_capacity), engine_power(engine_power), terrain(terrain) {
    std::cout << "Motorcycle Constructor (with parameters) called for " << brand << " " << model << std::endl;
}

Motorcycle::Motorcycle()
    : Motorcycle("Unknown", "Unknown", 0.0, 0.0, "Unknown") {
    std::cout << "Motorcycle Default Constructor called" << std::endl;
}

Motorcycle::Motorcycle(const Motorcycle& other)
    : Vehicle(other), engine_power(other.engine_power), terrain(other.terrain) {
    std::cout << "Motorcycle Copy Constructor called for " << brand << " " << model << std::endl;
}

Motorcycle::~Motorcycle()
{
    std::cout << "Motorcycle Destructor called for " << brand << " " << model << std::endl;
}

void Motorcycle::displayInfo() const
{
    std::cout << "Motorcycle" << std::endl;
    std::cout << "Brand: " << brand;
    std::cout << "| Model: " << model;
    std::cout << "| Engine capacity: " << engine_capacity;
    std::cout << "| Power: " << engine_power;
    std::cout << "| Terrain: " << terrain << std::endl;
}

std::string Motorcycle::getInfo()
{
    return "Motorcycle " + brand + " " + model + " " + std::to_string(engine_capacity) + " " + std::to_string(engine_power) + " " + terrain;
}