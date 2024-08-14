class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        
        score = 0
        i, j = 0, len(tokens) - 1
        
        while True:
            while i <= j and power >= tokens[i]:
                power -= tokens[i]
                i += 1
                score += 1
            if score == 0 or i >= j:
                break
            power += tokens[j]
            j -= 1
            score -= 1
            
        return score
    
