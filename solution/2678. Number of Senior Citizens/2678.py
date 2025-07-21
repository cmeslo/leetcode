class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(int(d[-4:-2]) > 60 for d in details)
    
