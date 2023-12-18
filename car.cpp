#include "car.h"

Car::Car(const std::string& brand, const std::string& model, const std::string& color, const std::string& transmission_type, float engine_capacity)
    : Vehicle(brand, model), color(color), transmission_type(transmission_type), engine_capacity(engine_capacity) {
    std::cout << "Car Constructor (with parameters) called for " << brand << " " << model << std::endl;
}

Car::Car()
    : Car("Unknown", "Unknown", "Unknown", "Unknown", 0.0) {
    std::cout << "Car Default Constructor called" << std::endl;
}

Car::Car(const Car& other)
    : Vehicle(other), color(other.color), transmission_type(other.transmission_type) {
    std::cout << "Car Copy Constructor called for " << brand << " " << model << std::endl;
}

Car::~Car()
{
    std::cout << "Car Destructor called for " << brand << " " << model << std::endl;
}

void Car::displayInfo() const
{
    std::cout << "Car" << std::endl;
    std::cout << "Brand: " << brand;
    std::cout << "| Model: " << model;
    std::cout << "| Color: " << color;
    std::cout << "| Transmission: " << transmission_type;
    std::cout << "| Engine capacity: " << engine_capacity;
    std::cout << std::endl;
}

std::string Car::getInfo()
{
    return "Car " + brand + " " + model + " " + color + " " + transmission_type + " " + std::to_string(engine_capacity);
}
