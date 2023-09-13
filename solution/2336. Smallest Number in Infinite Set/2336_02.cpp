class SmallestInfiniteSet {
private:
    int cur;
    set<int> s;

public:
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        if (s.empty()) {
            cur += 1;
            return cur - 1;
        } else {
            auto it = s.begin();
            int x = *it;
            s.erase(it);
            return x;
        }
    }
    
    void addBack(int num) {
        if (num < cur) {
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
