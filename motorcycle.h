#pragma once
#pragma once
#include "vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& brand, const std::string& model, float engine_capacity,
        double engine_power, const std::string& terrain);

    Motorcycle();

    Motorcycle(const Motorcycle& other);

    ~Motorcycle();

    void displayInfo() const override;

    std::string getInfo() override;

    float getEngineCapacity() const { return engine_capacity; }
    double getEnginePower() const { return engine_power; }
    const std::string& getTerrain() const { return terrain; }

    void setEnginePower(double newEnginePower) { engine_power = newEnginePower; }
    void setTerrain(const std::string& newTerrain) { terrain = newTerrain; }
    void SetEngineCapacity(const float NewEngineCapacity) { engine_capacity = NewEngineCapacity; }

private:
    float engine_capacity = 0.0;
    double engine_power;
    std::string terrain;
};