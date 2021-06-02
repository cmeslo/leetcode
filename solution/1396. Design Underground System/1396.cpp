class UndergroundSystem {
private:
    unordered_map<string, pair<int, int>> time_; // startStation-endStation -> {totalDuration, tripsCnt}
    unordered_map<int, pair<string, int>> in_; // id -> {startStation, timeIn}

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string startStation, int timeIn) {
        in_[id] = {startStation, timeIn};
    }
    
    void checkOut(int id, string endStation, int timeOut) {
        const auto& [startStation, timeIn] = in_[id];
        auto& [totalDuration, tripsCnt] = time_[startStation + '-' + endStation];
        totalDuration += timeOut - timeIn;
        ++tripsCnt;
    }
    
    double getAverageTime(string startStation, string endStation) {
        const auto& [totalDuration, tripsCnt] = time_[startStation + '-' + endStation];
        return (double) totalDuration / tripsCnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
