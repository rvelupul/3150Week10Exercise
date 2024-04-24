#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
protected:
    double weight;
    std::string name;
    double milesInTrip;

public:
    Vehicle();
    Vehicle(std::string name, double weight);
    virtual ~Vehicle();

    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual double fuelEfficiency() const = 0;
    virtual double calculateCostOfTrip(double miles) = 0;
};

class Electric : public virtual Vehicle {
private:
    double mpge;
    double costPerKwh;

public:
    Electric(std::string name, double weight);
    virtual ~Electric();

    double fuelEfficiency() const override;
    void Start() override;
    void Stop() override;

    double calculateCostOfTrip(double miles) override;

    void setMpge(double m);
    double getMpge() const;
    void setCostPerKwh(double c);
    double getCostPerKwh() const;
};

class Gasoline : public virtual Vehicle {
private:
    double mpg;
    double costPerGallon;

public:
    Gasoline(std::string name, double weight);
    virtual ~Gasoline();

    double fuelEfficiency() const override;
    void Start() override;
    void Stop() override;

    double calculateCostOfTrip(double miles) override;

    void setMpg(double m);
    double getMpg() const;
    void setCostPerGallon(double c);
    double getCostPerGallon() const;
};

class Hybrid : public Electric, public Gasoline {
public:
    Hybrid(std::string name, double weight);
    virtual ~Hybrid();

    double fuelEfficiency() const override;
    void Start() override;
    void Stop() override;

    double calculateCostOfTrip(double miles) override;
};

#endif 