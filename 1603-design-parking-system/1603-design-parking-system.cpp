class ParkingSystem {
public:
    
    int bigCarSlot;
    int mediumCarslot;
    int smallCarslot;
    ParkingSystem(int big, int medium, int small) {

        bigCarSlot = big;
        mediumCarslot = medium;
        smallCarslot = small;
    }
    
    bool addCar(int carType) {

        if(carType == 1 && bigCarSlot>0)
        {
            bigCarSlot--;
            return true;
        }

        if(carType == 2 && mediumCarslot > 0)
        {
            mediumCarslot--;
            return true;
        }

        if(carType == 3 && smallCarslot >0)
        {
            smallCarslot--;
            return true;
        } 
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */