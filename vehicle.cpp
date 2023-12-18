#include "vehicle.h"

Vehicle::Vehicle(const std::string& brand, const std::string& model)
    : brand(brand), model(model) {
    std::cout << "Vehicle Constructor (with parameters) called for " << brand << " " << model << std::endl;
}

Vehicle::Vehicle()
    : Vehicle("Unknown", "Unknown") {
    std::cout << "Vehicle Default Constructor called" << std::endl;
}

Vehicle::Vehicle(const Vehicle& other)
    : brand(other.brand), model(other.model) {
    std::cout << "Vehicle Copy Constructor called for " << brand << " " << model << std::endl;
}

Vehicle::~Vehicle()
{
    std::cout << "Vehicle Destructor called for " << brand << " " << model << std::endl;
}
