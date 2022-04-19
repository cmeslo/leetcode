class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m_.count(val)) return false;
        
        nums_.push_back(val);
        m_[val] = nums_.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!m_.count(val)) return false;
        
        int new_pos = m_[val];
        int last_val = nums_.back();
        
        m_[last_val] = new_pos;
        nums_[new_pos] = last_val;
        nums_.pop_back();
        m_.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums_[rand() % nums_.size()];
    }
    
private:
    vector<int> nums_;
    unordered_map<int, int> m_; // {val: index in nums_}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
