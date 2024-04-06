class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        return (set(path[1] for path in paths) - set(path[0] for path in paths)).pop()
    
