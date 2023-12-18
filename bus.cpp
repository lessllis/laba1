#include "bus.h"

Bus::Bus(const std::string& brand, const std::string& model, int seating_capacity, int total_capacity, const std::string& final_destination) : Vehicle(brand, model), seating_capacity(seating_capacity),
total_capacity(total_capacity), final_destination(final_destination) {
    std::cout << "Bus Constructor (with parameters) called for " << brand << " " << model << std::endl;
}

Bus::Bus() : Bus("Unknown", "Unknown", 0, 0, "Unknown") {
    std::cout << "Bus Default Constructor called" << std::endl;
}

Bus::Bus(const Bus& other)
    : Vehicle(other), seating_capacity(other.seating_capacity),
    total_capacity(other.total_capacity), final_destination(other.final_destination) {
    std::cout << "Bus Copy Constructor called for " << brand << " " << model << std::endl;
}

Bus::~Bus()
{
    std::cout << "Bus Destructor called for " << brand << " " << model << std::endl;
}

void Bus::displayInfo() const
{
    std::cout << "Bus" << std::endl;
    std::cout << "Brand: " << brand;
    std::cout << "| Model: " << model;
    std::cout << "| Seating capacity: " << seating_capacity;
    std::cout << "| Total capacity: " << total_capacity;
    std::cout << "| Destination: " << final_destination << std::endl;
}

std::string Bus::getInfo()
{
    return "Bus " + brand + " " + model + " " + std::to_string(seating_capacity) + " " + std::to_string(total_capacity) + " " + final_destination;
}
