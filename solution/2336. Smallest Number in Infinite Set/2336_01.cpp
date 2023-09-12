class SmallestInfiniteSet {
private:
    set<int> s;

public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i)
            s.insert(i);
    }
    
    int popSmallest() {
        int x = *s.begin();
        s.erase(x);
        return x;
    }
    
    void addBack(int num) {
        if (!s.count(num))
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
