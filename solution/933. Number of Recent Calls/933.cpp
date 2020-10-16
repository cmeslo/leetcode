class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int start = t - 3000, end = t;
        
        q.push(t);
        while (!q.empty()) {
            if (!(start <= q.front() && q.front() <= end))
                q.pop();
            else
                break;
        }
        
        return q.size();
    }

private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
