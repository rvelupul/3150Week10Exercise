#include "Vehicle.h"

Vehicle::Vehicle() : weight(0), milesInTrip(0.0), name("") {
    std::cout << "Constructor: Vehicle" << std::endl;
}

Vehicle::Vehicle(std::string name, double weight) : name(name), weight(weight), milesInTrip(0.0) {
    std::cout << "Constructor(string, double): Vehicle" << std::endl;
}

Vehicle::~Vehicle() {
    std::cout << "Destructor: Vehicle" << std::endl;
}

Electric::Electric(std::string name, double weight) : Vehicle(name, weight), mpge(0.0), costPerKwh(0.0) {
    std::cout << "Constructor: Electric" << std::endl;
}

Electric::~Electric() {
    std::cout << "Destructor: Electric" << std::endl;
}

double Electric::fuelEfficiency() const {
    return 100.0;
}

void Electric::Start() {
    std::cout << "Electric START" << std::endl;
}

void Electric::Stop() {
    std::cout << "Electric STOP" << std::endl;
}

double Electric::calculateCostOfTrip(double miles) {
    std::cout << "Cost of trip in Electric" << std::endl;
    return (miles / mpge * costPerKwh);
}

void Electric::setMpge(double m) { mpge = m; }
double Electric::getMpge() const { return mpge; }
void Electric::setCostPerKwh(double c) { costPerKwh = c; }
double Electric::getCostPerKwh() const { return costPerKwh; }

Gasoline::Gasoline(std::string name, double weight) : Vehicle(name, weight), mpg(0.0), costPerGallon(0.0) {
    std::cout << "Constructor: Gasoline" << std::endl;
}

Gasoline::~Gasoline() {
    std::cout << "Destructor: Gasoline" << std::endl;
}

double Gasoline::fuelEfficiency() const {
    return 25.0;
}

void Gasoline::Start() {
    std::cout << "Gasoline START" << std::endl;
}

void Gasoline::Stop() {
    std::cout << "Gasoline STOP" << std::endl;
}

double Gasoline::calculateCostOfTrip(double miles) {
    std::cout << "Cost of trip in Gasoline" << std::endl;
    return (miles / mpg * costPerGallon);
}

void Gasoline::setMpg(double m) { mpg = m; }
double Gasoline::getMpg() const { return mpg; }
void Gasoline::setCostPerGallon(double c) { costPerGallon = c; }
double Gasoline::getCostPerGallon() const { return costPerGallon; }

Hybrid::Hybrid(std::string name, double weight) : Vehicle(name, weight), Electric(name, weight), Gasoline(name, weight) {
    std::cout << "Constructor: Hybrid" << std::endl;
}

Hybrid::~Hybrid() {
    std::cout << "Destructor: Hybrid" << std::endl;
}

double Hybrid::fuelEfficiency() const {
    return (Electric::fuelEfficiency() + Gasoline::fuelEfficiency()) / 2.0;
}

void Hybrid::Start() {
    Electric::Start();  
    Gasoline::Start();
    std::cout << "Hybrid START" << std::endl;
}

void Hybrid::Stop() {
    Electric::Stop();  
    Gasoline::Stop();  
    std::cout << "Hybrid STOP" << std::endl;
}

double Hybrid::calculateCostOfTrip(double miles) {
    std::cout << "Cost of trip in Hybrid" << std::endl;
    return (Electric::calculateCostOfTrip(miles) + Gasoline::calculateCostOfTrip(miles)) / 2.0;
}
