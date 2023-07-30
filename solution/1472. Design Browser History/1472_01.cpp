class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        H.push_back(homepage);
        i = mx = 0;
    }
    
    void visit(string url) {
        if (i + 1 == H.size())
            H.push_back(url);
        else
            H[i + 1] = url;
        mx = ++i;
    }
    
    string back(int steps) {
        i = max(0, i - steps);
        return H[i];
    }
    
    string forward(int steps) {
        i = min(mx, i + steps);
        return H[i];
    }
    
private:
    vector<string> H;
    int i, mx;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
