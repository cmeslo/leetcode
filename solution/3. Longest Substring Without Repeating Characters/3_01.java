class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        
        int start = 0, max_len = 0;
        int[] map = new int[256];
        
        for (int i = 0; i < s.length(); ++i) {
            map[s.charAt(i)]++;
            while (map[s.charAt(i)] > 1) {
                map[s.charAt(start)]--;
                start++;
            }
            max_len = Math.max(max_len, i-start+1);
        }
        return max_len;
    }
}
