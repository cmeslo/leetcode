class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        s.insert({start, 1});
        s.insert({end, -1});
        
        int res = 0, count = 0;
        for (auto& x : s) {
            count += x.second;
            res = max(res, count);
        }
        return res;
    }
    
private:
    multiset<pair<int, int>> s;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
