class RideSharingSystem {
public:
    queue<int> Driver;
    queue<int> User;

    // rider -> driver
    unordered_map<int,int> ridebooked;

    // riders waiting currently
    unordered_set<int> waitingRiders;

    // cancelled rider ids
    unordered_set<int> rideCancelId;


    RideSharingSystem() {
        
    }
    

    void addRider(int riderId) {

        User.push(riderId);
        waitingRiders.insert(riderId);
    }
    

    void addDriver(int driverId) {

        Driver.push(driverId);
    }
    

    vector<int> matchDriverWithRider() {


        // remove cancelled riders lazily
        while(!User.empty() && 
              rideCancelId.find(User.front()) != rideCancelId.end())
        {
            User.pop();
        }


        // no matching possible
        if(User.empty() || Driver.empty())
        {
            return {-1,-1};
        }


        int riderId = User.front();
        int driverId = Driver.front();


        // remove from queue
        User.pop();
        Driver.pop();


        // no longer waiting
        waitingRiders.erase(riderId);


        // store booking
        ridebooked[riderId] = driverId;


        return {driverId, riderId};
    }
    

    void cancelRider(int riderId) {


        // rider already got driver
        if(ridebooked.find(riderId) != ridebooked.end())
        {
            return;
        }


        // rider is not waiting
        if(waitingRiders.find(riderId) == waitingRiders.end())
        {
            return;
        }


        // lazy deletion from queue
        rideCancelId.insert(riderId);

        // remove active status
        waitingRiders.erase(riderId);
    }
};