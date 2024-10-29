class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        d = deque()
        for x in sorted(deck)[::-1]:
            if d: d.appendleft(d.pop())  # 或者 d.rotate()
            d.appendleft(x)
        return list(d)
    
