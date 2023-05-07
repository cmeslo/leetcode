class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int res = 1;
        while (!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.emplace(price, res);
        return res;
    }
    
private:
    stack<pair<int, int>> st; // price, span
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


//    0  1  2  3  4  5  6
// [100,80,60,70,60,75,85]

//  100,              ,85
//    1, 1, 1, 2, 1, 4, 6
