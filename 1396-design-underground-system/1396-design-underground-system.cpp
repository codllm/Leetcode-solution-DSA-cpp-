class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkIninfo;

    unordered_map<string,pair<int,int>>checkOutinfo;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {

        checkIninfo[id] = { stationName, t };
        
    }
    
    void checkOut(int id, string stationName, int t) {

        auto [ stStation,stTime] = checkIninfo[id];
        string journey = stStation + "-->" + stationName;
        int travelTime = t - stTime;
        if(checkOutinfo.find(journey)==checkOutinfo.end())
        {
            
            checkOutinfo[journey] = {1,travelTime};
        }
        else
        {
            int time = checkOutinfo[journey].second + travelTime;
            int customer = checkOutinfo[journey].first + 1;

            checkOutinfo[journey] = {customer,time};
        }
        //key gonna startStation to destination

    }
    
    double getAverageTime(string startStation, string endStation) {

        string journey = startStation + "-->" + endStation;

        int time = checkOutinfo[journey].second;
        int customer = checkOutinfo[journey].first;

        return double(time)/customer;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */