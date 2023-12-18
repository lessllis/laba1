#pragma once
#pragma once

#include "vehicle.h"

class Bus : public Vehicle {
public:
    Bus(const std::string& brand, const std::string& model, int seating_capacity, int total_capacity, const std::string& final_destination);

    Bus();

    Bus(const Bus& other);

    ~Bus();

    void displayInfo() const override;

    std::string getInfo();

    int getSeatingCapacity() const { return seating_capacity; }
    int getTotalCapacity() const { return total_capacity; }
    const std::string& getFinalDestination() const { return final_destination; }

    void setSeatingCapacity(int newSeatingCapacity) { seating_capacity = newSeatingCapacity; }
    void setTotalCapacity(int newTotalCapacity) { total_capacity = newTotalCapacity; }
    void setFinalDestination(const std::string& newFinalDestination) { final_destination = newFinalDestination; }


private:
    int seating_capacity;
    int total_capacity;
    std::string final_destination;
};