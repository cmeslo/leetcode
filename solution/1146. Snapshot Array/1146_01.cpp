class SnapshotArray {
public:
    SnapshotArray(int length): A(length) {
        snapId = 0;
        for (int i = 0; i < length; ++i)
            A[i].push_back({snapId, 0});
    }
    
    void set(int index, int val) {
        if (A[index].back().first == snapId)
            A[index].back().second = val;
        else
            A[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto& history = A[index];
        int i = upper_bound(history.begin(), history.end(), make_pair(snap_id, 0), [](auto& a, auto& b) {
            return a.first < b.first;
        }) - history.begin() - 1;
        return history[i].second;
    }

private:
    vector<vector<pair<int, int>>> A;
    int snapId;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
