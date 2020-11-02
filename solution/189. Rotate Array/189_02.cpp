class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k %= n;
        if (k == 0 || k == n) return;
        
        int count = 0;
        int start = 0;
        
        while (count < n) {
            int curr = start;
            int currVal = nums[curr];
            
            do {
                int next = (curr + k) % n;
                int nextVal = nums[next];
                nums[next] = currVal; 
                curr = next;
                currVal = nextVal;
                ++count;
            } while (curr != start);
            
            ++start;
        }
    }
};
