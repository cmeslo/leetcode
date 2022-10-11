class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums)
            s.insert(x);
        
        it = next(s.begin(), k - 1);
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() == k || val > *it)
            it = prev(it);
        return *it;
    }
    
private:
    multiset<int, greater<>> s;
    multiset<int, greater<>>::iterator it;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// 10 9 8 5 5 4 4 3 2
    
// 8 5 4 2
// 3:  8  5 [4] 3 2
// 5:  8  5 [5] 4 3 2
// 10: 10 8 [5] 5 4 3 2
