class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sort = sorted(score)[::-1]
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + [str(i + 1) for i in range(3, len(score))]
        dt = dict(zip(sort, rank))
        
        # return map(dt.get, score)
        return [dt[s] for s in score]
    
