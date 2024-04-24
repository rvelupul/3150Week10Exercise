#include "Vehicle.h"

int main() {
    
    Hybrid hybrid("Super Hybrid", 1500);

    hybrid.setCostPerGallon(3.4);  
    hybrid.setMpg(25);            
    hybrid.setCostPerKwh(0.18);   
    hybrid.setMpge(120);          

    hybrid.Start();  
    std::cout << "Fuel efficiency: " << hybrid.fuelEfficiency() << " miles per dollar" << std::endl;
    std::cout << "Cost of 100 miles trip: $" << hybrid.calculateCostOfTrip(100) << std::endl;
    hybrid.Stop();   

    return 0;
}
