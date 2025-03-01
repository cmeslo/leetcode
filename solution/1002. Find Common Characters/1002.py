class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        res = Counter(words[0])
        for w in words:
            res &= Counter(w) # Counter 上的 & 操作會取兩者中的最小值
        return list(res.elements()) # Counter 的 elements() 會幫你按照數目逐個取出來 {a: 3} -> ['a', 'a', 'a']
    
