class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        joint = ''.join(words)
        s = set(joint)
        
        for i in s:
            if joint.count(i) % len(words) != 0: return False
        return True
    
