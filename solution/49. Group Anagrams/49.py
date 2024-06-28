class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = defaultdict(list)
        
        for word in strs:
            key = ''.join(sorted(word))
            m[key].append(word)
            
        return list(m.values())
    
