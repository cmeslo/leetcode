class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();
    }
    
    string back(int steps) {
        while (steps-- > 0 && history.size() > 1) { // alwasy keep home page
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    string forward(int steps) {
        while (steps-- > 0 && !future.empty()) {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
    
private:
    stack<string> history, future;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
