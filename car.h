
#pragma once

#include "vehicle.h"

class Car : public Vehicle {
public:
    Car(const std::string& brand, const std::string& model,
        const std::string& color, const std::string& transmission_type, float engine_capacity);

    Car();

    Car(const Car& other);

    ~Car();

    void displayInfo() const override;

    std::string getInfo() override;

    const std::string& getColor() { return color; }
    const std::string& getTransmissionType() { return transmission_type; }
    float getEngineCapacity() { return engine_capacity; }

    void setColor(const std::string& newColor) { color = newColor; }
    void setTransmissionType(const std::string& newTransmissionType) { transmission_type = newTransmissionType; }
    void setEngineCapacity(const float NewEngineCapacity) { engine_capacity = NewEngineCapacity; }

private:
    std::string color;
    std::string transmission_type = "";
    float engine_capacity = 0.0;
};