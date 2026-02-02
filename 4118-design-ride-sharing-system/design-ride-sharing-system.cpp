class RideSharingSystem {
public:
    queue<int>rider;
    queue<int>driver;
    unordered_map<int,bool>mp;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        mp[riderId] = true;

    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int>ans;

        while(rider.size() >=1 && mp[rider.front()] == false) rider.pop();

        if(rider.empty() || driver.empty()) return {-1,-1};
        
        int r = rider.front();rider.pop();
        int d = driver.front();driver.pop();
        
        ans.push_back(d);
        ans.push_back(r);
        mp[r] = false;
        return ans;
    }
    
    void cancelRider(int riderId) {
        mp[riderId] = false;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */