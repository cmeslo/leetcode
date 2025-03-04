class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        m = Counter(hand)
        for card in sorted(m):
            if m[card] > 0:
                for nxt in range(card + 1, card + groupSize):
                    m[nxt] -= m[card]
                    if m[nxt] < 0:
                        return False
                m[card] = 0
        return True
    
