// https://leetcode.com/problems/design-parking-system

// Class for managing a parking system
class ParkingSystem {
public:
    int capacity_big;    
    int capacity_medium; 
    int capacity_small; 

    // Constructor for initializing the parking system with capacities
    ParkingSystem(int big, int medium, int small) {
        this->capacity_big = big;
        this->capacity_medium = medium;
        this->capacity_small = small;
    }
    
    // Method for adding a car to the parking system
    bool addCar(int carType) {
        if ((carType == 1 && capacity_big == 0) || 
            (carType == 2 && capacity_medium == 0) || 
            (carType == 3 && capacity_small == 0)) {
            return false;
        }
        
        if (carType == 1) {
            capacity_big--;
        } else if (carType == 2) {
            capacity_medium--;
        } else {
            capacity_small--;
        }
        
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
