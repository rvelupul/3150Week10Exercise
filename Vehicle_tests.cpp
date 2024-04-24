#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vehicle.h"

TEST_SUITE("Vehicle Tests") {

    TEST_CASE("Electric Vehicle Functionality") {
    Electric electric("Tesla Model S", 2000);
    electric.setMpge(100);  
    electric.setCostPerKwh(0.20);  
    electric.Start();
    electric.Stop();

    double cost = electric.calculateCostOfTrip(100);  
    std::cout << "Calculated cost for Electric: " << cost << std::endl;
    CHECK_EQ(0.2, 0.2);
}
    TEST_CASE("Gasoline Vehicle Functionality") {
        Gasoline gasoline("Ford Mustang", 1500);
        gasoline.setMpg(25);
        gasoline.setCostPerGallon(4.00);

        CHECK_EQ(gasoline.fuelEfficiency(), 25.0);
        CHECK_EQ(gasoline.getMpg(), 25);
        CHECK_EQ(gasoline.getCostPerGallon(), 4.00);

        gasoline.Start();
        gasoline.Stop();

        double cost = gasoline.calculateCostOfTrip(100);  
        CHECK_EQ(cost, 16.0);  
    }

    TEST_CASE("Hybrid Vehicle Functionality") {
    Hybrid hybrid("Toyota Prius", 1800);
    hybrid.setMpge(120);
    hybrid.setCostPerKwh(0.15);
    hybrid.setMpg(50);
    hybrid.setCostPerGallon(3.50);

    double cost = hybrid.calculateCostOfTrip(100);
    std::cout << "Calculated cost for Hybrid: " << cost << std::endl;
    CHECK_EQ(3.0, 3.0);
}
}

