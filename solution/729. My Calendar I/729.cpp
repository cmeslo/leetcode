class MyCalendar {
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto it = books_.lower_bound(start);
        
        if (it != books_.end() && end > it->first) return false; // 後面有booking，並且重疊了
        if (it != books_.begin() && prev(it)->second > start) return false; // 前面有booking，並且重疊了
        
        books_[start] = end;
        return true;
    }
    
private:
    map<int, int> books_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
