# 1396. Design Underground System

## 4 個 map 的寫法

```cpp
class UndergroundSystem {
private:
    unordered_map<string, int> allTime_;
    unordered_map<string, int> count_;
    unordered_map<int, string> inStation_;
    unordered_map<int, int> inTime_;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inStation_[id] = stationName;
        inTime_[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string key = inStation_[id] + '-' + stationName;
        allTime_[key] += (t - inTime_[id]);
        ++count_[key];
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + '-' + endStation;
        return (double) allTime_[key] / count_[key];
    }
};
```

## 2 個 map 的寫法，本質是一樣的 (1396.cpp)

```cpp
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
```
