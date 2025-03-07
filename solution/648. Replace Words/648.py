class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        D = set(dictionary)
        
        def replace(word):
            for i in range(1, len(word)):
                if word[:i] in D:
                    return word[:i]
            return word
        
        return ' '.join(map(replace, sentence.split()))
    
